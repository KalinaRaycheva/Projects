import requests
from bs4 import BeautifulSoup


class PageUrls:

    def __init__(self):
        self.__pages = []

    def get_page_urls(self, url):
        html_text = requests.get(url).text
        soup = BeautifulSoup(html_text, 'lxml')
        total_pages = soup.find('li', class_='current').text.replace(' ', '')
        pages = int(str(total_pages).split("f")[-1])
        source = "https://books.toscrape.com/catalogue/page-{}.html"
        for page in range(1, pages + 1):
            self.__pages.append(source.format(page))
        return self.__pages
