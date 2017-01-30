#define tp this_player()
#define tpn this_player()->query_name()
#include "/players/eurale/closed/ansi.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "Fiendsville";
long_desc =
	"  This is an eerie place.  The shrubbery has been left unattended\n"+
	"for so long that it's grown out of control.  Thorny bushes grow\n"+
	"in abundance everywhere but they seem particulary thick in this\n"+
	"area.  The huge weeping willow trees cast long, dark shadows..\n"+
	"making it impossible to see.\n";
	

items = ({
	"bushes","These dense, tall bushes with 2 inch thorns on it's\n"+
		"branches provide a great cover for the hidden path\n"+
		"that's behind them.  Maybe if you search, you can find\n"+
		"a way to the path",
	"trees","Old trees with branches that reach the ground",
	"shrubbery","Various bushes and vines, all out of control",
});

dest_dir = ({
	"players/eurale/Fiend/mm28.c","east",
});

}
init() {
  ::init();
  add_action("search","search");
  tp->set_fight_area();
}

search(str) {
if(!str) { write("You need to search something...\n"); return 1; }
if(str == "path" || str == "bushes") {
  write("You plunge through the thorns and follow the path..\n");
  say(tpn+" plunges into the thorns and disappears....\n");
  tp->move_player("path#players/eurale/Fiend/mm30.c"); return 1; }
}
