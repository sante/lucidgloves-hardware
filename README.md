# lucidgloves-firmware
Arduino firmware for DIY haptic gloves. Officially compatible with LucidVR gloves.

Prototype 3 of the LucidVR glove prototype. This is a finger tracking glove that allows you to use your hands in VR. Follow along with Lucas_VRTech's developments on his Tiktok page:
https://www.tiktok.com/@lucas_vrtech

The assembly for each hand is as follows:
* Spool (5x)
* Tensioner (5x)
* Cover (5x)
* Holder (5x)
* GuideRing (2x per finger, 1x for thumb)
* EndCap (1x per finger, can be substituted for smaller guide ring) 

Disclaimer: You WILL need to print multiple sizes of the EndCap and GuideRing to fit the size of your fingers. Resize these in your slicer. Alternatively, you could print them in TPU for more flexible sizing.

Required parts for each hand:
* WL b10k ohm Potentiometer (5x)
* Arduino (Nano)
 - Will eventually be switching to ESP32 development boards for BTLE/Wifi
* Wiring/Connectors/Breadboards as needed.
 - I recommend crimping/using JST connectors, 5 pin JST-XH 2.54mm fit great on the potentiometers.
* Glove material of your choice.
 - Recommended: Nylon Inspection Gloves (more flexy), Cycling/Golf gloves (stronger, easier to put on)

More information will be available on the LucidVR site very soon.
Will be releasing video tutorials on how to assemble and setup the gloves.


This project uses the open source OpenVR driver created by LucidVR and Danwillm:
https://github.com/LucidVR/lucidgloves-openvr
