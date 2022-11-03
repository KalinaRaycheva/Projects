import unittest
from src.args_parser.genre_names import GenreHandler


class GenreHandlerTest(unittest.TestCase):
    def setUp(self):
        self.genre_names_test = GenreHandler()
        self.url = 'https://books.toscrape.com/'
        self.genre_correct = 'Classics'
        self.genre_incorrect = 'Classic'
        self.genre_link_correct = 'https://books.toscrape.com/catalogue/category/books/fantasy_19/index.html'
        self.genre_link_incorrect = 'https://books.toscape.com/catalogue/category/books/fantasy_19/index.html'

    def test_init(self):
        self.assertIsInstance(self.genre_names_test, GenreHandler)

    def test_get_genres_list_type(self):
        self.assertEqual(list, type(self.genre_names_test.get_genres_list(self.url)))

    def test_get_genre_list_correct(self):
        self.assertIn(self.genre_correct, self.genre_names_test.get_genres_list(self.url))

    def test_get_genre_list_incorrect(self):
        self.assertNotIn(self.genre_incorrect, self.genre_names_test.get_genres_list(self.url))

    def test_get_genres_links(self):
        self.assertEqual(list, type(self.genre_names_test.get_genres_links(self.url)))

    def test_get_genres_links_correct(self):
        self.assertIn(self.genre_link_correct, self.genre_names_test.get_genres_links(self.url))

    def test_get_genres_links_incorrect(self):
        self.assertNotIn(self.genre_link_incorrect, self.genre_names_test.get_genres_links(self.url))


if __name__ == '__main__':
    unittest.main()
