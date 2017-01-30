inherit "players/nightshade/new_room";
object duh;
reset(arg) {
   if(arg) return;
   long_desc = "Test Room";
   short_desc = "Test Room";
   dest_dir =
({
"players/nightshade/workroom", "south",
});
}
init()
{
   ::init();
   if(!present("vampire")) {
      duh=clone_object("players/nightshade/mons/vampire");
      move_object(duh, this_object());
   }
   if(!present("vendor")) {
     duh=clone_object("players/nightshade/mons/vendor");
     move_object(duh, this_object());
}
   if(!present("wulfgar")) {
     duh=clone_object("players/nightshade/mons/kargile");
     move_object(duh, this_object());
}
   if(!present("elf")) {
     duh=clone_object("players/nightshade/mons/hp_mon");
     move_object(duh, this_object());
}
}
