// Define ANSI escape codes for text formatting
#define RESET_COLOR "\033[0m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"

// Macros to print text in different colors
#define COLOR(text, color) cout << color << text << RESET_COLOR << endl

#define ERROR(text) cerr << endl << RED_TEXT << "ERROR: " << RESET_COLOR << text << endl
#define WARNING(text) cout << endl << YELLOW << "WARNING: " << RESET_COLOR << text << endl
#define INFO(text) cout << BLUE_TEXT << "INFO: " << RESET_COLOR << text << endl