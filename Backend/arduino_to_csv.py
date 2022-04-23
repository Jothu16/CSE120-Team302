import serial
import pandas as pd
from io import StringIO
import glob
import os
import boto3
from datetime import date

port = "/dev/ttyACM0" # Replace the xxx with the arduino serial protected
fileName = "Data.csv" # This is the file that will store data
baud = 115200 # Arduino p1am board runs at a baud of 115200
ser = serial.Serial(port, baud, timeout = 1)
sample_size = 100 
current_data = 0

file = open(fileName, "a")  # Stores the data in the file
file.write("Wind direction, Ambient temp, Solar irradiance, Collector inlet, Collector outlet, Tank inlet, Tank outlet, Loop pressure, Flow meter, Wind speed, Pump status\n\n")

# today = date.today()
# d1 = today.strftime("%m-%d-%Y")
s3 = boto3.client('s3')

while current_data <= sample_size: # Only takes in 100 inputs as a start
    communication = ser.readline().decode('utf-8')
    arduino_data = str(communication) # Gets the data from the arduino and converts to string
    data = arduino_data
    file = open(fileName, "a")  # Stores the data in the file
    file.write(data + " ")
    current_data += 1   # Increases the count

file.close()

hc = pd.read_csv(fileName)
csv_buf = StringIO()
hc.to_csv(csv_buf, header=True, index=False)
csv_buf.seek(0)
s3.put_object(Bucket='optic302', Body = csv_buf.getvalue(), Key = fileName)
