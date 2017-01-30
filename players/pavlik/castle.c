#define NAME "Pavlik"
#define DEST "room/eastroad2"

int miniquest_number;
object portal_location;

id(str) { 
  return str == "trail" || str == "mountain trail";
}

short() {
  return "A mountain trail (up)";
}

long() {
  write("A narrow trail leads up the steep mountainside.\n");
  return;
}

init() {
  add_action("up","up");
}

up() {
  write("You decide against climbing the trail.\n");
/*
  this_player()->move_player("up#players/pavlik/guild/mages/room/trail1");
*/
  return 1;
}

reset(arg) {
  object ob;
  object tmp;
  if(arg) return;
  move_object(this_object(), DEST);

  /* Mages Tower */
  ob = clone_object("players/pavlik/guild/mages/tower");
  move_object(ob, "players/saber/ryllian/ayre");

/*
  "/players/pavlik/mages/mage-master2"->load_me();
  "/players/pavlik/mages/mageobj2"->load_me();
*/
  call_other("/players/pavlik/ilstkarn/ilstkarn_portal","???");
  ob = clone_object("players/pavlik/armor/ilstkarn_ring");
  move_object(ob, "players/pavlik/ilstkarn/ilstkarn_portal");
  move_object(ob, DEST);
  move_object(clone_object("players/pavlik/armor/ilstkarn_ring"), "room/wild1");

}

set_portal_location(ob){ portal_location = ob; }
query_portal_location(){ return portal_location; }

query_miniquest_number(){ return miniquest_number; }
is_castle(){ return 1; }

