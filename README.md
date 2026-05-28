# LVGL Open — XML project template

A small, opinionated starting point for an LVGL Pro / Open XML UI. It ships a
tiny **design system**, a set of thin **component wrappers** with a minimal
API, and **two example screens** wired together with navigation and data
binding. Target display: **800 × 480**, `lvgl_version` 9.5.0.

## Layout

```
project.xml              one 800x480 target
globals.xml              the design system: consts, fonts, styles, subjects
components/
  layout/   base_box · container · panel
  typography/ h1 h2 h3 h4 h5 · text
  controls/ button · arc · slider · bar · toggle · text_input · text_box
screens/  screen_home (permanent) · screen_settings (created on demand)
fonts/    Montserrat Regular/Medium/SemiBold/Bold (compiled in)
```

## Design system (`globals.xml`)

- **Spacing** `#space_xs … #space_xl`, **shape** `#radius`, `#border_width`.
- **Colors** light/dark `#color_*_bg|panel|text`, plus `#color_accent`,
  `#color_accent_text`, `#color_danger`, `#color_track`.
- **Fonts** Montserrat: `font_body` (16) and `font_h5…font_h1` (18→44),
  in Regular/Medium/SemiBold/Bold. `font_body` is the inherited default.
- **Subjects** (the observable model the UI binds to):
  - `subject_theme_dark` — `0` light / `1` dark.
  - `subject_brightness` — `0…100`, driven by the demo controls.

## How theming works (read this before editing layout)

The screen root sets `text_color` + `text_font` through a **bound** light/dark
style. `base_box` runs `remove_style_all` once, so every `container`/`panel`
is theme-free and **inherits** that color. Result: flipping
`subject_theme_dark` recolors the whole screen at once.

So: build boxes with `container`/`panel`, and **don't set `text_color`** on
them — let it inherit. Set a color only as a deliberate one-off
(`style_text_color="…"` at the use-site).

## Components

Each exposes only a few props; everything else comes from the design system.

| Component | Key props |
|---|---|
| `container` | `pad` `gap` `flow`(column/row) `grow` |
| `panel` | `pad` `gap` `flow` `radius` `grow` |
| `h1`…`h5`, `text` | `text` |
| `button` | `text` `bg_color` `text_color` `radius` — attach `<event_cb>` / `<screen_*_event>` as children |
| `arc`, `slider` | `subject` `min` `max` `color` (two-way bound, draggable) |
| `bar` | `subject` `min` `max` `color` (read-only) |
| `toggle` | `subject` (0/1) `color` |
| `text_input` | `text` `placeholder` `password` (single line) |
| `text_box` | `text` `placeholder` (multi line) |

Set size/position at the use-site, e.g. `<slider subject="subject_brightness" width="100%" />`.

## Build / preview

```bash
lved validate .        # syntax + reference check
lved generate .        # emit C (screens, components, fonts)
lved compile . --target node   # build (needs a toolchain: container or local-emsdk)
```

`lved` = the LVGL editor CLI. You can also open this folder in the LVGL editor
to preview and edit visually.
