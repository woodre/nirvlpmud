#include "/players/wocket/closed/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("potion");
  add_alias("ether");
  set_short(BOLD+"A "+HIB+"Potion"+NORM+" of "+NORM+""+BLU+"Ether "+NORM);
  set_long("   This is a large "+HIB+"potion bottle"+NORM+" which\n"+
           "contains a few imbibes of "+NORM+""+NORM+""+BLU+"ether"+NORM+". There\n"+
           "is writing on the side of the bottle.\n");
  set_type("Imbibes");
  set_msg("You open the stopper and imbibe a portion of the "+HIB+"potion"+NORM+".\n"+
          "The "+NORM+""+BLU+"liquid"+NORM+" has the slight taste of "+NORM+""+BLK+"iron"+NORM+" and "+NORM+"chalk.   You\n"+
          "replace the stopper into the bottle's mouth.\n");
  set_msg2(" imbibes part of A "+HIB+" Potion"+NORM+" of "+NORM+""+BLU+"Ether"+NORM+".\n");
  add_cmd("imbibe");
  set_heal(0,50);
  set_charges(3);
  set_soak(7);
  set_stuff(7);
  set_value(400);
}
init()  {
  ::init();
add_action("read_potion", "read");
}
read_potion(str)  {
if((!str) || !id(str))  {
write("To use simply 'imbibe potion' or 'imbibe ether'.\n"+
      "(Made in:"+HIB+" Raven's Bluff"+NORM+".)\n");  
return 1;
}
}
query_save_flag(){
return 1;
}


