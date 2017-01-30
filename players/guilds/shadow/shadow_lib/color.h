#include "/players/guilds/shadow/shadow_lib/esc.h"
#define PUR ESC+"[35m"
#define YEL ESC + "[33m"
#define RED ESC+"[31m"
#define BLA ESC+"[8m"
#define GRE ESC+"[32m"
#define BLU ESC+"[34m"
#define CYA ESC + "[36m"
#define WHI ESC+"[37m"
#define NOSTYLE ESC+"[0m"
#define BOLD ESC+"[1m"
#define BLINK ESC+"[5m"
#define UNDERLINE ESC+"[4m"
#define REVERSE ESC + "[7m"
#define BACK_WHI ESC+"[47m"
#define BACK_BLA ESC+"[40m"
#define BACK_RED ESC+"[41m"
#define BACK_GRE ESC+"[42m"
#define BACK_YEL ESC+"[43m"
#define BACK_BLU ESC+"[44m"
#define BACK_PUR ESC+"[45m"
#define BACK_CYA ESC+"[46m"

precolor(str, color) {
   if(!str) return 0;
   if(color == "blue"||color == "blu") return BLU + str;
   if(color == "red") return RED + str;
   if(color == "green"||color == "gre") return GRE + str;
   if(color == "purple"||color == "pur") return PUR+str;
   if(color == "cyan"||color == "cya") return CYA + str;
   if(color =="yellow"|| color == "yel") return YEL + str;
   if(color == "white"||color == "whi") return WHI + str;
   return str;
}

postcolor(str, color) {
   if(!str) return 0;
   if(color == "blue"||color == "blu") return str + BLU;
   if(color == "red") return str + RED;
   if(color == "green"||color == "gre") return str + GRE;
   if(color == "purple"||color == "pur") return str + PUR;
   if(color == "cyan"||color == "cya") return str + CYA;
   if(color =="yellow"|| color == "yel") return str + YEL;
   if(color == "white"||color == "whi") return str + WHI;
   return str;
}

check_color(str) {
   if(!str) return 0;
   if(str == "blue"||str == "blu") return BLU;
   if(str == "red") return RED;
   if(str == "green"||str == "gre") return GRE;
   if(str == "purple"||str == "pur") return PUR;
   if(str == "cyan"||str == "cya") return CYA;
   if(str =="yellow"|| str == "yel") return YEL;
   if(str == "white"||str == "whi") return WHI;
   if(str == "RED") return RED;
   if(str == "YEL" || str == "YELLOW") return BOLD + YEL;
   if(str == "BLA" || str == "BLACK") return BOLD + BLA;
   if(str == "BLU" || str == "BLUE") return BOLD + BLU;
   if(str == "PUR" || str == "PURPLE") return BOLD + PUR;
   if(str == "GRE" || str == "GREEN") return BOLD + GRE;
   if(str == "WHI" || str == "WHITE") return BOLD + WHI;
   if(str == "CYA" || str == "CYAN") return BOLD + CYA;
   return 0;
}

check_back(str) {
   if(!str) return 0;
   if(str == "red") return BACK_RED;
   if(str == "gre" || str == "green") return BACK_GRE;
   if(str == "pur" || str == "purple") return BACK_PUR;
   if(str == "yel" || str == "yellow") return BACK_YEL;
   if(str == "blu" || str == "blue") return BACK_BLU;
   if(str == "cya" || str == "cyan") return BACK_CYA;
   if(str == "whi" || str == "white") return BACK_WHI;
   if(str == "bla" || str == "black") return BACK_BLA;
   return 0;
}

style_check(str) {
   if(!str) return 0;
   if(str == "bold"||str == "bol") return BOLD;
   if(str == "blink"||str =="bli") return BLINK;
   if(str == "reverse"||str =="rev") return REVERSE;
   if(str == "underline"||str == "und"||str == "ul") return UNDERLINE;
   if(str == "none"||str == "nostyle"||str == "plain"||str =="non") 
      return NOSTYLE;
   return 0;
}
