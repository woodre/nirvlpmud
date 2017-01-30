/*COPYRIGHT (C) VITAL CORP */
/* A HUMBLE MANIPULATION */
#include "../defs.h"

inherit "room/room";

reset(arg) {
  if(!arg)
  { 
    set_light(1);
    short_desc = HIG+"Enchanted Garden"+NORM;
    long_desc =
    HBGRN+"This is another small garden which seems to be placed perfectly\n"+NORM+
    HBGRN+"at the end of the pathway. The grass here is moist but the smell\n"+NORM+
    HBGRN+"seems different. There is a large black tent standing in the center\n"+NORM+
    HBGRN+"of the garden. Amongst the grass are shrubs that seem to have\n"+NORM+
    HBGRN+"been heavily damaged, yet they refuse to die and shine bright with\n"+NORM+
    HBGRN+"colour of life. Truely you have stumbled upon a magical place.\n"+NORM;

    items =
    ({
    "garden", "The garden gives you an eerie feeling despite it's warm glow",
    "dirt", "The dirt is a yellowish-orange color and seems very warm and inviting",
    "pathway",    "A dirt pathway that you arrived here from",
    "path",    "A dirt pathway that you arrived here from",
    "grass",    "Soft grass that is covered in dew",
    "shrubs", "The shrubs have suffered heavy damage yet still glow vibrantly",
    "tent", "A somewhat large black tent, it's made of strange fabric. Maybe you could enter it?",
    });
    dest_dir =
    ({
    "/players/humble/newbarea/rooms/faeriering",        "south",
    });

    move_object(clone_object("/players/humble/newbarea/mobs/guarddwarf.c"), this_object());
    move_object(clone_object("/players/humble/newbarea/mobs/guarddwarf.c"), this_object());

    add_feel("grass",     "The grass here is soft and covered in dew.\n");
    add_feel("tent",    "It feels like it's made from bear hide, it's finely crafted.\n");
    add_feel("pathway",    "A soft, gravel and dirt collabaration, it's consistency is a little thicker than sand.\n");
    add_feel("shrubs",    "The shrubs are rough unlike the other bushes, perhaps because they have been hacked.\n");
    add_sound("main", "There is a strange noise of friction here...\n");
    add_smell("main",    "You smell blood here, and liqour.\n");
  }
}

    init() {
      ::init();
      add_action("enter", "enter");
}

     enter(arg) {
    if(arg !="tent") {
    notify_fail("What do you want to enter?\n");
    return 0;
}

    write("You step into the tent.\n");
    say(capitalize(this_player()->query_name())+" opens a flap and steps into the tent.\n");
    move_object(this_player(),"/players/humble/newbarea/rooms/tent.c");
      command("look", this_player()); /* verte */
      return 1;
}
