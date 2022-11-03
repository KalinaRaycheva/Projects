import unittest
from src.book_specific.title import Title
from tests.test_book_specific.test_book_specific import TestBookSpecific


class TestTitle(TestBookSpecific):
    def get_book_title(self):
        page = self.get_first_page()
        experiment = Title(page).get_book_title()
        model = self.get_book_json_data()["Title"]
        message = "Title is not the same."
        self.assertEqual(experiment, model, message)
