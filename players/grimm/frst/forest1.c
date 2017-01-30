inherit "room/room";
reset(arg) {
   if(arg)
      return;
   short_desc="Long Dirt Path";
   long_desc="You start to walk along a very long path.  To the north\n"+
      "you can see some sort of street, but you can't make it out very well.\n"+
      "To the south the path continues to grow thicker into what looks to be\n"+
      "a large and extremely dark forest.  There are small rocks scattered\n"+
      "all around this path.  As you think about the direction you should\n"+
      "take, the blood in your veins starts to boil, as if it is threatened\n"+
      "by what lies beyond to the south. (This is weird-blood being scared?)\n",
      items=({"rocks","The rocks seem to have a misting of blood on them"});
   dest_dir=({"players/grimm/street1","north",
      "players/grimm/frst/forest4","south"});
   set_light(1);
}
