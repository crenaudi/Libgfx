LFT		=	libft.a
LGFX	=	libgfx.a

D_LFT	=	./libft
D_LGFX	=	./libgfx

all: $(LIBFT) $(LIBGFX)

$(LFT):
	@make -sC $(D_LFT)
	@cp $(D_LFT)/$(LFT) $(LFT)

$(LGFX) :
	@make -sC $(D_LGFX)
	@cp $(D_LGFX)/$(LGFX) $(LGFX)

all: $(LFT) $(LGFX)

clean:
	@make -sC $(D_LFT) clean
	@make -sC $(D_LGFX) clean

fclean:	clean
	@$(RM) $(D_LFT)/$(LFT) $(LFT)
	@$(RM) $(D_LGFX)/$(LGFX) $(LGFX)

re: fclean all
