import sys

from py_data.bar import *

from datetime import datetime
start = datetime.now()

def log_time(time):
    print('-' * 50)
    print(f'\tTime spent: {time}')
    print('-' * 50)

pygame.init()
_clock = pygame.time.Clock()
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
        list_to_bar([5, 6, 2, 7, 3, 3, 6, 7, 4, 3])
        pygame.display.update()

if __name__ == '__main__':
    print('start')
    main()

    pygame.quit()
    sys.exit

end = datetime.now()
log_time(end - start)
