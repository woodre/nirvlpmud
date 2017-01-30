
query_save_flag(){ return 1; }
/* REACT BANDAGES - CYBERNINJA HEALING ITEM */
 
#define TP this_player()
#define TO this_object()
#define ENV environment
#define ETO ENV(TO)
#define PRE present
#define THP ETO->query_hp()
#define TSP ETO->query_sp()
#define MSP ETO->query_msp()
#define MHP ETO->query_mhp()
 
int charge;
 
id(str) { return str == "bandages" || str == "superreact bandages"; }
short() { return "SuperReact Bandages ["+charge+"%]"; }
long() {
  write("CyberNinja SuperCharge Bandages. If activated, they will quickly\n"+
        "heal the owner when not in combat.\n"+
        "Command: activate mbandages ,  deactivate\n");
       write("React Bandages charged to ["+charge+"%]\n");
return 1;
}
 
query_weight() { return 0; }
get() { return 1; }
 
reset() {
  charge = 200;
}
 
init() {
  if(TP->query_guild_name() != "cyberninja") {
    write("These were not made for you!\n"); destruct(TO); }
  if(TP->query_guild_name() == "cyberninja") {
    add_action("activate","activate");
    add_action("deactivate","deactivate");
   }
}
 
activate(arg) {
  if(!arg) notify_fail("Activate what?\n");
  if(arg == "mbandages") {
    write("React Bandages activated.\n");
    call_out("react_heal",10);
  return 1;
  }
}
 
react_heal() {
  if(!living(ETO)) {
    deactivate(); return 1; }
  call_out("react_heal",5);
  if(ETO->query_attack()) return 1;
  if(MSP - TSP < 2 && MHP - THP < 2) {
    ETO->heal_self(1);
  return 1;
  }
  if(MSP - TSP < 5 || MHP - THP < 5) {
    say("The React Bandages pulse and warmth runs through your veins.\n");
    ETO->heal_self(10);
    charge = charge - 5;
      if(charge < 0) band_dest();
  return 1;
  }
  say("The React Bandages glow and healing energy pulses through your body.\n");
  ETO->heal_self(10);
  charge = charge - 10;
    if(charge < 0) band_dest();
return 1;
}
 
deactivate() {
  remove_call_out("react_heal");
  say("React Bandages deactivated at ["+charge+"%]\n");
return 1;
}

band_dest() {
  say("The React Bandages crumble as their energy runs out.\n");
  remove_call_out("react_heal");
  destruct(TO);
return 1;
}
query_save_flag() { return 1; }
