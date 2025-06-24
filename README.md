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
- Se încarcă fișierul `Brat_Robotic.ino` în Arduino IDE, iar celelalte doua fișiere să se afle în același folder
- Se conectează servo-motoarele conform pinilor configurați

### 2. Raspberry Pi
- Se instalează Node-RED și OpenCV
- Se pornește Node-RED. Pe un flow nou se incarcă fisierul 'Implementare_Node-RED.json'
- După încărcarea implementarii în Node-RED se configurează porturile pentru comunicația intre Arduino și Pi
- Se configurează locația fișierelor .json pentru încarcarea sau salvarea secvențelor
- Se configurează adresa locației fișierului pentru activarea camerei web
- Se apasă butonul 'Deploy' din Node-RED, iar implementarea este activă

### 3. Node-RED Dashboard
- Accesează interfața grafică prin `http://<ip_raspberry>:1880/ui`
- Butoanele și comenzile sunt disponibile pentru control complet

---

## 📎 Exemple de utilizare

- Se apasă butonul 'Deploy' din Node-RED, iar implementarea este activă
- Se apasă butonul 'Pornire' și se activează secvența salvată
- Controlul servo motoarelor din slide-uri
- "Încarcare secvență" → încarca fișierul JSON cu secvențele salvate

---

## 📜 Licență

Acest proiect este destinat uzului educațional și poate fi reutilizat cu menționarea sursei.  
Autor: Foghiș Nicușor-Gabriel – Universitatea Politehnica Timișoara, 2025.

---

