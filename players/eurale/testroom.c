#define tp this_player()->query_name()
#define TO this_object()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";
int shield;

reset(arg) {
if(!present("machine")) {
  move_object(clone_object("players/eurale/OBJ/vend"),TO); }
if(!present("doom")) {
  move_object(clone_object("players/eurale/NPC/doom"),TO); }

  if(arg) return;
set_light(-1);

short_desc = "The Testing Station";
long_desc =
  "  This is the testing station for Eurale's creations.  You are apt\n"+
  "to encounter anything here that he has dreamed up.  DO NOT attempt\n"+
  "to remove anything from here without permission.  Doing so will put\n"+
  "you in harms way for sure so BE WARNED!!\n";

items = ({
});

dest_dir = ({
	"room/church.c","church",
  "players/eurale/workroom","north",
});

}
init() {
  ::init();
  add_action("on","on");
  add_action("off","off");

if(this_player()->query_real_name() != "eurale" && shield == 1) {
  write("You feel an electric shock and are blinded by a "+HIY+
    "FLASH OF YELLOW"+NORM+" as you\n"+
    "deflect off some kind of force field...\n");
  this_player()->move_player("off the shield#room/church"); }
}

static on() {
  shield = 1;
  write("You "+BOLD+"activate"+NORM+" the shields.\n");
return 1; }

static off() {
if(this_player()->query_real_name() != "eurale") {
  write("You have NO AUTHORITY to do that!\n");
  return 1; }
  shield = 0;
  write("You "+BOLD+"deactivate"+NORM+" the shields.\n");
return 1; }
