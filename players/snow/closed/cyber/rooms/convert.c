#define TP this_player()
inherit "room/room";

init() {
  ::init();
  call_out("move_me", 0, TP);
  add_action("sp_me","SP");
  add_action("hp_me","HP");
  add_action("immerse_me","immersion");
}

move_me(object ob) {
  if(!present("either implants", ob)) {
  tell_object(ob, "------------>\n");
  tell_object(ob,"You have infiltrated Netropolis without authorization.\n");
  tell_object(ob, "------------>\n");
  if(ob->is_player() && ob->query_level() < 20) move_object(ob,"/room/church");
  }
}


reset(arg){
 if(!arg){
 set_light(1);
 short_desc="CyberNinja Conversion Chamber";
 long_desc=
"     The CyberNinja Conversion Chamber is an ominous spherical\n"+
"room filled with swiftly moving repair pods and nurse droids.\n"+
"You may choose to convert your hit points to spell points with\n"+
"the command 'SP <number>', convert your spell points to hit\n"+
"points with the command 'HP <number>', or you may choose to \n"+
"heal at an increased rate by 'immersion' in a healing pod.\n";

items=({
 "pods","Jet black immersion pods",
 "droids","Nurse droids to facilitate your healing process",
 });

  dest_dir=({
  "/players/snow/closed/cyber/rooms/hallway2.c", "up",
      });
  }   }

sp_me(int num) {
  int myhp, mysp, mymhp, mymsp, poo;
  if(!num || !sscanf(num, "%d", poo) ) {
    write("Usage: SP <number>.\n"); return 1; }
  myhp = TP->query_hp();
  mysp = TP->query_sp();
  mymhp = TP->query_mhp();
  mymsp = TP->query_msp();
  if(poo < 0) { write("POSITIVE NUMBERS!\n"); return 1; }
  if(poo + mysp > mymsp || myhp - poo < 1) {
    write("That operation cannot be physically achieved.\n");
    return 1;
  }
  TP->add_hit_point(-poo);
  TP->add_spell_point(poo);
  write("You have converted [ "+poo+" ] hit points into spell points.\n");
  write("You now have:  Hit Points   [ "+TP->query_hp()+" ]\n"+
        "               Spell Points [ "+TP->query_sp()+" ]\n");
  return 1;
}

hp_me(int num) {
  int myhp, mysp, mymhp, mymsp, poo;
  if(!num || !sscanf(num, "%d", poo) ) {
    write("Usage: HP <number>.\n"); return 1; }
  myhp = TP->query_hp();
  mysp = TP->query_sp();
  mymhp = TP->query_mhp();
  mymsp = TP->query_msp();
  if(poo < 0) { write("POSITIVE NUMBERS!\n"); return 1; }
  if(poo + myhp > mymhp || mysp - poo < 1) {
    write("That operation cannot be physically achieved.\n");
    return 1;
  }
  TP->add_spell_point(-poo);
  TP->add_hit_point(poo);
  write("You have converted [ "+poo+" ] spell points into hit points.\n");
  write("You now have:  Hit Points   [ "+TP->query_hp()+" ]\n"+
        "               Spell Points [ "+TP->query_sp()+" ]\n");
  return 1;
}

immerse_me() {
    write("The immersion healing pod has been temporarily removed\n"+
            "until snow fixes it.      - The Managment <11-14-97>\n");
return 1; 
  write("You are escorted by a Nurse droid into a healing pod.\n"+
        "Your options are now: cyber, help, progress, and stop.\n");
  move_object(TP, "/players/snow/closed/cyber/rooms/heal_pod");
  return 1;
}
