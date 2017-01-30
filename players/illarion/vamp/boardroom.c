#include "/players/eurale/defs.h"
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(0);

short_desc = "Vampire Meeting Room";
long_desc = "\
The Vampire meeting room is a tall, spacious hall, with a floor of cool grey\n\
stone interrupted by warm pools of light from the many elaborate black iron\n\
sconces lining the walls.  An enormous antique oak conference table\n\
surrounded by thickly padded leather-bound roller chairs dominates the room,\n\
its top shined to a mirror finish.  A matching sideboard rests along the east\n\
wall, its cabinet doors closed securely to conceal a variety of supplies.\n\
An oversized fireplace mid-way down the north wall warms the air and casts\n\
a flickering golden light across the room.\n";

items = ({
  "floor", "\
The dark grey stone of the floor is worn smooth with centuries of use",
  "sconces", "\
Black iron sconces twisted into intricately woven patterns punctuate the\n\
long walls of the room, each bearing three fat, flickering candles",
  "candle", "\
Thick candles rest in black iron sconces situated throughout the room",
  "candles", "\
Thick candles rest in black iron sconces situated throughout the room",
  "wall", "\
The dark grey stone of the walls is thick enough to muffle all sound from\n\
outside the room",
  "walls", "\
The dark grey stone of the walls is thick enough to muffle all sound from\n\
outside the room",
  "table", "\
The rectangular conference table appears to be centuries old, and can seat\n\
at least forty people",
  "chair", "\
The black leather high-backed chairs are on silent casters, and appear to\n\
be the only remotely modern furniture in the room",
  "chairs", "\
The black leather high-backed chairs are on silent casters, and appear to\n\
be the only remotely modern furniture in the room",
  "sideboard", "\
The antique oak sideboard has intricately carved scroll-work running up all\n\
four corners, as well as sigils carved into both of the front cabinet doors\n\
and the single large drawer\n\
The doors are securely shut, but you could "+HIW+"peek"+NORM+" inside",
  "cabinet", "\
The antique oak sideboard has intricately carved scroll-work running up all\n\
four corners, as well as sigils carved into both of the front cabinet doors\n\
and the single large drawer\n\
The doors are securely shut, but you could "+HIW+"peek"+NORM+" inside",
  "doors", "\
The doors are securely shut, but you could "+HIW+"peek"+NORM+" inside"
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/titles","south",
  "players/eurale/VAMPIRES/RMS/vguild_hall","west",
});

}

query_smell() { 
  return "\
The musky scent of the wood fire intermingles with the dark smell of leather\n\
and wood oil, but cannot entirely mask the faint coppery scent of old blood\n\
that permeates the room.\n";
}
query_sound() {
  return "\
The soft crackle of the fire, punctuated by the occasional popping of one\n\
of the logs, is the only sound in the otherwise profound silence of the room.\n";
}

realm() { return "NT"; }

init(arg) {
  ::init(arg);
  add_action("cmd_peek","peek");
}

cmd_peek(string str) {
  if(str != "inside cabinet" && str != "cabinet" && str !="doors" &&
     str != "inside doors" && str != "sideboard" && 
     str !="inside sideboard") {
    notify_fail("Peek inside what?\n");
    return 0;
  }
  say(this_player()->query_name() + " peeks inside the sideboard.\n");
  write("\
The sideboard is fully stocked for nearly any Vampire event.  An impressive\n\
selection of knives, ranging from tiny, razor-sharp paring knives to\n\
enormous, wickedly edged daggers, fills the drawer.  Tent-sized tablecloths\n\
are folded neatly on the bottom shelf of the cabinet, topped by stacks of\n\
folded linen napkins.  Rows of silver and crystal goblets hang from a rack\n\
just above the linens. On the top shelf are writing implements from nearly\n\
every era, as well as paper, parchment, and papyrus. The spacious middle\n\
shelf is stacked to overflowing with coiled rope, thin silver chain, thicker\n\
iron chain, leather straps, various sized manacles, and opaque black hoods,\n\
all of which have clearly seen heavy use at countless previous Vampire\n\
feasts.\n");
  return 1;
}