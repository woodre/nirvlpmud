/*
  paint_grenade.c
*/

#include "/players/eurale/closed/ansi.h"
#define TPRN this_player()->query_real_name()
inherit "/obj/treasure";

int pin_pulled;

reset(arg) {
  if(arg) return 0;
set_id("paint grenade");
set_alias("grenade");
set_short("paint grenade");
set_value(1);
set_weight(1);
pin_pulled = 0; }

long() { write(
  "This is a deadly paint grenade designed to splatter paint all\n"+
  "over an intended target. ");
if(pin_pulled) write("The pin has been removed!\n");
else write("\n"+
  "  'pull pin' to activate the grenade\n"+
  "  'throw grenade at <name>' to toss the paint grenade.\n");
}

init() {
  ::init();

  add_action("pull_pin",      "pull");
  add_action("throw_grenade", "throw");
}

pull_pin(str) {
if(str != "pin") { write("Pull what?\n"); return 1; }
  if(pin_pulled) {
    write("The pin has already been pulled.\n");
    return 1; }
write("You pull the pin and release the handle.\n");
say(capitalize(TPRN)+" pulls the pin from the paint grenade handle.\n");
pin_pulled = 1;
call_out("grenade_explode", 10);
return 1;
}

throw_grenade(str) {
object target_obj;
string target_name;
target_name = 0;
sscanf(str, "grenade at %s", target_name);
if(!str || !target_name) return 0;
target_obj = find_living(target_name);
if(!target_obj || target_obj == this_player()) {
  write("You consider throwing your grenade but can't find a target.\n");
  return 1; }
if(target_obj->query_level() > 20) {
  write("Are you nuts???  You think better of it and hang on to it.\n\n");
  return 1; }
write("You rear back and heave the grenade at "+target_name+".\n");
say(capitalize(TPRN)+
    " throws a paint grenade off into the distance.\n");
move_object(this_object(), target_obj);
tell_object(target_obj,
  BOLD+capitalize(TPRN)+" throws a grenade at you!"+NORM+"\n\n");
return 1;
}

grenade_explode() {
object obj, paint_obj;
string color;
int num;
num = random(5);
  if(num == 0) color = "red";
  if(num == 1) color = "yellow";
  if(num == 2) color = "blue";
  if(num == 3) color = "green";
  if(num == 4) color = "white";

  /* cover player */
paint_obj = clone_object("/players/eurale/OBJ/paint.c");
paint_obj->start_bucket_stuff(num);
move_object(paint_obj, environment(this_object()));

  /* cover everyone/everything else */
obj = first_inventory(environment(environment(this_object())));
  while (obj) {
    paint_obj = clone_object("/players/eurale/OBJ/paint");
    paint_obj->start_bucket_stuff(num);
    move_object(paint_obj, obj);
    obj=next_inventory(obj);
  }
  tell_room(environment(environment(this_object())),
    "\nWhomp!  A grenade explodes and splashes "+color+
    " paint everywhere.\n\n");
  destruct(this_object());
  return 1;
}
