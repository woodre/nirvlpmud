inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Imposter";
     long_desc =
"An imperial guard stands guard here. You notice something funny\n"+
"about him but cant quite put your finger on it.\n";
      dest_dir = 
({
"players/nightshade/room/imp5", "east",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/imposter");
move_object(duh, this_object());
}
}
