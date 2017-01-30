#define tp this_player()->query_name()
#include <ansi.h>
inherit "room/room";

reset(int arg){
  if(!present("cotrone")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/mon/cotrone.c"),this_object());
  }
  if(!present("sign")) {
move_object(clone_object("/players/daranath/qualtor/newstuff/obj/knightshop.c"),this_object());
  }
  if(!arg){
    
    set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Market Square)");
    long_desc=
"You quickly begin to wonder if you have entered a shop or an armory within\n"+
"Qual'tors market square. Racks of weapons and various pieces of armor line\n"+
"the walls, while others are on display within and on top of a long counter.\n"+
"Everything is meticulously kept and in perfect condition, ready to outfit a\n"+
"small garrison in a moments notice.\n"+
"A sign on the far wall lists the various items for sale.\n";

    items=({
"armory","The room looks like an armory with all the weapons about",
"weapons","Various weapons are placed around the shop for sale",
"armor","Several pieces of armor and suits of mail are for sale here",
"walls","The walls are lined perfectly with weapons and armors",
"counter","The long wooden counter is very clean and perfect for a shop like this",
"square","The market square is just outside the store to the south",
    });

    dest_dir=({
      "/players/daranath/qualtor/newstuff/marketsq.c","south",
    });

    }
  }

    init(){
      ::init();
    add_action("search","search");
add_action("ask_cotrone","ask");
    }

    search(){
    write("There are way too many items to search here. You could\n"+
          "spend days looking through everything.\n");
    say(tp +" searches the area.\n");
     return 1;
    }

ask_cotrone() {
if(this_player()->query_money() < 100) {
write("Cotrone says: You don't have enough money to spend in here, so what's the point?\n"+
      "     He then scoffs at you and turns back to his work.\n");
return 1; }
write("Cotrone says: You want to know about my wares? No problem...\n\n"+
      "The Chain Coif can be worn as a helmet\n"+
     "The shields are basic protection types\n"+
     "The surcoat of Qual'tor is an old favorite, once worn by\n"+
      "     the guards in the city\n"+
      "The signet ring can tell others were you hail from\n"+
      "Armored Boots are a staple of any warrior\n"+
      "Chainmail is basic protection\n"+
      "Once carried by the Paladins of the Realm, the Crusader Blade\n"+
      "     was discarded in favor of Holy Blades to fight evil\n"+
      "The Guardian platemail offers excellent protection in a fight\n\n"+
      "You tip Cotrone "+YEL+"100"+NORM+" coins and he thanks you.\n");
  this_player()->add_money(-100);
return 1;
}
