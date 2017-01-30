#include "/players/wocket/closed/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("potion");
  add_alias("heal");
  set_short(BOLD+"A "+HIB+"Potion"+NORM+" of "+HIG+"HEAL"+NORM);
  set_long("This is a large "+HIB+"potion bottle"+NORM+" which\n"+
           "contains a spell of "+HIG+"HEAL"+NORM+".  There is\n"+
           "writing on the side of the bottle.\n");
  set_type("Slam");
  set_msg("You open the stopper and slam the "+HIB+"potion"+NORM+" down your throat.\n"+
          ""+HIG+"Healing"+HIC+" energy"+NORM+" flows through you as you are "+HIM+"FULLY HEALED!"+NORM+"\n");
  set_msg2(" slams down a "+HIB+"potion"+NORM+" of "+HIG+"HEAL"+NORM+"!\n");
  add_cmd("slam");
  set_heal(2000,2000);
  set_charges(1);
  set_value(10000);
}
init()  {
  ::init();
add_action("read_potion", "read");
}
read_potion(str)  {
if((!str) || !id(str))  {
write("To use simply 'slam potion' or 'slam heal'.\n"+
      "(Made in:"+HIB+" Raven's Bluff"+NORM+".)\n");  
return 1;
}
}
query_save_flag(){
return 1;
}


