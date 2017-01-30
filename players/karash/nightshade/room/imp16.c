inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Imprisoned";
     long_desc =
"A long time prisoner of Mr. Important, Imprisoned sits in the\n"+
"corner of the jail moaning and wishing his life would end.\n"+
"Why dont you oblige him.\n";
      dest_dir = 
({
"players/nightshade/room/imp15", "west",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/imprisoned");
move_object(duh, this_object());
}
}
