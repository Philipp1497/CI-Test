
def read_segments(flag):
    with open('segments.txt') as file:
        lines = file.readlines()
        lines = [line.strip() for line in lines] # jede zeile trennen
        if flag == 0:
            lines.remove('ROM:')
            lines.remove('RAM:')
        return lines



def find_in_mapfile(segments):
    index = 0
    flag = 0
    file = open('mapfiles/*.map', 'r')
    for line in file:
            index += 1
            if segments in line:
                flag = 1
                break
    if flag == 1:
        return line

def generate_outputfile():
    file = open('output/output.txt', 'a')
    file.write('Resource Tool by Philipp Pawlischinez' + '\n' +
               '##############################################################################'
               + '\n' + find_in_mapfile('used') + '\n')



def copy_into_output(line):
    file = open('output/output.txt', 'a')
    file.write(line)

def generate_results():
    rom = 0
    ram = 0
    file = open('output/output.txt', 'a')
    file.write('\n' + '#############################################################################' +
               '\n' + 'Calculated Resources used:' + '\n')
    list = read_segments(1)
    length = len(list)
    ram_index = list.index('RAM:')
    i = 1
    while i < ram_index:
        line = find_in_mapfile(list[i])
        line = line.split()
        conversion = int(line[3], base=16)
        rom = rom + conversion
        i += 1
    while i < length - 1:
        i += 1
        line = find_in_mapfile(list[i])
        line = line.split()
        conversion = int(line[3], base=16)
        ram = ram + conversion
    file.write('ROM used: '+ str(rom) + ' Bytes' + '\n')
    file.write('RAM used: '+ str(ram) + ' Bytes')


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    generate_outputfile()
    value = read_segments(0)
    for i in value:
        line = find_in_mapfile(i)
        copy_into_output(line)         #generate Output file with segments and
    generate_results()
