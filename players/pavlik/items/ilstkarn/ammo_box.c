#include <ansi.h>

int ammo;

reset(arg){
  if(arg) return;
  ammo = 120+random(120);
}

id(str) {
  return str == "ammo" || str == "box" || str == "ammo box" ||
  str == "bullets" || str == "gun_clip";
}

long(){
  write(
  "A small green ammunition box.  The sturdy metal case\n"+
  "is used to store rounds of machine-gun ammunition.\n");

  if(ammo > 10) {
    write("A long strand of .60 caliber bullets is inside.\n");
    write("There are "+ammo+" bullets in the box.\n");
  }
  else if(ammo > 0) {
    if(ammo == 1) write("There is 1 bullet left in the box.\n");
    else write("There are "+ammo+" bullets in the box.\n");
  }
  else {
    write("The box is empty.\n");
  }
  return;
}

short(){
  return "An ammo box";
}

get() {
  if(present("gun_clip", this_player())) {
    write("You take the bullets and put them in your existing box.\n");
    present("gun_clip", this_player())->add_ammo(ammo);
    destruct(this_object());
    return;
  }
  return 1;
}

query_weight() {
  return 3;
}

query_value() {
  return 1 * ammo;
}

query_save_flag() {
  return 1;
}

query_ammo() { return ammo; }

add_ammo(i) {
  if(!environment())
    return 1;

  if(environment()->query_ilstkarn() && i < 1) {
    return 1;
  }

  ammo += i;
  if(ammo < 0) ammo = 0;

  if(ammo == 0) {
    tell_object(environment(), "You run out of ammunition.\n");
    environment()->add_weight(-3);
    destruct(this_object());
    return 1;
  }
  return 1;
}

