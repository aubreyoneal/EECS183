# Author: Aubrey O'Neal
# Uniqname: aubreyo
# Date: 02/10/14
# Purpose: Learn to use python
# Description: Sort data by population size in upcoming years


import sys
import math

def processInputLine(data, line):
    newList = [ 1, 2, 3, 4]
    list = []
    list = line.split(',')
    for i in range( 1, 4):
        newList[i] = float(list[i])
    finalList = [list[0], newList[1], newList[2], newList[3]]
    data.append(finalList)
    return data
    """ Converts a line of input to a list and appends it to the data.

    Parameters: data: A list of lists; each row of the list represents
                one country
                line: one new line of input from the file
    Requires: line has 4 pieces of information separated by commas
              (name of country, area, current population, population growth)
    Modifies: data
    Effects: A new row is added to data; the row must itself be a list of
             four elements.  The line must be split apart into elements
             (they are currently separated by commas).  The name of the
             country is added as a string; the other three values (area,
             current population, growth rate) are converted to float
             before being added.

             NOTE: If the line is blank (which should not happen, even at
			 the end of the file), take no action.  If the first character
			 of the line is #, it is a comment and should not be added to
			 data.
    """


def processInputFile(filename):
    lst = []
    new = []
    try:
        with open(filename, 'r') as inputFile:
            for line in inputFile:
                if line.startswith('#'):
                    pass
                else:
                    lst = processInputLine(lst, line)
    except IOError:
        print 'File failed to open'
        return lst
    return lst
    
    """ Open input file, processing every line to produce a list of lists.

    Parameters: filename: The name of a file to load from disk.
    Requires: Nothing
    Modifies: Nothing
    Effects: Starts with an empty list, opens the input file, and then
             for each line of the file it calls processInputLine().
             When the function ends, it returns the list of lists that
             has been built.

             If the file cannot be opened, display an error message
             and return an empty list.
    Text: 'File failed to open'
    """


def advanceYears(data, years):
    rows = len(data)
    for i in range(0, rows): 
        #futurePop = data[i][2]
        '''
        for i in range(0, years):
            futurePop += (((data[i][3] / 100) + 1) * data[i][2])
            '''
        futurePop = float((((data[i][3] / 100) + 1)**years) * data[i][2])
        data[i].insert(4, futurePop)
    for i in range(0,rows):
        futureDens = float(data[i][4] / data[i][1])
        data[i].insert(5, futureDens)
    print data
    return data
    """ Predicts each country's population and density in the future.

    Parameters: data: A list of lists; each row of the list represents
                one country
                years: the number of years to predict population growth
    Requires: years > 0; population data loaded
    Modifies: data
    Effects: For each row, append two new floating-point numbers to it:
               the new population after the years have passed
               the future population density (new population / area)
    """


def sortByDensity(data):
    data.sort(key = lambda x: x[-1], reverse = True)
    return data
    """ Sorts the data list of lists by density, highest to lowest.

    Parameters: data: A list of lists; each row of the list represents
                one country
    Requires: Population data loaded and advanced in years
    Modifies: data
    Effects: Sort data by population density (column 5), from highest
             to lowest
    """


def displayHeader():
    header = ['Country/Principality', 'Population', 'Density']
    print '{0:35s}{1:>15s}{2:>15s}'.format(*header)
    
    """ Displays the header line for the table.

    Parameters: None
    Requires: Nothing
    Modifies: Nothing
    Effects: Display a header line: width 35 for the country name (left
             justified), 15 each for the population and density (both
             right justified).
    Text: 'Country/Principality', 'Population', 'Density'
    """


def histogramLine(name, dens):
    report = name + ':'
    print '{0:35}'.format(report),
    density = range(0, int(round(dens/1000)))
    for count in density:
        
        print '*',
        sys.stdout.softspace = 0
    print
    """ Creates a histogram line for a given country and population density.

    Parameters: name: The name of the country
                dens: The population density of the country
    Requires: dens >= 0; population data loaded and advanced in years
    Modifies: Nothing
    Effects: Creates and returns a line of text, containing a country name
             (right justified, width 35), then ': ', finally a number of
             asterisks equal to the population density / 1000, ROUNDED.
    """


def makeHistogram(data):
    rows = len(data)
    if rows <= 9:
        top = range(0,rows)
    else:
        top = range(0,9)
    for i in top:
        histogramLine(data[i][0], data[i][5])
        
    """ Creates the histogram for the top 10 most population-dense countries.

    Parameters: data: A list of lists; each row of the list represents
                one country
    Requires: Population data loaded, advanced in years, and sorted
              by density
    Modifies: Nothing
    Effects: Take the 10 most populous countries in the table, create a
             histogram line for each one, and display it.
    Text: 'Top countries by density:'
    """


def displayTable(data):
    displayHeader()
    print
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
    print
    print 'Total population', totalPop
    """ Creates most of the output for the program in a formatted table.

    Parameters: data: A list of lists; each row of the list represents
                one country
    Requires: Population data loaded and advanced in years
    Modifies: Nothing
    Effects: Displays the population table, nicely formatted.  It should
             consist of a header line as described in displayHeader(),
             a line of dashes (length 65), the table with the country name
             (left justified, width 35), future population (right justified,
             width 15, with commas), and future density (same as population).
             After the table, draw another line of dashes, followed by the
             total world population at that future year.

             NOTE: the population should be truncated to an integer (don't
             round .5 people up into a whole one), but the density should
             be rounded to the nearest integer.
    Text: 'Total population'
    """


def main(argv):
    
    filename = raw_input('Enter filename to open: ')
    data = processInputFile(filename)
    if len(data) == 0:
        return
    years = raw_input('Enter number of years for population to grow: ')
    while years <= 0:
        print
        print 'Number of years must be > 0'
        print
        years = raw_input('Enter number of years for population to grow: ')
    future = advanceYears(data, years)
    print sortByDensity(future)
    makeHistogram(future)
    print
    displayTable(future)
    '''

    filename = 'pop-small.csv'
    data = processInputFile(filename)
    future = advanceYears(data, 10)
    print sortByDensity(future)
    makeHistogram(future)
    print
    displayTable(future)
    '''
    
    """ put your code for the main program below this line

    When you get the filename, just pass it to processInputFile().
    If that file returns a list of length 0, do nothing.

    When you ask for the number of years, if it is not > 0, display
    an error message, prompt them again, etc. until they enter a
    correct number of years.

    Prompts: 'Enter filename to open: '
             'Enter number of years for population to grow: '
             'Number of years must be > 0'
    """


# DO NOT alter these 2 lines
# NO ADDITIONAL CODE goes below these 2 lines
if __name__ == "__main__":
    main(sys.argv)
