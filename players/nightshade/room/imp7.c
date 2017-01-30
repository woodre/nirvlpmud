inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Imperceptable";
     long_desc =
"You can barely see a shimmering outline of somone here. They\n"+
"may be hard to hit, but not impossible.\n";
      dest_dir = 
({
"players/nightshade/room/imp8", "east",
"players/nightshade/room/imp6", "west",
"players/nightshade/room/imp12", "north",
"players/nightshade/room/imp3", "south",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/imperceptable");
move_object(duh, this_object());
}
}
