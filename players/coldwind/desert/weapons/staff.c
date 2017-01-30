#include "/players/coldwind/define.h"
inherit "obj/weapon.c";
int sell;
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("staff");
set_alias("weapon");
set_alt_name("weapon_4_sale");
set_sell(3200 + random (1700));
set_short(HIK+"Staff of the giant"+NORM);
set_long(HIK+
" A huge black staff made from a strange material. One word carved toward \n"+
"the middle of the weapon in dark letters....\n"+
" \n"+
""+HIK+"                           A S H G A N                 \n"+NORM);
set_type("polearm");
set_class(18);
set_weight(4);
set_value(1000);
/* <ill>
set_hit_func(this_object());
*/
set_params("other|dark",0,"dark_hit");
}
set_sell(int n){ sell = n; }
query_sell(){ return sell; }
init(){
    ::init();
	 add_action("magician_sell", "sell");
     }

dark_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(20);
if(W>14)  {
  say(WHT+"You feel presence of dark forces.\n"+
  " \n"+
  " \n"+
  "              "+HIK+ attacker->query_name() + " is slammed to the ground by an invisible force."+NORM+"\n"+ 
  " \n"+
  " \n");

  write(WHT+"You feel presence of dark forces.\n"+
  " \n"+
  " \n"+
  "              "+HIK+ attacker->query_name() + " is slammed to the ground by an invisible force."+NORM+"\n"+
  " \n"+
  " \n");
  return 7;
   }
if(W>10)  {
  say(HIK+"Dark mist encircles "+user+"'s staff."+NORM+"\n"+
"                         "+HBWHT+HIB+" A S H G A N "+NORM+"\n"+ 
""+HIK+"                                "+ attacker->query_name() + " is hit by an invisible force."+NORM+"\n");

  write(HIK+"Dark mist encircles your staff."+NORM+"\n"+
"                         "+HBWHT+HIB+" A S H G A N "+NORM+"\n"+
""+HIK+"                                Your foe is hit by an invisible power."+NORM+"\n");
  return 4;
   }
return;
}
magician_sell(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "staff"){
      if(!present("farha", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_sell();
	this_player()->add_money(coins);
	write("Farha beams with happiness as she eyes the weapon.\n");
	write("She says: Great, just what i need!\n");
	write("She gives you "+coins+" coins and takes the staff from your hands happily!\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   

