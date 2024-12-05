<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Getting Started with Your Instrument</title>
</head>
<body>
    <h1>Getting Started with Your Instrument</h1>
    <p>
        This guide will help you set up and play your custom instrument, which integrates Arduino, Max/MSP, and Ableton Live 11 to create an expressive and dynamic performance system. Follow the steps below to ensure proper installation and setup.
    </p>

    <h2>1. Installation Information</h2>

    <h3>Required Software</h3>

    <ul>

        <li>
            <strong>Arduino IDE</strong><br>
            <ul>
                <li><strong>Download:</strong> <a href="https://www.arduino.cc/en/software" target="_blank">Arduino IDE Official Website</a></li>
                <li><strong>Installation:</strong> Follow the instructions for your operating system. Ensure the Teensyduino add-on is installed for Teensy 4.0 compatibility.</li>
                <li><strong>Teensyduino:</strong> <a href="https://www.pjrc.com/teensy/teensyduino.html" target="_blank">Download and Install Teensyduino</a>.</li>
            </ul>
        </li>

        <li>
            <strong>Max/MSP 9</strong><br>
            <ul>
                <li><strong>Download:</strong> <a href="https://cycling74.com/products/max" target="_blank">Max/MSP Official Website</a></li>
                <li><strong>Installation:</strong> Follow the provided installation wizard.</li>
            </ul>
        </li>
        <li>
            <strong>Ableton Live 11</strong><br>
            <ul>
                <li><strong>Download:</strong> <a href="https://www.ableton.com/en/live/" target="_blank">Ableton Official Website</a></li>
                <li><strong>Installation:</strong> Install the latest version and ensure it is authorized for use.</li>
            </ul>
        </li>
    </ul>

    <h3>Arduino Libraries</h3>
    <ul>
        <li>
            <strong>Adafruit LSM6DSOX Library</strong><br>
            <ul>
                <li>Install through Arduino IDE:
                    <ol>
                        <li>Open Arduino IDE and navigate to <strong>Sketch > Include Library > Manage Libraries</strong>.</li>
                        <li>Search for <code>Adafruit LSM6DSOX</code> and click <strong>Install</strong>.</li>
                    </ol>
                </li>
                <li>Alternatively, download from <a href="https://github.com/adafruit/Adafruit_LSM6DSOX" target="_blank">Adafruit GitHub Repository</a>.</li>
            </ul>
        </li>
    </ul>

    <h3>Max/MSP Packages</h3>
    <ul>
        <li>
            <strong>MSerial Object</strong> for communication between Arduino and Max/MSP.<br>
            <ul>
                <li>Create a Max’s Serial Object:
                    <ol>
                        
                        <li>Search for <code>Serial</code> Create in the Max Blank Panel</li>
                    </ol>
                </li>
            </ul>
        </li>
    </ul>

    <h2>2. Hardware Assembly</h2>
    <h3>Required Hardware</h3>
    <ul>
        <li>Teensy 4.0 (microcontroller)</li>
        <li>LSM6DSOX Motion Sensor (for detecting hand motion)</li>
        <li>Three Force Pressure Sensors (for controlling note velocity and dynamics)</li>
    </ul>

    <h3>Assembly Instructions</h3>
    <p>Download the hardware diagram: <a href="./Diagram.pdf" target="_blank">Diagram.pdf</a>.</p>
    <ul>
        <li><strong>Force Pressure Sensors:</strong>
            <ul>
                <li>Connect the three pressure sensors to analog input pins on the Teensy 4.0. Use appropriate resistors (as per sensor specifications) to ensure signal stability.</li>
            </ul>
        </li>
        <li><strong>LSM6DSOX Motion Sensor:</strong>
            <ul>
                <li>Connect the LSM6DSOX to the Teensy via I2C (SCL/SDA). Ensure proper wiring for power (VCC to 3.3V, GND to GND).</li>
            </ul>
        </li>
        <li><strong>Teensy 4.0:</strong>
            <ul>
                <li>Connect the Teensy to your computer via USB. Ensure all hardware connections are secure.</li>
            </ul>
        </li>
    </ul>

    <h2>3. Software Initialization</h2>
    <h3>Arduino IDE</h3>
    <ul>
        <li>Open the Arduino sketch for your instrument. Load the <code>Adafruit_LSM6DSOX</code> library and confirm the correct pin mappings for your hardware.</li>
        <li>Upload the code to the Teensy 4.0 using Arduino IDE.</li>
    </ul>

    <h3>Max/MSP</h3>
    <ul>
        <li>Open the Max patch included in your project directory.</li>
        <li>Ensure Maxuino is configured to read sensor data from the Teensy.</li>
        <li>Select the correct COM port corresponding to your Teensy.</li>
        <li>Verify data flow from the sensors.</li>
    </ul>

    <h3>Ableton Live 11</h3>
    <ul>
        <li>Open the Ableton Live project template.</li>
        <li>Ensure the MIDI/OSC input is correctly mapped to receive data from Max/MSP.</li>
        <li>Assign the incoming data to control <strong>reverb</strong> and <strong>EQ</strong> parameters.</li>
    </ul>

    <h2>4. Playing the Instrument</h2>
    <h3>Connect Sensors</h3>
    <ul>
        <li>Ensure the force pressure sensors are securely placed where the performer can press them comfortably.</li>
        <li>Hold the LSM6DSOX-equipped device in your left hand for motion control.</li>
    </ul>

    <h3>Start Performance</h3>

    <ul>
        <li>Press the pressure sensors to play notes. The force you apply will control the velocity of the notes.</li>
        <li>Move your left hand to adjust <strong>reverb</strong> and <strong>EQ</strong> parameters dynamically.</li>
    </ul>

    <h3>Adjust Settings</h3>
    <ul>
        <li>Use Max/MSP to fine-tune sensor thresholds and Ableton to modify audio effects.</li>
    </ul>



    
</body>
</html>
