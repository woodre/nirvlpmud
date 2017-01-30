#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("priest");
set_alias("jeserius");
set_alt_name("templar_priest");
set_race("human");
set_short("Jeserius, High Priest of the Templars");
set_long(
"  Looking at this man you see someone of medium height and build, his\n"+
"face care-worn and slightly wrinkled.  He wears the robes of his office\n"+
"with ease, their bleached white material reflecting the incoming light\n"+
"of the domed ceiling overhead.  He wears the cross of the Templars\n"+
"around his neck.\n");
set_level(4);
set_hp(80);
set_al(1000);
set_wc(8);
set_ac(3);
set_aggressive(0);
set_heart_beat(1);
set_chat_chance(5);
  load_chat("Jeserius says: Welcome my friend.\n");
  load_chat("The Templar Priest smiles.\n");
  load_chat("Jeserius comments: It is a fine day, a fine day indeed.\n");
gold = clone_object("obj/money");
gold->set_money(50);
move_object(gold,this_object());
}


heart_beat(){
int x;
object ob;
::heart_beat();		
if(!query_attack() && random(100) < 25){
ob = users();
for (x = 0; x < sizeof(ob); x ++){
	if(present(ob[x], environment()) && living(ob[x]) && present("KnightInvite", ob[x]) &&
	   ob[x]->query_hp() < ob[x]->query_mhp()){
	ob[x]->heal_self(random(5) + 1);
	tell_object(ob[x], "Jeserius reaches out with his holy symbol and touches you...\n"+
	                   "You feel a warmth travel into your body.\n");
	                   }
                       }
                    }
  	          }	
  	          