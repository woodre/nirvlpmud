#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Borderlands";
long_desc =
"The wind is harsh and whips the dust from the rocky path\n"+
"into your eyes and nose.  These are the Boarderlands, barren\n"+
"and arid, almost without life.  You would be wise to check your\n"+
"canteen and ration sack, for food and drink are scarce in this\n"+
"region of the country.  The path drags you north.\n";

items = ({
"dust","Grainy and annoying, it blows into your eyes and nose.",
"path","Strewn with sharp rocks, it is difficult to travel.",
});

dest_dir = ({
"/players/fakir/workroom.c","up",
"/players/fakir/blands/room3.c", "north",
});

}
