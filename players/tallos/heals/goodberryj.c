#include "/players/wocket/closed/ansi.h"
inherit "/obj/generic_heal.c";

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("juice");
  add_alias("juice");
  set_short(BOLD+""+HIG+"Good"+HIR+"berry"+NORM+""+NORM+""+MAG+" Juice"+NORM);
  set_long("This is a large "+HIB+"potion bottle"+NORM+" which\n"+
           "contains several chugs of "+NORM+""+NORM+""+BLU+""+HIG+"Good"+HIR+"berry"+NORM+""+NORM+"\n"+
           ""+MAG+"Juice"+NORM+". There is writing on the side\n"+
           "of the bottle.\n");
  set_type("Chugs");
  set_msg("You open the stopper and chug a portion of "+HIG+"good"+HIR+"berry"+NORM+""+NORM+""+MAG+" juice"+NORM+".\n"+
          "The liquid has the most "+HIR+"delicious"+HIM+" flavor"+NORM+" that you have ever\n"+
          "tasted in your life! You have to have more of this stuff!\n");
  set_msg2(" chugs some "+HIG+"Good"+HIR+"berry"+NORM+""+NORM+""+MAG+" Juice"+NORM+".\n");
  add_cmd("chug");
  set_heal(50,0);
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
write("To use simply 'chug juice'.\n"+
      "(Made in:"+HIB+" Raven's Bluff"+NORM+".)\n");  
return 1;
}
}
query_save_flag(){
return 1;
}


