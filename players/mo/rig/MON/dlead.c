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
random_index=random(4);
set_name( ({"tim","frank","tom"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("team leader");
set_gender("male");
set_short( ({"Tim"+BLU+""+BOLD+" |Drill Team Leader|"+NORM+"","Frank"+BLU+""+BOLD+" |Drill Team Leader|"+NORM+"","Tom"+BLU+""+BOLD+" |Drill Team Leader|"+NORM+""})[random_index]);
set_long(
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair that looks very clean.  You can tell\n"+
"that "+query_name()+" mostly stays inside the Command Center.  "+capitalize(query_possessive())+" name tag\n"+
"reads "+query_name()+" |Drill Team Leader|.\n"+
"\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: "+BLU+"Above Average"+NORM+"\n"+
"Height: "+BRED+"Tall"+NORM+"\n"+
"Demeanor: "+BOLD+"Focused"+NORM+"\n"+
"\n"+
"\n");
set_level(30);
set_hp(1400 + random(100));
set_ac(29 + random(10));
set_wc(60 + random(5));
set_al(100);
add_money(10000+random(4000));
  set_chat_chance(5);
load_chat(query_name()+" says: Get to work, y'all!\n");
load_chat(query_name()+" looks confused and says: What am I doing?.\n");
set_chance(25);
set_spell_dam(100);
set_spell_mess1(query_name()+" flails around, swinging his drill pipe!\n");
set_spell_mess2(query_name()+" hits you as he flails his pipe wildly in the air!\n");
}
