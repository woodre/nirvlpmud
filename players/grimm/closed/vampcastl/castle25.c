inherit "room/room";
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Castle Hall";
long_desc="You have entered the castle of Malachi.  It seems that the entire\n"+
   "castle is very dark from here, as if who ever lives here hates light.\n"+ 
   "You notice that there are many creatures in the castle and as they\n"+
   "turn they notice you!!!!!!\n";
dest_dir=({"players/grimm/closed/vampcastl/castle2","west"});
set_light(1);
}
init(arg) {
   int count;
   object monster;
   if(!present("werewolf"))
      while (count < 5)  {
         monster = clone_object("players/grimm/monster/werewolf");
         move_object(monster,this_object());
         count += 1;
      }
   add_action("west","west");
   add_action("west","w",1);
   ::init();
}
west() {
this_player()->move_player("west#/players/grimm/closed/vampcastl/castle2");
return 1;
}
