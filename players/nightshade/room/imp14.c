inherit "players/nightshade/new_room";
reset(arg){
monster();
   if(arg) return;
        set_light(1);
short_desc="Impoverished";
     long_desc =
"A poor former employee of Mr. Important. Mr. I keeps him around\n"+
"to make an example of him. Dont ever cross mr. I!\n";
      dest_dir = 
({
"players/nightshade/room/imp15", "east",
      });
}
monster() {
object duh;
if(!present("imp")) {
duh=clone_object("players/nightshade/mons/impoverished");
move_object(duh, this_object());
}
}
