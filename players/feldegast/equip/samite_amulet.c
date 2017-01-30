#include "/players/feldegast/defines.h"
#define CHARGES 6
#define STRENGTH 6
#define VAL_PER 300

int charges;

inherit "obj/armor";
reset(arg) {
  if(arg) return;
  set_name("amulet");
  set_short("Samite Amulet");
  set_long(
"A prism hangs amidst the twin coiling dragons of Order and Chaos,\n\
the symbol of the Order of Samite.  You may use the amulet to 'purify'\n\
yourself if you wish.\n");
  set_ac(1);
  set_type("amulet");
  set_weight(1);
  charges=CHARGES;
}
query_value() {
  return charges*VAL_PER;
}

init() {
  ::init();
  add_action("cmd_purify","purify");
}
int cmd_purify(string str) {
  if(charges <= 0) return 0;
  write("You clutch the Samite Amulet in your hands and feel its purifying\n"+
        "energy sweep through you.\n");
  say(TPN+" clutches "+TP->query_possessive()+" Samite Amulet.\n");
  TP->add_stuff(-3);
  TP->add_soak(-3);
  charges--;
  return 1;
}
locker_arg() {
  return charges+"";
}
locker_init(arg) {
  sscanf(arg,"%d",charges);
}
do_special(owner) {
  if(!random(50)) {
    tell_object(owner,"Your Samite Amulet bathes you in a healing glow.\n");
    return 2;
  }
  if(!random(30)) {
    tell_object(owner,"You clutch your Samite Amulet and feel luckier.\n");
    return 1;
  }
}


generic_object() { return 1; } 

restore_thing(str) {
  restore_object(str);
  return 1;
}

save_thing(str) {
  save_object(str);
  return 1;
}
