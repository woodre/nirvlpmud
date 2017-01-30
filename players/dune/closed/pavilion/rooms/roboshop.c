/* Place to create RoboMechs, with weapons and ammo */
inherit "room/room";
#include "../DEFS.h"
#define MECH environment(this_player())
#define MO   move_object

init() {
  add_action("register","register");
  add_action("types","types");
  add_action("champs","champs");
/* RoboMech is temporarily under construction - Dune */
  if (TRN == "Dune" || TRN == "Dunetest")
  add_action("new_mech","assemble");
  add_action("goplace","up");
  ::init();
  }

reset(arg) {

   if(!present("terminal")) {
     move_object(clone_object("/players/dune/closed/pavilion/roboboard.c"),
                 this_object());
     }
   if(!arg) {
   set_light(1);
   short_desc=("RoboMech Hangar");
   long_desc=
"     Surrounding you no all sides rest several towering\n"+
"robomechs.  Several more are being assembled, supported\n"+
"by spiderlike metallic structures.  Here you may make your\n"+
"robomech from scratch and customize it any way you want.\n"+
"Type 'register' for instructions.\n"+
"When you are ready to fight, go 'up' the battlefield!.\n";

   dest_dir=({
   "/players/dune/closed/pavilion/rooms/roboentry.c", "entryway",
        });

   items=({
   "structures",
"The structures allow the mechanics to reach the\n"+
"higher levels of robomech bodies",
   "robomechs","The robomechs vary widely in size and shape",
        });
   }   }

goplace() {
  /* RoboMech or player placed randomly on battlefield */
  int rnd;
  string file;
  object mech;
  rnd = random(12)+1;
  mech = this_player();
  file = "/players/dune/closed/pavilion/rooms/field/";
  say(this_player()->short()+
      " enters the RoboMech Battlefield.\n");
  write("You enter RoboMech Battlefield.\n\n");
  switch(rnd) {
    case 1:  MO(mech, file+"white1.c"); break;
    case 2:  MO(mech, file+"white2.c"); break;
    case 3:  MO(mech, file+"white3.c"); break;
    case 4:  MO(mech, file+"white4.c"); break;
    case 5:  MO(mech, file+"blue2.c");  break;
    case 6:  MO(mech, file+"blue3.c");  break;
    case 7:  MO(mech, file+"black1.c"); break;
    case 8:  MO(mech, file+"black4.c"); break;
    case 9:  MO(mech, file+"red2.c");   break;
    case 10: MO(mech, file+"red3.c");   break;
    case 11: MO(mech, file+"green1.c"); break;
    case 12: MO(mech, file+"green4.c"); break;
    }
  return 1;
}

register() {
  write(
"List of services available...\n"+
"___________________________________________________________\n"+
"   NOTE: assembly of mechs temporarily disabled during construction\n"+
/*
"assemble <name> <type>....This allows you to create and\n"+
"                          customize your mech for free.\n"+
"                          You must name your mech and\n"+
"                          choose a type.\n"+
*/
"types.....................Info on Types of RoboMechs available\n"+
"champs....................Champions of RoboMech (and losers)\n"+
"___________________________________________________________\n");
  return 1;
}

types() {
  write(
"\n"+
" TYPE       SPEED   DURABILITY   HEAT LOSS   CAPACITY\n"+
"___________________________________________________________\n"+

" Lancer       1        60           50          60\n"+
" Light        2        70           45          70\n"+
" Medium       3        80           40          80\n"+
" Heavy        4        90           35          90\n"+
" Full         5        100          30          100\n"+
"___________________________________________________________\n"+
"Speed refers to how many seconds each move will take\n"+
"Durability is how many hits your mech can take\n"+
"Heat loss is how much heat your mech can tolerate\n"+
"Capacity is how much weapons your mech can hold\n");
  return 1;
}

champs() {
  /* shows record of wins and losses */
  string file;
  file = "/players/dune/log/ROBOMECH";
  if(file_size(file) >= 0) {
    write("Champions of RoboMech\n");
    write("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
    if(file_size(file) < 100) {
      cat(file); }
    else {
      call_other("/players/dune/closed/pavilion/daemons/_more.c",
                 "more_file", file); }
    return 1; }
  write("There are no RoboMech Champions at this time.\n");
  return 1; }

object PIT(object ob) {
  /* similar to #define */
  object cockpit;
  cockpit = present("_cockpit_", environment(ob));
  return cockpit;
}

new_mech(string str) {
  /* creates a new mech.  variables are all set */
  int spd, mxht, mxcap, dur;
  string pilot, name, type;
  object ob;
  if(!str) {
    write("Usage: assemble <name> <type>\n");
    return 1; }
  if(!sscanf(str, "%s %s", name, type)) {
    write("Usage: assemble <name> <type>\n");
    return 1; }
  if(strlen(name) > 10) {
    write("Your mech name must be 10 characters or less.\n");
    return 1; }
  switch(type) {

    case "lancer":  dur=60; spd=0; mxht=100; mxcap=60; break;
    case "light":   dur=70; spd=2; mxht=90; mxcap=70; break;
    case "medium":  dur=80; spd=3; mxht=80; mxcap=80; break;
    case "heavy":   dur=90; spd=4; mxht=70; mxcap=90; break;
    case "full":    dur=100; spd=5; mxht=60; mxcap=100; break;
    }
  if(!dur) {
    write("Wrong mech type, you may choose from:\n"+
          "'lancer, light, medium, heavy, or full'\n");
    return 1; }
  if(MECH->is_mech()) {
    write("You already have a mech.\n");
    return 1; }
  pilot = this_player()->query_real_name();
  pilot = capitalize(pilot);
  ob = clone_object("/players/dune/closed/pavilion/mech.c");
  ob->set_myname(name);
  ob->set_pilot(pilot);
  ob->set_speed(spd);
  ob->set_maxheat(mxht);
  ob->set_maxcapacity(mxcap);
  ob->set_type(type);
  ob->set_hits(dur);
  move_object(ob, environment(this_player()));
  name = lower_case(name);
  write("You purchase a mech and name it "+capitalize(name)+".\n");
  write("You climb into your mech.\n");
  tell_room(environment(this_player()), capitalize(this_player()->
            query_name())+" climbs into a new mech.\n");
  write("Type 'robo' for RoboMech information.\n");
  move_object(this_player(), ob);
  ob->reset();
  return 1;
}

