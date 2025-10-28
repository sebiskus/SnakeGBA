## SnakeGBA

<img width="1000" alt="Logo-GitHub" src="Logo-GitHub.png" />

---

**Language / Sprache:** [🇬🇧](#english) | [🇩🇪](#deutsch)

---
made with [Butano](https://github.com/GValiente/butano)

## English

### Compile Instructions

**Compile command:**
```bash
export DEVKITPRO=[environment location] && sudo -E make -j[Number of CPU cores]
```

**Example (MacOS):**
```bash
export DEVKITPRO=/opt/devkitpro && sudo -E make -j6
```

**Requirements:**
Python3, DEVKITARM and WONDERFUL_TOOLCHAIN must be installed (see Butano repo: https://github.com/GValiente/butano)

### Known Issues

- Fix seed generation
- Background is pink after the end of the game
- Fix music loop

**Note:** Source code comments are primarily in German.

## Deutsch

### Compile-Anleitung

**Befehl zum Compilen:**
```bash
export DEVKITPRO=[environment location] && sudo -E make -j[Core Anzahl deiner CPU]
```

**Beispiel (MacOS):**
```bash
export DEVKITPRO=/opt/devkitpro && sudo -E make -j6
```

**Voraussetzungen:**
Python3, DEVKITARM und WONDERFUL_TOOLCHAIN müssen installiert sein (siehe Butano repo: https://github.com/GValiente/butano)

### Bekannte Issues

- Seed generation fixen
- Hintergrund ist nach dem Spielende pink
- Musik loop fixen

**Hinweis:** Kommentare im Source-Code sind größtenteils auf Deutsch.

<img alt="Snake-GitHub" src="Snake-GitHub.png" />