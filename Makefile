SRC_DIR = src
OBJ_DIR = obj

MODULES = main matrix

OUT_FILE = kirhgoph

OBJ = $(addsuffix .o, $(MODULES))
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

CXX = g++
CXX_FLAGS = -g
LD = g++
LD_FLAGS = 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $^ -o $@ $(CXX_FLAGS)

$(OUT_FILE): $(OBJ_PATH)
	$(CXX) $^ -o $(OUT_FILE)

all: $(OUT_FILE)

run: all
	./$(OUT_FILE)
clean:
	rm $(addprefix $(OBJ_DIR)/, $(OBJ))
