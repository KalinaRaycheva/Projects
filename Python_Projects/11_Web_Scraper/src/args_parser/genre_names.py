import requests
from bs4 import BeautifulSoup


class GenreHandler:

    def __init__(self):
        self.genres = []
        self.genre_links = []

    def get_genres_list(self, url):
        html_text = requests.get(url).text
        soup = BeautifulSoup(html_text, 'lxml')
        selection = soup.find('div', class_='side_categories').get_text(",", strip=True)
        self.genres = selection.split(',')[1:]
        return self.genres

    def get_genres_links(self, url):
        html_text = requests.get(url).text
        soup = BeautifulSoup(html_text, 'lxml')
        selection = soup.find( 'div', "side_categories").get_text(",", strip=True).split(',')[1:]
        linx = soup.find('div', "side_categories").find_all('a', href=True)[1:]
        link_constructor = 'https://books.toscrape.com/{}'
        for index in range(0, len(linx)):
            self.genre_links.append(link_constructor.format(linx[index]['href']))
        return self.genre_links


# genres = GenreHandler().get_genres_list('http://books.toscrape.com/')
#
# # print(genres)
#
# links = GenreHandler().get_genres_links('http://books.toscrape.com/')



# print(links)

# genres_dict = dict(zip(genres, links))
# print(genres_dict)







