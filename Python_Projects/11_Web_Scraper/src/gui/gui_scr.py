from Tkinter import *
import Tkinter as tk
from PIL import ImageTk, Image
from src.args_parser.args_types import GENRES
from src.gui.gui_result import ResultDesigner
from src.user_choice.user_books import UserBooks


class App:
    def __init__(self, root):
        self.root = root
        self.gui_data = {}
        self.sort_data = None
        self.filter_data = None
        self.books_count = None

        root.title("Web Scraper Team 6")
        root.geometry("1000x600")

        self.canvas1 = Canvas(root, width=1000, height=500)
        self.canvas1.grid(columnspan=4, rowspan=8)

# Logo:

        self.logo = Image.open('src/gui/book.png')
        self.logo = ImageTk.PhotoImage(self.logo)
        self.logo_label = tk.Label(image=self.logo)
        self.logo_label.image = self.logo
        self.logo_label.grid(columnspan=4, row=0)

# Welcome:

        self.instructions = tk.Label(root, text="Welcome to webscraper \nPlease enter your selection", font="Corbel")
        self.instructions.grid(columnspan=4, row=1)

# NumberBooks:

        self.instructions_num = tk.Label(root, text="Enter number of books to scrape")
        self.instructions_num.grid(column=0, row=2)
        self.num_of_books = Entry(root, width=5)
        self.num_of_books.grid(column=1, row=2)

# Genres:

        self.options = GENRES

        self.clicked = StringVar()
        self.clicked.set("Choose Genre")

        self.drop = OptionMenu(root, self.clicked, *self.options)
        self.drop.grid(column=2, row=2)


# Sort:

        self.instructions_sort = tk.Label(root, text="Sort Options")
        self.instructions_sort.grid(column=0, row=3)

        self.list_sort_options1 = ['Price', 'Availability', 'Rating']
        self.sort_clicked_option1 = StringVar()
        self.clicked.set("Choose Sort Parameter")

        self.drop = OptionMenu(root, self.sort_clicked_option1, *self.list_sort_options1)
        self.drop.grid(column=1, row=3)
        self.list_sort_options2 = ['ascending', 'descending']

        self.sort_clicked_option2 = StringVar()
        self.clicked.set("Choose Sort Order")

        self.drop = OptionMenu(root, self.sort_clicked_option2, *self.list_sort_options2)
        self.drop.grid(column=2, row=3)


# Filter:

        self.instructions_filter = tk.Label(root, text="Filter Options")
        self.instructions_filter.grid(column=0, row=4)

        self.list_filter_options1 = ['Price', 'Availability', 'Rating']

        self.filter_clicked_option1 = StringVar()
        self.clicked.set("Choose Filter Parameter")

        self.drop = OptionMenu(root, self.filter_clicked_option1, *self.list_filter_options1)
        self.drop.grid(column=1, row=4)

        self.list_filter_options2 = ['<', '>', '==']

        self.filter_clicked_option2 = StringVar()
        self.clicked.set("Choose Filter Parameter")

        self.drop = OptionMenu(root, self.filter_clicked_option2, *self.list_filter_options2)
        self.drop.grid(column=2, row=4)

        self.filter_value = Entry(root, width=4)
        self.filter_value.grid(column=3, row=4)

# SubmitQuit:

        self.browse_text = tk.StringVar()
        self.browse_btn = tk.Button(root,
                                    textvariable=self.browse_text,
                                    font="Corbel",
                                    height=1,
                                    width=15,
                                    command=self.submit_button)
        self.browse_text.set("Submit")
        self.browse_btn.grid(column=1, row=8)

        self.browse_text = tk.StringVar()
        self.browse_btn = tk.Button(
            root,
            textvariable=self.browse_text,
            font="Corbel",
            height=1,
            width=15,
            command=root.destroy)
        self.browse_text.set("Quit")
        self.browse_btn.grid(column=2, row=8)

    def set_user_gui_args(self):
        if self.sort_clicked_option1.get() is not '':
            self.sort_data = [self.sort_clicked_option1.get(), self.sort_clicked_option2.get()]
        if self.filter_clicked_option1.get() is not '':
            self.filter_data = [self.filter_clicked_option1.get(),
                                self.filter_clicked_option2.get(),
                                self.filter_value.get()]
        if self.num_of_books.get() is not '':
            self.books_count = int(self.num_of_books.get())

    def get_user_gui_args(self):
        self.set_user_gui_args()
        self.gui_data = {
            'book_count': self.books_count,
            'sort_type': self.sort_data,
            'filters': self.filter_data,
            'title': None,
            'genre': None,
        }
        return self.gui_data

    def submit_button(self):
        gui_data = self.get_user_gui_args()
        result_root = tk.Tk()
        ResultDesigner(result_root, UserBooks(gui_data).get_user_library())

