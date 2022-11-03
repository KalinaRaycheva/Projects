from src.book_specific.availability import Availability
from src.book_specific.description import Description
from src.book_specific.price import Price
from src.book_specific.rating import Rating
from src.book_specific.review import Review
from src.book_specific.title import Title
from src.book_specific.genre import Genre


class Book(Title, Availability, Rating, Price, Description):
    def __init__(self, page_content):
        Title, Availability, Rating, Price, Description.__init__(self, page_content)
        self.book = {}
 
    def get_book_data(self):
        self.book['Review'] = Review(self.page_content).get_reeview()
        self.book['Title'] = Title(self.page_content).get_book_title()
        self.book['Rating'] = Rating(self.page_content).get_book_rating()
        self.book['Genre'] = Genre(self.page_content).get_book_genre()
        self.book['Price'] = Price(self.page_content).get_book_price()
        self.book['Description'] = Description(self.page_content).get_book_description()
        self.book['Availability'] = Availability(self.page_content).get_book_availability()
        return self.book
