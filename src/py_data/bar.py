from py_data.helpers import *

class Bar(pygame.sprite.Sprite):
    def __init__(self, pos, dims, color):
        super().__init__()
        self.screen = screen
        self.pos = pos
        
        self.image = pygame.Surface(dims)
        self.image.fill(color)
    def update(self):
        self.rect = self.image.get_rect(midbottom=self.pos)
        screen.blit(self.image, self.rect)

bar_list = []
bar_group = pygame.sprite.Group()

def list_to_bar(list, shrink = 1.0):
    bar_group.empty()
    height_multiplier = 200 / find_tallest(list)
    bw = bar_width * shrink
    width  = len(list)*bw + (len(list) - 1)*bar_gap
    if (width > win_width - 20):
        list_to_bar(list, shrink * 0.75)
    pos_x_start = (win_width / 2) - (width / 2) + (bw / 2)
    pos_x = pos_x_start
    for _ in list:
        bar_list.append(
            Bar(
                [pos_x, win_height - 50], 
                [bw, height_multiplier * _], 
                [10, 10, 10]
            )
        )
        pos_x += bar_gap + bw
    for _ in bar_list:
        bar_group.add(_)
    bar_list.clear()
    bar_group.update()