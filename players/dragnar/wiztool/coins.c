inherit "obj/treasure";
#include <ansi.h>

void
reset(int arg) {
   if (arg) return;
   set_id("coins");
   set_short("A veritable dragon horde of gold coins ["+HIY+"80000"+NORM+"]");
   set_long(
"80000 pieces of Nirvana's main currency: the gold coin.\n" +
"They are extremely heavy\n");
   set_weight(100);
   set_value(1200);
   set_save_flag();
}

void init() { 
  add_action("cmd_coins","coins"); 
}

get() {
  write(HIY+"April Fools!\n"+NORM);
  return 0;
}
