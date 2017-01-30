/* healdrv.c: heal driver 
 * Call the set_ functions in reset() after ::reset() 
*/
#include "defs.h"
 
string action_name;
int heal_amt;
int intox_amt;
int intox_type;
string *local_id;
string short_desc, long_desc;
string my_msg, other_msg;
status dest_on_empty, dest_on_drop;
int uses,used;
int value;
 
is_member(str, arr) {
  int i, so;
  so = sizeof(arr);
  for(i = 0; i < so; i++) {
    if(arr[i] != 0 && arr[i] == str)
      return 0;
  }
  return -1;
}
get() { return 1; }
id(str) { return (is_member(str, local_id) == 0);  }
query_value() { return value; }
long() { write(long_desc); }
short() { 
  string sh;
  sh = short_desc;
  if(this_player()->query_level() >= 40) 
    sh += " <"+(uses-used)+" uses, "+heal_amt+" heal, "+intox_amt+" intox>"; 
  return sh;  
}
drop() {
  if(dest_on_drop) destruct(this_object());
  return 0;
}
query_weight() { return uses/3; }
reset(arg) {
  if(arg)
    return ;
  long_desc = short_desc = "A generic heal";
  local_id = ({"heal","generic heal"});
  action_name = "heal";
}
/* array of strings */
set_id(arr)   { local_id = arr; }
set_short(s)  { short_desc = s; }
set_long(l)   { long_desc  = l; }
set_value(x)  { value      = x; }
set_usage(s)  { action_name= s; }
set_type(x)   { intox_type = x; }
set_intox(x)  { intox_amt  = x; }
set_heal(x)   { heal_amt   = x; }
set_uses(x)   { uses       = x; }
set_my_msg(s) { my_msg     = s; }
set_o_msg(s)  { other_msg  = s; }
set_ddest(x)  { 
  dest_on_drop = x;
}
set_edest(x)  {
  dest_on_empty = x;
}
init() {
  add_action("use_heal",action_name);
}
use_heal(str) {
  if(environment(this_object()) != this_player() || !id(str)) 
    return 0; 
  if((uses-used) < 1) {
    write("There doesn't appear to be any left.\n");
    return 1;
  }
  if(intox_type == DRINK) {
    if(!this_player()->drink_alcohol(intox_amt)) {
      write("You try to, but end up loosing most of it in the process.\n");
      say(this_player()->query_name()+" just can't handle his drinks.\n");
      return 1;
    }
  } else if(intox_type == FOOD) {
    if(!this_player()->eat_food(intox_amt)) {
      write("You make yourself sick trying to "+query_verb()+" it.\n");
      say(this_player()->query_name()+" nearly throws up.\n");
      return 1;
    }
  } else if(intox_type == SOAK) {
    if(!this_player()->drink_soft(intox_amt)) {
      write("You start foaming at the mouth from all this pop.\n");
      say(this_player()->query_name()+" burps up some "+str+".\n");
      return 1;
    }
  }
  this_player()->heal_self(heal_amt);
  write(my_msg);
  say(this_player()->query_name()+" "+other_msg);
  used++;
  if(used == uses) {
    write("You finish off the "+str+".\n");
    if(dest_on_empty) {
      write("The container falls to the ground and erodes into dust.\n");
      destruct(this_object());
    }
  }
  return 1;
}
