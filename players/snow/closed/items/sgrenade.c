/* Stun grenade usable by cyberninjas */

#define TP this_player()
#define CAP capitalize
#define TPN CAP(TP->query_name())
#define TR tell_room
#define ENV environment
#define GRENOB "/players/snow/closed/items/stunob.c"

id(str) { return str == "shock grenade" || str == "grenade" ||
                 str == "black ball" || str == "ball"; }
short() {
  if(present("either implants",TP)) return "A shock grenade";
  else return "A black ball"; }
long() {
  if(present("either implants",TP)) {
    write("This is a CyberNinja shock grenade.\n"+
          "To use, 'activate grenade'. \n");
  return 1;
  }
  else write("A black ball with strange wiring all over it.\n");
return 1;
}

query_weight() { return 1; }
query_value() { return 1500; }
get() { return 1; }

init() {
  if(present("either implants",TP)) add_action("activate_grenade","activate");
}

activate_grenade(arg) {
  object meat;
  if(!arg) { write("Activate what?\n"); return 1; }
  if(arg == "grenade") {
    write("You activate the complex trigger mechanism of the grenade...\n"+
         "\n"+"The shock grenade flies into the air and starts to spin!\n");
    say(TPN+" fiddles with a black ball...\n"+
       "\n"+"The black ball rises in the air and starts to spin!\n");
    meat = first_inventory(ENV(TP));
      while(meat) {
         if(meat->is_pet()) meat = next_inventory(meat);
        if(meat->query_npc()) {
          TR(ENV(TP),CAP(meat->query_name())+" is hit by a shock wave!\n");
          move_object(clone_object("/players/snow/closed/items/sobj"),meat);
          call_other(meat,"hit_player",random(20)+5);
          meat->stop_fight(); meat->stop_fight(); meat->stop_hunter();
        }
      meat = next_inventory(meat);
      }
    write("The stun grenade stops spinning and bursts in a flash of energy!\n");
    say("The black ball stops spinning and bursts in a flash of energy!\n");
    destruct(this_object());
  return 1;
  }
}
