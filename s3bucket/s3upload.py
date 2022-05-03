############

"""
DONT HIT RUN JUST YET

FOLLOW INSTRUCTIONS FIRST

Make sure to have Python3 downloaded first


HERE ARE THE FOLLOWING CREDENTIALS FOR THIS PROJECT:

        USERNAME: ***
        PASSWORD: ****
        ACCESS KEY: ****
        SECRET ACCESS KEY: ****
        CONSOLE LOGIN: ****



1.) DOWNLOAD AWS CLI and BOTO3 in terminal/command prompt enter

    pip3 install awscli

    pip3 install boto3

2.) ADD CREDINTIALS FOR AWS

    ! ENTER THE FOLLOWING IN TERMINAL OR COMMAND PROMPT !
        
        aws configure
    
    ENTER AWS ACCESS KEY ID:

        ****

    ENTER AWS SECRET ACCESS KEY:

        ****

    ENTER DEFAULT REGION NAME:

        us-west-1

    !DONT ENTER NOTHING FOR DEAFAULT OUTPUT FORMAT
    JUST HIT ENTER!

    

    3.) RUN CODE in terminal/command prompt this should upload the file to s3

        python3 s3upload.py

"""

############
import pandas as pd

##NEW
from io import StringIO

import glob
import os
##os.chdir("/Users/ericsolorio/Desktop/s3bucket")
import boto3
from datetime import date


"""
##combining csvs
extension = 'csv'
data = [i for i in glob.glob('*.{}'.format(extension))]

#combine all files in the list
combined_csv = pd.concat([pd.read_csv(f) for f in data ])
#export to csv
combined_csv.to_csv( "combined_csv.csv", index=False, encoding='utf-8-sig')

"""

#python todays date library
#today = date.today()

# Month-day-Year
#d1 = today.strftime("%m-%d-%Y")

#calling s3
s3 = boto3.client('s3')


##UPLOAD SINGLE FILE
#s3.upload_file('FILE IN YOUR LOCAL COMPUTER','NAME OF S3 BUCKET','RENAME THE FILE')
#s3.upload_file('account.csv','optic302',d1)
#s3.upload_file('/Users/ericsolorio/Desktop/CSE120-Team302/s3bucket/account.csv'.csv,'optic302','test2')

##UPLOAD ATTEMPT TWO

hc = pd.read_csv('account.csv')

csv_buf = StringIO()
hc.to_csv(csv_buf, header=True, index=False)
csv_buf.seek(0)
s3.put_object(Bucket='optic302', Body = csv_buf.getvalue(), Key = 'tteesstt.csv')



##DOWNLOAD SINGLE FILE
##s3.download_file('BUCKET_NAME', 'name of file IN S3 BUCKET', 'FILE_NAME')
##s3.download_file('optic302', 'manmeme.jpeg', 'meme.jpeg')
