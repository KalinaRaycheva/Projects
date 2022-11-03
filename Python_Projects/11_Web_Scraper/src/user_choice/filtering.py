class Filter(object):
    def __init__(self, content, filter_arguments):
        self.content = content
        self.filter_arguments = filter_arguments
        self.criteria = self.filter_arguments[0]
        self.sign = self.filter_arguments[1]
        self.quantity = self.filter_arguments[2]

    def filter_data(self):
        data = filter(lambda book:
                      eval("{} {} {}".format(book[self.criteria], self.sign, self.quantity)),
                      self.content)
        return data
