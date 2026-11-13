# CYBER QUEST: Physical Arena & Cyber Armory ⚡

A high-octane physical turn-based cyberpunk RPG featuring **Live Optical WebCam Tracking** of physical opponents, **Tactile Arcade Attack Buttons & USB Gamepad Controller API**, and an interactive **Cyber Armory & Combat Review System** backed by SQLite.

---

## 🕹️ New Physical Game Features

### 1. 📷 Physical Opponent WebCam Arena
- Position an opponent physically in front of your computer or device!
- The camera locks onto the physical person with an augmented reality (AR) targeting reticle, cyber scanlines, and target brackets.
- When an attack is executed, cyber-plasma slashes and sparks explode directly on the opponent's video stream.
- Toggle anytime between **Live WebCam Arena** and **Holographic Simulation**.

### 2. 🎮 Physical Arcade Attack Buttons & Gamepad API
- **Big Tactile Arcade Buttons** with physical mechanical depression feedback:
  - `⚔️ PHYSICAL ATTACK`: Primary melee or energy strike
  - `⚡ SPECIAL ABILITY`: High-impact class ultimate (`Power Strike` / `Fireball`)
  - `🛡️ DEFEND`: Absorbs 50% extra incoming damage
  - `🧪 USE POTION`: Consumes nano-repair potion
  - `🛡️ ARMORY REVIEW`: Open equipment bay
  - `📊 COMBAT REVIEW`: Telemetry & hit-zone analysis
- **Hardware Keyboard Hotkeys:**
  - `SPACEBAR` or `F`: Physical Attack
  - `S`: Special Ability
  - `D`: Defend
  - `Q`: Use Potion
  - `R`: Open Cyber Armory
  - `C`: Combat Review
- **USB Gamepad & Arcade Fight Stick Support:**
  - Button 0 (`A` / Cross): Attack
  - Button 1 (`B` / Circle): Defend
  - Button 2 (`X` / Square): Special
  - Button 3 (`Y` / Triangle): Potion
  - Button 8/9 (`Select` / `Start`): Armory

### 3. 🛡️ The Cyber Armory ("Review with Armory")
- **Weapons Arsenal:**
  - *Plasma Katana* (Base ATK 30, Energy Blade)
  - *Vibro Nano-Dagger* (Base ATK +10, Ultrasonic Piercing)
  - *Arc EMP Staff* (Base ATK +18, Electromagnetic shock)
  - *Heavy Rail-Buster* (Base ATK +30, Linear magnetic devastation)
- **Armor & Exosuits:**
  - *Kevlar Nano-Weave* (15% Damage Absorption)
  - *Carbon Exosuit* (25% Damage Absorption)
  - *Aegis Kinetic Barrier* (35% Damage Absorption)
  - *Cyber Titan Plating* (50% Damage Absorption)
- **Review with Armory Tab:**
  - Inspect your tactical loadout specifications, weapon scaling, damage mitigation percentage, and potion capacities.
  - Upgrade weapons and armor using coins earned in battle.

### 4. 📊 Combat Review & Telemetry
- Inspect detailed hit analysis:
  - Hit location (Optic Core, Cybernetic Cranium [CRITICAL], Torso Flank)
  - Raw strike damage vs Opponent armor absorption
  - Total strikes, gross damage dealt, and gross damage received

---

## 🚀 How to Run

### Method 1: Full-Stack Web App (Recommended)
Start the built-in Node server:

```powershell
cd backend
node server.js
```

Open your browser to:
👉 **[http://localhost:3000](http://localhost:3000)**

### Method 2: Standalone Static File
Double-click:
👉 [frontend/index.html](file:///c:/Users/Administrator/OneDrive/Desktop/CyberQuest/frontend/index.html)
