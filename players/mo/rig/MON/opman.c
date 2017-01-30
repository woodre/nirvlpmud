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
random_index=random(3);
hair_index=random(4);
set_name( ({"kyle","nate","kendle"})[random_index] );
set_alt_name("worker");
set_race("human");
set_gender("male");
set_alias("manager");
set_short( ({"Kyle "+BRED+"|Operations Manager|"+NORM+"","Nate "+BRED+"|Operations Manager|"+NORM+"","Kendle "+BRED+"|Operations Manager|"+NORM+""})[random_index]);


set_long(
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair that looks very clean.  You can tell\n"+
"that he mostly stays inside the Command Center.  He is wearing a pocket\n"+
"protector and looks very, very nerdy.\n"+
"\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: Average"+NORM+"\n"+
"Height: "+BLU+"Above Average"+NORM+"\n"+
"Demeanor: "+BOLD+"Focused"+NORM+"\n"+
"\n"+
"\n");
set_level(30);
set_hp(1000 + random(100));
set_ac(15 + random(5));
set_wc(40 + random(3));
set_al(150);
add_money(random(1000)+5000);
  set_chat_chance(5);
load_chat(query_name()+" stares at the computer monitors.\n");
add_spell("jab","#MN# "+RED+"c h a r g e s"+NORM+" at you!\n",
"#MN# charges at #TN#!\n",
30,79,"physical");
}
