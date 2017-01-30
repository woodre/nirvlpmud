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
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair that looks very clean.  You can tell\n"+
"that they mostly stay inside the Command Center.  He is wearing a pocket\n"+
"protector and looks very, very nerdy.\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: "+YEL+"Skinny"+NORM+"\n"+
"Height: Average\n"+
"Demeanor: "+YEL+"Quiet"+NORM+"\n"+
"\n"+
"\n"+
"\n");
set_level(15);
set_hp(350 + random(20));
set_ac(15 + random(5));
set_wc(20 + random(2));
set_al(750);
add_money(random(200) + 400);
set_chat_chance(4);
load_chat("the Pilot asks, 'Are you here to "+BOLD+"rent"+NORM+" a "+BOLD+"helicopter"+NORM+"?'\n");
}

