#include "../def.h"
inherit MYROOM;
reset(arg) {
  if(!present("cow")) {
    move_object(clone_object(PATH+"Farm/cow"),this_object());
  }
  if (arg) return;
  set_light(1);
  short_desc="A Farm";
  long_desc=
"     This is a meadow nestled between the shade of two hills.\n"+
"On the west side of the meadow is a big red barn, and on the\n"+
"east side is a farmhouse.  An unpainted fence pens in a herd\n"+
"of livestock in between the two buildings.  To the southeast\n"+
"a path leads up the slope of one of the hills.\n";
  items=({
    "hills","The two ridges form a small valley",
    "barn","A big red barn with a large open door",
    "farmhouse","The farmhouse is a long building painted pale blue\n"+
                 "and with a flat roof",
    "fence","The weathered old fence is formed by crudely chopped logs",
    "path","The path leads up the southern slope at an angle then\n"+
            "doubles back onto itself before it reaches the top",
    "slope","The rocky slope is covered in plants, but is still too\n"+
            "steep to climb easily",
  });
  dest_dir=({
    PATH+"Farm/barn","barn",
    PATH+"Farm/house","house",
    PATH+"Farm/path1","southeast",

  });
}   
