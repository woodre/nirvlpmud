inherit "room/room";

init() {
 ::init();
 add_action("go_west", "west");
}

/*TRY TO AVOID CHEATING*/
go_west() {
  if(this_player()->query_pl_k() == 2) {
    write("Sorry, you may not enter the lounge.\n"+
          "You have left with spar on so now it remains.\n");
    return 1; }
  else return 0;
}

reset(arg){


if(!present("ideaterminal")) {
   move_object(clone_object("/players/snow/closed/cyber/boards/ideaboard.c"),
   this_object());
   }

if(!present("suggestion box")) {
  move_object(clone_object
    ("/players/snow/closed/cyber/emote_box.c"),
    this_object()); }

 if(!arg){
 set_light(1);
 short_desc="Streets of Netropolis";
 long_desc=
"     The electronic streets of Netropolis glow with\n"+
"the streaming lights of optical wires and heated lines\n"+
"of central processing units.  Yet you can see a strong\n"+
"influence of warrior pride.  Arches of gigantic blades\n"+
"and columns stand decorated with ancient suits of armor.\n";

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
 "/players/snow/closed/cyber/rooms/shop.c","north",
 "/players/snow/closed/cyber/rooms/guildhall.c","east",
  /*"/players/snow/closed/cyber/rooms/lore1.c","south",*/
/* ARENA CLOSED FOR NOW, PK SETTING AND XP PROBLEMS
  "/players/snow/closed/cyber/rooms/arenalounge.c","west",
*/
"/players/snow/closed/cyber/rooms/convert.c","down",
      });
  }   }

feel() { return "no"; }
