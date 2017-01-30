inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Wall of Passage";
    long_desc =
    "Before you is a Great Wall of Mist.  Behind you is the sea,\n"+
    "before you- who knows.  'Pass' beyond the wall if you dare.\n";
  items = ({
    "wall","A Great Wall of Mist.  It seems to pulse and light streams from it.",
    "sea","The sea is behind you, it seems to be waiting for something.",
    "mist","The mist seems to swirl and glow.  You peer beyond it, but you cannot see anything.",
  });

  dest_dir = ({
    "/players/mythos/entrance.c", "pass",
    "/room/sea.c","west",
  });
} }
