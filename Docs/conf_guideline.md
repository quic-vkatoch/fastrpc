📄 **YAML Configuration Usage Guide**

---

### 🔧 **Purpose**
The YAML configuration file enables **fastrpc** to set machine-specific configurations at runtime. Each machine entry corresponds to a specific hardware platform.

- fastrpc supports reading YAML configuration files from a particular directory. Users should ensure all configuration files are stored in that same directory.
  - For Linux platforms: `/usr/share/qcom/conf.d/`
- **Machine Name**: Obtain the machine name for your platform from:
  ```
  /sys/firmware/devicetree/base/model
  ```
  (fastrpc uses same path for matching machine names)

---

### 📄 **Current Properties**
- **DSP_LIBRARY_PATH**: Specifies the path to DSP binaries and resources for the Machine.

---

### 📁 **Format Guidelines**
The configuration uses YAML format with the following structure:
```
machines:
  "Machine Name":
    DSP_LIBRARY_PATH: "/relative/path/to/dsp/binaries/"
```

**Key Points:**
- The root element is `machines:`
- Each machine name is a quoted string key under `machines:`
- Properties are indented under each machine name
- Use proper YAML indentation
- Paths should be quoted strings

---

### ✅ **Example Configuration**
```
machines:
  "Qualcomm Technologies, Inc. DB820c":
    DSP_LIBRARY_PATH: "/apq8096/Qualcomm/db820c/"
  "Thundercomm Dragonboard 845c":
    DSP_LIBRARY_PATH: "/sdm845/Thundercomm/db845c/"
```

---

### ⚠️ **Important Notes**
- Do **not** modify machine names unless adding a new supported Machine.
- Ensure `DSP_LIBRARY_PATH` values:
  - Are enclosed in double quotes (`"..."`).
  - Are **relative to `/usr/share/qcom/`**.
- Follow YAML syntax rules:
  - Use consistent indentation.
  - Ensure proper spacing after colons (`: `).
  - Quote strings containing special characters or spaces.
  - Avoid tabs (use spaces only).
- Maintain:
  - Proper YAML structure and hierarchy.
  - Consistent formatting across entries.
- When adding new properties:
  - Document their purpose **here**.
  - Follow the same indentation pattern.
- Do **not** create duplicate Machine entries.
- Validate YAML syntax before deployment to avoid parsing errors.

---

### ➕ **Adding New Platforms**
To add a new Machine, follow the existing YAML format:
```
machines:
  "New Machine Name":
    DSP_LIBRARY_PATH: "/new_machine/path/"
```

Ensure the new entry is properly indented under the `machines:` root element and follows YAML syntax conventions.

---

### 📝 **File Naming**
Configuration files should use the `.yaml` or `.yml` extension and be placed in the designated configuration directory (`/usr/share/qcom/conf.d/` on Linux platforms).
