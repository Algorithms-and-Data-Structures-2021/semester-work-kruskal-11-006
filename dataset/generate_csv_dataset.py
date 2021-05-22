<<<<<<< HEAD
import csv
import random

=======
import argparse
import random

DEFAULT_DESCRIPTION = 'CSV dataset generator script demo.'
DEFAULT_SAMPLES = 100
DATA_SIZES = [100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000]
DATA_SETS = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10']
>>>>>>> bc244b0fa0294846750ec3aca99baa34c9b212c3

import csv  #csv
import random #random


def csv_writer(k, path):
    """
<<<<<<< HEAD
    Write data to a CSV file path
    """
    with open(path, "w", newline='') as csv_file:
        csv_file.truncate()
        for line in range(k):
            node1, node2 = generate_two_nodes(k)
            weight = random.randint(1, 20)
            csv_file.write(f'{node1} {node2} {weight}\n')
=======
    parser = argparse.ArgumentParser(description=DEFAULT_DESCRIPTION)

    # parser.add_argument('--output',
    #                     type=str,
    #                     default='data/output.csv',
    #                     help='output CSV file, e.g. data/output.csv')

    parser.add_argument('samples',
                        type=int,
                        default=DEFAULT_SAMPLES,
                        help='number of samples to generate (default: {})'.format(DEFAULT_SAMPLES))

    return parser.parse_args()
>>>>>>> bc244b0fa0294846750ec3aca99baa34c9b212c3


def generate_two_nodes(num_of_nodes):
    node1 = random.randint(1, num_of_nodes-1)
    node2 = random.randint(node1+1, num_of_nodes)
    return node1, node2


<<<<<<< HEAD
if __name__ == "__main__":
    amount = [100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000]
    size = 50000
    for i in range(10):
        for j in range(10):
            if (i + 1) < 10:
                path = "data" + "/algorithm" + "/" + "0" + str(i + 1) + "/" + str(amount[j]) + ".csv"
            else:
                path = "data" + "/algorithm" + "/" + str(i + 1) + "/" + str(amount[j]) + ".csv"
            csv_writer(size, path)
            size += 50000
=======
if __name__ == '__main__':
    args = parse_args()

    # валидация аргументов
    if args.samples < 0:
        raise ValueError('Number of samples must be greater than 0.')

    num_of_nodes = args.samples/10

    for dataset in DATA_SETS:
        # запись данных в файл
        with open('data/'+dataset+'/'+str(args.samples)+'.csv', 'w') as file:
            for i in range(args.samples):
                node1, node2 = generate_two_nodes(num_of_nodes)
                weight = random.randint(1, 20)
                file.write(f'{node1};{node2};{weight};\n')

>>>>>>> bc244b0fa0294846750ec3aca99baa34c9b212c3
