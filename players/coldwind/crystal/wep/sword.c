#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

#define user environment(this_object())->query_name()

int sell;
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("broadsword");
set_alias("weapon");
set_type("sword");
set_alt_name("weapon_4_sale");
set_sell(4000 + random (1500));
set_short(HIC+"C"+NORM+CYN+"rystal "+HIC+"B"+NORM+"roadsword"+NORM);
set_long(CYN+
"    You are looking at a long crystal sword. It's wide double\n"+
"edged blade gleams madly and ends with a wicked point, while the \n"+
"crystal hilt has very small curves for better grip.\n"+NORM);
set_class(19);
set_weight(3);
set_value(1500);
set_hit_func(this_object());
}
set_sell(int n){ sell = n; }
query_sell(){ return sell; }
init(){
    ::init();
	 add_action("magician_sell", "sell");
     }
	
weapon_hit(attacker){
int W;
W = random(20);
if(W>13)  {
  say(HIC+" \n"+
  "        The broadsword twirls madly...\n"+ 
  ""+NORM+RED+"      ~~~~~~~~~~~~"+HIC+"S L A S H"+NORM+RED+"~~~~~~~~~~~~\n"+
  "        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);

  write(HIC+" \n"+
  "        The broadsword twirls madly...\n"+ 
  ""+NORM+RED+"      ~~~~~~~~~~~~"+HIC+"S L A S H"+NORM+RED+"~~~~~~~~~~~~\n"+
  "        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
 return 7;
   }
if(W>9)  {
  say(HIC+" \n"+
  "        The broadsword twirls madly...\n"+ 
  ""+NORM+RED+"     ~~~~~~~~~~~~"+HIC+"C L E A V E"+NORM+RED+"~~~~~~~~~~~~\n"+
  "        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);


  write(HIC+" \n"+
  "        The broadsword twirls madly...\n"+ 
  ""+NORM+RED+"     ~~~~~~~~~~~~"+HIC+"C L E A V E"+NORM+RED+"~~~~~~~~~~~~\n"+
  "        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);


  return 4;
   }
return;
}
magician_sell(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "sword"){
      if(!present("farha", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_sell();
	this_player()->add_money(coins);
	write("Farha checks the broadsword carefully.\n");
	write("She says: Nice weapon...Of course i'll buy it.\n");
	write("She gives you "+coins+" coins and puts the broadsword away.\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   