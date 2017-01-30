#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

#define user environment(this_object())->query_name()

int sell;
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("spear");
set_alias("weapon");
set_type("polearm");
set_alt_name("weapon_4_sale");
set_sell(5000 + random (1000));
set_short(HIC+"C"+NORM+CYN+"rystal "+HIC+"S"+NORM+"pear"+NORM);
set_long(CYN+
"    You are checking a long, yet very light crystal spear.\n"+
"Its pointy blade gleams under the light wickedly. You recall\n"+
"the stories you heard about the crystalline plane.\n"+NORM);
set_class(17);
set_weight(2);
set_value(2000);
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
  "    Wicked pointy crystal pieces encircle "+attacker->query_name() +"\n"+
  ""+NORM+CYN+attacker->query_name()+NORM+RED+" SCREAMS"+CYN+" as the pointy pieces make their strikes.\n"+
  " \n"+NORM);

  write(HIC+" \n"+
  "    Wicked pointy crystal pieces encircle "+attacker->query_name() +"\n"+
  ""+NORM+CYN+attacker->query_name()+NORM+RED+" SCREAMS"+CYN+" as the pointy pieces make their strikes.\n"+
  " \n"+NORM);
 return 7;
   }
if(W>9)  {
  say(" \n"+
  ""+HIC+"Wicked sharp pieces of crystal attack "+attacker->query_name()+NORM+HIC+" from one side.\n"+
  "   "+NORM+CYN+user+" jumps forward and "+HIR+"PIERCES"+NORM+CYN+" the distracted foe.\n"+
  " \n"+NORM);

  write(" \n"+
  ""+HIC+"Wicked sharp pieces of crystal attack "+attacker->query_name()+NORM+HIC+" from one side.\n"+
  "    "+NORM+CYN+"You jump forward and "+HIR+"PIERCE"+NORM+CYN+" your distracted foe.\n"+
  " \n"+NORM);

  return 4;
   }
return;
}
magician_sell(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "spear"){
      if(!present("farha", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_sell();
	this_player()->add_money(coins);
	write("Farha smiles happily at you.\n");
	write("She says: Nice...I was looking for some crystal spears for the knights of the village!\n");
	write("She gives you "+coins+" coins and takes the spear from your hands happily!\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   