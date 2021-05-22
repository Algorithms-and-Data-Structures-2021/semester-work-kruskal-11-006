import csv
import random


import csv  #csv
import random #random


def csv_writer(k, path):
    """
    Write data to a CSV file path
    """
    with open(path, "w", newline='') as csv_file:
        csv_file.truncate()
        for line in range(k):
            node1, node2 = generate_two_nodes(k)
            weight = random.randint(1, 20)
            csv_file.write(f'{node1} {node2} {weight}\n')


def generate_two_nodes(num_of_nodes):
    node1 = random.randint(1, num_of_nodes-1)
    node2 = random.randint(node1+1, num_of_nodes)
    return node1, node2


if __name__ == "__main__":
    amount = [100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000]
    for i in range(10):
        for j in range(10):
            if (i + 1) < 10:
                path = "data" + "/algorithm" + "/" + "0" + str(i + 1) + "/" + str(amount[j]) + ".csv"
            else:
                path = "data" + "/algorithm" + "/" + str(i + 1) + "/" + str(amount[j]) + ".csv"
            csv_writer(amount[j], path)
