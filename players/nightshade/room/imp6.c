inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impotent";
     long_desc =
"As you walk in you catch some guy looking at a skin flick trying\n"+
"to well, get it up. End his tired existence.\n";
      dest_dir = 
({
"players/nightshade/room/imp7", "east",
"players/nightshade/room/imp5", "west",
"players/nightshade/room/imp11", "north",
"players/nightshade/room/imp2", "south",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impotent");
move_object(duh, this_object());
}
}
