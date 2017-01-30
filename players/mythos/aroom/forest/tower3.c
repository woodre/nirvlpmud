#define tp this_player()->query_name()
inherit "room/room";
reset(arg) {
  if(!present("fudo")) {
    move_object(clone_object("/players/mythos/amon/forest/fudo.c"),this_object());
  }
  if(!arg) {
  set_light(-1);
    short_desc = "Tower 3rd Level";
    long_desc =
    "This room is cloaked in darkness.  All is silent.\n"+
    "You peer through the darkness and see a tall man\n"+
    "standing in the corner.\n"+
    "You sense danger here....\n";
  items = ({
    "up","You glance at the stairs leading up... something gives you the shivers",
    "down","The stairs disappear down",
  });

  dest_dir = ({
  "/players/mythos/aroom/forest/tower4.c","up",
  "/players/mythos/aroom/forest/tower2.c","down",
  });
} }

init() {
  ::init();
  this_player()->set_fight_area();
}

/*
exit(ob) { if(!ob) return; ob->clear_fight_area(); }
[attempt to fix strange but w/ shardak mounting dragon] (Jaraxle, 11/15/02)
Following line added to replace noted out line:
*/
exit(){    if(this_player()) this_player()->clear_fight_area();     }
