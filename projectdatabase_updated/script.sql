CREATE TABLE Dashboard (
    AnalogChannelone TEXT,
    AnalogChanneltwo DECIMAL(100,100),
    AnalogChannelthree DECIMAL(100,100),
    AnalogChannelfour DECIMAL(100,100),
    AnalogChannelfive DECIMAL(100,100),
    AnalogChannelsix DECIMAL(100,100),
    AnalogChannelseven DECIMAL(100,100),
    AnalogChanneleight DECIMAL(100,100),
    DiscreteChannelone DECIMAL(100,100),
    DiscreteChanneltwo DECIMAL(100,100),
    AlarmOutone TEXT,
    AlarmOuttwo DECIMAL(100,100),
    AlarmOutthree DECIMAL(100,100),
    AlarmOutfour DECIMAL(100,100)

    

);


.mode csv

.separator ","

.import ./2022-02-23T08-00-00.csv Dashboard




/* These two queries are examples of what we would use in our database
But since right now our first priortity is displaying the database we
don't have to worry a lot about the queries that we have to implement
for right now */

/*
SELECT AnalogChannelone FROM Dashboard
WHERE AlarmOutone = 483398;
*/

/*
SELECT AnalogChannelone FROM Dashboard
WHERE AnalogChanneltwo = -1.85957;
*/

