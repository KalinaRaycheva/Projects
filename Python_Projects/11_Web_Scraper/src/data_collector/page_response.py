import grequests
from src.data_collector.book_urls import BookUrls


class PageResp:
    def __init__(self, books_count):
        self.books_count = books_count

    def get_page_resp(self):
        book_urls = BookUrls(self.books_count).get_book_urls('http://books.toscrape.com/')
        resp_ = (grequests.get(u) for u in book_urls)
        page_responses = grequests.map(resp_)
        return page_responses
