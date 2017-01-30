#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Borderlands";
long_desc =
"A long, dusty road with an empty bottle beside it.\n";

items = ({
"bottle","A dirty old bottle with a bug in it",
});

dest_dir = ({
"/players/fakir/workroom.c","up",
"/players/fakir/blands/blx.c", "north",
});

}
