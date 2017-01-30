inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impenetrable";
     long_desc =
"Another guard for Mr.Important. Hes hard as well.\n";
      dest_dir = 
({
"players/nightshade/room/imp16", "east",
"players/nightshade/room/imp11", "south",
"players/nightshade/room/imp14", "west",
"players/nightshade/room/imp17", "north",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impenetrable");
move_object(duh, this_object());
}
}
