#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "A Muddy Road.";
long_desc =
	"You stand at the entrance to a dark and forboding swamp. \n"+
      "The area ahead seems to darken, even though the trees and \n"+
      "vines in the area dont seem to give enough cover to block out \n"+
      "the sunlight.  The entire area seems to give off a foul odor. \n"+              	
      "The swamp continues to the south, and to the east is small \n"+
      "rundown village. \n"
      ;
      
items = ({
  "trees","The bare trees look like blackened skeletal hands",
  "vines","These vines grow in abundance here choking out the rest of the vegetation",
  "swamp","A dark marshy area south of here" 
});

dest_dir = ({
  "/players/dusan/area1/rooms/room2.c","south",
  "/players/dusan/area1/rooms/twn1.c","east",
});

}
