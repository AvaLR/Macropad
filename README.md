# Macropad

PCB:
- Started to design this in KiCad starting with the skematic design and then moving to the PCB design.
- I originally started with a 3X4 with 2 rotary encoders and 1 OLED
- I wanted to add LEDs so I removed 1 rotary encoder and made the other rotary encoder's button the same as button 3. Also made it a 3X3 instead of a 3X4.
- Wiring was a challenge and reminded me of that Flow Free game so it was kinda fun in that aspect.
<img width="500" height="350" alt="Screenshot 2026-07-26 at 11 47 30 AM" src="https://github.com/user-attachments/assets/377be910-935b-4b73-b9b2-1cf1fc368a45" />
<img width="500" height="350" alt="Screenshot 2026-07-26 at 11 47 11 AM" src="https://github.com/user-attachments/assets/d07dd326-7d89-47b7-89c3-21e263804044" />
<img width="1000" height="350" alt="Screenshot 2026-07-26 at 11 45 51 AM" src="https://github.com/user-attachments/assets/fb5088c5-9bf2-4845-89aa-9a4b1e98069b" />



Enclosure:
- A lot easier then the PCB
- First I inserted a .step file of my PCB into AutoDesk Fusion 
- Then based on the PCB I made my bottom enclosure (120mm X 100mm X 13mm) with 2.9mm holes in each corner so I can add screws to put my top and bottom enclosures together. I also put a hole on back for the USB.
- After I made the bottom enclosure I created the top enclosure with holes for all my buttons (inserting my PCB design really helped for this part because I knew exactly where the holes went). I put 2.9mm holes here as well to again be able to put the top and bottom together. 
- The top enclosure was a 120mm x 100mm x 3mm so with the top and bottom enclosure together it turned into a 120mm x 100mm x 16mm enclosure.
<img width="955" height="350" alt="Screenshot 2026-07-26 at 11 55 19 AM" src="https://github.com/user-attachments/assets/124056ba-6369-4c87-a813-ce3b0f76dd8f" /><img width="475" height="350" alt="Screenshot 2026-07-26 at 11 55 47 AM" src="https://github.com/user-attachments/assets/ed855903-2956-4c70-85d0-969f2ad78ee0" /> <img width="475" height="350" alt="Screenshot 2026-07-26 at 11 55 33 AM" src="https://github.com/user-attachments/assets/6da8d98d-65f5-4e5f-b799-423a8649308e" />

Firmware:
- Created 3 layers of Buttons: Daily, AVTF & Coding
- Each layer does different things that will make my life easier from study time to coding to editing videos!
- Each layer has its own RGB unkeyglow color, and the OLED will show what the layer I'm on
<>









Credit: 
Info & Guide - Hack Club
PCB, Enclosure, Firmware - Ava Russell using QMK Resources/Code/Guide
Debugging Help - AI
