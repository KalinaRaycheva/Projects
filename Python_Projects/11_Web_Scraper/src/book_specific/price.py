class Price:
    def __init__(self, page_content):
        self.page_content = page_content

    def get_book_price(self):
        try:
            book_price = float(self.page_content.find('p', class_='price_color').getText()[2:])
            return book_price
        except AttributeError:
            book_price = "No price available."
            return book_price
