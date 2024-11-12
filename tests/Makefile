#==============================================================================#
#                           GET_NEXT_LINE PROJECT                              #
#==============================================================================#

# Main target names
NAME = get_next_line_tester.out
NAME_BONUS = get_next_line_tester_bonus.out

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
# Source files for main library
SRCS_BONUS = ${addprefix ${SRC_PATH}/, get_next_line_bonus.c \
			 get_next_line_utils_bonus.c}
# Object files derived from source files
OBJS_BONUS = ${addprefix ${BUILD_PATH}/, ${notdir ${SRCS_BONUS:.c=.o}}}
FILES = ${addprefix ${FILES_PATH}/, excuse-me.txt}

#------------------------------------------------------------------------------#
#                            	   FLAGS & COMMANDS                            #
#------------------------------------------------------------------------------#

CC = cc                           # Compiler to use
CCFLAGS = -Wall -Wextra -Werror   # Compiler flags for warnings and errors
BUFFFLAGS		?= -D BUFFER_SIZE=
BUFFER_SIZE ?= 11
RM = rm -fr                       # Command to remove files/directoriesforcefully
MKDIR_P = mkdir -p                # Command to create directories (with parent)
INC = -I ${INC_PATH}              # Include path for header file

#------------------------------------------------------------------------------#
#                                    RULES                                     #
#------------------------------------------------------------------------------#

##  Compilation Rules for Libft  ##

all: ${BUILD_PATH} ${OBJS}
	@printf "${CYAN}${DIM}Compiling main.c for test...${RESET}\n"
	@${CC} ${CCFLAGS} ${BUFFFLAGS} ${BUFFER_SIZE} main.c ${OBJS} ${FILES} -o ${NAME}
	@printf "${GREEN}${BOLD}${CHECK} Test executable compiled successfully!${RESET}\n"
	@printf "${YELLOW}${BOLD}Running tests...${RESET}\n"
	@./${NAME}
	@printf "${GREEN}${BOLD}${CHECK} Tests completed!${RESET}\n"
	@${RM} ${NAME}

${BUILD_PATH}:
	@printf "\n${BLUE}${BOLD}Creating build directory...${RESET}\n"
	@${MKDIR_P} ${BUILD_PATH}
	@printf "${GREEN}${BOLD}${CHECK} Build directory created successfully!${RESET}\n"

${BUILD_PATH}/%.o: ${SRC_PATH}/%.c ${HEADERS} | ${BUILD_PATH}
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${BUFFFLAGS} ${BUFFER_SIZE} ${INC} -c $< -o $@

${BUILD_PATH}/%.o: ${BONUS_PATH}/%.c ${HEADERS_BONUS}  # Compile bonus source files into object files (bonus)
	@printf "${CYAN}${DIM}Compiling: ${WHITE}%-30s${RESET}\r" ${notdir $<}
	@${CC} ${CCFLAGS} ${BUFFFLAGS} ${BUFFER_SIZE} ${INC} -c $< -o $@

bonus: ${BUILD_PATH} ${OBJS_BONUS}
	@printf "${CYAN}${DIM}Compiling main_bonus.c for test...${RESET}\n"
	@${CC} ${CCFLAGS} ${BUFFFLAGS} ${BUFFER_SIZE} main_bonus.c ${OBJS_BONUS} -o ${NAME_BONUS}
	@printf "${GREEN}${BOLD}${CHECK} Test executable compiled successfully!${RESET}\n"
	@printf "${YELLOW}${BOLD}Running tests...${RESET}\n"
	@./${NAME_BONUS}
	@printf "${GREEN}${BOLD}${CHECK} Tests completed!${RESET}\n"
	@${RM} ${NAME_BONUS}

##  Norms Rules  ##

norm_mandatory:                # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking Norminette...${RESET}\n"
	@norminette_output=$$(norminette ${SRC_PATH}/*.c ${INC_PATH}/*.h | grep -v "OK!" || true); \
	if [ -z "$$norminette_output" ]; then \
		printf "${GREEN}${BOLD}${CHECK} No norminette errors found!${RESET}\n"; \
	else \
		printf "$$norminette_output\n"; \
		printf "${RED}${BOLD}❌ Norminette errors found.${RESET}\n"; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Norminette check completed!${RESET}\n"

norm_bonus:                    # Check norms for bonus sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking Norminette...${RESET}\n"
	@norminette_output=$$(norminette ${BONUS_PATH}/*.c ${INC_PATH_BONUS}/*.h | grep -v "OK!" || true); \
	if [ -z "$$norminette_output" ]; then \
		printf "${GREEN}${BOLD}${CHECK} No norminette errors found!${RESET}\n"; \
	else \
		printf "$$norminette_output\n"; \
		printf "${RED}${BOLD}❌ Norminette errors found.${RESET}\n"; \
	fi
	@printf "${GREEN}${BOLD}${CHECK} Norminette check completed!${RESET}\n"

norm_all:                     # Check norms for all sources 
	@make norm_mandatory
	@make norm_bonus

##   Check for external functions  ##
check_external_functions: all               # Check norms for mandatory sources 
	@printf "\n${BLUE}${BOLD}${TEST} Checking External Functions...${RESET}\n"
	nm ./${NAME} | grep "U" | grep -v "__"
	@printf "${GREEN}${BOLD}${CHECK} External functions check completed!${RESET}\n"
	
##  Cleaning Rules  ##

clean:                       # Clean up object files and temporary build files 
	@printf "\n${YELLOW}${BOLD}${CLEAN} Cleaning object files...${RESET}\n"
	@${RM} ${OBJS} ${OBJS_BONUS}
	@printf "${GREEN}${BOLD}${CHECK} Object files cleaned!${RESET}\n"

fclean: clean               # Fully clean up by removing executables and build directories 
	@printf "${YELLOW}${BOLD}${CLEAN} Removing executable, libft.a and build files...${RESET}\n"
	@${RM} ${NAME}
	@${RM} ${BUILD_PATH}
	@${RM} ${EXEC}
	@${MAKE} ${LIBFT_PATH} fclean
	@printf "${GREEN}${BOLD}${CHECK} All files cleaned!${RESET}\n"

re: fclean ${NAME}          # Rebuild everything from scratch 

.PHONY: all test clean fclean re norm start_tmux start_tmux_bonus get_libft
# Declare phony targets
