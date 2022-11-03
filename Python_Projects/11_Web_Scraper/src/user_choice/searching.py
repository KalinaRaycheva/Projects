from src.args_parser.args_activation import ArgsActivation


class Search(object):
    def __init__(self, content):
        self.content = content

    def title_searching(self, title):
        return filter(lambda book: title in book['Title'], self.content)

    def genre_searching(self, genre):
        return filter(lambda book: genre in book['Genre'], self.content)

    def search_books_from_json(self):
        searched_titles = ArgsActivation().get_file()
        search_result = []
        for title in searched_titles:
            found_books = filter(lambda book: title in book['Title'], self.content)
            if found_books:
                search_result.append(found_books)
        return search_result
