#include "/players/pavlik/closed/colors.h"

int amount;

reset(arg){
  if(arg) return;
  amount = 0;
}

short(){ return; }
long(){ write("stone_skin.\n"); }
id(str){ return str == "stone_skin"; }
get(){ return 0; }
drop(){ return 1; }

do_stone_skin(x)
{
  amount = x;
  environment()->RegisterArmor(this_object(), ({"physical", amount, 0, 0}));
  call_out("remove_skin", 800+random(amount*10));
  return 1;
}

remove_skin()
{
  if(environment()) {
	environment()->RemoveArmor(this_object());
	tell_object(environment(this_object()), CYN+
	  "Yout Stone Skin spell wears off.\n"+
	  "You feel your flesh soften and return to normal as the spell fades.\n"+NORM);
  }
  destruct(this_object());
  return 1;
}

remove_object()
{
  if(environment())
	environment()->RemoveArmor(this_object());
}

extra_look()
{
  if(environment()==this_player())
	write("You are protected by "+CYN+"stone skin"+NORM+".\n");
  else
	write((string)environment()->query_name()+" is protected by "+
	  CYN+"stone skin"+NORM+".\n");
}

