import pprint
import Tkinter as tk
from src.gui.gui_scr import App
from src.args_parser.args_types import ArgsTypes
from src.user_choice.user_books import UserBooks

if __name__ == '__main__':
    parser = ArgsTypes()
    parser.set_user_console_args()
    parser_data = parser.get_user_console_args()

    if parser_data['gui']:
        root = tk.Tk()
        app = App(root)
        root.mainloop()
    else:
        pprint.pprint(UserBooks(parser_data).get_user_library())
