#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(!present("berserker_book")){
    move_object(clone_object("/players/guilds/warriors/OBJ/trainer_berserker"), this_object());
}
  if(arg) return;
set_light(1);

short_desc = "Swamp";
long_desc =
	"   It is cramped, dirty, and uncomfortable underneath the massive \n"+
      "tree, but it is safe here. The roots make a wall that the denizens \n"+
      "of the swamp can not penetrate.  The ceiling of this shelter is a \n"+
      "mass of tangled roots and mud.  The ground is a hard-packed black \n"+
      "earth.  To the east is the uncertainty of the swamp. \n"
   ;
      
items = ({
  "tree","A huge tree. It's mass of roots make a natural shelter",
  "ground","Hard-packed black earth",
  "mud","A brackish mud the has tiny handprints in it",
  "handprints","Tiny handprints in the mud",
  "ceiling","A tangled mass of roots and mud which is actually the underside of a tree",
  "wall","A thick barrier of roots that protects you from the denizens of the swamp",
  "swamp","It seems a world away, but is only a few feet to the east",
  "roots","Black gnarled roots as thick as a mans leg",
  "shelter","The wall of roots makes a natural shelter",
});

dest_dir = ({
  "/players/dusan/area1/rooms/swamp11.c","east",
});

}
