inherit "room/room";
realm() { return "NT"; }
reset(arg) {
monster();
if(arg)
   return;
short_desc="Feeding Room";
long_desc="This is the feeding room of the vampires.\n";
dest_dir=({"players/grimm/closed/vampcastl/castle18","north"});
set_light(1);
}
monster() {
   int count;
   object monster;
   if(!present("vampire")) 
      while(count < 7) {
         count += 1;
         monster = clone_object("players/grimm/monster/yungvamp");
         move_object(monster,this_object());
      }
return 1; 
}
