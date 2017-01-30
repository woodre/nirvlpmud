inherit "room/room";
reset(arg) {
  if(!present("benkei")) {
    move_object(clone_object("/players/mythos/amon/forest/benkei.c"),this_object()); }
  if(!arg) {
  set_light(0);
  short_desc = "Bridge2";
    long_desc =
    "You stand upon the bridge- the raging river far below you.\n"+
    "Before you stands a man of great girth.  Beyond you see a tower.\n";
  items = ({
    "back","You may go back to toward the forest",
    "cross","You see an odd tower before you",
    "bridge","The bridge is made of sturdy wood",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/bridge.c", "back",
    "/players/mythos/aroom/forest/tower.c","cross",
  });
} }

init() {
  ::init();
  add_action("cross","cross");
}

cross() {
  object ob;
  ob = present("benkei");
  if(present("benkei")) {
    write("Benkei blocks you way and demands a duel.\n");
    say("Benkei moves to block "+this_player()->query_name()+" and demands a duel.\n");
  return 1; }
  if(!present("benkei")) {
    call_other(this_player(),"move_player","cross#players/mythos/aroom/forest/tower.c");
    say(this_player()->query_name()+" crosses the bridge.\n");
  return 1; }
}

run() {
  object ob2;
  ob2 = present("benkei");
  if(present("benkei")) {
  write("You run by Benkei and head toward the tower.\n"+
    "What a COWARD!\n");
  say(this_player()->query_name()+" runs past Benkei.  What a COWARD!\n");
  this_player()->set_title("the COWARD");
  this_player()->set_pretitle("I am a COWARD says ");
  this_player()->set_al_title("COWARD");
    call_other(this_player(),"move_player","run#players/mythos/aroom/forest/tower.c");
  return 1;
}}
