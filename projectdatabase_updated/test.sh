#!/bin/bash

db="cse120.sqlite"
rm -f ${db}
touch ${db}

sqlite3 ${db} < script.sql
