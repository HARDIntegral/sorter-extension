import pygame
import sys

from datetime import datetime
start = datetime.now()

def log_time(time):
    print('-' * 50)
    print(f'\tTime spent: {time}')
    print('-' * 50)

win_width = 600
win_height = 400

pygame.init()
_clock = pygame.time.Clock()
screen = pygame.display.set_mode((win_width, win_height))
pygame.display.set_caption('Sort')

condition = True

def _exit():
    global condition

    condition = False

def main():
    while condition:
        _clock.tick(60)
        screen.fill((80, 190, 225))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                _exit()
        pygame.display.update()

if __name__ == '__main__':
    print('start')
    main()

    pygame.quit()
    sys.exit

end = datetime.now()
log_time(end - start)
