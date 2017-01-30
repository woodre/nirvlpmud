inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"There is a male drow here chanting a spell. A small make-shift bed\n"+
"lays in the corner of the room and there is a pack resting on top\n"+
"of it. A small harness and saddle lay off to the right. They must\n"+
"belong to the giant lizard standing guard over the drow becuase he\n"+ 
"is totallly consumed with his spell casting.\n";
      dest_dir = 
({
"players/nightshade/room/c5", "west",
      });
}
monster() {
object duh;
if(!present("mage")) {
duh=clone_object("players/nightshade/mons/drow_mage");
move_object(duh, this_object());
}
}
