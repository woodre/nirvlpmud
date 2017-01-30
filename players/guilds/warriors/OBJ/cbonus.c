#include <ansi.h>

get(){ return 1; }
drop(){ return 1; }

query_weight(){ return 0; }
query_value(){ return 0; }

string owner;
int duration;
int power;

set_power(int i, string wname){ duration = i; power = random(i) + i; owner = wname; }

start(){ call_out("dest", duration); }

dest(){
 destruct(this_object());
 }

id(str){ return str == "knight_command_bonus" || str == "generic_wc_bonus"; }

gen_wc_bonus(){
  tell_object(environment(),
  HIW+"[ "+NORM+BOLD+"Battle Command"+HIW+" ]"+NORM+"\n"+
  HIW+"You follow the commands of "+capitalize(owner)+" and strike with precision!\n"+NORM);
return power * 2;
  }
