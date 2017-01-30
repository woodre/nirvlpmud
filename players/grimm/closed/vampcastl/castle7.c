inherit "room/room";
int flag;
realm() { return "NT"; }
reset(arg) {
monster();
if(arg)
   return;
short_desc="Vampire Crypt";
long_desc="You have walked into a very dark and smelly room.  There are no\n"+
          "lights here, as in the rest of the castle, but you seem to notice\n"+
          "a dark glow coming from the ground.\n";
dest_dir=({"players/grimm/closed/vampcastl/castle4","south"});
set_light(1);
}
init() {
   add_action("pull","pull");
   add_action("down","down");
   :: init();
}
pull(str) {
   if(!str) {
      write("Pull what?\n");
   return 1; }
   if ((str!="corpse")&&(str!="body")) return;
   flag = 1;
   write("As you pull the "+str+" a hole in the floor opens up!\n");
   return 1;
}
down() {
   if(!flag) return 0;
   this_player()->move_player("into the hole#players/grimm/closed/vampcastl/castle8");
   flag = 0;
return 1; 
}
monster() {
   object corpse;
   if(!present("corpse",this_object())) {
   corpse = clone_object("players/grimm/object/corpse");
   move_object(corpse,this_object());
   }
return 1; 
}
