SOURCE_DIR = src/
OBJS = ball.o breakout.o image_pack.o timer.o utils.o
INCLUDES = -lSDL -lSDL_image

breakout: $(OBJS)
	g++ -o breakout $(OBJS) $(INCLUDES)

ball.o: $(SOURCE_DIR)ball.h $(SOURCE_DIR)ball.cpp
	g++ -c $(SOURCE_DIR)ball.cpp

breakout.o: $(SOURCE_DIR)breakout.cpp
	g++ -c $(SOURCE_DIR)breakout.cpp

image_pack.o: $(SOURCE_DIR)image_pack.h $(SOURCE_DIR)image_pack.cpp
	g++ -c $(SOURCE_DIR)image_pack.cpp

timer.o: $(SOURCE_DIR)timer.h $(SOURCE_DIR)timer.cpp
	g++ -c $(SOURCE_DIR)timer.cpp

utils.o: $(SOURCE_DIR)utils.h $(SOURCE_DIR)utils.cpp
	g++ -c $(SOURCE_DIR)utils.cpp

clean: rm -f $(OBJS) breakout
