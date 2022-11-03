import json
import unittest
import urllib2
import requests
from bs4 import BeautifulSoup


class TestBookSpecific(unittest.TestCase):
    @staticmethod
    def get_book_json_data():
        with open('book_specific_example.json', 'r') as file:
            data = json.load(file)
        return data

    def get_first_page(self):
        url = self.get_book_json_data()["URL"]
        data = urllib2.urlopen(url).read()
        page_content = BeautifulSoup(data, 'lxml')
        return page_content

    def test_check_book_resp(self):
        response = requests.get(self.get_book_json_data()["URL"])
        if response.ok:
            return response.text
        else:
            return "Bad Response With Book Url!"
