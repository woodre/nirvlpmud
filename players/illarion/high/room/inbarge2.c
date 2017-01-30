inherit "players/illarion/room";
#include "/players/illarion/dfns.h"
void reset(int arg) {
  if(!present("Duncan MacLeod",this_object()))
    move_object(clone_object(HMON+"duncan"),this_object());

  if(arg) return;
  set_light(1);
  set_short("The refurbished hold of a barge");
  set_long(
"If not for the portholes along either wall, and the slight swaying of the "+
"room, there would be no evidence you were in the hold of a cargo barge, "+
"and not in a penthouse apartment.  The walls are panelled in the finest "+
"wood, and the bed to the south is large and made up in what looks like "+
"black satin sheets.  A couple of bedside tables and a chest of drawers "+
"would complete the illusion of a bedroom, but for the lack of any divider "+ 
"from the rest of the barge other than a couch.  The walls are hung with "+
"a variety of different kinds of artwork. Beyond the couch to the north is "+
"the rest of the barge, and there is a back way out behind the bed, but "+
"it appears to be blocked off.");
  add_item("portholes","On one side, you can see only stone, but the "
                      +"portholes on the opposite side give a good view of "
                      +"a river, and a stone bank on the far side.");
  add_item("bed","A large bed, and the owner apparently uses it for more "
                +"than sleeping, judging by the sheets.");
  add_item("sheets","Black satin.  Very interesting.");
  add_item("tables","The bedside tables look very old, but are beautifully "
                   +"shaped and in good condition.");
  add_item("chest","An antique chest of drawers, with, oddly, almost no "
                  +"clutter on the top.");
  add_item("couch","The back of a couch marks the edge of the bedroom area.");
  add_item("artwork","Sketches, paintings, and sculptures, all in "
                    +"exquisite taste.");

  add_exit("north",HROOM+"inbarge1");
}
