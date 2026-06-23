# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project

LVGL Pro / Open **XML** UI project — `lvgl_version` 9.5.0, single 800×480 target
(`project.xml`). The UI is authored as XML; the LVGL editor CLI (`lved`)
generates C from it. There is no hand-written widget tree.

Use the `lvgl-open-xml-writer` skill for any XML authoring or refactor — it
holds the full syntax/rules reference and a validated example project. The
project follows that skill's conventions.

## Commands

Run from the project root:

```bash
lved validate .                 # syntax + reference check — run after every edit
lved generate .                 # emit *_gen.c / *_gen.h from XML (and fonts)
lved compile  . --target node   # build (needs container or local-emsdk)
```

`lved` resolves to `node ~/.claude/skills/lvgl-open-xml-writer/scripts/lved-cli.js`
(bundled). The editor can also open this folder for visual preview.

CMake build (after `lved generate`): the standard `cmake -S . -B build && cmake --build build`
flow; `CMakeLists.txt` is generated — extend it via `user_config.cmake`
(`LV_EDITOR_PROJECT_SOURCES`), never by editing `CMakeLists.txt` or
`file_list_gen.cmake` directly.

## Architecture

**XML → generated C.** Every `*.xml` under `components/`, `screens/`, plus
`globals.xml` and the fonts, is compiled into a paired `*_gen.c`/`*_gen.h`
sibling by `lved generate`. Generated files are tracked in git but **never
edited by hand** — re-running the generator overwrites them. The only
hand-written C is `lvgl_open_template.c/.h`, which wraps the generated
`lvgl_open_template_init_gen(asset_path)` entry point.

**Component layering (load-bearing — read before editing layout).** Three
layers in `components/layout/`:

1. `base_box` — the **single** place `<remove_style_all/>` runs. It strips
   the theme (including the theme's per-widget `text_color`) so the screen's
   bound text color can inherit down the tree. Used internally only.
2. `container` — extends `base_box`, adds `pad`/`gap`/`flow`/`grow` locals.
   Transparent, theme-free. This is the everyday grouping box.
3. `panel` — extends `container`, adds a visible card surface via the
   `style_panel_light` / `style_panel_dark` styles from globals, swapped by
   `subject_theme_dark`. Use when a child needs a visible background.

Because `remove_style_all` lives in its own component, anything that extends
`base_box` has its locals applied *after* the wipe, so they survive. If the
wipe and the locals were on the same view, the wipe would erase them.

**Theming via inheritance.** Screen roots (`extends="lv_obj"`) apply
`style_screen_light` and a bound `style_screen_dark` (subject
`subject_theme_dark`). Those two styles set both `text_color` and `text_font`.
Every child below is a theme-free `container`/`panel`, so a single toggle of
`subject_theme_dark` recolors all text and swaps panel surfaces at once.
**Never set `text_color` on `container` or `panel`** — let it inherit. Set
color only as a deliberate one-off via `style_text_color="…"` at the
use-site.

**Data binding via subjects.** The observable model lives in `globals.xml`
`<subjects>` (`subject_theme_dark`, `subject_brightness`, `subject_popup_open`,
the `subject_*` contact-screen group). Widgets bind with `bind_value` /
`bind_checked` / `bind_text` / `<bind_style>`. Moving any control bound to
`subject_brightness` updates every other widget bound to it in real time.

**Screen patterns.**
- `permanent="true"` (e.g. `screen_home`) — kept in RAM, state survives
  background loads.
- No `permanent` (e.g. `screen_settings`) — built by `<screen_create_event>`
  on demand and destroyed when navigated away.
- Use `<screen_load_event>` to switch to a permanent screen (no rebuild) and
  `<screen_create_event>` to build + load a non-permanent one.

## Design system (`globals.xml`)

Single source of truth — when adding spacing, colors, fonts, styles, or
subjects used by more than one component, add them here rather than
duplicating literals. Existing tokens:

- Spacing: `#space_xs` (4) … `#space_xl` (40); shape: `#radius` (14),
  `#border_width` (2).
- Light/dark palettes: `#color_{light,dark}_{bg,panel,text}`; semantic:
  `#color_accent`, `#color_accent_text`, `#color_danger`, `#color_track`.
- Fonts: Montserrat compiled in (`as_file="false"`) — `font_body` (16,
  inherited default) plus `font_h5`…`font_h1` (18→44).
- Styles: `style_screen_{light,dark}`, `style_panel_{light,dark}`,
  `style_text_accent`, `style_muted`, `style_list_row`, `style_dim`
  (recolor — cheaper than a translucent overlay), `style_track`,
  `style_indicator`, `style_scrollbar`.

## Components

Thin wrappers in `components/` exposing only a few props each — set
size/position at the use-site:

- `layout/`: `base_box` · `container` · `panel` · `window`
- `typography/`: `h1`…`h5` · `text` (single `text` prop each)
- `controls/`: `button` (attach `<event_cb>` / `<screen_*_event>` as
  children) · `arc` · `slider` · `bar` · `toggle` · `text_input` · `text_box`
- `list/`: `list` · `list_section` · `list_item` · `list_item_switch` ·
  `list_separator`
- `overlays/`: `popup`

## Files to know

- `project.xml` — target display.
- `globals.xml` — design system + subjects (see above).
- `lvgl_open_template.{c,h}` — hand-written init wrapper; add custom C
  alongside the generated init call.
- `user_config.cmake` — append your extra `.c` sources here.
- `*_gen.c` / `*_gen.h` / `fonts/font_*_data.c` / `file_list_gen.cmake` —
  **generated, do not edit**.
- `tests/` is currently empty; if adding XML tests, see the testing section
  of the `lvgl-open-xml-writer` skill.
