inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impact";
     long_desc =
"One tough guy looks at you looking for a fight. He basically wants to kick your ass.\n";
      dest_dir = 
({
"players/nightshade/room/imp11", "east",
"players/nightshade/room/imp5", "south",
"players/nightshade/room/imp9", "west",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impact");
move_object(duh, this_object());
}
}
