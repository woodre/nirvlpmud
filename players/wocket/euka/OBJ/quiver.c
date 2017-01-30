#include "/players/wocket/closed/ansi.h"
int number;

get(){ return 1; }
drop(){ return 0; }
id(str){ return str == "bundle" || str == "arrows" || str == "bundle of arrows" || str == "w_arrows"; }
reset(arg){
  if(arg){ return; }
  number = 0;
}
short(){ return "A bundle of arrows ["+number+"]"; }
add_arrows(i){ number = number+i; }
set_arrows(i){ number = i; }
query_arrows(){ return number; }

init(){
object alt_set;
int num;
  if(environment(this_object()))
  alt_set = present("w_arrows 2",environment(this_object()));
  if(alt_set){
    num = alt_set->query_arrows();
  add_arrows(num);
  destruct(alt_set);
  write("You collect the arrows up into one bundle.\n");
  say(this_player()->query_name()+" collects the arrows up into one bundle.\n");
  }
}
