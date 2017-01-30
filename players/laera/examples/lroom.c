inherit "room/room";
#include "/players/laera/closed/ldef.h"
#include "/players/laera/closed/ansi.h"

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "shrt";
long_desc =
	"long";

items = ({
  "item","Description of the item",
});

dest_dir = ({
  "/players/name/path","direction",
});

}
