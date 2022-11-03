import argparse
from src.args_parser import genre_names
from src.args_parser.args_activation import ArgsActivation

GENRES = genre_names.GenreHandler().get_genres_list('http://books.toscrape.com/')
 
 
class ArgsTypes(object):
    def __init__(self):
        self.parser = argparse.ArgumentParser(description="BOOKS SCRAPER")
        self.args_data = {}

    def set_user_console_args(self):
        self.parser.add_argument("-b", type=int, default=1000, dest="books_count",
                                 help="number of books")
        self.parser.add_argument("-s", type=list, dest='sort_type', nargs='+',
                                 help='list of sortings (for the output, ascending or descending)')
        self.parser.add_argument("-f", type=list, dest='filters', nargs='+',
                                 help='list of priority filters for which books to exclude from the scrape')
        self.parser.add_argument("-g", type=str, dest='genre', choices=GENRES,
                                 help='list of genres to search through')
        self.parser.add_argument("-t", type=str, default=None, dest='title', help='title of a book to search for')
        self.parser.add_argument("-d", type=str, dest='keywords', nargs='+',
                                 help='list of keywords to be searched from the description')
        self.parser.add_argument("-F", '--books', type=str, dest='file_name',
                                 help='list of book titles to search for (from given json)')
        self.parser.add_argument("-X", dest='gui', help='start graphic interface', action='store_true')

    def get_user_console_args(self):
        args = self.parser.parse_args()
        activation = ArgsActivation(args)
        self.args_data['book_count'] = args.books_count
        self.args_data['sort_type'] = activation.get_user_sort()
        self.args_data['filters'] = activation.get_user_filtering()
        self.args_data['gui'] = activation.get_user_gui_status()
        self.args_data['title'] = activation.get_user_title()
        self.args_data['genre'] = activation.get_user_genre()
        return self.args_data
