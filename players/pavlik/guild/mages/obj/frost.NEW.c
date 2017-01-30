#include "/players/pavlik/closed/colors.h"

int amount;

reset(arg){
  if(arg) return;
  amount = 0;
}

short(){ return; }
long(){ write("frost.\n"); }
id(str){ return str == "mage_frost"; }
get(){ return 0; }
drop(){ return 1; }

do_frost(x) {
  amount = x;
  environment()->RegisterArmor(this_object(), ({"other|fire", amount, 0, 0}));
  call_out("undo_frost", 800+random(amount*10));
  return 1;
}

undo_frost() {
  if( !environment(this_object()) || !living(environment(this_object()) ) {
	destruct(this_object());
	return 1;
  }
  tell_room(environment(environment(this_object())),
	"The frost spell ends.\n");
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
  {
    write("You are protected by "+CYN+"stone skin"+NORM+".\n");
  }
  else
    write((string)environment()->query_name()+" is protected by "+
    CYN+"stone skin"+NORM+".\n");
}
