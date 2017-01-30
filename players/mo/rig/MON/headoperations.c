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
set_name( ({"jack","jim","gerald"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("head");
set_short( ({"Jack "+BRED+"/Head of Operations/"+NORM+"","Jim "+BRED+"/Head of Operations/"+NORM+"","Gerald "+BRED+"/Head of Operations/"+NORM+""})[random_index]);

set_long(
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair that looks very clean.  You can tell\n"+
"that "+query_name()+" mostly stays inside the Command Center.  He has a\n"+
"name tag on his chest that reads "+query_name()+".\n"+
"\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: "+BLU+"Above Average"+NORM+"\n"+
"Height: "+YEL+"Below Average"+NORM+"\n"+
"Demeanor: "+BOLD+"Focused |on putting|"+NORM+"\n"+
"\n"+
"\n");
set_level(15);
set_hp(900 + random(50));
set_ac(16);
set_wc(24 + random(2));
set_al(40);
add_money(4000 + random(1000));
  set_chat_chance(5);
load_chat(query_name()+" putts the golf ball into the cup.\n");
add_spell("swing",""+BOLD+" #MN# swings at you with his putter..."+NORM+"\n",
""+BOLD+" #MN# swings at #TN# with his putter..."+NORM+"\n",
90,25,"physical");
 weapon=clone_object("/players/mo/rig/WEP/putter.c");
  move_object(weapon, this_object());
  command("wield putter", this_object());
}
