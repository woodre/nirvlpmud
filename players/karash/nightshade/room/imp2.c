inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impatient";
     long_desc =
"Mr. Impatient stands here cursing and muttering to himself about\n"+
"somebody who is taking to long to get there. Maybe you should end\n"+
"his misery and kill him.\n";
      dest_dir = 
({
"players/nightshade/room/imp3", "east",
"players/nightshade/room/imp1", "west",
"players/nightshade/room/imp6", "north",
"players/nightshade/room/imp", "south",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impatient");
move_object(duh, this_object());
}
}
