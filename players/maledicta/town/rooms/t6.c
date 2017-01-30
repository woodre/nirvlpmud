#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
#define guard4 "/players/maledicta/town/mobs/guard4.c"

inherit "room/room";
int i;
reset(arg) {
if(!present("civilian", this_object())) {
    for(i=0; i < 4; i++) {
      move_object(clone_object("/players/maledicta/town/mobs/civilian.c"),
      this_object());
    }
   } 	
if(!find_object(guard4)){
move_object(guard4, this_object());
}	
  if(arg) return;
set_light(1);

short_desc = ""+HIG+"Derellia IV"+NORM+"";
long_desc =
" Here the road veers to the north, following the defense wall. Numerous\n"+
"houses line the street to your left, their well kept yards and gardens\n"+
"giving the town a quaint feel. A huge white building can be seen from\n"+
"here, towering high over the lower trees in this area. To the north the\n"+
"road continues, as well as back to the west.\n";

items = ({
  "road",
  "A well constructed road made of stone, it is clean and smooth",
  "wall",
  "The towns defensive wall. It is made of stone and steel, and is surrounded\n"+
  "by an energy field",
  "field",
  "A shimmering field of energy that strengthens the wall",
  "houses",
  "Small to medium in size, and made with white stone, each is made to be sturdy\n"+
  "and yet blend with the town",
  "street",
  "A well constructed street made of stone, it is clean and smooth",
  "yards",
  "Green and healthy, each yard is well-kept",
  "gardens", 
  "Full of beautiful flowers and small plants, each is taken good care of by its\n"+
  "owner",
  "building",
  "Standing tall and proud, it is made from white stone and steel plates and beams,\n"+
  "giving it a strong look and yet beautiful in its own right",
  "trees",
  "The trees here are only slightly shorter, but blend with the houses and foliage\n"+
  "unlike any other town you have visited",
});

dest_dir = ({
  "/players/maledicta/town/rooms/t7.c","north",
  "/players/maledicta/town/rooms/t2.c","west"
});

}
init(){
  ::init();
  this_player()->set_fight_area();
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }
	