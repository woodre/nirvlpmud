inherit "/players/vertebraker/closed/std/monster";

#include "/sys/lib.h"

#include <ansi.h>


reset(arg)
{
  object gold,armor,weapon;
int random_index;
int hair_index;
  ::reset(arg);
  if(arg) return;
random_index=random(3);
hair_index=random(4);
set_name( ({"skip","pablo","steve"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("toolhand");
set_short( ({"Skip"+BOLD+" |Head Toolhand|"+NORM+"","Pablo"+BOLD+" |Head Toolhand|"+NORM+"","Steve"+BOLD+" |Head Toolhand|"+NORM+""})[random_index]);
set_long(
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair that looks very clean.  You can tell\n"+
"that "+query_name()+" mostly stays inside the Command Center.  He has a\n"+
"name tag on his chest that reads "+query_name()+".\n"+
"\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: "+BLU+"Above Average"+NORM+"\n"+
"Height: Average\n"+
"Demeanor: "+BRED+"Annoyed"+NORM+"\n"+
"\n"+
"\n");
set_level(51);
set_hp(950 + random(200));
set_ac(19 + random(10));
set_wc(36 + random(15));
set_al(-100);
add_money(5000 + random(1000));
  set_chat_chance(5);
load_chat(query_name()+" says, 'And you are here because why?'\n");
add_spell("jab","#MN# stabs you with a pencil!\n",
"#MN# stabs #TN# with a pencil!\n",
35,75,"physical");
}
