/* Players can stomp on mound to create ants. Most ants have nothing of value
   although 1 in 10 will have toadstool (ant2), and 1 in 20 will have grapeshot
   (ant3). 1 in 20 chance of anteater showing up instead of ant, to drive players
   away from mound. Anteater should slaughter most players in area. 
   Total of 10 stomps allowed, so players don't camp here */

#define tp this_player()->query_name()
inherit "room/room";
#include <ansi.h>

int A, B;

reset(int arg){
  if(!arg){

B = 0;
    
    set_light(1);
short_desc= (BOLD+BLK+"City of Qual'tor"+NORM+" (Northern Fields)");
    long_desc=
  "After blindly walking through the tallgrass, you come across a small open\n"+
  "area within the fields. A large mound of dirt rises from the soil,\n"+
  "blocking the grass from growing further. A skeleton lies alongside the\n"+
  "mound.\n";

    items=({
  "grass","Tall yellowing grass grows in the place of crops",
  "ruins","The ruins of the city extend to the south from here",
  "field","The fields have long since been forgotten, with noone needing food",
  "fields","The fields have long since been forgotten, with noone needing food",
  "skeleton","A skeleton of what looks to be a human lies next to the mound.\n"+
        "The bones look to have been gnawed upon",
  "mound","A large mound rises from the ground, creating a gap within the tall\n"+
         "grass. You can probably "+HIR+"stomp"+NORM+" upon the mound",
    });

    dest_dir=({
  "/players/daranath/outside/field1.c","south",
    });

    }
  }

init() {
  ::init();
  add_action("search","search");
  add_action("stomp","stomp");
}

    search(){
write("Outside of the mound and skeleton, nothing else of interest is found.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

stomp() {
A = random(15);
  if(B > 9){
write("The mound is empty, nothing else will come out of it.\n");
return 1; }
write("You stomp upon the large mound in the center of the clearing.\n");
B = B + 1;
say(tp+" stomps down upon the large mound.\n");
  if(A < 10) {
move_object(clone_object("/players/daranath/outside/mon/ant.c"),this_object());
write("An ant climbs from the mound, in reaction to your stomping,\n");
return 1; }
  if(A == 10) {
move_object(clone_object("/players/daranath/outside/mon/ant2.c"),this_object());
write("An ant climbs from the mound, in reaction to your stomping.\n");
return 1; }
  if(A == 11) {
move_object(clone_object("/players/daranath/outside/mon/ant2.c"),this_object());
write("An ant climbs from the mound, in reaction to your stomping.\n");
return 1; }
  if(A == 12) {
move_object(clone_object("/players/daranath/outside/mon/ant2.c"),this_object());
write("An ant climbs from the mound, in reaction to your stomping.\n");
return 1; }
  if(A == 13) {
move_object(clone_object("/players/daranath/outside/mon/ant3.c"),this_object());
write("An ant climbs from the mound, in reaction to your stomping.\n");
return 1; }
  if(A == 14) {
move_object(clone_object("/players/daranath/outside/mon/anteater.c"),this_object());
write("An anteater crashes through the tall grass, trying to chase you away.\n");
return 1; }
}
