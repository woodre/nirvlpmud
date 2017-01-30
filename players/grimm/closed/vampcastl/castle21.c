inherit "room/room";
realm() { return "NT"; }
reset(arg) {
monster();
if(arg)
   return;
short_desc="Gaurdian Chamber";
long_desc="You have entered the chamber were the gaurdians of the vampires rest!!\n";
dest_dir=({"players/grimm/closed/vampcastl/castle18","south"});
set_light(1);
}
monster() {
   int count;
   object monster;
   if(!present("gargoyle")) 
      while(count < 7) {
         count += 1;
         monster = clone_object("players/grimm/monster/gargoyle2");
         move_object(monster,this_object());
      }
return 1; 
}
