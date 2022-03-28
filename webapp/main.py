import serial
import streamlit as st 
import time

st.write("Hello! Welcome to the Web Interface")

motorSelection = st.selectbox("Select Motor", [1,2,3,4])
motorSteps = st.slider("Steps", 10, 1000, 1)

try: 
    uno1 = serial.Serial("COM6", baudrate=9600)
except Exception as e:
    print(e)
else:
    time.sleep(3)

try:
    uno2 = serial.Serial("COM10", baudrate=9600)
except Exception as e:
    print(e)
else: 
    time.sleep(3)


if st.button("Send Command"):
    query = str(motorSelection) + str(motorSteps)
    if motorSelection == 1 or motorSelection == 2:
        uno1.write(motorSelection)
    elif motorSelection == 3 or motorSelection == 4:
        uno2.write(motorSelection)