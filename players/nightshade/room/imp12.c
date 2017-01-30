inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impassioned";
     long_desc =
"Some chick standing in the room rushes over to you and starts\n"+
"kissing and licking you all over. Either kill her or get it on!\n";
      dest_dir = 
({
"players/nightshade/room/imp13", "east",
"players/nightshade/room/imp7", "south",
"players/nightshade/room/imp11", "west",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impassioned");
move_object(duh, this_object());
}
}
