#include "def.h"

/* Healer Guild Object
   Based on code from Mythos healers
   recoded by Illarion
   August 2015
*/

/* Saved Variables */
int light_points;
int default_heal_amount;

/* Non-Saved Variables */
static int healer_level;
static int healer_piety;

object usr, gob;

id(str) {
    return str == "healerob" 
      || str == "mythos_healer" 
      || str == "healer_staff" 
      || str == "GI" 
      || str == GUILD_OB_ID 
      || str == "staff" 
      || str == "no_spell"; 
}

drop () { return 1; }
get() { return 1; }

short() { return "Healer's Staff"; }

long() {
write("A long white staff of stout oak.\n"+
	  "It is the tool of the Healer.\n"+
	  "hhelp will give you the help files.\n");
}

reset(arg) {
  if(arg) return;
}

query_default_heal_amount() {
  if(default_heal_amount > healer_level)
    default_heal_amount = healer_level;
  return default_heal_amount;
}

set_default_heal_amount(x) {
  default_heal_amount = x;
  return query_default_heal_amount();
}

query_max_heal_amount() {
  return healer_level;
}

init() {
  if(this_player() != environment())
    return;
  
  usr=TP;
  gob=TO;
  gob->calc_levels();
  DAEM->load_commands(usr, gob);
  add_action("cmd_renew","renew");
}

cmd_renew() {
  destruct(gob);
  move_object(clone_object(GOB_PATH), TP);
  return 1;
}

load_command(fun, cmd)
{
  add_action(fun, cmd);
}

healer_cmd(str) {
  return DAEM->exec_command(str, gob);
}

calc_levels() {
  healer_level = usr->query_level() + usr->query_extra_level();
  if(healer_level > 40)
    healer_level = 40;
  healer_piety = usr->query_attrib("pie");
  
}

query_light_points() {
  return light_points;
}

add_light_points(x) {
  light_points += x;
  return query_light_points();
}

query_healer_level() {
  return healer_level;
}

query_healer_piety() {
  return healer_piety;
}

