#define tp this_player()
#define tpn tp->query_name()

int rate;

id(str) { return str== "potion" || str == "healing"; }

short() { return "Potion of Healing"; }

long() { write("A light blue liquid swirls inside the small vial.\n"); }
 
set_heal(a) { rate = a; }

query_weight() { return 2; }

reset(arg) { if(arg) return; rate = 1; }

drop() { return 0; }
get() { return 1; } 
 
init() {
  add_action("drink","drink");
}

drink(str) { 
  if(!str) { write("Drink what?\n"); return 1; }
  if(id(str)) {
     write("You down the blue shimmering liquid.\n");
     write("The vial disappears.\n");
     say(tpn+" downs some blue liquid from a small vial.\n");
     tp->heal_self(rate/2 + random(rate/2));
     if(tp == environment(this_object())) tp->add_weight(-2);
     destruct(this_object());
  return 1; }
}

