
#include "std.h"
int drinks, price;

id(str) { return str == "potion" || str == "flask"; }

reset(arg) {
        if (!arg) drinks = 22;
        price = drinks * 20;
}

long() {
  write("This is a small flask which reeks of a curiously powerful black magic,\n"+
  "and you get the chills when you jiggle it around. Apparently, you can\n"+
  "'flick' a monster with some of it...\n"+
	"There are ["+drinks+"] servings left.\n");
}

short() {
  return "A flask of superconcentrated evil [" + drinks + "]";
}

query_save_flag() { return 1; }
query_value() { return price; }

init() {
add_action("use", "flick");
}

use(arg){
object tp;
  object ob;
tp = this_player();
  ob=present(arg, environment(this_player()));
  if(!ob) {
    write("There is no " + arg + " here.\n");
    write("You boggle in confusedment.\n");
  return 1;
  }
  if(!living(ob)) {
    write("Duh. You stop yourself at the last moment from wasting some perfectly\n"+
    "good evil potion.\n");
    return 1;
  }
    if(!ob->query_npc()) {
    write("Nothing happens.\n");
    say((this_player()->query_name()) + " flicks some evil potion on " + (ob->query_name()) + " but nothing happens.\n");
    drinks = drinks - 1;
   check_empty();
    return 1;
  }
    if(creator(ob) != "mizan") {
    write("You whip out the eyedropper and flick some evil on " + (ob->query_name()) + " but nothing happens.\n");
    say((this_player()->query_name()) + " flicks some evil potion on " + (ob->query_name()) + " but nothing happens.\n");
  drinks = drinks - 1;
  check_empty();
  return 1;
  }
  if(ob->query_alignment() < 0) {
  write("That monster looks nasty enough!\n");
  return 1;
  }
  ob->set_al(-2);
  write("You squirt some evil on " + (ob->query_name()) + " and see it grow nasty before your eyes.\n");
  say((this_player()->query_name()) + " squirts "+ (ob->query_name()) + " with some funky black ooze.\n");
  write((ob->query_name()) + " grins biggly.\n");
  say((ob->query_name()) + " grins biggly.\n");
  if(1==random(20) && ob->query_level() > 17) {
    ob->set_aggressive(1);
    if(1==random(4)) ob->attack_object(this_player());
  }
  drinks=drinks-1;
  check_empty();
  return 1;
}

check_empty() {
  if(drinks==0) {
  write("You finish the bottle, and it crumbles into dust.\n");
  this_player()->add_weight(-1);
  destruct(this_object());
  return 1;
  }
}
get() { return 1; }

query_weight() { return 1; }
