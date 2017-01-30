#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

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
