import matplotlib.pyplot as mpl
import os

fighters = []
reads = []
allocations = []


def clear_lists():
    fighters.clear()
    reads.clear()
    allocations.clear()

def make_graph(data_file):
    # Save the filename for naming
    filename = os.path.basename(data_file)
    filename = filename[:-4:]

    # Open the file inside the with block
    with open(data_file) as file:
        next(file)  # Skip the first line
        for line in file:
            # Split input by commas and convert to ints
            f, r, a = map(int, line.split(','))
            fighters.append(f)
            reads.append(r)
            allocations.append(a)

    #create figure
    mpl.figure()

    # Plot
    mpl.plot(fighters, reads, label='Reads', marker='o', color='green')
    mpl.plot(fighters, allocations, label='Allocations', marker='x', color='orange')

    # Add axis labels
    mpl.xlabel('Number of Fighters')
    mpl.ylabel('Allocations')
    mpl.title(filename + ': Reads and Allocations')

    # Add legend
    mpl.legend()

    # Save plot
    save_path = "..\\images\\" + filename + "Graph.png"
    mpl.savefig(save_path)

# Clear lists before graphing
clear_lists()
make_graph('../data/BubbleData.txt')

clear_lists()
make_graph('../data/HeapData.txt')

clear_lists()
make_graph('../data/MergeData.txt')

clear_lists()
make_graph('../data/QuickData.txt')

# Show graphs
mpl.show()