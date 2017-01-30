#include "/players/feldegast/closed/shortcut.h"
#include "/players/feldegast/closed/ansi.h"
inherit "obj/armor";
string owner;
reset(arg) {
  set_name("armor");
  set_short("Snakeskin armor");
  set_owner("Feldegast");
  set_long(
    "This is a suit of armor made out of thick snakeskin leather.\n"
  );
  set_ac(4);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(800);
}
wear(str) {
  if(!str) return 0;
  if(!str=="armor") return 0;
  if(owner!=TPN) {
    write("The snakeskin armor won't fit you.\n");
    return 1;
  }
  return ::wear(str);
}
set_owner(str) {
  owner=str;
} 
id(str) {
  return str=="armor"||str=="quest_snake_armor";
}
generic_object() { return 1;}
locker_arg() { return owner; }
locker_init(arg) { owner=arg; }
restore_thing(str) {
  restore_object(str);
  return 1;
}
save_thing(str) {
  save_object(str);
  return 1;
}
query_owner() { return owner; }
