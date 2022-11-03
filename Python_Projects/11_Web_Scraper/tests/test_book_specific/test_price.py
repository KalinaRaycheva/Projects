from src.book_specific.price import Price
from tests.test_book_specific.test_book_specific import TestBookSpecific


class TestPrice(TestBookSpecific):
    def test_get_book_price(self):
        page = self.get_first_page()
        experiment = Price(page).get_book_price()
        model = self.get_book_json_data()["Price"]
        message = "Price is not the same."
        self.assertEqual(experiment, model, message)
