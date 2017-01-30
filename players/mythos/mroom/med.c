#define tp this_player()
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Medical Center>> ";
    long_desc =
    "                        Tokyo Medical Center\n"+
    "You are in a large medical building.  All your ills of the body\n"+
    "may be 'cure'd here <diseases> or if you are wounded you may be\n"+
    "'heal'ed.  Also for a small fee you may have a 'checkup'\n"+
    "to see if you have any dormant illnesses.\n"+
    "All concerns about drug caused problems are referenced to the \n"+
    "rehabilitaion center.\n";
  items = ({
    "out","You see the exit",
    "rehab","You see the rehab center",
  });

  dest_dir = ({
    "/players/mythos/mroom/masakado.c", "out",
    "/players/mythos/mroom/rehab.c","rehab",
  });
} }

init() {
  ::init();
  add_action("ccure","cure");
  add_action("hheal","heal");
  add_action("checkup","checkup");
}

ccure() {
  if(!present("disease",tp) && !present("poison",tp) && 
  !present("infection",tp))
  { write("You are quite fine it seems!\n"); return 1;}
  destruct(present("disease",tp));
  destruct(present("infection",tp));
  if(present("poison",tp)) {
  destruct(present("poison",tp));
  tp->add_money(-100); }
  tell_room(environment(tp),"\n");
return 1;}

hheal() {
  if(tp->query_money() < 10000) { write("You do not have enough money!\n"); return 1;}
  tp->heal_self(1000);
  tp->add_money(-10000);
  tell_room(environment(tp),"\n");
return 1;}

checkup() {
  if(tp->query_money() < 1000) { 
  write("You do not have enough money <1000>!\n"); return 1;}
  tp->add_money(-1000);
  tell_room(environment(tp),"\n");
  if(!present("disease",tp) && !present("sterm",tp) && !present("lterm",tp) &&
  !present("poison",tp) && !present("curse",tp) && !present("cursed",tp) ||
  (tp->query_hp() < tp->query_mhp())) {
  write("The doctor declares that you are fit!\n"); }
  if(tp->query_hp() < tp->query_mhp()) {
  write("The doctor tells you: You are wounded.\n"+
  "                            You may wish to become 'heal'ed.\n"); }
  if(present("disease",tp) || present("infection",tp)) { 
  write("The doctor tells you: You are ill.\n"+
  "                            You may wish to become 'cure'ed.\n"); }
  if(present("sterm",tp) || present("lterm",tp)) { 
  write("The doctor tells you: You have drug related problems.\n"); 
  write("                      You may wish to go to the rehab center.\n"); }
  if(present("curse",tp) || present("cursed",tp)) {
  write("The doctor tells you: You have a curse on you.\n"); 
  write("                      You may wish to go to the rehab center.\n");} 
  if(present("poison",tp)) {
  write("The doctor tells you: You have been poisoned.\n"); 
  write("                      You may wish to be 'cure'ed.\n");}
  say("The doctor whispers something to "+capitalize(tp->query_real_name())+".\n");
return 1;}
