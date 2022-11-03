import os
import json

from src.user_choice.user_books import UserBooks


received_content = UserBooks().get_contents()

cwd = os.getcwd()
path = os.path.join(cwd, "output")

try:
    os.mkdir(path)
except OSError:
    path = "output/"

with open(os.path.join(path, "Book library"), "w") as collection:
    collection.write(
        json.dumps(received_content, collection, indent=2, encoding="utf-8")
        )
print("JSON created successfully!")
print("Collection JSON saved in output/Book library.txt")