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
random_index=random(4);
hair_index=random(4);
set_name( ({"bob","bill","tim","phil"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("geologist");
set_short( ({"Bob |Head Geologist|","Bill |Head Geologist|","Tim |Head Geologist|","Phil |Head Geologist|"})[random_index]);

set_long(
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair that looks very clean.  You can tell\n"+
"that "+query_name()+" mostly stays inside the Command Center.  He has a\n"+
"name tag on his chest that reads "+query_name()+".\n"+
"\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: "+BLU+"Above Average"+NORM+"\n"+
"Height: "+BLU+"Above Average"+NORM+"\n"+
"Demeanor: "+BOLD+"Focused"+NORM+"\n"+
"\n"+
"\n");
set_level(16);
set_hp(900 + random(160));
set_ac(21 + random(3));
set_wc(21);
set_al(0);
add_money(random(1000)+5000);
  set_chat_chance(5);
load_chat(query_name()+" jots something down on their clipboard.\n");
add_spell("stab","#MN# stabs you with a pencil!\n"+
"\n"+
"            O U C H !\n",
"#MN# stabs #TN# with a pencil!\n",
40,70,"physical");
}
