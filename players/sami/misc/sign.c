#include <ansi.h>

id(str) {
   return str=="sign" || str== "notice";
}


long()
{
   write("\n\
      HAPPY VALENTINES DAY\n\n");
}

short() {
   return "A "+BLINK+HIR+"Sign"+NORM+"";
}

init() {
   add_action("cmd_read","read");
}


int cmd_read(string str) {
   if(str != "sign") return 0;
   long();
   return 1;
}
