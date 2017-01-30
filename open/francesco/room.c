#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
inherit "players/francesco/univ/junk/add.c";

reset(arg) {
  if(arg) return;

if (!present("receptionist")) {
  move_object(clone_object("/players/francesco/closed/monsters/mons1.c"),
	this_object()); }
set_light(1);

short_desc = "University";
long_desc =
  "This is the University.  There is a large grass quad with\n"+
  "concrete sidewalks intersecting at the center.  Huge, old\n"+
  "trees provide shade to the rustic old buildings.\n";

items = ({
  "trees","Large old oaks with benches underneath for studying",
});

dest_dir = ({
  "/players/francesco/univ/room2.c","north",
});

}
