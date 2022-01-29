#
#

NOM=libmlx.a
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
SRC+= mlx_png.c mlx_mouse.m
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+= -O2 -w

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11

GREEN		=	"\033[1;32m"
YELLOW		=	"\033[0;33m"
CYAN		=	"\033[3;36m"

all: $(NOM)

$(NOM):	$(OBJ)
	@ar -r -c $(NOM) $(OBJ)
	@echo $(YELLOW)"Archiving object files"$(DEFAULT)
	@ranlib $(NOM)
	@echo $(GREEN)"MiniLibX Ready! 😎"$(DEFAULT)

clean:
	@rm -f $(NOM) $(OBJ) *~
	@rm -f mlx_app

re: clean all
