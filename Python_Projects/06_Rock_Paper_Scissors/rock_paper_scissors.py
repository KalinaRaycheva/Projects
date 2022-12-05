import random


def is_win(player, opponent):
    if (player == 'r' and opponent == 's') or (player == 's' and opponent == 'p') or (
            player == 'p' and opponent == 'r'):
        return True


def play():
    user = input("What's your choice?\n 'r' for rock,\n 'p' for paper,\n 's' for scissors\n--> ")
    computer = random.choice(['r', 'p', 's'])

    if user == computer:
        return 'It\'s a tie.'
    elif is_win(user, computer):
        return 'You won!'
    else:
        return 'You lost!'

print(play())
