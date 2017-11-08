# Author: Aubrey O'Neal
# Uniqname: aubreyo
# Date: 02/10/14
# Purpose: Learn to use python
# Description: Sort data by population size in upcoming years


import sys
import math

def processInputLine(data, line):
    if not line.startswith('#'):
        newList = [0, 1, 2, 3]
        row = []
        row = line.split(',')
        if not len(row) < 4: 
            for i in range(1, 4):
                newList[i] = float(row[i])
            finalList = [row[0], newList[1], newList[2], newList[3]]
            data.append(finalList)


def processInputFile(filename):
    lst = []
    new = []
    try:
        with open(filename, 'rU') as inputFile:
            for line in inputFile:
                processInputLine(lst, line)
                    
    except IOError:
        print 'File failed to open'
        return lst
    return lst
    

def advanceYears(data, years):
    rows = len(data)
    for i in range(0, rows): 
        #futurePop = data[i][2]
        '''
        for i in range(0, years):
            futurePop += (((data[i][3] / 100) + 1) * data[i][2])
            '''
        futurePop = float((((data[i][3] / 100) + 1) ** years) * data[i][2])
        data[i].insert(4, futurePop)
    for i in range(0,rows):
        futureDens = float(data[i][4] / data[i][1])
        data[i].insert(5, futureDens)


def sortByDensity(data):
    data.sort(key = lambda x: x[-1], reverse = True)

def displayHeader():
    header = ['Country/Principality', 'Population', 'Density']
    print '{0:35s}{1:>15s}{2:>15s}'.format(*header)


def histogramLine(name, dens):
    report = name + ':'
    stars = ''
    density = range(0, int(round(dens/1000)))
    for count in density:
        stars += '*'
        sys.stdout.softspace = 0
    return '{0:>36} '.format(report) + stars


def makeHistogram(data):
    print 'Top countries by density:'
    rows = len(data)
    if rows <= 10:
        top = range(0,rows)
    else:
        top = range(0,10)
    for i in top:
        print histogramLine(data[i][0], data[i][5])
        

def displayTable(data):
    displayHeader()
    line = range(0,65)
    for count in line:
        print '-',; sys.stdout.softspace = False
    print
    rows = len(data)
    row = range(0,rows)
    totalPop = 0
    for i in row:
        population = int(data[i][4])
        density = int(round(data[i][5]))
        print '{0:35s}{1:>15d}{2:>15d}'.format(data[i][0], population, density)
        totalPop += population
    for count in line:
        print '-',; sys.stdout.softspace = False
    totalString = 'Total population'
    print
    print '{0:35s}{1:>15d}'.format(totalString, totalPop)
    print
    print


def main(argv):
    
    filename = raw_input('Enter filename to open: ')
    data = processInputFile(filename)
    if not len(data) == 0:
        status = 1
        while status == 1:
            years = raw_input('Enter number of years for population to grow: ')
            try:
                years = float(years)
            except ValueError:
            #if not(isinstance(years, int)):
                print 'Number of years must be > 0'
                status = 1
                continue
            if years <= 0:
                years = int(years)
                print 'Number of years must be > 0'
                status = 1
            else:
                years = int(years)
                status = 2
                print
        advanceYears(data, years)
        sortByDensity(data)
        displayTable(data)
        makeHistogram(data)


# DO NOT alter these 2 lines
# NO ADDITIONAL CODE goes below these 2 lines
if __name__ == "__main__":
    main(sys.argv)
