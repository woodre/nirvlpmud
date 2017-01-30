inherit "players/nightshade/new_room";
init() {
::init();
add_action("north", "north");
}
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Imperial";
     long_desc =
"An imperial guard stads here to prevent passage north.\n"+
"Defeat him. He is hard.\n";
      dest_dir = 
({
"players/nightshade/room/imp15", "north",
"players/nightshade/room/imp12", "east",
"players/nightshade/room/imp10", "west",
"players/nightshade/room/imp6", "south",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/imperial");
move_object(duh, this_object());
}
}
north() {
if(present("imp")) {
   write("The guard does not allow you to go that way.\n");
   return 1;
}
}
