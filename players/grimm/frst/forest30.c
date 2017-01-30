inherit "room/room";
reset(arg) {
   if(arg)
      return;
   short_desc="Long Dirt Path";
   long_desc="You start to walk along a very long path.  To the north you\n"+
      "can see some sort of street, but you can't make it out very well.\n"+
      "There is also a path leading into the town circle to the west and to\n"+
      "the south the path continues to grow thicker into what looks to be\n"+
      "a large and extremely dark forest.  There are small rocks scattered\n"+
      "all around this path.  As you think about the direction you should\n"+
      "take, the blood in your veins starts to boil, as if it is threatened\n"+
      "by what lies beyond to the south. (This is weird-blood being scared?)\n",
      items=({"rocks","The rocks seem to have a misting of blood on them"});
   dest_dir=({"players/grimm/street7","north",
              "players/grimm/frst/forest31","south",
              "players/grimm/street8","west"});
   set_light(1);
}
