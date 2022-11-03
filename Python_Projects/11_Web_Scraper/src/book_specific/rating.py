import re

rating_converter = {
    'One': 1,
    'Two': 2,
    'Three': 3,
    'Four': 4,
    'Five': 5
}


class Rating:
    def __init__(self, page_content):
        self.page_content = page_content

    def get_book_rating(self):
        try:
            book_rating_link = str(self.page_content.find('p', class_='star-rating').get)
            book_rating = re.findall(r"(?<=\bstar-rating\s)(\w+)", book_rating_link)[0]
            return rating_converter[book_rating]
        except AttributeError:
            book_rating = "No rating available."
            return book_rating
