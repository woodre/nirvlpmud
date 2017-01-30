inherit "room/room";
reset(arg) {
   if(arg)
      return;
short_desc="Forest of Blood";
long_desc="This is one of the entrances to The Forest of Blood.  As you look\n"+
   "around, you notice that no light is able to penetrate through the trees\n"+
   "that tower above you.  The forest has an extremely evil sense to it, as\n"+
   "though this were the shrine of some evil master.  You notice that one of\n"+
   "the trees has something carved into it.  The forest grows darker to the\n"+
   "south.\n",
items=({"tree","               [1mBEWARE!!!!![m\n"+
               "         All who enter the forest\n"+
               "         shall be murdered by the\n"+
               "             Vampire Malachi!\n"});
dest_dir=({"players/grimm/frst/forest9","south",
           "players/grimm/frst/forest24","southeast",
           "players/grimm/frst/forest3","west",
           "players/grimm/frst/forest1","north"});
set_light(0);
}
