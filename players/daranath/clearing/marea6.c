#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("earth")){
move_object(clone_object("/players/daranath/mons/earth_ele1.c"),this_object());
}
  if(!arg){
    
    set_light(1);
short_desc= "Storm Mountain (Peak)";
    long_desc=
      "The clearing within the mountain top ends here, leading only to\n"+
      "the south. Blackened marks amongst the rocks serve as notice for\n"+
      "the lightning overhead, constantly reminding you of the danger\n"+
      "all about this area of the mountain.\n"+
      "A small cave mouth opens up in the rock to the north.\n";
                                                                      
    items=({
"cave","The cave mouth has been intricatly carved with various glyphs and\n"+
     "wards dedicated to the Earth Domain of magic",
      "mouth", "The cave mouth is filled with shadows",
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
      "/players/daranath/clearing/marea5.c","south",
      "/players/daranath/clearing/geo1.c","north",
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
if(present("earth")) {
write("The Earth Elemental blocks your path into the geomancer hall.\n");
return 1; }
return 0;
}

