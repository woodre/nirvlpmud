#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
    
    set_light(1);
short_desc= "Storm Mountain (peak)";
    long_desc=
      "The clearing at the top of the mountain spreads about to the east\n"+
      "and northwest from here, large rocky walls encasing the area in\n"+
      "an almost deliberate manner. The dark clouds flash and rumble\n"+
      "overhead, threatening to unleash their fury at you.\n";
                                                                      
    items=({
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "stone", "The dark stone seems to have borne the brunt of the storm\n"+
               "which rages all about you. Blast marks from the lightning\n"+
               "cover the rock all about",
      "rock", "The outcroppings of rock make for an enclosed feel to the\n"+
              "opening within the mountain's peak",
      "clearing", "The clearing within the stone is not typical for a\n"+
                  "mountain",
    });

    dest_dir=({
      "/players/daranath/clearing/marea2.c","east",
      "/players/daranath/clearing/mlair.c","northwest",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
    }

    search(){
    write("You find nothing about the stone and rock.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


