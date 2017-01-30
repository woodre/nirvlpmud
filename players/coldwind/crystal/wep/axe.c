#include "/players/coldwind/define.h"
inherit "obj/weapon.c";
int sell;
reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("weapon");
set_alt_name("weapon_4_sale");
set_sell(9000 + random (4000));
set_alias("battleaxe");
set_long(RED+
"  This is a heavy red crystal battleaxe. The blade is very\n"+
"sharp and the hadle is long. It would require two hands as\n"+
"well as great strength to be able to use such a weapon.\n"+NORM);
set_type("axe");
set_class(20);
set_weight(5);
set_value(10000);
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
      write("You need both hands free for this axe.\n");
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
int W;
object user;
user = environment(this_object())->query_name();
W = random(20);
if( random(tp->query_attrib("str")) > 25)
if(W>14)  {
  say(RED+"     "+user+NORM+RED+" swings his battleaxe with mighty strength...\n"+
  " \n");
  say("             "+HIK+"(-"+HIR+"="+HIK+"-"+HIR+"="+HIK+"-"+HIR+"="+HIK+"=-)"+HIR+" W R E C K "+HIK+"(-"+HIR+"="+HIK+"-"+HIR+"="+HIK+"-"+HIR+"="+HIK+"=-)\n"+
          ""+NORM+"   \n");

  write(RED+"     You swing you battleaxe with mighty strength...\n"+
  " \n");
  write("           "+HIK+"(-"+HIR+"="+HIK+"-"+HIR+"="+HIK+"-"+HIR+"="+HIK+"=-)"+HIR+" W R E C K "+HIK+"(-"+HIR+"="+HIK+"-"+HIR+"="+HIK+"-"+HIR+"="+HIK+"=-)\n"+
        "        "+NORM+"\n");
		attacker->heal_self(-20);
  return 7;
   }
if(W>10)  {
if( random(tp->query_attrib("str")) > 15)
  say(HIK+user+NORM+HIR+" DEVISTATES "+HIK+attacker->query_name() +NORM+HIK+" with a powerful attack.\n"+ 
  ""+NORM+RED+attacker->query_name()+NORM+RED+"'s mouth drops in pain and surprise."+NORM+"\n");

  write(HIK+"You"+HIR+" DEVISTATE "+HIK+attacker->query_name() +NORM+HIK+" with a powerful attack.\n"+ 
  ""+NORM+RED+attacker->query_name()+NORM+RED+"'s mouth drops in pain and surprise."+NORM+"\n");
 return 3;
   }
   if(W>7)  {
          if(attacker->query_hp()*100/attacker->query_mhp() < 20) {
   if( random(tp->query_attrib("str")) > 28)

  say(HIR+user+" axe blazes deep red.\n"+
      NORM+RED+"The battle axe drinks from "+attacker->query_name()+NORM+RED+"'s blood.\n"+NORM);

  write(HIR+"Your axe blazes deep red.\n"+
      NORM+RED+"The battle axe drinks from your weakened foe's blood.\n"+NORM);
  return 7;

attacker->heal_self(-random(25));

   }
   }
return;
}
magician_sell(string str){
  int coins;
      if(!str){ write("What?\n"); return 1; }
      if(str == "axe", "battleaxe"){
      if(!present("farha", environment(this_player()))){
		write("What?\n");
		return 1;
	}
	coins = this_object()->query_sell();
	this_player()->add_money(coins);
	write("Farha beams with happiness as she eyes the weapon.\n");
	write("She says: Great, just what i need!\n");
	write("She gives you "+coins+" coins and takes the battleaxe from your hands happily!\n");
	destruct(this_object());
	return 1;
     }
     write("What?\n");
     return 1;
}   


