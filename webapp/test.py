import serial
import time

uno2 = serial.Serial("COM6", baudrate=9600)
time.sleep(5)

for i in range(2):
    uno2.write(b'H')
    print(i)

print("Turning Motor 1 of Uno2")

# uno2.close()
# if st.button("Turn Motor 2 of uno2"):
#     print(uno2.write(b'J'))
#         # print("LOL")
#     print("Turning Motor 2 of Uno2")





# dev.write(b'1')
# dev.write(b'0')
