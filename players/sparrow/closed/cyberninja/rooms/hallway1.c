inherit "/players/dune/closed/guild/rooms/room";
#include "../DEFS.h"

init() {
::init();
  add_action("holodeck","holodeck");
add_action("upp","up");
add_action("upp","u");
}

reset(arg){
  if(!arg){
  set_light(1);
  short_desc="Streets of Netropolis";
  long_desc=
"     The electronic streets of Netropolis glow with\n"+
"the streaming lights of optical wires and heated lines\n"+
"of central processing units.  Yet you can see a strong\n"+
"influence of warrior pride.  Arches of gigantic blades\n"+
"and columns stand decorated with ancient suits of armor.\n"+
"Three large hexagonal domes surround the outer edges of\n"+
"of the wide street square.  They are entrances to:\n"+
"the 'holodeck'.\n\n";

  items=({
"streets", "The streets are made of dark-colored metal",
"wires","Thick colorful wires lace along the roadside",
"lines","CPU lines glow red with all the info passing through them",
"arches","Several gigantic arches tower over the streets",
"blades","The blades are symbols of ninja strength",
"columns","Several columns hold up the dark ceiling above",
"armor","These suits of armor serve as fitting decorations",
"suits","These suits of armor serve as fitting decorations",
  });

  dest_dir=({
    ROOMDIR + "/fab.c","east",
    ROOMDIR + "/chopshop.c","west",
    ALTLOGIN,"south",
    ROOMDIR + "/council.c","up",
/* Exit not working
    ANSHAR_ROOMS, "down",
*/
  });
  }
}

upp() {
if(!present("implants",this_player())) {
write("Stay out of cyber affairs.\n");
return 1;
}
if (!call_other(OFFICED, "checkStone", TP, "diamond sapphire pearl emerald onyx"))
{
write("The CyberDaemon says: 'Access Denied!'\n");
return 1;
}
else {
return 0;
}
}

holodeck() {
  say(TPN+" decides to enter the Holodeck.\n");
  write("You decide to enter the Holodeck.\n");
  write("Type 'cyber holodeck' for information.\n");
  move_object(TP, ROOMDIR + "/holodeck.c");
  return 1; 
}
