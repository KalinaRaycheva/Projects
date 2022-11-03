from src.book_specific.description import Description
from tests.test_book_specific.test_book_specific import TestBookSpecific


class TestRating(TestBookSpecific):
    def test_get_book_description(self):
        page = self.get_first_page()
        experiment = Description(page).get_book_description()
        model = self.get_book_json_data()["Description"]
        message = "Title is not the same."
        self.assertEqual(experiment, model, message)
