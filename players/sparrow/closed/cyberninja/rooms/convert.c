inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"

init() {
  if(present(GUILD_ID, TP)) {
  add_action("sp_me","SP");
  add_action("hp_me","HP");
  add_action("immerse_me","immersion");
  }
  ::init();
}

reset(arg){
  if(!arg){
  set_light(1);
  short_desc=FUNKYNAME+" Conversion Chamber";
  long_desc=
"     The "+FUNKYNAME+" Conversion Chamber is an ominous spherical\n"+
"room filled with swiftly moving repair pods and nurse droids.\n"+
"You may choose to convert your hit points to spell points with\n"+
"the command 'SP <number>', convert your spell points to hit\n"+
"points with the command 'HP <number>', or you may choose to \n"+
"heal at an increased rate by 'immersion' in a healing pod (500 credits).\n";

  items=({
    "pods","Jet black immersion pods",
    "droids","Nurse droids to facilitate your healing process",
   });

  dest_dir=({
    ROOMDIR + "/hallway2.c", "up",
  });
  }
}

int sp_me(int num) {
  int myhp, mysp, mymhp, mymsp, poo;
  if(!num || !sscanf(num, "%d", poo) ) {
    write("Usage: SP <number>.\n"); 
    return 1; }
  myhp =  (int)TP->query_hp();
  mysp =  (int)TP->query_sp();
  mymhp = (int)TP->query_mhp();
  mymsp = (int)TP->query_msp();
  if(poo < 0) { 
    write("POSITIVE NUMBERS!\n"); 
    return 1; }
  if(poo + mysp > mymsp || myhp - poo < 1) {
    write("That operation cannot be physically achieved.\n");
    return 1; }
  TP->add_hit_point(-poo);
  TP->add_spell_point(poo);
  write("You have converted [ "+poo+" ] hit points into spell points.\n");
  write("You now have:  Hit Points   [ "+(int)TP->query_hp()+" ]\n"+
        "               Spell Points [ "+(int)TP->query_sp()+" ]\n");
  return 1;
}

int hp_me(int num) {
  int myhp, mysp, mymhp, mymsp, poo;
  if(!num || !sscanf(num, "%d", poo) ) {
    write("Usage: HP <number>.\n"); 
    return 1; }
  myhp =  (int)TP->query_hp();
  mysp =  (int)TP->query_sp();
  mymhp = (int)TP->query_mhp();
  mymsp = (int)TP->query_msp();
  if(poo < 0) { 
    write("POSITIVE NUMBERS!\n"); 
    return 1; }
  if(poo + myhp > mymhp || mysp - poo < 1) {
    write("That operation cannot be physically achieved.\n");
    return 1; }
  TP->add_spell_point(-poo);
  TP->add_hit_point(poo);
  write("You have converted [ "+poo+" ] spell points into hit points.\n");
  write("You now have:  Hit Points   [ "+(int)TP->query_hp()+" ]\n"+
        "               Spell Points [ "+(int)TP->query_sp()+" ]\n");
  return 1;
}

int immerse_me() {
/*
  write("This function has been shut down again. - Snow\n"); return 1;
*/
  if(IPTP->balance() < 500) {
    write("You need a credit balance of at least 500 to enter the healing pod.\n");
    return 1; }
  IPTP->addToBalance(-500);
  IPTP->save_me();
  write("Your account has been deducted 500 credits for use of the healing pod.\n");
  write("You are escorted by a Nurse droid into a healing pod.\n");
  say(TPN+" enters the healing pod.\n");
  move_object(TP, ROOMDIR + "/heal_pod");
  return 1;
}
