# Plague? Where? by glasseshead (David Sun)
A solo-programmed VEX V5 TeleOp program based on FTC's LocalizerTest TeleOp program built using LemLib and PROS that's fully customizable for your robot.

Thanks Zachary & Mooncy from 5776K; Aaron from 5776T; Iris from 5776A; Alvin and Elaine from FTC 16026 Alphabots

## Features
- **Real-time odometry localizer**  
  Utilizes IMU and tracking wheels to fetch robot position in real time

- **Live continuous pose streaming**  
  Outputs:
  - x, y, θ
  - Current pose
  - Start pose
  - Delta pose (relative movement)

- **Pose capturing support for primitive and advanced**
  - Capability to capture current poses and save to file in both primitive and advanced formats
  - Primitive: x, y, θ (radians), θ (degrees)
  - Advanced: x, y, θ (degrees) in moveToPose format

- **High-frequency enhanced telemetry**
  - Optimized for low flicker and high refresh rate
  - Integrated compact brain telemetry

- **Write to SD card support**
  - Capability to clear all contents of both data files

- **Live continuous error tracking and streaming**
  - Distance error
  - Heading error

- **Sensor calibration support**
  - Built-in IMU and tracking wheel calibration

- **Radian/Degree Support**
  - Radians / Degrees for heading

- **Adjustable data precision**
  - Tune decimal accuracy for specific units

- **Pose zeroing support**
  - Capability to zero the current pose and writing zero data to file

- **File clearing support**
  - Capability to clear all contents of both data files

- **Fully customizable architecture**
  - Easily adaptable to any VEX V5 drivetrain or sensor configuration

- **Arson, Yaay! compatability**
  - Designed to be compatible with Arson-based structures and can be modifiable for other architectures

## Controls
- Zero PoseA = L1
- Clear File = L2
- Capture Point (Primitive) = R1
- Capture Point (Advanced) = R2

## Notes
- All drivetrain and sensor configurations are currently placeholders and must be set per robot
- Sx/Sy/St: Start x/y/theta
- Cx/Cy/Ct: Current x/y/theta
- Dx/Dy/Dt: Delta x/y/theta
- dErr: Distance error
- hErr: Heading error
- ZpA: Zeroing PoseA Toggle
- Clr: Clearing File Toggle
- CpP: Primitive Capturing Point Toggle
- CpA: Advanced Capturing Point Toggle