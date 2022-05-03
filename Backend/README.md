# Python Script

## Functionality
The python script takes in the data from the arduino, sorts it, then stores it in a csv file on a day by day basis.

## Repeatability
When running this code, there will be issues that need to be addressed.
+ The first is the import serial issue which occurs when 1 of two things happen, there is either no serial library installed or it is outdated. To fix this, install or update the pyserial library.
+ The second issue has to do with finding the correct serial port where the arduino is connected. This is dependent on the OS that the computer is running. Linux will use "/dev/ttyACM*", mac will use "/dev/tty.usbmodem*", windows will use "P1AM-100 (COM*)". This project was run on a linux (ubuntu 20.04), and in this case to run the code, there was an additional step which included using "sudo chmod a+rw /dev/ttyACM0".
 + The third issue is the use of an S3 bucket which this script exports csv files to. By the time this is readable, the S3 bucket files will no longer work and any future users must purchase a subscription to AWS services and create a new S3 bucket. You must install the boto3 library and set up authentication credentials for your AWS account. This website has all the details: https://boto3.amazonaws.com/v1/documentation/api/latest/guide/quickstart.html . First uncomment, lines 46-50, then one has to go to lines 50 and insert there bucket name under "Bucket = 'YOUR_BUCKET_HERE'"

After these are all solved the script should work perfectly :)
