# Mini Reminder
The mini-version of a multimodal reminder using an LED, a small speaker, and an Arduino Mini Pro.

Mini Reminder was a little fun-project, inspired by the multimodal reminder of the GAL project ( http://www.altersgerechte-lebenswelten.de/ ). 
The goal was to create a version that fits onto a PhD-hat. 

The LED was addressed using the impressive Adafruit Neopixel library: https://github.com/adafruit/Adafruit_NeoPixel
(and yes, I do know that we could've used just a single RGB-LED, but we had this one laying around ;) )

The code for playing the sound (PCM.h and PCM.c) was copied from https://playground.arduino.cc/Code/PCMAudio (thanks to Michael Smith) and slightly modified to include the sound file differently.

I couldn't find the origin of the used source-file for the sound, so I can't upload it. I converted my sound files into hexadecimal notation for a .h-file by first converting it to an unsigned 8-bit, 8000 Hz wave-file (e.g., by using Audacity), and then opening it in an Hex-editor (e.g., HxD)  and saving it as text-file. 

Unfortunately, I did not take a picture of the result or the wiring, but these resources may help you to connect everything correctly: 
* https://learn.adafruit.com/adafruit-neopixel-uberguide/basic-connections (for the LED)
* http://highlowtech.org/?p=1963 (for the speaker)
