#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

#define user environment(this_object())->query_name()

int sell;
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("stick");
set_alias("weapon");
set_type("polearm");
set_alt_name("weapon_4_sale");
set_sell(2000 + random (1000));
set_short(HIC+"C"+NORM+CYN+"rystal "+HIC+"S"+NORM+"tick"+NORM);
set_long(CYN+
"    A crystal light stick gleams under the light. It's about 6 feet\n"+
"long and doesn't look deadly, but in the hands of a crystal guard,\n"+
"it would be a powerful weapon.\n"+NORM);
set_class(15);
set_weight(2);
set_value(1000);
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
  "   "+NORM+CYN+user+" jumps forward and "+HIR+"CRUSHES"+NORM+CYN+" the distracted foe.\n"+
  " \n"+NORM);

  write(" \n"+
  ""+HIC+"Wicked sharp pieces of crystal attack "+attacker->query_name()+NORM+HIC+" from one side.\n"+
  "    "+NORM+CYN+"You jump forward and "+HIR+"CRUSH"+NORM+CYN+" your distracted foe.\n"+
  " \n"+NORM);

  return 4;
   }
return;
}
magician_sell(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "stick"){
      if(!present("farha", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_sell();
	this_player()->add_money(coins);
	write("Farha smiles happily at you.\n");
	write("She says: Nice...I was looking for some crystal stick for the knights to train with!\n");
	write("She gives you "+coins+" coins and takes the stick from your hands happily!\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   