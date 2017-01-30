inherit "/obj/monster";

#include "/sys/lib.h"

#include <ansi.h>


reset(arg)
{
   object gold,armor,weapon;
   int hair_index;
   ::reset(arg);
   if(arg) return;
   hair_index=random(4);
   set_name("pilot");
   set_race("human");
   set_alias("pilot");
   set_short("A Helicopter Pilot");
   set_long(
      query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair that looks kind of matted.\n"+
      "You can tell that he normally has a helmet, and headset on to \n"+
      "communicate while he is flying.\n");
   set_level(15);
   set_hp(350 + random(20));
   set_ac(15 + random(5));
   set_wc(20 + random(2));
   set_al(750);
   add_money(random(200) + 400);
   set_chat_chance(4);
   load_chat("Pilot says, 'Oh being on the rig.. You should "+BOLD+"call"+NORM+" for a helicopter"+NORM+" so\n"+
      "I can get out of here.'\n");
}


