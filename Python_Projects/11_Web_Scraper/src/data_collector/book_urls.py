import grequests
from bs4 import BeautifulSoup
from src.data_collector.page_urls import PageUrls


class BookUrls:
    def __init__(self, books_count):
        self.books_count = books_count
        self.__books_urls = []

    def get_book_urls(self, url):
        pages_links = PageUrls().get_page_urls(url)

        handled_books = 0
        for link in pages_links:
            reqs = [grequests.get(link) for link in pages_links]
            resp = grequests.map(reqs)
            for r in resp:
                soup = BeautifulSoup(r.text, 'lxml')
                tags_ = soup.findAll('li', class_='col-xs-6 col-sm-4 col-md-3 col-lg-3')
                link_constructor = 'https://books.toscrape.com/catalogue/{}'
                for tag in tags_:
                    self.__books_urls.append(link_constructor.format(tag.find('a').get('href')))
                    handled_books += 1
                    if handled_books == self.books_count:
                        return self.__books_urls

        return self.__books_urls
