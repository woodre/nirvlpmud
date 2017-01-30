#include "/players/coldwind/define.h"
inherit "obj/weapon.c";

#define user environment(this_object())->query_name()

int sell;
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("claws");
set_alias("weapon");
set_alt_name("claws_4_sale");
set_sell(1700 + random (300));
set_short(HIY+"Cla"+NORM+YEL+"ws of the a"+HIY+"pes"+NORM);
set_long(YEL+
"    Three sharp blades made from copper alloys.  The blades are\n"+
"pointed from one side, while connected from the other to a ring made\n"+
"of the same material.  You can slide your fingers inside the ring and\n"+
"wield these deadly claws.\n"+NORM);
set_class(16);
set_weight(2);
set_value(600);
set_hit_func(this_object());
/* second part of weapon_hit should deal magical damage - illarion may 2005 */
set_params("magical",0,"magic_hit");
}
set_sell(int n){ sell = n; }
query_sell(){ return sell; }
init(){
    ::init();
	 add_action("magician_sell", "sell");
     }

int W; /* make global to affect both specials*/
weapon_hit(attacker){
W = random(20);
if(W>13)  {
  say(HIY+" \n"+
  "      Sharp claws "+HIR+"SHREDS"+HIY+" "+ attacker->query_name() +"'s chest."+NORM+"\n"+ 
  "          "+RED+ attacker->query_name() +" screams in pain...\n"+
  "                 \n"+NORM);

  write(HIY+"  \n"+
  "      Sharp claws "+HIR+"SHREDS"+HIY+" "+ attacker->query_name() +"'s chest."+NORM+"\n"+ 
  "          "+RED+ attacker->query_name() +" screams in pain...\n"+
  "                 \n"+NORM);
  return 7;
   }
}
/* make seperate so it can return different damage */
magic_hit(attacker) {
if(W>9 && W<14)  {
  say(" \n"+
  "   "+YEL+"Souls of the dead apes encircles "+user+NORM+YEL+"'s claws.\n"+
""+HIY+" The claws glow as it "+HIB+"TEARS"+HIY+" up "+ attacker->query_name() +"'s arm into slices.\n"+
"   \n"+NORM);

  write(" \n"+
  "   "+YEL+"Souls of the dead apes encircles "+user+NORM+YEL+"'s claws.\n"+
""+HIY+" The claws glow as it "+HIB+"TEARS"+HIY+" up "+ attacker->query_name() + "'s arm into slices."+NORM+"\n"+
" \n");
  return 5; /* bump dam up 1 pt because it's randomized seperately from physical dam */
   }
return;
}

magician_sell(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "claws"){
      if(!present("farha", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_sell();
	this_player()->add_money(coins);
	write("Farha smiles happily at you.\n");
	write("She says: I can smash those and use their dust for some of my magical tricks!\n");
	write("She gives you "+coins+" coins and takes the claws from your hands happily!\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   
