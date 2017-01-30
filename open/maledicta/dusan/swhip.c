#include "/players/maledicta/ansi.h"
inherit "obj/weapon.c";
int collect;

#define user environment(this_object())
int collect;
reset(arg){
  ::reset(arg);
  if (arg) return;
set_collect(random(3000) + 3000);
set_name("whip");
set_alias("shadows");
set_short(""+BOLD+""+MAG+"Whip"+BLK+" of "+MAG+"Shadows"+NORM+"");
set_long(
  "  This weapon was once wielded by the Archangel of Shadows.  It is made\n"+
  "from some unknown material that seems extremely strong and very capable\n"+
  "when dealing damage. The handle is wrapped in a fine red leather, and a\n"+
  "small strap dangles from its hilt. The end is set with a large adamantium\n"+
  "barb, weighted perfectly for flaying flesh.\n"); 

set_type("knife");
set_class(18);
set_weight(2);
set_value(3000);
set_hit_func(this_object());
set_save_flag(1);
}
set_collect(int n){ collect = n; }
query_collect(){ return collect; }


init(){
   ::init();
   add_action("collect_reward", "collect");
   }	
weapon_hit(attacker){
 int chance;
chance = random(100);
if(chance < 30){ 
 
write(
""+BOLD+""+BLK+"You lash out at "+attacker->query_name()+""+NORM+"\n"+             
""+HIR+"\n\n\n"+              
"                                 .             .         \n"+                            
"                               /             /          \n"+
"                      /      /      /      /         /\n"+
"                     /      /      /      /         /\n"+   
"                    /      /      /      /         /\n"+
"                         /             /\n"+
""+NORM+"\n"+
""+BOLD+""+BLK+"                                Flaying their flesh!"+NORM+"\n");                                                  
say(
""+BOLD+""+BLK+""+user->query_name()+" lashes out at "+attacker->query_name()+""+NORM+"\n");             
say(""+HIR+""+              
"                                 .             .         \n");                            
say("                               /             /          \n");
say("                      /      /      /      /         /\n");
say("                     /      /      /      /         /\n");   
say("                    /      /      /      /         /\n");
say("                         /             /            \n");
say("                       .             .             \n");
say(""+NORM+"\n");
say(""+BOLD+""+BLK+"                                Flaying their flesh!"+NORM+"\n");                                                  
 return 9;
 }
return;
}

collect_reward(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "bounty"){
      if(!present("eghyron", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_collect();
	this_player()->add_money(coins);
	write("Eghyron congratulates you.\n");
	write("He says: You defeated the Archangel of Shadows, MOST impressive!\n");
	write("He hands you "+coins+" coins for your most excellent work!\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   
