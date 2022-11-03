import re


class Genre:
    def __init__(self, page_content):
        self.page_content = page_content

    def get_book_genre(self):
        try:
            paragraph = self.page_content.find('ul', class_='breadcrumb')
            book_linx = paragraph.findAll('a')
            book_genre_link = book_linx[2]
            book_genre_string = str(book_genre_link)
            book_genre = re.findall(r"\>([^$]*)\<", book_genre_string)[0]
        except AttributeError:
            book_genre = "No genre available."
        return book_genre
