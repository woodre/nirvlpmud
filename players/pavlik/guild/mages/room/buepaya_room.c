#include "/players/pavlik/guild/mages/defs.h"
inherit "/players/pavlik/guild/mages/inherit/room";
inherit "room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc=HIM+"Buepaya's"+NORM+MAG+" Chambers"+NORM;
  long_desc=
	"You have walked into the peaceful solitude of Buepaya's chambers.\n"+
	"The smell of incense fills the air and large "+GRN+"green ferns"+NORM+" provide\n"+
	"a natural decor.  Buepaya spends most of her time here in meditation.\n"+
	"A small "+HIW+"fountain"+NORM+" bubbles in the corner.  A door to the north leads out\n"+
	"and a door in the west wall leads to Buepaya's private rooms.\n";

  items=({
    "incense",
	"Dozens of incense candles are placed about the room.  They\n"+
	"permeate the air with a pleasant odor and provide gentle\n"+
	"lighting to the room",
    "ferns",
	"The rooms is full of lush plant life.  The ferns give you\n"+
	"a sense of peace and harmony with nature",
    "fountain",
	"A tiny fountain bubbles away quietly.  You spot several fish\n"+
	"swimming inside of its bowl",
    "fish",
	"Several different breeds of fish swim happily inside the fountain",
  });

  dest_dir=({
	ROOM_DIR+"masters_hall",	"north",
	"null",				"west",
  });

  if(!present("buepaya", this_object()))
	move_object(clone_object(NPC_DIR+"buepaya"), this_object());

}

query_mguild(){ return "Buepaya's"; }

init(){
  ::init();
  if(!mage_check()) return;
  add_action("guild_move","gm");
  add_action("no_way","west");
}

no_way()
{
  write(
  "You move towards the western door and the burning candles\n"+
  "flare alarmingly.  You think better of going there.\n");
  say("The candles flare brightly for a moment.\n");
  return 1;
}

