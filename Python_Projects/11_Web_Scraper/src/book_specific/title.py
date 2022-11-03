class Title:
    def __init__(self, page_content):
        self.page_content = page_content

    def get_book_title(self):
        try:
            book_title = self.page_content.find('h1').text
            return book_title
        except AttributeError:
            book_title = "No title available."
            return book_title
