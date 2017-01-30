inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Implode";
     long_desc =
"Some dood is here hangin out. He suddenly starts to implode!\n"+
"If ya hurry maybe ya can kill him before he finishes.\n";
      dest_dir = 
({
"players/nightshade/room/imp2", "east",
"players/nightshade/room/imp5", "north",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/implode");
move_object(duh, this_object());
}
}
