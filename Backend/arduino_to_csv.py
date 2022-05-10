import serial
import pandas as pd
from io import StringIO
import glob
import os
import boto3
from datetime import date
import time

def newFile(file_name):
    fileName = file_name + ".csv"
    file = open(fileName, "a")
    file.write("Name, Optic, , , , , , , , , , \n")
    file.write("Description, This arduino is at the UC Merced campus being used for data gathering, , , , , , , , , , \n")
    file.write("Wind direction, Ambient temp, Solar irradiance, Collector inlet, Collector outlet, Tank inlet, Tank outlet, Loop pressure, Flow meter, Wind speed, Pump status\n\n")
    return fileName



port = "/dev/ttyACM2" # Replace the xxx with the arduino serial protected
baud = 115200 # Arduino p1am board runs at a baud of 115200
ser = serial.Serial(port, baud, timeout = 1)


today = date.today()
today = today.strftime("%m-%d-%Y")
#add name of file to dates.txt
f = open("dates.txt","a+")
f.write(today+"\n")
current_day = today
fileName = newFile(today)
s3 = boto3.client('s3')

while (True): 

    new_time = time.strftime("%H-%M")
    current_time = new_time

    while (new_time == current_time): # Sends the csv to the s3 bucket once per minute

        communication = ser.readline().decode('utf-8')
        data = str(communication) # Gets the data from the arduino and converts to string
        file = open(fileName, "a")  # Stores the data in the file
        file.write(data)
        current_time = time.strftime("%H-%M") #Updates the minute

    file.close()

    # hc = pd.read_csv(fileName)
    # csv_buf = StringIO()
    # hc.to_csv(csv_buf, header=True, index=False)
    # csv_buf.seek(0)
    # s3.put_object(Bucket='optic302', Body = csv_buf.getvalue(), Key = fileName)

    current_day = date.today()
    current_day = current_day.strftime("%m-%d-%Y")
    if (today != current_day):
        os.remove(fileName)
        today = current_day
        fileName = newFile(current_day)
   

