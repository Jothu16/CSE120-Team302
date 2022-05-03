# CSE120-Team302 

Arduino to CSV to Web App

This project was completed for Winston Cone Optics in the spring of 2022 at the University of California Merced as part of the Software Engineering Capstone. 

The authors are as follows:
Andy Hernandez
Austin Myhre
Eric Solorio
Harjot Grewal
Navroop Khangura

Please read the corresponding README for each section for instructions on how to use this repo properly. 

Below are important notes on each folder:

## Arduino

This ONLY runs on the P1AM board. This CANNOT compile or run in any other IDE, except for the arduino IDE. To use the P1AM-100, you need to follow the instructions posted on the public GitHub repo to install the board as well as the corresponding library.

## BackEnd

python script that takes in data from arduino then formats it into a csv file, and uploads that csv file to our team's S3 Bucket. 
The code can also be used just to create csv files without uploading them to the cloud. 

## s3bucket

In order to use the front end portion of this code you will have to access to AWS and your own S3 bucket. 

## Front-End


