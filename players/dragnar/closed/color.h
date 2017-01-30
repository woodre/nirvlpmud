#include "/players/dragnar/closed/esc.h"
#define PUR ESC+"[35m"
#define YEL ESC + "[33m"
#define RED ESC+"[31m"
#define GRE ESC+"[32m"
#define BLU ESC+"[34m"
#define CYA ESC + "[36m"
#define WHI ESC+"[37m"
#define NOSTYLE ESC+"[0m"
#define BOLD ESC+"[1m"
#define BLINK ESC+"[5m"
#define UNDERLINE ESC+"[4m"
#define REVERSE ESC + "[7m"
#define RESET ESC + "[0m"
/*
string precolor(string str, string color) {
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
*/

#define precolor(str,c) str
#define postcolor(str,c) str
#define check_color(str) str
#define style_check(str) str
