#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
move_object(clone_object("/players/daranath/closed/stuff/warr.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_knight1.c"),this_object());
move_object(clone_object("/players/daranath/mons/un_knight2.c"),this_object());
move_object(clone_object("/players/daranath/mons/skel_war1.c"),this_object());
move_object(clone_object("/players/daranath/mons/skel_war1.c"),this_object());
  if(!arg){
    
    set_light(1);
short_desc= ("Storm Mountain (Apex)");
    long_desc=
      "The dark clouds overhead seem to center on this area, the apex of\n"+
      "the entire mountain itself. Black sorch marks run about the ground\n"+
      "as if the fury of the gods have presented themselves in force.\n"+
      "A series of candles have been lit upon one side of the rock,\n"+
      "making it seem as if someone was worshipping here. Stairs run to\n"+
      "the south from here.\n";
                                                                      
    items=({
      "clouds", "The dark clouds are very angry in nature",
      "lightning", "Flashed of blue and bright yellow energy cross the\n"+
                   "dark clouds in an agressive manner",
      "stone", "The dark stone seems to have borne the brunt of the storm\n"+
               "which rages all about you. Blast marks from the lightning\n"+
               "cover the rock all about",
      "candle", "Each small candle is white and seemingly freshly lit",
      "candles", "The candle are laid out in a specific pattern, set up\n"+
                 "so they are almost mesmorizing to the sight. They seem\n"+
                 "to draw you in to thier dancing flames",
      "rock", "The rock is clear here, leaving a small flat area that is\n"+
              "the apex of the mountain itself. Perfect for standing on\n"+
              "and viewing the whole of the DarkenWood and Nirvana",
      "marks", "The marks make you think that some god somewhere is\n"+
               "extremly angry at something",
    });

    dest_dir=({
      "/players/daranath/clearing/marea1.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search_room");
    }

    search(){
    write("You find nothing but blackened sorches marks about the\n"+
          "surface of the rocks here at the mountain's apex.\n");
    say(tp +" searches the area.\n");
     return 1;
    }


