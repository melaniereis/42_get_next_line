#==============================================================================#
#                           GET_NEXT_LINE PROJECT                              #
#==============================================================================#

# Main target names
NAME = get_next_line_tester.out
NAME_BONUS = get_next_line_tester_bonus.out
COMPARE_NAME = compare_tester.out

# Buffer sizes to test
BUFFER_SIZES = 1 5 32 42 10000000

#------------------------------------------------------------------------------#
#                                COLORS & STYLES                               #
#------------------------------------------------------------------------------#

# ANSI color codes for prettier output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

# Text style codes
BOLD = \033[1m
DIM = \033[2m
ITALIC = \033[3m
UNDERLINE = \033[4m

# Emojis for visual feedback
CHECK = ✓
CLEAN = 🧹
BUILD = 🔨
ROCKET = 🚀
BOOK = 📚
SPARKLES = ✨

#------------------------------------------------------------------------------#
#                            	  NAMES AND PATHS                              #
#------------------------------------------------------------------------------#

# Directory structure
BUILD_PATH = .build
SRC_PATH = ../srcs
BONUS_PATH = ../srcs_bonus
INC_PATH = ../incs
INC_PATH_BONUS = ../incs_bonus
FILES_PATH = ./files/
HEADERS = ${INC_PATH}/get_next_line.h
HEADERS_BONUS = ${INC_PATH}/get_next_line_bonus.h

# Source files for main library
SRCS = ${addprefix ${SRC_PATH}/, get_next_line.c get_next_line_utils.c}
# Object files derived from source files
OBJS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS:.c=.o}}}
# Source files for bonus library
SRCS_BONUS = ${addprefix ${BONUS_PATH}/, get_next_line_bonus.c \
			 get_next_line_utils_bonus.c}
# Object files derived from bonus source files
OBJS_BONUS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS_BONUS:.c=.o}}}
FILES = big_line_no_nl.txt empty.txt hello-whirl.txt \
judgement-night.txt mini-vulf.txt quality-over-opinion.txt test.txt zzz.txt \
big_line_with_nl.txt excuse-me.txt into-the-void.txt kglw.txt onechar.txt \
read_error.txt vulf.txt

#------------------------------------------------------------------------------#
#                            	   FLAGS & COMMANDS                            #
#------------------------------------------------------------------------------#

CC = cc                           # Compiler to use
CCFLAGS = -Wall -Wextra -Werror   # Compiler flags for warnings and errors
BUFFFLAGS = -D BUFFER_SIZE=
RM = rm -fr                       # Command to remove files/directories forcefully
MKDIR_P = mkdir -p                # Command to create directories (with parent)
INC = -I ${INC_PATH}              # Include path for header file

# Valgrind settings
VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
DEBUG_FLAG = -g

#------------------------------------------------------------------------------#
#                                    RULES                                     #
#------------------------------------------------------------------------------#

test:
	@for size in ${BUFFER_SIZES}; do \
		printf "\n${CYAN}${BOLD}Testing with BUFFER_SIZE=$$size${RESET}\n"; \
		${CC} ${CCFLAGS} ${BUFFFLAGS}$$size main.c ${SRCS} -o ${NAME}; \
		printf "${YELLOW}${BOLD}Running tests...${RESET}\n"; \
		for file in ${FILES}; do \
			printf "\n${PURPLE}${BOLD}Testing file: $$file${RESET}\n"; \
			./${NAME} $$file; \
		done; \
	done
	@${RM} ${NAME}

bonus:
	@for size in ${BUFFER_SIZES}; do \
		printf "\n${CYAN}${BOLD}Testing bonus with BUFFER_SIZE=$$size${RESET}\n"; \
		${MAKE} -s test_bonus BUFFER_SIZE=$$size; \
	done

test_bonus:
	@${CC} ${CCFLAGS} ${BUFFFLAGS}${BUFFER_SIZE} main_bonus.c ${SRCS_BONUS} -o ${NAME_BONUS}
	@printf "${YELLOW}${BOLD}Running tests...${RESET}\n"
	@./${NAME_BONUS} ${FILES}
	@${RM} ${NAME_BONUS}
	
##  Comparing tests ##

test_compare:
	@for size in ${BUFFER_SIZES}; do \
		printf "\n${CYAN}${BOLD}Testing with BUFFER_SIZE=$$size${RESET}\n"; \
		${CC} ${CCFLAGS} ${BUFFFLAGS}$$size compare_tester.c ${SRCS} -o ${COMPARE_NAME}; \
		printf "${YELLOW}${BOLD}Running comparison tests...${RESET}\n"; \
		for file in ${FILES}; do \
			printf "${PURPLE}${BOLD}Testing file: $$file ${RESET}"; \
			./${COMPARE_NAME} ${FILES_PATH}$$file 3<${FILES_PATH}$$file; \
		done; \
	done
	@${RM} ${COMPARE_NAME}
	
##  GNL_tester  ##

gnlTester: deps $(EXEC) get_gnlTester		## Run gnlTester
	tmux split-window -h "$(MAKE) $(GNLTESTER_PATH) a"
	tmux set-option remain-on-exit on

get_gnlTester:
	@echo "* $(CYA)Getting gnlTester submodule$(D)]"
	@if test ! -d "$(GNLTESTER_PATH)"; then \
		git clone git@github.com:Tripouille/gnlTester.git $(GNLTESTER_PATH); \
		echo "* $(GRN)gnlTester download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)gnlTester already exists 🖔"; \
		echo " $(RED)$(D) [$(GRN)Nothing to be done!$(D)]"; \
	fi

gnl-station-tester: deps $(EXEC) get_gnlStationTester			## Run gnl-station-tester
	tmux split-window -h "$(MAKE) $(GNL_STATION_TESTER_PATH)"
	tmux set-option remain-on-exit on

get_gnlStationTester:
	@echo "* $(CYA)Getting gnlStationTester submodule$(D)]"
	@if test ! -d "$(GNL_STATION_TESTER_PATH)"; then \
		git clone git@github.com:kodpe/gnl-station-tester.git $(GNL_STATION_TESTER_PATH); \
		echo "* $(GRN)gnl-station-tester download$(D): $(_SUCCESS)"; \
	else \
		echo "* $(GRN)gnl-station-tester already exists 🖔"; \
		echo " $(RED)$(D) [$(GRN)Running tester!$(D)]"; \
	fi
	
##  Valgrind tests ##

test_valgrind:
	@for size in ${BUFFER_SIZES}; do \
		printf "\n${CYAN}${BOLD}Testing with Valgrind and BUFFER_SIZE=$$size${RESET}\n"; \
		${MAKE} -s run_single_test_valgrind BUFFER_SIZE=$$size; \
	done

run_single_test_valgrind:
	@${CC} ${CCFLAGS} ${DEBUG_FLAG} ${BUFFFLAGS}${BUFFER_SIZE} main.c ${SRCS} -o ${NAME}
	@printf "${YELLOW}${BOLD}Running tests with Valgrind...${RESET}\n"
	@for file in ${FILES}; do \
		printf "\n${PURPLE}${BOLD}Testing file with Valgrind: $$file${RESET}\n"; \
		VALGRIND_OUTPUT=$$(${VALGRIND} ${VALGRIND_FLAGS} ./${NAME} $$file 2>&1); \
		if echo "$$VALGRIND_OUTPUT" | grep -q "definitely lost" || \
		   echo "$$VALGRIND_OUTPUT" | grep -q "indirectly lost" || \
		   echo "$$VALGRIND_OUTPUT" | grep -q "possibly lost" || \
		   echo "$$VALGRIND_OUTPUT" | grep -q "still reachable"; then \
			printf "${RED}${BOLD}Memory leak detected!${RESET}\n"; \
			echo "$$VALGRIND_OUTPUT" | grep -E "definitely|indirectly|possibly|still reachable"; \
		else \
			printf "${GREEN}${BOLD}No leaks detected.${RESET}\n"; \
		fi; \
	done
	@${RM} ${NAME}

test_bonus_valgrind:
	@for size in ${BUFFER_SIZES}; do \
		printf "\n${CYAN}${BOLD}Testing bonus with Valgrind and BUFFER_SIZE=$$size${RESET}\n"; \
		${MAKE} -s run_single_test_bonus_valgrind BUFFER_SIZE=$$size; \
	done

run_single_test_bonus_valgrind:
	@${CC} ${CCFLAGS} ${DEBUG_FLAG} ${BUFFFLAGS}${BUFFER_SIZE} main_bonus.c ${SRCS_BONUS} -o ${NAME_BONUS}
	@printf "${YELLOW}${BOLD}Running bonus tests with Valgrind...${RESET}\n"
	@VALGRIND_OUTPUT=$$(${VALGRIND} ${VALGRIND_FLAGS} ./${NAME_BONUS} ${FILES} 2>&1); \
	if echo "$$VALGRIND_OUTPUT" | grep -q "definitely lost" || \
	   echo "$$VALGRIND_OUTPUT" | grep -q "indirectly lost" || \
	   echo "$$VALGRIND_OUTPUT" | grep -q "possibly lost" || \
	   echo "$$VALGRIND_OUTPUT" | grep -q "still reachable"; then \
		printf "${RED}${BOLD}Memory leak detected!${RESET}\n"; \
		echo "$$VALGRIND_OUTPUT" | grep -E "definitely|indirectly|possibly|still reachable"; \
	else \
		printf "${GREEN}${BOLD}No leaks detected.${RESET}\n"; \
	fi
	@${RM} ${NAME_BONUS}

##  Cleaning rules ##

clean:

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all test clean fclean re bonus test_bonus run_single_test test_compare
