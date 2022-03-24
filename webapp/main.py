import serial
import streamlit as st 
import time

st.write("Hello! Welcome to the Web Interface")


try: 
    uno1 = serial.Serial("COM6", baudrate=9600)
except Exception as e:
    print(e)
else:
    if st.button("Turn Motor 1 of uno1"):
        uno1.write(b'H')
    if st.button("Turn Motor 2 of uno1"):
        uno1.write(b'J')

try:
    uno2 = serial.Serial("COM10", baudrate=9600)
except Exception as e:
    print(e)
else: 
    time.sleep(3)

if st.button("Turn Motor 1 of uno2"):
    uno2.write(b'H')
    print("Turning Motor 1 of Uno2")
if st.button("Turn Motor 2 of uno2"):
    print(uno2.write(b'J'))
        # print("LOL")
    print("Turning Motor 2 of Uno2")





# dev.write(b'1')
# dev.write(b'0')
