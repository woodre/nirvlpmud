inherit "room/room";
#include "/players/fakir/color.h"

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Great Hall";
long_desc =
"   The hall continues in grand proportions. Servants bustle about in\n"+
"haste to prepair a great feast.  The gray stone walls of the grand\n"+
"hall glisten in the flickering light from the flames of oil lamps.\n"+
"Tall tapestries hang from the walls, as well as murals and paintings\n"+
"of many sizes.\n";

items = ({
"tapestries", "Curtains with forgotten lore stitched into the patterns",
"murals",     "Wide, hand painted depictions of battles won in the distant past",
"paintings",  "Portraits of past Kings, Queens, and other royal family members",
"hall",       "The hall in which you stand",
"walls",      "The interior walls of the great hall. They are covered with\n"+
              "paintings, murals, and tapestries",
"ceiling",    "A high ceiling slanting downward from the center east and west",
"columns",    "Hand cut columns of wood, each as large as mature fur tree",
"beam",       "A three foot by three foot square beam",
"tables",     "Ornate tables with guilded legs and trim",
"chairs",     "They match the tables in design and purpose",
"room",       "The great hall of the castle",
"servants",   "Those who willingly serve the royal family",
"patterns",   "A single thread is loose in one of the patterns\n"+
              "of the center tapestry.  That thread really bugs\n"+
              "you. It really, really does",

});

    if(!present("trolloc",this_object()))
      move_object(clone_object("/players/fakir/woods/TEMP/trolloc4.c"),this_object());

dest_dir = ({"/players/fakir/fcastle/room37.c", "south",
});
}
init()  {
  ::init();
    add_action("pull_thread","pull");
}
pull_thread(arg)  {
    if(!arg || arg != "thread") {
    notify_fail("What are you trying to pull?\n");
      return 0; 
}

    write(WHITE+"You pull the loose thread from the pattern...\n\n"+
          "                             and suddenly...\n\n"+
          "                                the tapestry shimmers briefly...\n\n"+
          "                                     and you fall forward into soft cloth....\n\n"+OFF+
          "As you pick yourself up, you take a look around...\n");
    move_object(this_player(),"/players/fakir/ways/room"+random(48));
    command("look",this_player());
    return 1; 
}




