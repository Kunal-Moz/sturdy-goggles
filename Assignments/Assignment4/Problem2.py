#!/usr/bin/env python

from StudentRecord import *
import sys

print("okay it works")
def main():
    if len(sys.argv) < 2:
        print ('Usage: ', sys.argv[0], ' records.txt')
        return

    # Make a list of class names and list of records
    # Careful with the "pass by object reference" storage mode of python!
    labels = ['Total', 'Physics', 'Literature', 'History']
    inputvals = [ [],[],[],[] ]

    # Hold the actual records in a single dictionary
    records = dict( zip( labels, inputvals) )
    print(records)
    # Open the file, get the lines, loop through them.
    # Loop through lines
    for line in open( sys.argv[1] ).readlines():
        # Get the data, comma-separated (in python, the last one without the comma is also appended)
        data = line.rstrip().split(',')
        # The 0th element of data contains the name of the course, i.e. "Physics", "Literature", etc.
        # Append to that list, and the total.
        # You can use the "eval" method to get the right class based on the string data[0]! Neat, right!?!
        print(data)
        s = eval('StudentRecord' + data[0])(data[1:])
        records['Total'].append(s)
        records[data[0]].append(s)
        #records[data[1]] = StudentRecord.__str__
        

        
        
    ### your code goes here
    print("This should be the output")
    for record in records :
        #print(record)
        print( records[record])

    
    
    
if __name__ == "__main__":
    main()
