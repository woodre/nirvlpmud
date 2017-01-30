inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impaired";
     long_desc =
"Some freak is here trying to learn how to walk again. Cut off\n"+
"his legs so he doesnt have to walk! *cackle*\n";
      dest_dir = 
({
"players/nightshade/room/imp10", "east",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impaired");
move_object(duh, this_object());
}
}
