from src.book_specific.availability import Availability
from tests.test_book_specific.test_book_specific import TestBookSpecific


class TestAvailability(TestBookSpecific):
    def test_get_book_availability(self):
        page = self.get_first_page()
        experiment = Availability(page).get_book_availability()
        model = self.get_book_json_data()["Availability"]
        message = "Availability is not the same."
        self.assertEqual(experiment, model, message)
