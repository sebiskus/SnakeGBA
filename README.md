## SnakeGBA

<img width="1000" height="400" alt="Logo-GitHub" src="https://github.com/sebiskus/SnakeGBA/blob/c736ff35676bdbe95c39f27be6d84e183727de22/Logo-GitHub.png" />

---

**Language / Sprache:** [🇬🇧](#english) | [🇩🇪](#deutsch)

---

## English

### Compile Instructions

**Compile command:**
```bash
export DEVKITPRO=[environment location] && sudo -E make -j[Number of CPU cores]
```

**Example:**
```bash
export DEVKITPRO=/opt/devkitpro && sudo -E make -j6
```

**Requirements:**
Python3, DEVKITARM and WONDERFUL_TOOLCHAIN must be installed (see Butano repo: https://github.com/GValiente/butano)

### Known Issues

- Fix seed generation
- Background is pink (even though it looks cool)
- Fix music loop

**Note:** Source code comments are primarily in German.

---

## Deutsch

### Compile-Anleitung

**Befehl zum Compilen:**
```bash
export DEVKITPRO=[environment location] && sudo -E make -j[Core Anzahl deiner CPU]
```

**Beispiel:**
```bash
export DEVKITPRO=/opt/devkitpro && sudo -E make -j6
```

**Voraussetzungen:**
Python3, DEVKITARM und WONDERFUL_TOOLCHAIN müssen installiert sein (siehe Butano repo: https://github.com/GValiente/butano)

### Bekannte Issues

- Seed generation fixen
- Hintergrund ist pink (auch wenn's cool aussieht)
- Musik loop fixen

**Hinweis:** Kommentare im Source-Code sind größtenteils auf Deutsch.
