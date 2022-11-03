# import unittest
# from src.args_parser.args_activation import ArgsActivation
# from src.args_parser.args_validation import ArgsValidation
# from src.args_parser.args_types import ArgsTypes
#
#
# class ArgsActivationTest(unittest.TestCase):
#     def setUp(self):
#         self.args_activation = ArgsActivation() #parsed_args not found
#         self.args_type = '-s "price ascending"'
#         self.args_validation = ArgsValidation()

    # def test_init(self):
    #     self.assertIsInstance(self.args_activation, ArgsActivation)
    #
    # def test_get_books_count(self):
    #     default_books_count = 1000
    #     self.assertEqual(default_books_count, ArgsActivation.get_books_count(self.args_activation))
    #
    # def test_set_books_count(self):
    #     count_to_set = 5
    #     self.args_activation.set_books_count(count_to_set)
    #     self.assertEqual(count_to_set, self.args_activation.get_books_count())

    # def test_get_user_sort(self):
    #     parsed_args = ['price', 'ascending']
    #     print(self.args_activation.get_user_sort())
    #     self.assertEqual(parsed_args, self.args_activation.get_user_sort())

    # def test_get_user_genre(self):
    #     self.assertEqual(str, self.args_activation.get_user_genre())

#
# if __name__ == '__main__':
#     unittest.main()
