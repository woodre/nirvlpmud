#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!present("skeleton 3")) {
move_object(clone_object("/players/daranath/mons/skel_war1.c"),this_object());
move_object(clone_object("/players/daranath/mons/skel_war1.c"),this_object());
move_object(clone_object("/players/daranath/mons/skel_war1.c"),this_object());
  }
  if(!arg){
    
    set_light(1);
short_desc= ("Storm Mountain (Peak)");
    long_desc=
      "Smooth and flat stone lay all about, not what you would expect\n"+
      "for the top of a large mountain. Sharp rock outcroppings surround\n"+
      "the unusual clearing, giving it an enclosed and secure feel. The\n"+
      "area spreads out to the east and west, while just to the north, a\n"+
      "set of wide stairs climb up onto another level.\n";

    items=({
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "stone", "The dark stone seems to have borne the brunt of the storm\n"+
               "which rages all about you. Blast marks from the lightning\n"+
               "cover the rock all about",
      "stairs", "The wide steps that lead up to another level within the\n"+
                "clearing are not natural by any means. They look as if\n"+
                "the lightning from the dark clouds overhead have caused\n"+
                "these to form, leading onto the unknown",
      "rock", "The outcroppings of rock make for an enclosed feel to the\n"+
              "opening within the mountain's peak",
      "clearing", "The clearing within the stone is not typical for a\n"+
                  "mountain",
    });

    dest_dir=({
      "/players/daranath/clearing/mapex.c","north",
      "/players/daranath/clearing/mpeak.c","south",
      "/players/daranath/clearing/marea4.c","east",
      "/players/daranath/clearing/marea2.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    add_action("dar_north","north");
    }

    search(){
    write("You find nothing about the stone and rock.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_north() {
  if(present("secret secret alias thingy")) {
  write("The skeleton stands in your way, protecting the warlord.\n");
  return 1; }
return 0;
}
