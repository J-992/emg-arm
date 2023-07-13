import serial
from pymyoware import MyoWare

# Configures the serial port for communication with Arduino
arduino_port = '/dev/ttyACM0'  # Update this with the correct arduino port
baud_rate = 9600
arduino = serial.Serial(arduino_port, baud_rate)

# Initialize MyoWare sensor
myoware_sensor = MyoWare(port='/dev/ttyUSB0', baud_rate=9600)

# Connect to MyoWare sensor
myoware_sensor.connect()

while True:
    # Read EMG data from  sensor
    emg_data = myoware_sensor.read_emg_data()

    # Perform data processing and translation
    # Replace this n translate EMG data into servo motor signals

  '''[
  
  
  bruh

  replace ths w actual servo code
  
  ]'''
    # The code below is just a placeholder
    servo1_signal = emg_data[0]
    servo2_signal = emg_data[1]
    servo3_signal = emg_data[2]
    servo4_signal = emg_data[3]
    servo5_signal = emg_data[4]

    # Send servo motor signals to Arduino
    # The Arduino code should be set up to receive these signals and control the servos accordingly
    arduino.write(f'{servo1_signal},{servo2_signal},{servo3_signal},{servo4_signal},{servo5_signal}\n'.encode())
