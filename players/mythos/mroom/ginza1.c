inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!present("seller")) {
    move_object(clone_object("/players/mythos/mmisc/drugs/seller.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Ginza>> ";
    long_desc =
    "                       Ginza\n\n"+
    "You step upon the streets of Ginza.  People swarm by, each person\n"+
    "searching for that one product that would liven up their daily life.\n"+
    "Some search from window to window, looking in and drooling over items\n"+
    "that they wish they could get.\n";
  items = ({
    "in","Ginza station.. to get onto the trains...",
    "west","Towards Juliana's- the hottest place on earth",
  });

  dest_dir = ({
    "/players/mythos/mroom/ginza.c","in",
    "/players/mythos/mroom/juliana0.c","west",
  });
} }
