inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Implausable";
     long_desc =
"A short, stocky guy sits here bored. Kill him.\n";
      dest_dir = 
({
"players/nightshade/room/imp7", "west",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/implausable");
move_object(duh, this_object());
}
}
