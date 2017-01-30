inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"
 
init() {
 add_action("register","register");
 add_action("join_ninjas","join");
 add_action("leave_ninjas","leaveNinjas");
 add_action("purchase","buy");
 add_action("equip_list","list");
 ::init();
}

reset(arg){
  if(!present(DOCTOR_NPC)) {
    move_object(clone_object(ROOMDIR+"/DoctoR.c"),
    this_object());
  }
  if(!arg){
  set_light(1);
  short_desc=FUNKYNAME+" Chop Shop";
  long_desc=
"Welcome to the CHOP shop.\n"+
"     Hundreds of moniters and blinking lights fill every wall and\n"+
"corner of this large complex.  All around you, tables and hanging\n"+
"platforms are loaded with the latest electronic technology.  On one\n"+
"side wall, large metal cages protect various cybernetic enhancements.\n"+
"Centered in the room, a huge mechanical bed lies suspended in a mass\n"+
"of wires and monitering equipment.  Several splatters of blood stain\n"+
"everything within a 10' radius around the bed.\n"+
"Please type 'register' to list the services available to you.\n";

  items=({
"moniters", "The moniters display internal views of organs",
"lights","The lights blink on and off in various colors",
"bed","This is the operation table for new implants or enhancements",
"tables","The tables are burdened with spare parts and circuit boards",
"platforms","The platforms descend to about chest height",
"blood","Both fresh and dried blood lie splattered about",
  });

  dest_dir=({
    ROOMDIR+"/hallway1.c", "east",
  });
  }
}


status register() {
  if(!TP || !environment(TP)) return 1;
  write( 
"Services available:\n" +
"\n" +
"list.................list all enhancements available.\n" +
"cyberware............gives you an enhancement manual.\n" +
"buy <enhancement>....buy a new enhancement and have it\n" +
"                     surgically implanted in your body.\n" +
"join.................insert new implants and become\n" +
"                     a new "+FUNKYNAME+"\n" +
"leaveNinjas..........remove all hardware, honorably commit\n" +
"                     seppuku (kill yourself), and leave\n" +
"                     the "+FUNKYNAME+"\n" +
"\n");
  return 1;
}


status equip_list() {
  if(!IPTP) return 0;
  write("Enhancements available for sale.....\n");
  call_other(ENHANCEMENTD, "list", TP);
  return 1;
}


status purchase(string item) {
  if(!IPTP) return 0;
  if(!present(DOCTOR_NPC, environment(TP))) {
    write("The doctor is not present.\n");
    return 1; }
  if(!item) {
    write("Buy what?\n");
    return 1; 
  }
  write("You attempt to buy a '"+item+"'.\n");
  if(!call_other(ENHANCEMENTD, "purchase", TP, item)) {
    write("You failed to buy a '"+item+"'.\n");
  }
  else
    write("Doctor says: Your bone marrow is accepting it well.\n");
  return 1;
}


status join_ninjas(string str) {
  if(!present(DOCTOR_NPC, environment(TP))) {
    write("The doctor is not present.\n");
    return 1; }
  write("You attempt to join the "+GUILDNAME+" guild.\n");
  if(!call_other(MEMBERD, "join_ninjas", TP)) {
    write("Your attempt to join failed.\n");
  }
  else 
    write("Doctor says: By the way, your blood will turn green in three days.\n");
  return 1;
}


status leave_ninjas(string str) {
  if(!IPTP) return 0;
  if(!present(DOCTOR_NPC, environment(TP))) {
    write("The doctor is not present.\n");
    return 1; }
  write("You attempt suicide.\n");
  if(!call_other(MEMBERD, "leave_ninjas", TP)) {
    write("Your suicide attempt fails.\n"+
          "You remain a "+GUILDNAME+".\n");
  }
  else {
    write( 
      "You disconnect your cyberlinks.\n"+
      "Your implants are surgically removed.\n"+
      "The doctor hands you a long-bladed dagger.\n"+
      "You kneel and honorably commit seppuku.\n"+
      "No longer are you a "+FUNKYNAME+".\n");
    call_other(CHANNELD, "overchannel", TRN+
      " has honorably quit the Ninjas.\n");
    call_other(CHANNELD,"resetchannel");
    say(TRN+" has left the guild.\n");
    write_file(LOGDIR + "/LEAVE", 
      TRN+" left the guild. ("+ctime()+")\n");
    write("Doctor says: I'll clean up the mess.\n");
  }
  return 1;
}
