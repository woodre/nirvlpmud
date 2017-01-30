inherit "room/room";

reset(arg) {
  object door;
  if (arg) return;
  set_light(1);
  short_desc="A marble staircase";
  long_desc=
"  You are on a landing of the huge marble staircase that spirals up\n"+
"the center of the Crystal Tower.  A pair of highbacked antique\n"+
"chairs sit opposite each other in a small alcove with a window\n"+
"that overlooks the clearing beneath the tower.  To the north is\n"+
"a tall stone arch that leads to the tower's chapel.  To the east\n"+
"and west are anonymous looking oak doors.\n";
  items=({
  });
  dest_dir=({
    "/players/feldegast/closed/tower/chapel","north",
    "/players/feldegast/closed/tower/meeting_room","west",
    "/players/feldegast/closed/tower/studio","east",
    "/players/feldegast/closed/tower/tower2","up",
    "/players/feldegast/closed/tower/tower0","down"
  });
  door=clone_object("/players/feldegast/std/door.c");
  door->add_id("door");
  door->add_id("oak door");
  door->set_key("nifty staff");
  door->set_locked(1);
  door->set_open_desc("A strong oak door.\n");
  door->set_close_desc("A strong oak door.\n");
  door->set_destination("/players/feldegast/closed/tower/meeting_room.c");
  door->set_exit("west");
  move_object(door,this_object());
  door->set_partner("door","/players/feldegast/closed/tower/meeting_room.c");
}
