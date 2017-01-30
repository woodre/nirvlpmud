#include "/players/coldwind/define.h"
inherit "obj/weapon.c";
int sell;
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("weapon");
set_alt_name("weapon_4_sale");
set_sell(5000 + random (2000));
set_alias("daggers");
set_long(RED+
"  This is a heavy red crystal battleaxe. The blade is very\n"+
"sharp and the hadle is long. It would require two hands as\n"+
"well as great strength to be able to use such a weapon.\n"+NORM);
set_type("dagger");
set_class(18);
set_weight(5);
set_value(5000);
set_hit_func(this_object());
}
query_save_flag(){ return 1; }
short(){
if (wielded) 
{
return 
HIR+"B"+NORM+RED+"erserker "+HIR+"B"+NORM+RED+"attleaxe"+NORM+" (wielded with both hands)";
}
else {
 return
HIR+"B"+NORM+RED+"erserker "+HIR+"B"+NORM+RED+"attleaxe"+NORM;
}
}

status id(string str) {
  if(str == "notarmor" && (string)previous_object()->query_type() == "shield")
    return 1;
  return (status)::id(str);
}

status wield(string str) {
  object *inv;
  int x,s;
  if(!id(str))
    return 0;
  if(environment()!=tp)
    return 0;
  if(present("notweapon",this_player())) {
    write("You need both hands to hold the axe.\n");
    return 1;
  }
  if (wielded) {
    write("You already wield it!\n");
    return 1;
  }
  inv=all_inventory(tp);
  s=sizeof(inv);
  for(x=0;x<s;x++) {
    if((string)inv[x]->query_type() == "shield" && inv[x]->query_worn()) {
      write("You need both hands free to wield these daggers.\n");
      return 1;
    }
  }
  wielded_by = this_player();
  call_other(this_player(), "wield", this_object(), silentwield);
  wielded = 1;
 return 1;
}
set_sell(int n){ sell = n; }
query_sell(){ return sell; }
init(){
    ::init();
	 add_action("magician_sell", "sell");
     }

weapon_hit(attacker){
    int dam;
	object user;
	user = environment(this_object())->query_name();
    
    if( (tp->query_attrib("ste")) > 15)

        dam = random(45);
        if(dam > 3)
		say(""+user+" missed "+attacker->query_name()+".\n");
		write("You missed "+attacker->query_name()+".\n");
        if(dam > 7)
		    say(""+user+" "+HIW+"scratched"+NORM+" "+attacker->query_name()+"'s skin.\n");
            write("You "+HIW+"scratched"+NORM+" "+attacker->query_name()+"'s skin.\n");

        if(dam > 10)
		    say(""+user+" "+HIW+"grazed"+NORM+" "+attacker->query_name()+" with a weak attack.\n");
            write("You "+HIW+"grazed"+NORM+" "+attacker->query_name()+" with a weak attack.\n");
        if(dam > 13)
		    say(""+user+" "+HIW+"nicked"+NORM+" "+attacker->query_name()+" with a slow attack.\n");
            write("You "+HIW+"nicked"+NORM+" "+attacker->query_name()+" with a slow attack.\n");
          if(dam > 17)
		    say(""+user+" "+HIW+"stabed"+NORM+" "+attacker->query_name()+" in the arm causing a minor wound.\n");
            write("You "+HIW+"stabed"+NORM+" "+attacker->query_name()+" in the arm causing a minor wound.\n");
		 if(dam > 21)
		    say(""+user+" "+HIW+"cut"+NORM+" "+attacker->query_name()+"'s chest causing a deep wound.\n");
            write("You "+HIW+"cut"+NORM+" "+attacker->query_name()+"'s chest causing a deep wound.\n");
		 if(dam > 25)
		    say(""+user+" "+HIW+"STABED"+NORM+" "+attacker->query_name()+" in the chest with a quick strike.\n");
            write("You "+HIW+"STABED"+NORM+" "+attacker->query_name()+" in the chest with a quick strike.\n");
		 if(dam > 30)
		    say(""+user+" "+HIW+"MANGLED"+NORM+" "+attacker->query_name()+" with a blinding strike.\n");
            write("You "+HIW+"MANGLED"+NORM+" "+attacker->query_name()+" with a blinding strike.\n");
		 if(dam > 35)
		    say(""+user+" "+HIW+"MASSACRED"+NORM+" "+attacker->query_name()+" with a sequence of quick stabs.\n");
            write("You "+HIW+"MASSACRED"+NORM+" "+attacker->query_name()+" with a sequence of quick stabs.\n");
		if(dam > 40)
		    say(""+user+" "+HIW+"BUTCHERED"+NORM+" "+attacker->query_name()+" into little pieces.\n");
            write("You "+HIW+"BUTCHERED"+NORM+" "+attacker->query_name()+" into little pieces.\n");

return dam;
}
magician_sell(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "daggers","dagger"){
      if(!present("farha", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_sell();
	this_player()->add_money(coins);
	write("Farha beams with happiness as she eyes the weapon.\n");
	write("She says: Wow...These are very nice daggers!:)\n");
	write("She gives you "+coins+" coins and takes the daggers from your hands happily!\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   


