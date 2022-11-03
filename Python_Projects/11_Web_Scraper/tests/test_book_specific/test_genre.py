from src.book_specific.genre import Genre
from tests.test_book_specific.test_book_specific import TestBookSpecific


class TestGenre(TestBookSpecific):
    def test_get_book_genre(self):
        page = self.get_first_page()
        experiment = Genre(page).get_book_genre()
        model = self.get_book_json_data()["Genre"]
        message = "Genre is not the same."
        self.assertEqual(experiment, model, message)
