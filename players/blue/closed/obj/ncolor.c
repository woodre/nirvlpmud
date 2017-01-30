#include "/players/blue/closed/lib/color.h"
#include "/players/blue/closed/lib/basic.h"


string com, strn;

id(str) { return str == "color"; }
short() { return "A Color Object"; }
long() { write("A color object.\n"); }
query_weight() { return 0; }
query_value() { destruct(this_object()); }

reset(arg) {
   if(arg) return;
  
   com = 0;
   strn = "";

}

init() {
   
   add_action("set_command", "setcom");
   add_action("show_com","colshow");
   add_action("clear_me","colclear");
   add_action("set_string","setstr");
   add_action("execute_com","excom");

}

set_command(str) {
   com = str;
   write("Command set at: "+com+"\n");
   return 1;
}

set_string() {
   if(strn) write(strn+"\n>>>");
   else write(">>>");
   input_to("catch_string");
   return 1;
}

catch_string(str) {
   string temp;
   if(str == "q"||str == "quit") {
      write("Current string: "+strn+"\n");
      return 1;
   }
   temp = find_color(str);
   if(temp) strn = strn + temp;
      else strn = strn +" "+str;
   write("Current: "+strn+"\n");
   write(">>>");
   input_to("catch_string");
   return 1;
}

find_color(str) {
   if(str == "cya") return CYA;
      else if(str == "red") return RED;
      else if(str == "blu") return BLU;
      else if(str == "whi") return WHI;
      else if(str == "pur") return PUR;
      else if(str == "yel") return YEL;
      else if(str == "bold") return BOLD;
      else if(str == "nostyle") return ESC+"[0m";
   else if(str == "blink") return BLINK;
   else if(str == "bla") return BLA;
   else if(str == "und") return UNDERLINE;
   else if(str == "rev") return REVERSE;
      else if(str == "gre") return GRE;
      else return 0;
}

execute_com() {
   command(com+" "+strn, TP);
   return 1;
}


clear_me() {
   strn = "";
   com = 0;
   write("Ok.\n");
   return 1;
}

show_com() {
   write("Current command: "+com+"\nCurrent string: "+strn+"\n");
   return 1;
}
