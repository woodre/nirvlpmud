#include <ansi.h>

id(str) {
   return str=="board" || str== "notice";
}


long()
{
   write("\n\
      Due to some heals being illegal, they have been changed.\n\
      There is now a chance they will explode, with no harm\n\
      to the player!\n\
      Direct all hate mail to Jareel!\n\n");
}

short() {
   return ""+BLINK+HIR+"Warning Notice"+NORM+"";
}

init() {
   add_action("cmd_read","read");
}


int cmd_read(string str) {
   if(str != "notice") return 0;
   long();
   return 1;
}
