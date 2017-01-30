inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Important";
     long_desc =
"You have finally reached Mr. Important. You are suprised at the\n"+
"way he looks. He is just an ordinary wimp of a guy who wields\n"+
"a little power. He shouldn't be to hard to kill.\n";
      dest_dir = 
({
"players/nightshade/room/imp17", "south",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/important");
move_object(duh, this_object());
}
}
