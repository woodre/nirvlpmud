inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  object ob;
  int x;
  for(x=1;x<=2;x++) if(!present("patron "+x,this_object())) {
    ob=clone_object("obj/monster");
    call_other(HMON+"patron_gen","patron_generator",ob);
    move_object(ob,this_object());
  }
  if(arg) return;

  set_light(1);
  short_desc="A coatroom";
  long_desc=
"A dim overhead light just barely outlines a deep alcove holding a\n"+
"large coat rack hung with a number of coats.    A narrow dorway leads\n"+
"north to one end of the bar, and opposite that a door leads out to\n"+
"the street.  Although nothing is overly fancy, everything is in better\n"+
"condition than you expected at first.\n";

  items= ({
    "coat rack","Beat up metal with projections to hang coats on",
    "coats","The coats of the bar's guests.  None of them\n"+
            "are anything special, and of course no one would leave\n"+
            "valuables in an open coat room",
    "doorway","A wood-framed doorway into tbe bar proper",
    "bar","It actually looks pretty friendly",
    "street","A dour, dangerous city street waits outside",
    "door","The bar's door is solid but presentable"
  });
  dest_dir= ({
    HROOM+"bar","north",
    HROOM+"nystreet2","out",
  });
}
