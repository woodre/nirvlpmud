inherit "room/room";

reset(arg) {
   
   object mon;
   
   if(!arg) {
      
      set_light(1);
      short_desc = "Linus' Basement";
      long_desc=  "This is a fun sample room.  Yay.\n";
      
      dest_dir=({
            "/players/linus/workroom","workroom"
});
      
      mon = clone_object("/players/linus/examples/monster.c");
      move_object(mon, this_object());
   }
}
