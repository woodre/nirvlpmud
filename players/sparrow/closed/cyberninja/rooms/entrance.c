inherit "room/room";
#include "../DEFS.h"

init() {
  tell_object(this_player(), RED+"\tCYBERNINJA GUILD ZONE\n"+OFF);
  this_player()->set_fight_area();
  add_action("listen","listen");
  add_action("westfunc","west");
  add_action("restoration","restore");
  add_action("fix","fix");
  ::init();
}

exit() { if(this_player()) this_player()->clear_fight_area(); }

reset(arg){
  if(!arg){
  set_light(1);
  short_desc="Entrance to Netropolis";
  long_desc=
"     The vast city of Netropolis lies westward.  Looking west,\n"+
"streams of lights and optical cables lace across the\n"+
"futuristic landscape.  A broad arch looms just over your\n"+
"head.  Upon the arch rests the huge figurine of a technological\n"+
"nightmare.  Red eyes glare through the ninja-like figure.\n"+
"This statue seems to have something important to say.\n"+
"Perhaps if you 'listen' you might learn more about what lies ahead.\n"+
"A moniter rests embedded in the metallic arch.\n"+
"A warning sign reads: Restricted Access Area. Enter at Risk of Death.\n";

  items=({
"lights",     "The lights shine brightly in the otherwise dark city",
"cables",     "Thick colorful cables run along the Netropolis streets",
"landscape",  "The electronic landscape is dark and alive with energy",
"arch",       "The broad red arch towers above you",
"figure",     "The menacing figure of a ninja warrior stands before you",
"statue",     "The statue is black, with red glowing eyes",
"monitor",    "The monitor reads:\n"+
    "If your implants have broken or disappeared, \n"+
    "type 'restore' and then 'fix' to solve the problem",
"moniter",    "The moniter reads:\n"+
    "If your implants have broken or disappeared, \n"+
    "type 'restore' and then 'fix' to solve the problem",
"netropolis", "Netropolis, city of the "+FUNKYNAME,
"Netropolis", "Netropolis, city of the "+FUNKYNAME,
"city",       "Netropolis, city of the "+FUNKYNAME,
 });

  dest_dir=({
    GUILDEXIT, "guildexit",
  });
  }
}

westfunc() {
  if( !present(AFFILIATE, TP) ) {
    if(TP->query_level() < 8) {
      tell_object(TP, "You are too small to try to invade the CyberNinja Guild.\n");
      return 1; }
    if(!TP->query_pl_k()) {
      tell_object(TP, "You are too afraid to enter.\n"); return 1; }
  }
    call_other(TP, "move_player", "west#"+ALTLOGIN);
    return 1;
}

listen() {
  tell_room(environment(TP),
"A deep voice emanates from the dark warrior statue.....\n"+
"To be a "+FUNKYNAME+", you first seek out a "+FUNKYNAME+" who can\n"+
"show you the Way.  You must learn this Way, and only then may\n"+
"you become one of us!\n"+
"...The voice dies into silence.\n");
  return 1;
}

int restoration() {
  string name, file;
  name = (string)this_player()->query_real_name();
  name = lower_case(name);
  file = NINJADIR + name + ".o";
  if(file_size(file) <= 0) {               
    write("You are not a "+FUNKYNAME+"!\n");
    return 1; 
  }
  call_other(MEMBERD, "restoration", TP);
  write("Your implants have been restored.\n");
  return 1;
}

int fix() {
  if(!IPTP) {
    write("You have no implants. Type 'restore' first.\n");
    return 1; 
  }
  call_other(MEMBERD, "fix", TP);
  write("Guild status fixed.\n");
  return 1;
}

CN_PK() { return 1; }
realm() { return "NT"; }
