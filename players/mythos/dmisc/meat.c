#include "/players/mythos/closed/ansi.h"
#define tp this_player()

id(str) { return str == "meat" || str == "drake's meat"; }

drop() { return 0; }
get() { return 1; }

query_weight() { return 3; }
query_save_flag() { return 0; }
query_value() { return 9000; }

short() { return "Drake's Meat"; }

long() { write("A dark piece of drake's flesh.\n"+
               "It seems a bit stringy and tough but\n"+
               "it seems edible.\n");
        }
        
init() {
  add_action("eat","eat");
}

eat(str) {
int amount;
  if(!str) return 0;
  if(id(str)) {
    if(tp->query_hp() > tp->query_mhp()*9/10) {
      write("You dont think you want to waste the meat.\n");
    return 1; }
    amount = tp->query_mhp()*9/10 - tp->query_hp();
    if(amount > 30) amount -= random(10);
    write("You eat the meat.\nIts a bit tough and spicey but it goes down.\n");
    say(tp->query_name()+" eats some rather tough dark meat.\n");
    tp->heal_self(amount);
    write("\nSuddenly you feel a lot better.\n");
    if(environment(this_object()) == tp) tp->add_weight(-3);
    destruct(this_object());
  return 1; }
}
