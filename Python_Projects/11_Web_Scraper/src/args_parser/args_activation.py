import json


class ArgsActivation:

    def __init__(self, parsed_args):
        self.parsed_args = parsed_args

    def get_user_sort(self):
        if self.parsed_args.sort_type is None:
            return None
        else:
            args = []
            for arg in self.parsed_args.sort_type:
                args.append(''.join(arg).capitalize())
            if len(args) < 2:
                args.append(' ')
            return args

    def get_user_filtering(self):
        if self.parsed_args.filters is None:
            return None
        else:
            args = []
            for arg in self.parsed_args.filters:
                args.append(''.join(arg))
            result_with_space = ''.join(args)
            result_without_space = result_with_space.split(" ")
            return result_without_space

    def get_user_genre(self):
        return self.parsed_args.genre

    def get_user_keywords(self):
        return self.parsed_args.keywords

    def get_user_title(self):
        return self.parsed_args.title

    def get_file(self):
        with open(self.parsed_args.file_name, 'r') as f:
            data = json.load(f)
            return data

    def get_user_gui_status(self):
        return self.parsed_args.gui
