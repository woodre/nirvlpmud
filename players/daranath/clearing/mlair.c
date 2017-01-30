#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
  if(!arg){
move_object(clone_object("/players/daranath/mons/griffin3.c"),this_object());
move_object(clone_object("/players/daranath/mons/griffin3.c"),this_object());
move_object(clone_object("/players/daranath/mons/griffin3.c"),this_object());
move_object(clone_object("/players/daranath/mons/griffin2.c"),this_object());
move_object(clone_object("/players/daranath/mons/griffin1.c"),this_object());
    
    set_light(1);
short_desc= "Storm Mountain (Griffin Lair)";
    long_desc=
  "The blackened stone and rock here has taken another purpose\n"+
  "altogether. Large branches entwined with rocks and sticks are\n"+
  "all woven together to form a large nesting area. Remains of\n"+
  "horse skeletons and other large kills are about, leading you to\n"+
  "wonder if you should even be here.\n";
                                                                      
    items=({
      "clouds", "The dark clouds are very angry in nature",
      "skeleton", "The skeletal horses are long since dead",
      "branches", "Branches make up the bulk of the nest",
      "nest", "The nest is sized for many large birds",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "stone", "The dark stone seems to have borne the brunt of the storm\n"+
               "which rages all about you. Blast marks from the lightning\n"+
               "cover the rock all about",
      "rock", "The rock is clear here, leaving a small flat area that is\n"+
              "the apex of the mountain itself. Perfect for standing on\n"+
              "and viewing the whole of the DarkenWood and Nirvana",
      "marks", "The marks make you think that some god somewhere is\n"+
               "extremly angry at something",
    });

    dest_dir=({
      "/players/daranath/clearing/marea3.c","southeast",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("You find nothing but blackened sorches marks about the\n"+
          "surface of the rocks here at the griffon's lair.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


