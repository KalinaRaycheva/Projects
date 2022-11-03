import re


class Availability:
    def __init__(self, page_content):
        self.page_content = page_content

    def get_book_availability(self):
        try:
            book_availability_text = self.page_content.find('p', class_='instock availability')
            book_availability = int(''.join(re.findall(r'(\d+)', book_availability_text.getText(strip=True))))
            return book_availability
        except AttributeError:
            book_availability = "No count available."
            return book_availability
