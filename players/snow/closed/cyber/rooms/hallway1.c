inherit "room/room";

init() {
add_action("holodeck","holodeck");
 ::init();
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
 "/players/snow/closed/cyber/rooms/meditation.c","east",
 "/players/snow/closed/cyber/rooms/chopshop.c","west",
 "/players/snow/closed/cyber/rooms/guildhall.c","south",
 "/players/snow/closed/cyber/rooms/council.c","up",
 "/players/anshar/closed/cninja/b_room.c","down",
      });
  }   }

holodeck() {
  say(capitalize(this_player()->query_name())+
     " decides to enter the Holodeck.\n");
  write("You decide to enter the Holodeck.\n");
  write("Type 'cyber holodeck' for information.\n");
  move_object(this_player(),
      "/players/snow/closed/cyber/rooms/holodeck.c");
  return 1; }

feel() { return "no"; }