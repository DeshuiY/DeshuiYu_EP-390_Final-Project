<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>User Manual</title>
</head>
<body>
    <h1>User Manual</h1>
    <p>
        This manual provides an overview of all potential interactions and approaches to engage with your instrument. By exploring the dynamics of pressure sensors and motion controls, performers can achieve expressive musical results.
    </p>

    <h2>1. Overview of Controls</h2>
    <ul>
        <li><strong>Force Pressure Sensors:</strong>
            <ul>
                <li><strong>Purpose:</strong> Control note velocity and dynamics.</li>
                <li><strong>Interaction:</strong> Apply varying amounts of pressure to modify the intensity and dynamics of the generated notes.</li>
                <li><strong>Configuration:</strong>
                    <ul>
                        <li>Each pressure sensor corresponds to specific musical parameters, allowing customized responses.</li>
                    </ul>
                </li>
            </ul>
        </li>
        <li><strong>LSM6DSOX Motion Sensor:</strong>
            <ul>
                <li><strong>Purpose:</strong> Control reverb and EQ parameters through left-hand motion.</li>
                <li><strong>Interaction:</strong>
                    <ul>
                        <li>Move your hand vertically to adjust reverb intensity.</li>
                        <li>Sway your hand horizontally to modulate EQ parameters (e.g., increasing bass or treble).</li>
                    </ul>
                </li>
                <li><strong>Configuration:</strong> Adjust sensitivity via Max/MSP to suit your motion range.</li>
            </ul>
        </li>
    </ul>

    <h2>2. Interaction Techniques</h2>
    <h3>Playing Notes</h3>
    <p>
        Engage the pressure sensors to produce notes with varying velocities:
        <ul>
            <li>Press lightly for soft and subtle dynamics.</li>
            <li>Apply more pressure for louder, more pronounced notes.</li>
        </ul>
    </p>

    <h3>Dynamic Modulation with Motion</h3>
    <p>
        Use your left hand to add expressive effects:
        <ul>
            <li><strong>Reverb:</strong> Raise or lower your hand to expand or reduce the sense of space in the sound.</li>
            <li><strong>EQ:</strong> Move your hand side-to-side to alter tonal characteristics like brightness or warmth.</li>
        </ul>
    </p>

    <h3>Combining Sensors</h3>
    <p>
        Combine pressure and motion inputs for more dynamic performances:
        <ul>
            <li>Apply pressure to play a note while simultaneously modulating reverb or EQ with hand motions.</li>
            <li>Create evolving textures by varying pressure intensity and hand movement speed.</li>
        </ul>
    </p>

    <h2>3. Customization</h2>
    <p>
        Modify settings in Max/MSP and Ableton to fit your performance style:
        <ul>
            <li><strong>Adjust Pressure Sensitivity:</strong> Use Max/MSP to set thresholds for each force sensor.</li>
            <li><strong>Modify Motion Sensor Parameters:</strong> Configure LSM6DSOX sensitivity for specific ranges of motion.</li>
            <li><strong>Assign Effects:</strong> In Ableton, reassign Max/MSP outputs to control additional parameters like delay or filters.</li>
        </ul>
    </p>

    <h2>4. Performance Tips</h2>
    <ul>
        <li><strong>Experiment:</strong> Try different combinations of pressure and motion to discover unique soundscapes.</li>
        <li><strong>Calibrate:</strong> Perform a quick calibration before playing to ensure sensors respond accurately.</li>
        <li><strong>Layer Effects:</strong> Use Ableton’s effect chains to stack multiple effects for richer textures.</li>
        <li><strong>Practice:</strong> Familiarize yourself with the instrument's response to gain precise control over dynamics and effects.</li>
    </ul>

    <h2>5. Troubleshooting</h2>
    <ul>
        <li><strong>No Response from Pressure Sensors:</strong>
            <ul>
                <li>Ensure the sensors are connected correctly to the Teensy.</li>
                <li>Check Max/MSP for incoming data. Reconfigure if necessary.</li>
            </ul>
        </li>
        <li><strong>Motion Control Feels Unresponsive:</strong>
            <ul>
                <li>Verify that the LSM6DSOX is powered and connected.</li>
                <li>Adjust motion sensitivity settings in Max/MSP.</li>
            </ul>
        </li>
        <li><strong>Latency Issues:</strong>
            <ul>
                <li>Check the USB connection and ensure no background programs are consuming resources.</li>
                <li>Optimize MIDI/OSC settings in Ableton.</li>
            </ul>
        </li>
    </ul>

    <h2>6. Creative Approaches</h2>
    <p>
        Use this instrument to explore creative ideas:
        <ul>
            <li><strong>Live Performance:</strong> Improvise dynamic soundscapes by blending notes and motion effects.</li>
            <li><strong>Studio Production:</strong> Record MIDI/OSC data from Max/MSP and edit in Ableton for detailed compositions.</li>
            <li><strong>Interactive Installations:</strong> Integrate the instrument into larger multimedia projects for interactive sound design.</li>
        </ul>
    </p>
</body>
</html>
