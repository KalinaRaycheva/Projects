from src.book_specific.rating import Rating
from tests.test_book_specific.test_book_specific import TestBookSpecific


class TestRating(TestBookSpecific):
    def test_get_book_rating(self):
        page = self.get_first_page()
        experiment = Rating(page).get_book_rating()
        model = self.get_book_json_data()["Rating"]
        message = "Rating is not the same."
        self.assertEqual(experiment, model, message)
