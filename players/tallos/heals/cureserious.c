#include "/players/wocket/closed/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("potion");
  add_alias("serious");
  set_short(BOLD+"A "+HIB+"Potion"+NORM+" of "+HIG+"Cure "+HIM+"Serious Wounds"+NORM);
  set_long("   This is a large "+HIB+"potion bottle"+NORM+" which\n"+
           "contains a few imbibes of "+HIG+"cure "+HIM+"serious\n"+
           "wounds"+NORM+". There is writing on the side\n"+
           "of the bottle.\n");
  set_type("Imbibes");
  set_msg("You open the stopper and imbibe a portion of the "+HIB+"potion"+NORM+".\n"+
          "The "+HIM+"liquid"+NORM+" has a "+HIG+"good"+HIR+"berry"+NORM+" flavor and tastes "+HIR+"delicious"+NORM+"!\n"+
          "You replace the stopper into the bottle's mouth.\n");
  set_msg2(" imbibes part of A "+HIB+"Potion"+NORM+" of "+HIG+"Cure "+HIM+"Serious Wounds"+NORM+".\n");
  add_cmd("imbibe");
  set_heal(50,50);
  set_charges(3);
  set_soak(4);
  set_stuff(4);
  set_value(867);
}
init()  {
  ::init();
add_action("read_potion", "read");
}
read_potion(str)  {
if((!str) || !id(str))  {
write("To use simply 'imbibe potion' or 'imbibe serious'.\n"+
      "(Made in:"+HIB+" Raven's Bluff"+NORM+".)\n");  
return 1;
}
}
query_save_flag(){
return 1;
}


