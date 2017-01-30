#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
   if(!arg) {
set_light(3);
short_desc = YEL+"Courtyard "+NORM;
long_desc = YEL+
 "   Once within the castle gates, a small city appears.  First the\n"+
 "houses near the outer-walls, then cobbled-streets lined with brick\n"+
 "structures rising up like stone crops to greet the misty sunlight.\n"+NORM; 

items = ({
  "city","The city appears to be small but very active",
  "gates","The gates are made of thick wood and are very strong",
  "castle gates","The gates are made of thick wood and are very strong",
  "houses","The houses are additional dwellings for the peasants and nobles\n"+
           "living within the castle walls",
  "streets","The streets are made from cobbled-stones and lead to all\n"+
            "directions within the city",
  "cobbled streets","The streets are made from cobbled-stones and lead to all\n"+
                    "directions within the city",
  "structures","The various structures built within the city walls consist of\n"+
               "shops, pubs, houses, and towers to provide the needs of the\n"+
               "citizenry that live here",
  "walls","The walls surround the city and protect the castle",
  "outer-walls","The walls surround the city and protect the castle",
  
});

dest_dir = ( {
    "players/nikki/Tintagel/Rooms/entrance.c", "backward",
    "players/nikki/Tintagel/Rooms/square.c", "forward",
});
}}
init() {
  ::init();
    add_action("looke","look");
    add_action("lookee","l");
}

looke(str) {
  if(str != "sunlight" && !str){
    return 0;
    }
  if(str == "sunlight" || str == "at sunlight"){
    TP->heal_self(-10);
    write(BLINK+HIY+"You feel a piercing pain in your eyes!\n"+NORM);
    say(capitalize(TP->query_name())+" cringes and turns "+TP->query_possessive()+" head.\n");
    return 1;
    }
}

lookee(str) {
  if(str != "sunlight" && !str){
    return 0;
    }
  if(str == "sunlight" || str == "at sunlight"){
    TP->heal_self(-15);
    write(BLINK+HIY+"You feel a piercing pain in your eyes!\n"+NORM);
    say(capitalize(TP->query_name())+" cringes and turns "+TP->query_possessive()+" head.\n");
    return 1;
    }
}


