#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!present("randal")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/mon/randal.c"),this_object());
  }
  if(!present("sign")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/obj/potionshop.c"),this_object());
  }
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Market Square)");
    long_desc=
  "The countertop here is splashed with chemicals and covered in grime,\n"+
  "making you wonder exactly why you are shopping here. Various vials, beakers\n"+
  "and jars line the shelves, strange liquids and glowing oozes ready to\n"+
  "be purchased, if you can stand the filth.\n"+
  "A sign on the far wall lists the various items for sale.\n";

    items=({
     "shelves","The shelves are mostly made of wood",
     "curtain","A black curtain covers the entrance to the back room",
     "doorway","The doorway leads somewhere you cannot go",
     "counter","The counter also displays items for sale",
    });

    dest_dir=({
      "/players/daranath/qualtor/newstuff/marketsq.c","west",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
     add_action("dar_list","list");
add_action("ask_randal","ask");
    }

    search(){
    write("There are way too many items to search here. You could\n"+
          "spend days looking through everything.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

dar_list() {
write("Perhaps you should just l at the sign.\n");
  return 1;
}

ask_randal() {
if(this_player()->query_money() < 100) {
write("Randal doesn't seem interested in helping, due to your light coinpurse.\n");
return 1; }
write("Randal says: You want to know about my wares?  sure thing...\n\n"+
      "The Toadstool is a very weak and cheap bit of food.\n"+
      "The Grapeshot is a bit better, although also quite weak\n"+
      "The wheel of cheese is a Qual'tor classic, and my customers demanded\n"+
      "     that I carry it. A favorite piece of food in these parts\n"+
      "The Turkey Leg is a favorite amongst the newer explorers in the region\n"+
      "The Luminescent Slime is one of my specialties. It restores ones magical\n"+
      "     qualities, while leaving health untouched\n"+
      "The Bottle of Red Wine is another Qual'tor classic\n"+
      "The Tin of Healing Salve is another Qual'tor classic\n"+
      "The Jello Shot is a highly powerful and intoxicating heal\n"+
      "Gelantinous Ooze is another of my favorites. It not only heals your body\n"+
      "     but takes care of the soul as well\n"+
      "And finally, The highly magical potion of healing cures everything that you need\n\n"+
      "You tip Randal "+YEL+"100"+NORM+" coins and he thanks you.\n");
  this_player()->add_money(-100);
return 1; 
}

