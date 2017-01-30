inherit "players/nightshade/new_room";
reset(arg){
   if(arg) return;
        set_light(1);
short_desc="Imp Land";
     long_desc =
"Welcome to imp land. These doods arent very hard to kill so it\n"+
"is a place for newbies. Have fun and be kool!\n";
      dest_dir = 
({
"players/nightshade/room/imp2", "north",
"players/nightshade/room/forest6", "west",
      });
}
