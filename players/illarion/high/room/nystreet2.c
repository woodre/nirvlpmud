inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  object ob;
  int x;
  for(x=1;x<=3;x++) if(!present("patron "+x,this_object())) {
    ob=clone_object("obj/monster");
    call_other(HMON+"patron_gen","patron_generator",ob);
    move_object(ob,this_object());
  }
  if(arg) return;

  set_light(1);
  short_desc="A New York City Street";
  long_desc=
"A typical big city street stretches out east and west, littered\n"+
"with the usual garbage and litter.  To the north, a large neon sign\n"+
"advertises \"Joe's Bar\".  At first glance it looks like any other\n"+
"place, but something about it tells you it is special.  Opposite the bar\n"+
"is a dark, boarded up building.\n";

  items= ({
    "street","A street that could belong to any big city",
    "garbage","I'll be nice and let you reconsider",
    "litter","You'd put it in a trash can, but there aren't\n"+
              "any of those around",
    "sign","The sign is red, and in good working order",
    "bar","New York is of course full of small bars, but this\n"+
          "one somehow seems to not be one of those",
    "building","Concrete block with boarded up windows"
  });
  dest_dir= ({
    HROOM+"nystreet","east",
    HROOM+"barcoat","bar",
  });
}
