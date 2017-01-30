/*  hemlock - alignment potion */
#include "/players/eurale/defs.h"

reset(arg) {
  if(arg) return;
}

long() { write(
  "This powerful extract comes from the poisonous hemlock tree.  It\n"+
  "has been boiled down to a syrupy thickness and is the color of jet\n"+
  "black ink.  It also emits a nauseating odor.\n");
}

short() { return
  BOLD+"extract"+NORM+" of "+BOLD+"hemlock"+NORM; }

query_weight() { return 1; }

query_value() { return 250; }

init() {
  add_action("drink","drink");
}

drink(str) {
  if(str == "extract" || str == "hemlock") {
    if(environment() != this_player()) return;

/*  Non Vampires  */
if(!present("vampire fangs",TP)) {
  write("You swallow the "+BOLD+"black, gelatinous liquid"+NORM+
        " and immediately RETCH!\n");
  TP->heal_self(-random(30));
  say(capitalize(TPRN)+" swallows a"+BOLD+
         "vile black liquid"+NORM+" and RETCHES.\n");
  destruct(this_object());
  return 1; }

/* Vampire Guild Only */
  TP->set_al_title("Lord of Darkness");
  if(!present("tpass",TP))
    move_object(clone_object("players/eurale/VAMPIRES/OBJ/tpass"),TP);
  write("You let the "+BOLD+"black, gelatinous liquid"+NORM+
            " drip into your mouth...\n"+
        "You GAG as you swallow and then an evilness settles over you.\n");
  FANGS->tell_my_room(capitalize(TPRN)+" swallows a "+BOLD+
    "black, gelatinous liquid"+NORM+" and shivers violently.\n");
  destruct(this_object());
  return 1; }
}

get() { return 1; }

id(str) { return str == "extract" || str == "hemlock"; }
