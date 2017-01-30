inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Imperiled";
     long_desc =
"You are walking underneath an overhang in which there is somone\n"+
"hanging off of it. Slice his feet off and let him bleed to death!\n";
      dest_dir = 
({
"players/nightshade/room/imp12", "west",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/imperiled");
move_object(duh, this_object());
}
}
