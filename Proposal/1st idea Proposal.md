### This is my first idea of instrument design.

# Motion Keyboard


### My instrument idea specifically

For the instrument I want to design, I aim to create something that can be played in the air, capable of sending MIDI CC and notes to any DAW or working independently with Max/MSP. Based on my research in the last two sessions on the motion sensor LSM6DSOX and the pressure sensor, I plan to apply this knowledge to help me build this instrument. My goal is for the performer to simply place their hand in the air to start controlling the parameters of this instrument.

I'll use the LSM6DSOX sensor to let the performer adjust the instrument's tone or control the ADSR. The tone can be modified by the movement of the performer’s left hand, and each adjustment can be locked by pressing a lock button. For the right hand, based on my research on the MF01A-N-221-A pressure sensor, I will set up five pressure sensors attached to a wearable box. These will allow the performer to control pitch, switch between different modes, and shift octaves up and down.

One inspiration for the ADSR control comes from my revised assignment involving the ultrasonic sensor. I believe I’ll continue refining this instrument design based on the insights from this project.[Google Drive](https://drive.google.com/drive/folders/103PamP4QufTZJQmk1LSWuOoSu0nwhBnQ?usp=share_link) [Repo](https://github.com/DeshuiY/EP-390_Distance-based-Musical-Instrument)




### Good Outcome Deliverable

**Basic Sound Switching with Left Hand:**

The left hand will be able to switch between different sounds, even if limited to a few preset options.

**Note Playing with Right Hand:**

The right hand will utilize a pressure sensor to perform simple note playing, providing a foundational level of interaction for the instrument.

### Better Outcome Deliverable

**Expanded Sound Switching Options for Left Hand:** 

The left hand will have access to a greater variety of sound options, with multiple presets that provide richer tonal flexibility.

**Dynamic Note Control with Right Hand Pressure Sensor:** 

The right hand’s pressure sensor will support more expressive note control, including dynamics or intensity based on pressure variations.


### Best Outcome Deliverable

**Seamless Hand-Controlled Parameter Adjustment:**

Both hands can smoothly control corresponding parameters, ensuring precise and responsive performance.

**Flawless Mode Switching:**

Seamless switching between modes without lag or unintended behavior, enabling uninterrupted performance transitions.

**Intuitive and Accessible UI:** 

A well-designed user interface that enhances understanding and ease of use, allowing performers to focus on their art without technical distraction.

**Gradual Visual Reset:** 

When the performer opens the left hand, the temperature gradually decreases, causing the visual effects to return to their original state, seamlessly reflecting the performer’s physical interaction with the instrument.

**Temperature-Driven Visual Effects Integration:** 

Using the LSM6DSOX sensor’s temperature data to influence Max/MSP visual effects (viz effects). When the performer’s left hand grips, the temperature at the center of the left hand rises, transmitting data to Max/MSP. This data dynamically modifies camera-linked visuals using scale, jit.gl.slab, and other effects, creating a visual response that evolves with the performance.

### Additional Skills Require 

For the next steps, I believe the focus should be on figuring out how to extend the cables connecting each sensor to give the performer more space and freedom to move comfortably within a wider range while playing the instrument. I may need to learn some soldering skills, as well as how to explain the controls in a way that is concise yet clear for the performer. Additionally, I will look into how to make the wearable setup as comfortable as possible, ensuring ease of use while playing.