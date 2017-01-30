inherit "/players/persephone/closed/thingys.c";
reset (arg){
 if(arg) return;
  set_light(1);
  short_desc="Dark Path";
  long_desc="You are travelling along a small dark path which appears to bend further\n" +
            "to the south. To the north you think you can just make out a dell while\n" +
            "to the east and the west the path is bordered by trees which appear\n" +
            "to become thicker to the south and east\n" +
            "\n";
  dest_dir=({"players/persephone/rooms/hall","north",
             "players/persephone/rooms/junpata","south",
  });
}
