import serial

port = "/dev/ttyACM0" # Replace the xxx with the arduino serial protected
fileName = "Data.csv" # This is the file that will store data
baud = 115200 # Arduino p1am board runs at a baud of 115200
communication = serial.Serial(port, baud)
sample_size = 100 
current_data = 0


while current_data <= sample_size: # Only takes in 100 inputs as a start
    arduino_data = str(communication.readline()) # Gets the data from the arduino and converts to string
    data = arduino_data[0:][:-2]
    file = open(fileName, "a")  # Stores the data in the file
    file.write(data + " ")
    current_data += 1   # Increases the count

file.close()

# This is still a test to see if we can get data from the adruino onto a computer and recieve an output
# Still need to sort data as it comes in
# Sort it based on type of data ie sensor
#