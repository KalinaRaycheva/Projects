# import unittest
# from src.args_parser.args_types import ArgsTypes
#
#
# class ArgsTypesTest(unittest.TestCase):
#     def setUp(self):
#         self.arg_type = ArgsTypes()
#
#     def test_init(self):
#         self.assertIsInstance(self.arg_type, ArgsTypes)
#
#     def test_set_user_args(self):
#         expected ='Namespace(books_count=1000, file_name=None, filters=None, genre=None, gui=False, keywords=None, sort_type=None, title=None)'
#         result = str(self.arg_type.set_user_args())
#         self.assertEqual(expected, result)
#
#
# if __name__ == '__main__':
#     unittest.main()
