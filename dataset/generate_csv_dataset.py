import argparse
import random

DEFAULT_DESCRIPTION = 'CSV dataset generator script demo.'
DEFAULT_SAMPLES = 100
DATA_SIZES = [100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000]
DATA_SETS = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10']


def parse_args():
    """
    Парсинг аргументов командной строки (CLI).
    :return интерфейс для работы с аргументами.

    Больше информации на https://docs.python.org/3.7/howto/argparse.html
    """
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


def generate_two_nodes(num_of_nodes):
    node1 = random.randint(1, num_of_nodes-1)
    node2 = random.randint(node1+1, num_of_nodes)
    return node1, node2


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

