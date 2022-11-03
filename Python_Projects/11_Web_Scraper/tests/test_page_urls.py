import unittest
from src.data_collector.page_urls import PageUrls


class PageUrlsTest(unittest.TestCase):
    def setUp(self):
        self.page_urls_test = PageUrls()
        self.url = 'https://books.toscrape.com/'
        self.url_page = 'https://books.toscrape.com/catalogue/page-49.html'
        self.url_page_wrong = 'https://books.toscape.com/catalogue/page-50.html'
        self.num_pages_expected = 50

    def test_init(self):
        self.assertIsInstance(self.page_urls_test, PageUrls)

    def test_get_book_urls_type(self):
        self.assertEqual(list, type(self.page_urls_test.get_page_urls(self.url)))

    def test_get_correct_urls(self):
        self.assertIn(self.url_page, (self.page_urls_test.get_page_urls(self.url)))

    def test_wrong_url(self):
        self.assertNotIn(self.url_page_wrong, (self.page_urls_test.get_page_urls(self.url)))

    def test_url_number(self):
        self.assertEqual(self.num_pages_expected, len(self.page_urls_test.get_page_urls(self.url)))


if __name__ == '__main__':
    unittest.main()
