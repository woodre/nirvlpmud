inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impersonal";
     long_desc =
"As you walk in you catch some guy looking at a skin flick trying\n"+
"to well, get it up. End his tired existence.\n";
      dest_dir = 
({
"players/nightshade/room/imp6", "east",
"players/nightshade/room/imp4", "west",
"players/nightshade/room/imp10", "north",
"players/nightshade/room/imp1", "south",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impersonal");
move_object(duh, this_object());
}
}
