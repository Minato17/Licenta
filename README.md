# Licenta
Lucrare de Licenta - Brat robotic

---

## ⚙️ Tehnologii utilizate

- 🧠 **Raspberry Pi 4** – unitate centrală de procesare
- ⚙️ **Arduino Uno** – controlul servo-motoarelor
- 📷 **Xiaomi Imilab CMSXJ22A** – cameră pentru recunoaștere vizuală
- 🟢 **Node-RED** – interfață grafică și orchestrare logică
- 🐍 **Python + OpenCV** – procesare imagini și identificare culori
- 💬 **MQTT / Sparkplug B** – comunicație între sisteme
- 🔌 **USB Serial / UART** – transmitere comenzi între Pi și Arduino

---

## 🔍 Funcționalități principale

- Control manual al brațului robotic prin interfață Node-RED
- Salvarea și redarea secvențelor de mișcare (JSON)
- Detectarea obiectelor pe baza culorii (roșu, verde, albastru)
- Comunicarea bidirecțională cu alte sisteme prin MQTT (Sparkplug)
- Posibilitate de oprire automată a fluxului pe baza unui mesaj extern (ex: oprire bandă transportoare)

---

## 🚀 Instruire și rulare

### 1. Arduino
- Se încarcă fișierul `Brat_Robotic.ino` în Arduino IDE
- Se conectează servo-motoarele conform pinilor configurați

### 2. Raspberry Pi
- Se instalează Node-RED și OpenCV
- Se pornește flow-ul din `node-red/flow.json`
- Se rulează scriptul `python/camera_detectie.py` pentru detecția vizuală

### 3. Node-RED Dashboard
- Accesează interfața grafică prin `http://<ip_raspberry>:1880/ui`
- Butoanele și comenzile sunt disponibile pentru control complet

---

## 📎 Exemple de utilizare

- Apasă "Start Detectare" → se lansează scriptul de culoare
- Obiect roșu detectat → trimite codul în Node-RED → acțiune automată braț
- "Salvează Secvență" → creează fișier JSON pentru redare ulterioară

---

## 📜 Licență

Acest proiect este destinat uzului educațional și poate fi reutilizat cu menționarea sursei.  
Autor: Foghiș Nicușor-Gabriel – Universitatea Politehnica Timișoara, 2025.

---

