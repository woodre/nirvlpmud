inherit "players/nightshade/new_room";
object ob;
reset(arg){
monster();
   if(arg) return;
        set_light(1);
        short_desc = " Dark Cave";
     long_desc =
"The cave is damp and slightly dark. The walls are slimy and covered\n"+
"with an odd species of fungi which glows a faint gold color.\n";
      dest_dir = 
({
"players/nightshade/room/c15", "west",
      });
}
monster() {
object duh;
if(!present("basilisk")) {
duh=clone_object("players/nightshade/mons/basilisk");
move_object(duh, this_object());
}
}