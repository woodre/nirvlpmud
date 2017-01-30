#include "/players/eurale/closed/ansi.h"
#define ETP environment(this_player())
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

set_name("knife");
set_alias("silver knife");
set_short("A sterling silver knife");
set_long(
  "This sterling silver knife was stolen from a valuable collection of\n"+
  "dinnerware.  Its sharp edge make it a weapon but its real worth\n"+
  "can by gotten if you 'barter' it.\n");
set_type("knife");  /*  sword/knife/club/axe/bow/polearm  */
set_class(8);
set_weight(1);
set_value(975);
}

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "knife" || str == "sterling knife") {
  if(wielded == 1) {
    write("You cannot barter a wielded weapon!\n");
    return 1; }
  num = 1900 + random(100);
  write("Sedjak takes the ornate knife and quickly hides it.  He gives\n"+
        "you "+num+" coins and whispers, 'Keep quiet about this.'\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}
