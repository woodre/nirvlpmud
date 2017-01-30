inherit "room/room";

reset(arg) {
   if(!present("vendor")) move_object(clone_object("/players/llew/monsters/heal_seller"),this_object());
if(!arg) {
   set_light(1);
   short_desc="Caer Dyvi Market";
   long_desc="\tThe path from the east becomes a clearing spread with\n"+
         "stalls of crops, livestock, and goods for barter.  A few caer-folk\n"+
         "bring in their commodities for sale.  The wall of the caer\n"+
         "rises to the north and east of the market area, cutting off all\n"+
         "but the tallest trees from view.  The eastern path leads\n"+
         "back to the caer entrance.\n";
   dest_dir=({
      "/players/llew/rooms/dyvi1","east",
   });
   items=({
      "path","Well trampled from the traffic in the market, but still soft and moist",
      "clearing","Wide enough for livestock to maneuver and market goers\n"+
         "to ease through.  It gives an open view of the sky overhead",
      "stalls","The few stalls are run by caer-folk, selling goods\n"+
         "or trading wares amongst each other",
      "stall","The few stalls are run by caer-folk, selling goods\n"+
         "or trading wares amongst each other",
      "folk","People dressed in wool or leather carying about their business",
      "caer-folk","People dressed in wool or leather carrying about their busines",
      "comodities","The livestock and such that constitutes their income\n"+
          "Cows, pigs, sheep, grain, fish, a lone food seller",
     "wall","Leaves grace the tops of the spiring timbers in the\n"+
         "distance, the only landscape seen over the tall walls",
      "market","The stalls and wares of the caer-folk for sale",
   });
   }
}
