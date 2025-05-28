# 🚀 ESP32-S3 Deauther Enhanced Web Interface

<div align="center">

![ESP32-S3](https://img.shields.io/badge/ESP32--S3-Supported-green?style=for-the-badge&logo=espressif)
![PlatformIO](https://img.shields.io/badge/PlatformIO-Compatible-orange?style=for-the-badge&logo=platformio)
![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)
![Version](https://img.shields.io/badge/Version-2.0-red?style=for-the-badge)

**🔥 Enhanced ESP32-S3 Deauther with Modern Web Interface 🔥**  
*A powerful WiFi deauthentication tool with an intuitive, mobile-friendly web interface*

</div>

---


## ✨ Features

### 🎯 Core Functionality

- **WiFi Deauthentication Attacks** – Disconnect devices from WiFi networks  
- **Access Point Scanning** – Discover nearby WiFi networks  
- **Apple Juice Attack** – iOS device targeting capabilities  
- **Packet Monitor** – Real-time WiFi packet analysis  

### 🌟 Enhanced Web Interface

- **🎨 Modern UI Design** – Clean, intuitive interface  
- **📱 Mobile Optimized** – Perfect for smartphones and tablets  
- **🔄 Auto-Navigation** – Automatic return to homepage  
- **🎛️ Selection-Based Controls** – No more manual command input  
- **⚡ Real-time Updates** – Live status and progress indicators  
- **🌙 Responsive Design** – Works on all screen sizes  

---

## 🆕 What's New

### 🎉 Version 2.0 Improvements  
**Based on:** [ESP32-s3-Deauther-master-with-apple-juice](https://github.com/electronicminer/ESP32-s3-Deauther-master-with-apple-juice)

#### 🔥 Enhanced Web Interface

- **✅ Dropdown Selections**  
- **🏠 Auto-Return Feature**  
- **📱 Mobile-First Design**  
- **🎨 Visual Improvements**  
- **⚡ Simplified Operation**  

#### 🛡️ Default Configuration

- **📡 Network Name:** `DeauthV1`  
- **🔐 Password:** `12345678`  
- *(Customizable in `definitions.h`)*

---

## 🛠️ Hardware Requirements

### 📟 Supported Boards

- **ESP32-S3** (Primary target)  
- **ESP32-S3-DevKitC-1**  
- **ESP32-S3-WROOM-1**  
- **ESP32-S3-MINI-1**  

### 🔌 Minimum Specifications

- **Flash Memory:** 4MB minimum (8MB recommended)  
- **RAM:** 512KB minimum  
- **WiFi:** 802.11 b/g/n support  
- **Antenna:** Built-in or external  

---

## ⚡ Quick Start

### 🚀 Installation via PlatformIO

#### 1️⃣ Prerequisites

```bash
pip install platformio
```
 Or install PlatformIO IDE extension for VS Code

#### 2️⃣ Clone Repository

```git clone https://github.com/IddoxLatifi/ESP32-S3-Deauth-AppleJuice.git
cd ESP32-S3-Deauther-Enhanced
```

#### 3️⃣ Build and Upload

```bash
pio run

pio run --target upload

# Monitor serial output (optional)
pio device monitor
```

#### 4️⃣ Connect to Device

1. **📡 Find WiFi Network:** Look for `DeauthV1`  
2. **🔐 Enter Password:** `12345678`  
3. **🌐 Open Browser:** Navigate to `http://192.168.4.1`  
4. **🎉 Start Using:** Enjoy the enhanced interface!



---  
## 📱 Web Interface

### 🏠 Homepage  
The redesigned homepage provides quick access to all features:

- **🎯 Quick Actions Panel**  
- **📊 System Status Display**  
- **⚙️ Settings Access**  
- **📱 Mobile-Optimized Layout**  


### 🔍 Network Scanner  
Enhanced scanning interface with:

- **📋 Network List View**  
- **🎛️ Filter Options**  
- **📊 Signal Strength Indicators**  
- **⚡ One-Click Selection**  


### 🎯 Attack Interface  
Simplified attack controls featuring:

- **📝 Target Selection Dropdown**  
- **🎚️ Attack Type Chooser**  
- **⏱️ Duration Settings**  
- **▶️ Start/Stop Controls**  


### 📊 Monitoring Dashboard  
Real-time monitoring with:

- **📈 Live Packet Graphs**  
- **📋 Activity Logs**  
- **🔄 Auto-Refresh**  
- **📱 Touch-Friendly Controls**  


---  
## ⚙️ Configuration

### 🔧 Basic Settings  
Edit `definitions.h` to customize:

```cpp
// WiFi Access Point Settings
#define AP_SSID "DeauthV1"        // Default: "DeauthV1"
#define AP_PASSWORD "12345678"    // Default: "12345678"
```
## 📸 Screenshots

<div align="center">
  <table>
    <tr>
      <td align="center"><strong>🖥️ Desktop View</strong></td>
      <td align="center"><strong>📱 Mobile View</strong></td>
    </tr>
    <tr>
      <td>
        <img src="https://github.com/user-attachments/assets/a929a6b0-a685-4685-b0ce-bbca9f52c010" width="300">
      </td>
      <td>
        <img src="https://github.com/user-attachments/assets/fac4f930-6bf9-4ec0-aae1-5f541ac9d162" width="200">
      </td>
    </tr>
  </table>
</div>


## 🙏 Acknowledgments

### 🌟 Credits

- **Original Project:** [ESP32-s3-Deauther-master-with-apple-juice](https://github.com/electronicminer/ESP32-s3-Deauther-master-with-apple-juice)  
- **ESP32 Community** – For extensive documentation and support  
- **PlatformIO Team** – For the excellent development platform  
- **Contributors** – Everyone who helped improve this project

## ⚠️ Legal Disclaimer

### 🚨 Important Notice  
This tool is designed for **educational and authorized testing purposes only**.

#### ✅ Authorized Use

- **🏠 Personal Networks** – Testing your own WiFi security  
- **🎓 Educational Labs** – Learning WiFi security concepts  
- **🔒 Penetration Testing** – Authorized security assessments  
- **🧪 Research** – Academic and professional research

#### ❌ Prohibited Use

- **🚫 Unauthorized Networks** – Attacking networks without permission  
- **💼 Commercial Disruption** – Interfering with business operations  
- **🏛️ Public Networks** – Disrupting public WiFi services  
- **🎯 Malicious Intent** – Using for harmful purposes

#### 📜 Legal Responsibility  
**Users are solely responsible for compliance with local laws and regulations. The developers assume no liability for misuse of this software.**


### 🚀 Ready to Get Started?

**[⬇️ Download Latest Release](https://github.com/IddoxLatifi/ESP32-S3-Deauth-AppleJuice)** |  
**[💬 Discord-Community](https://discord.gg/KcuMUUAP5T)**  

---

**⭐ Star this repository if you found it helpful!**  


<h2 align="left">I code with</h2>

<div align="left">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/javascript/javascript-original.svg" height="40" alt="javascript logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/docker/docker-original.svg" height="40" alt="docker logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/python/python-original.svg" height="40" alt="python logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/visualstudio/visualstudio-plain.svg" height="40" alt="visualstudio logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/css3/css3-original.svg" height="40" alt="css3 logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/git/git-original.svg" height="40" alt="git logo"  />
  <img width="12" />
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/rust/rust-original.svg" height="40" alt="rust logo"  />
</div>

<div align="center">
  <img src="https://github-readme-stats.vercel.app/api?username=IddoxLatifi&hide_title=false&hide_rank=false&show_icons=true&include_all_commits=true&count_private=true&disable_animations=false&theme=dracula&locale=en&hide_border=false&order=1" height="150" alt="stats graph"  />
  <img src="https://github-readme-stats.vercel.app/api/top-langs?username=IddoxLatifi&locale=en&hide_title=false&layout=compact&card_width=320&langs_count=5&theme=dracula&hide_border=false&order=2" height="150" alt="languages graph"  />
</div>


</div>
