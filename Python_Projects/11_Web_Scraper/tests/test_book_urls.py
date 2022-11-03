import unittest

from src.data_collector.book_urls import BookUrls


class BookUrlsTest(unittest.TestCase):
    def setUp(self):
        self.books_count = 1000
        self.book_urls_test = BookUrls(self.books_count)
        self.url = 'https://books.toscrape.com/'
        self.url_book = 'https://books.toscrape.com/catalogue/tipping-the-velvet_999/index.html'
        self.url_book_wrong = 'https://books.toscape.com/catalogue/tipping-the-velvet_999/index.html'
        self.num_books_expected = 1000

    def test_init(self):
        self.assertIsInstance(self.book_urls_test, BookUrls)

    def test_get_book_urls_type(self):
        self.assertEqual(list, type(self.book_urls_test.get_book_urls(self.url)))

    def test_get_correct_urls(self):
        self.assertIn(self.url_book, (self.book_urls_test.get_book_urls(self.url)))

    def test_wrong_url(self):
        self.assertNotIn(self.url_book_wrong, (self.book_urls_test.get_book_urls(self.url)))

    def test_url_number(self):
        self.assertEqual(self.num_books_expected, len(self.book_urls_test.get_book_urls(self.url)))


if __name__ == '__main__':
    unittest.main()
