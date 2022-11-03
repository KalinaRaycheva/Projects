import argparse


class ArgsValidation(object):

    @staticmethod
    def valid_sort_type(s_input):
        list_sort_options1 = ['default', 'rating', 'price', 'availability', 'alphabetical']
        list_sort_options2 = ['ascending', 'descending', ' ']
        if s_input[0] not in list_sort_options1:
            msg = "Incorrect sort type. You can sort by: {}".format(list_sort_options1)
            raise argparse.ArgumentTypeError(msg)
        elif s_input[1] not in list_sort_options2:
            msg = "Incorrect sort order. Choose sort order: {}".format(list_sort_options2)
            raise argparse.ArgumentTypeError(msg)
        else:
            return

    @staticmethod
    def valid_filter_opt(f_input):
        list_filter_options1 = ['Price', 'Availability', 'Rating', 'Review']
        list_filter_options2 = ['<', '>', '=']
        if f_input[0] not in list_filter_options1:
            msg = "Incorrect filter type. You can filter by: {}.".format(list_filter_options1)
            raise argparse.ArgumentTypeError(msg)
        elif f_input[1] not in list_filter_options2:
            msg = "Incorrect sign. Please use one of following signs: {}.".format(list_filter_options2)
            raise argparse.ArgumentTypeError(msg)
        else:
            return
