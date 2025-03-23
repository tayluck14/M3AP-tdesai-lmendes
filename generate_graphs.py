import matplotlib.pyplot as mpl

fighters = []
reads = []
allocations = []

with open('../data/BubbleData.txt') as bubble_file:
    next(bubble_file) #Skip the first line
    for line in bubble_file:
        # Split input by commas and convert to ints
        f, r, a = map(int, line.split(','))
        fighters.append(f)
        reads.append(r)
        allocations.append(a)

# Plot
mpl.plot(fighters, reads, label='Reads', marker='o', color='green')
mpl.plot(fighters, allocations, label='Allocations', marker='x', color='orange')

# Add axis labels
mpl.xlabel('Number of Fighters')
mpl.ylabel('Allocations')
mpl.title('Bubble Sort Data: Reads and Allocations')

# Add legend
mpl.legend()

# Show plot
mpl.show()
