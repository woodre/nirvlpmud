inherit "room/room";
realm() { return "NT"; }
reset(arg) {
monster();
if(arg)
   return;
short_desc="A Bare Room";
long_desc="This is a bare room.  It seems that there use to be something\n"+
          "here, but it must have been moved away.\n";
dest_dir=({"players/grimm/frst/forest21","up"});
set_light(1);
}
monster() {
   int count;
   object monster;
   if(!present("spider")) 
      while(count < 10) {
         count += 1;
         monster = clone_object("players/grimm/monster/spider");
         move_object(monster,this_object());
      }
return 1; 
}
