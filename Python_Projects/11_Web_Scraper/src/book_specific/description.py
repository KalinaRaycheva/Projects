import unicodedata


class Description:
    def __init__(self, page_content):
        self.page_content = page_content

    def get_book_description(self):
        try:
            paragraph = self.page_content.find('div', id='product_description')
            book_description = paragraph.findNext('p').text
            book_description = unicodedata.normalize('NFKD', book_description).encode('ascii', 'ignore')
            return book_description
        except AttributeError:
            book_description = "No description available."
            return book_description
