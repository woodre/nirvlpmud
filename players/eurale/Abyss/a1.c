#define tpn this_player()->query_name()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(0);

short_desc = "The Abyss";
long_desc =
  "  You have stepped into what appears to be nothingness.  The dark-\n"+
  "ness that surrounds you has an eerie stillness to it.  The only\n"+
  "thing that you can definitely identify is your fear...  Something\n"+
  "'feels' very close and it frightens you...\n";

items = ({
});

dest_dir = ({
	"players/eurale/Abyss/a2.c","down",
	"players/eurale/Abyss/entry2.c","portal",
});

}
realm() { return "NT"; }
