import json
from bs4 import BeautifulSoup
from src.book_specific.book import Book
from src.data_collector.page_response import PageResp
from src.user_choice.filtering import Filter
from src.user_choice.searching import Search
from src.user_choice.sorting import Sort


class UserBooks:
    def __init__(self, user_data):
        self.user_data = user_data
        self.content = []

    def set_user_wanted_books(self):
        all_responses = PageResp(self.user_data['book_count']).get_page_resp()
        for response in all_responses:
            page_content = BeautifulSoup(response.content, 'lxml')
            book_content = Book(page_content)
            self.content.append(book_content.get_book_data())

    def set_user_criteria(self):
        if self.user_data['sort_type'] is not None:
            self.content = Sort(self.content, self.user_data['sort_type']).sorted_data()
        if self.user_data['filters'] is not None:
            self.content = Filter(self.content, self.user_data['filters']).filter_data()
        if self.user_data['title'] is not None:
            self.content = Search(self.content).title_searching(self.user_data['title'])
        if self.user_data['genre'] is not None:
            self.content = Search(self.content).genre_searching(self.user_data['genre'])

    def set_json_user_data(self, json_user_data='src/user_choice/user_data.json'):
        with open(json_user_data, 'w') as file:
            json.dump(self.content, file, indent=4)

    def get_user_library(self):
        self.set_user_wanted_books()
        self.set_user_criteria()
        self.set_json_user_data()
        return self.content
