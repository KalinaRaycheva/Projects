import Tkinter as tk
from Tkinter import *
 
from src.user_choice.searching import Search
 
 
class ResultDesigner:
    def __init__(self, root, content):
        root.title("Search Results")
        self.content = content
        self.width = 900
        self.height = 700
        self.screenwidth = root.winfo_screenwidth()
        self.screenheight = root.winfo_screenheight()
        self.alignstr = '%dx%d+%d+%d' % (self.width, self.height, (self.screenwidth - self.width) / 2, (self.screenheight - self.height) / 2)
        root.geometry(self.alignstr)
        root.resizable(width=False, height=False)
 
        self.canvas2 = Canvas(root, width=900, height=700)
        self.canvas2.grid(columnspan=8, rowspan=8)
 
        self.label = tk.Label(root)
        self.font = "Corbel"
        self.label["font"] = self.font
        self.label["fg"] = "#333333"
        self.label["justify"] = "center"
        self.label["text"] = "Your search results are:"
        self.label.place(x=260, y=30, width=346, height=30)
 
        self.list_box = tk.Listbox(root)
        self.list_box["borderwidth"] = "1px"
        self.font = "Corbel"
        self.list_box["font"] = self.font
        self.list_box["fg"] = "#333333"
        self.list_box.place(x=130, y=70, width=638, height=428)
        self.convert_content()
 
        self.search_again_button = tk.Button(root)
        self.search_again_button["bg"] = "#f0f0f0"
        self.font = "Corbel"
        self.search_again_button["font"] = self.font
 
        self.quit_button = tk.Button(root)
        self.quit_button["bg"] = "#f0f0f0"
        self.font = "Corbel"
        self.quit_button["font"] = self.font
        self.quit_button["fg"] = "#000000"
        self.quit_button["justify"] = "center"
        self.quit_button["text"] = "Close"
        self.quit_button.place(x=550, y=600, width=200, height=40)
        self.quit_button["command"] = root.destroy
 
        # Words:
 
        self.instructions_words = tk.Label(root, text="Enter Search In Descr")
        self.instructions_words.place(x=137, y=510)
 
        self.words_field = Entry(root, width=50)
        self.words_field.place(x=300, y=507)
 
        # word_options = ['exclude', 'include']
 
        # clicked = StringVar()
        # clicked.set("Exclude / Include Words")
        #
        # drop = OptionMenu(root, clicked, *word_options)
        # drop.grid(column=2, row=5)
 
        # Title:
 
        self.instructions_title = tk.Label(root, text="Enter Search Title")
        self.instructions_title.place(x=150, y=550)
 
        self.title_field = Entry(root, width=50)
        self.title_field.place(x=300, y=547)
 
        # instructions_file = tk.Label(root, text="Search a List of Titles from File")
        # instructions_file.grid(column=0, row=7)
 
        # File:
 
        #self.browse_button = tk.Button(root)
        #self.browse_button["bg"] = "#f0f0f0"
        #self.browse_button["font"] = self.font
        #self.browse_button["fg"] = "#000000"
        #self.browse_button["justify"] = "center"
        #self.browse_button["text"] = "Browse"
        #self.browse_button.place(x=70, y=600, width=200, height=40)
 
        self.search_button = tk.Button(root)
        self.search_button["bg"] = "#f0f0f0"
        self.search_button["font"] = self.font
        self.search_button["fg"] = "#000000"
        self.search_button["justify"] = "center"
        self.search_button["text"] = "Search"
        self.search_button.place(x=150, y=600, width=200, height=40)
        self.search_button["command"] = self.search_button_command
 
    def search_button_command(self):
        self.content = Search(self.content).title_searching(self.title_field.get())
        self.convert_content()
 
    def convert_content(self):
        self.list_box.delete(0, END)
        for el in self.content:
            self.list_box.insert(END, el['Title'])
 
