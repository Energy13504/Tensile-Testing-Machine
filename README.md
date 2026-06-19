# Tensile-Testing-Machine

This project presents a tensile testing machine developed to evaluate the mechanical behavior of materials under uniaxial tension. It measures key properties such as tensile strength, elongation, and force-displacement response, making it useful for material testing, prototyping, and academic research.

#Machine architecture: 

The tensile testing machine consists of a mechanical loading frame, a motion control system, a force sensing unit, and a data acquisition module. Two stepper motors generate controlled linear motion to apply tensile force to the specimen, while an S-beam load cell measures the applied load and sends feedback to the Arduino Uno for processing and logging.

System components
Mechanical frame: Holds the specimen securely and supports the moving and fixed grips during tensile loading.

Stepper motors: Two stepper motors drive the motion mechanism to stretch the test sample at a controlled rate.

Arduino Uno: Acts as the central controller for motor coordination, sensor reading, and serial data communication.

S-beam sensor: Measures the tensile force applied to the specimen during testing.

Data logging: Test data is recorded into Excel for plotting graphs and analyzing force-displacement behavior.

