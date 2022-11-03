class Sort(object):
    def __init__(self, content, sort_arguments):
        self.content = content
        self.sort_arguments = sort_arguments
        self.criteria = self.sort_arguments[0]
        self.direction = self.sort_arguments[1]
 
    def sorted_data(self):
        if self.direction == 'Descending':
            return sorted(self.content, key=lambda x: x[self.criteria], reverse=True)
        else:
            return sorted(self.content, key=lambda x: x[self.criteria], reverse=False)
