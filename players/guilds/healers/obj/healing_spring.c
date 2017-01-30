#define tp this_player()
#define tpn tp->query_name()

int rate;
int uses;

id(str) { return str == "fountain" || str == "healing"; }

short() { return "Healing Spring"; }

long() { write("A fountain of water shoots up from the ground.\nYou may drink from it\n"); }
 
set_heal(a) { rate = a; }
set_uses(a) { uses = a; }

reset(arg) { if(arg) return; rate = 1; uses = 1;}

drop() { return 0; }
get() { return 0; } 
 
init() {
  add_action("drink","drink");
}

drink(str) { 
object what;
  if(!str) { write("Drink what?\n"); return 1; }
  if(str == "spring" || str == "water" && this_player()->query_real_name() != "guest") {
     write("You drink from the of Healing Spring.\n");
     uses = uses - 1;
     say(tpn+" drinks from the Healing Spring.\n");
      this_player()->heal_self(rate/2 + random(rate/2));
     if(uses < 1) {  
                   tell_room(environment(this_object()),"The Spring dries up.\n");
                   destruct(this_object()); }
  return 1; }
}

