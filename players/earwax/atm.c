#include <ansi.h>

string short() { return U+BLINK+RED+REVERSE+BOLD+YELLOW+"Beta Char Coin Dispenser"+NORM+NORM; }

void long() { write("Get your free money: "+HIK+"press button"+NORM+"\n"); }


int id(string arg) { return (arg == "dispenser" || arg == "atm"); }

int get() { return 0; }
int drop() { return 0;}

int press(string arg) { 
  write("You now have 80k.  Enjoy.\n");
  this_player()->add_money(80000);
  return 1;
}

void init() { add_action("press", "press"); }
