id(str) { return str == "crystal"; }
short() { return "Crystal of Divine Intervention"; }
long() {
  write("This is a deep blue crystal made purely of a stone that is\n"+
	"completely alien to you. It seems to have some magical\n"+
	"properties, but you have no idea how it would be used for\n"+
	"your own good.\n");
}

get() { return 1; }

query_weight() { return 1; }
query_save_flag() { return 1; }
query_value() { return 10000; }
query_magik() { return 10; }
 
init() {
  add_action("superheal","rub");
}

static superheal(str) {
  object room,ob;
  if(!str || str != "crystal") return 0;
  room=environment(this_object());
  ob=first_inventory(room);
  say("You rub the crystal, and are blinded by a brilliant blue light...\n\n\n");
    while(ob) {
      object oc;
      oc=ob;
      ob=next_inventory(oc);
        if(living(oc)) {
          if(oc->query_npc() !=1) {
            if((oc->query_name()) == "Mizan") {
              say("Mizan begins glowing.\n");
            } else {
              say((oc->query_name())+" is healed by the light.\n");
              oc->heal_self(150);
            }
          }
        if(oc->query_npc() == 1) {
          if((oc->query_name()) == "Summerhead") {
            say("Summerhead begins to glow.\n");
          } else {
            say((oc->query_name())+" appears to be rejuvenated by the glow.\n");
            oc->heal_self(200);
          }
        }
      }
    }
  say("The crystal fades into nothing, its energies spent...\n");
  destruct(this_object());
  return 1;
}
