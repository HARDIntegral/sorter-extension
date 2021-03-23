import pygame

win_width = 600
win_height = 400
screen = pygame.display.set_mode((win_width, win_height))

bar_width = 45
bar_gap = 2
def find_tallest(list):
    highest = list[0]
    for _ in list:
        if _ > highest:
            highest = _
    return highest