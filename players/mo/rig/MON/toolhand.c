inherit "/obj/monster";

#include "/sys/lib.h"

#include <ansi.h>


reset(arg)
{
  object gold,armor,weapon;
int random_index;
int hair_index;
  ::reset(arg);
  if(arg) return;
random_index=random(6);
hair_index=random(4);
set_name( ({"serena","mary","allison","kasey","georgia","brie"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("toolhand");
set_gender("female");
set_short( ({"Serena"+BOLD+" |Well 1 Toolhand|"+NORM+"","Mary"+BOLD+" |Well 1 Toolhand|"+NORM+"","Allison"+BOLD+" |Well 1 Toolhand|"+NORM+"","Kasey"+BOLD+" |Well 1 Toolhand|"+NORM+"","Georgia"+BOLD+" |Well 1 Toolhand|"+NORM+"","Brie"+BOLD+" |Well 1 Toolhand|"+NORM+""})[random_index]);
set_long(
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair but it is mostly covered by "+query_possessive()+"\n"+
"hard hat.  She has a name tag on her chest that says "+query_name()+"\n"+
"|Well #1 Toolhand| and it is slightly covered by reflective gear.\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: "+BLU+"Above Average"+NORM+"\n"+
"Height: Average\n"+
"Demeanor: "+BOLD+"Focused"+NORM+"\n"+
"\n"+
"\n"+
"\n");
set_level(25);
set_hp(400 + random(100));
set_ac(21 + random(3));
set_wc(41 + random(8));
set_al(0);
add_money(2000 + random(1000));
  set_chat_chance(5);
load_chat(query_name()+" looks carefully at one of the wells.\n");
load_chat(query_name()+" jots something down on her clipboard.\n");
armor=clone_object("/players/mo/rig/AC/helmet.c");
  move_object(armor, this_object());
  command("wear helmet", this_object());
armor=clone_object("/players/mo/rig/AC/gear.c");
  move_object(armor, this_object());
  command("wear vest", this_object());

}
