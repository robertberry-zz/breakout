# Rather messy Makefile. I'm sure all of this can (and should) be automated. Am
# going to look into autoconf etc. soon.

SOURCE_DIR = src/
OBJS = ball.o breakout.o image_pack.o timer.o utils.o bat.o score_counter.o entity.o brick.o renderable.o
INCLUDES = -lSDL -lSDL_image -lSDL_ttf

breakout: $(OBJS)
	g++ -o breakout $(OBJS) $(INCLUDES)

ball.o: $(SOURCE_DIR)ball.h $(SOURCE_DIR)ball.cpp
	g++ -c $(SOURCE_DIR)ball.cpp

bat.o: $(SOURCE_DIR)bat.h $(SOURCE_DIR)bat.cpp
	g++ -c $(SOURCE_DIR)bat.cpp

brick.o: $(SOURCE_DIR)brick.h $(SOURCE_DIR)brick.cpp
	g++ -c $(SOURCE_DIR)brick.cpp

breakout.o: $(SOURCE_DIR)breakout.cpp
	g++ -c $(SOURCE_DIR)breakout.cpp

entity.o: $(SOURCE_DIR)entity.cpp
	g++ -c $(SOURCE_DIR)entity.cpp

image_pack.o: $(SOURCE_DIR)image_pack.h $(SOURCE_DIR)image_pack.cpp
	g++ -c $(SOURCE_DIR)image_pack.cpp

score_counter.o: $(SOURCE_DIR)score_counter.h $(SOURCE_DIR)score_counter.cpp
	g++ -c $(SOURCE_DIR)score_counter.cpp

renderable.o: $(SOURCE_DIR)renderable.h $(SOURCE_DIR)renderable.cpp
	g++ -c $(SOURCE_DIR)renderable.cpp

timer.o: $(SOURCE_DIR)timer.h $(SOURCE_DIR)timer.cpp
	g++ -c $(SOURCE_DIR)timer.cpp

utils.o: $(SOURCE_DIR)utils.h $(SOURCE_DIR)utils.cpp
	g++ -c $(SOURCE_DIR)utils.cpp

clean:
	rm -f $(OBJS) breakout
