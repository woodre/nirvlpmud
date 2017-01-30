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
random_index=random(10);
hair_index=random(4);
set_name( ({"bob","bill","tim","phil","ralph","mark","matt","jason","randall","cliff"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("geologist");
set_short( ({"Bob, a geologist","Bill, a geologist","Tim, a geologist","Phil, a geologist","Ralph, a geologist","Mark, a geologist","Matt, a geologist","Jason, a geologist","Randall, a geologist","Cliff, a geologist"})[random_index] );
set_long(
query_name() + " has "+ (({"blonde","brown","red","black"})[hair_index])+" hair although "+query_possessive()+" hair is mostly covered by "+query_possessive()+"\n"+
"hard hat.  "+capitalize(query_possessive())+" name tag reads '"+query_name()+"\n"+
"|Geologist| and is slightly covered by reflective gear.\n"+
"\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: Average\n"+
"Height: Average\n"+
"Demeanor: Focused\n"+
"\n"+
"\n");
set_level(26);
set_hp(550 + random(100));
set_ac(15 + random(3));
set_wc(37 + random(3));
set_al(0);
add_money(random(1000)+5000);
  set_chat_chance(5);
load_chat(query_name()+" looks carefully at one of the wells.\n");
load_chat(query_name()+" jots something down on their clipboard.\n");
add_spell("jab","#MN# stabs you with a pencil!\n",
"#MN# stabs #TN# with a pencil!\n",
35,45,"physical");
armor=clone_object("/players/mo/rig/AC/helmet.c");
  move_object(armor, this_object());
  command("wear helmet", this_object());
armor=clone_object("/players/mo/rig/AC/gear.c");
  move_object(armor, this_object());
  command("wear vest", this_object());
 weapon=clone_object("/players/mo/rig/WEP/pencil.c");
  move_object(weapon, this_object());
  command("wield pencil", this_object());
}
