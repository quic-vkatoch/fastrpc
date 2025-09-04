📄 **conf Usage Guide**

---

### 🔧 **Purpose**
The `<>.conf` file enables **fastrpc** to set machine-specific configurations at runtime. Each section corresponds to a specific hardware platform.

- fastrpc supports reading config files from a particular directory. Users should ensure all configuration files are stored in that same directory.
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
Each entry in the `.conf` file must follow this structure:
```
[Machine Name]
DSP_LIBRARY_PATH = "<relative path to DSP binaries and resources for the Machine>"
```

---

### ✅ **Example Entries**
```
[Qualcomm Technologies, Inc. DB820c]
DSP_LIBRARY_PATH = "/apq8096/Qualcomm/db820c/"

[Thundercomm Dragonboard 845c]
DSP_LIBRARY_PATH = "/sdm845/Thundercomm/db845c/"
```

---

### ⚠️ **Important Notes**
- Do **not** modify section headers (`[Machine Name]`) unless adding a new supported Machine.
- Ensure `DSP_LIBRARY_PATH` values:
  - Are enclosed in double quotes (`"..."`).
  - Are **relative to `/usr/share/qcom/`**.
- Avoid:
  - Trailing spaces.
  - Special characters that may break parsing.
- Maintain:
  - Consistent indentation.
  - Proper line breaks.
- When adding new properties:
  - Document their purpose **here**.
- Do **not** create duplicate Machine entries.

---

### ➕ **Adding New Platforms**
To add a new Machine, follow the existing format:
```
[New Machine Name]
DSP_LIBRARY_PATH = "/new_machine/path/"
```
