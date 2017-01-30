/* Drip room */

/* Edited by Pain 6/5/2002 to stop all the unfettered cloning of slime */
inherit "players/snow/chaos/arch.c";
#include "/players/snow/chaos/defs.h"
#include "/players/snow/closed/cyber/color.h"

static int slimes;


reset(arg) {
  ::reset();

slimes = 6;

  if(!arg) {
  short_desc=YELLOW+"C"+OFF+
             MAGENTA+"h"+OFF+
             GREEN+"A"+OFF+
             CYAN+"o"+OFF+
             BLUE+"S"+OFF;
  long_desc=
"  A greenish "+GREEN+"glow"+OFF+" sickeningly lights up this room.\n\
Slime covers the walls and every few seconds you can hear\n\
a     PLOP!    as some viscous liquid drips from the ceiling\n\
to the floor and is instantly absorbed.\n";
  items=({
    "slime","A horrid greenish slime. You could 'scrape' some off the\n"+
            "walls if you could stand the stuff",
    "liquid","If you wanted to try something daring you could open your\n"+
             "mouth and try to 'catch' the drop before it hits the ground",
    "floor","The floor is a greenish hue. It is slightly reddish where\n"+
            "the drops of liquid land",
      });
  }
}

init() {
  ::init();
  add_action("scrape_slime","scrape");
  add_action("catch_drop","catch");
}

scrape_slime(str) {
  object slime;
  int ran;

  slime = clone_object("/players/snow/food.c");
  ran = random(100) - 50;
  if(!str) { write("Scrape what?\n"); RE; }
  if(str == "slime" && slimes > 0 && random(99) > 74) {
    slimes--;
    write("You scrape some slime off the walls.\n"+
          "  Now you have a bit of slime!\n");
    say(TPN+" scrapes some slime off the walls.\n");
    slime->set_name("slime");
    slime->set_alias("green slime");
    slime->set_short("Some green "+GREEN+"slime"+OFF);
    slime->set_strength(ran);
    slime->set_value(0);
    slime->set_eater_mess("You slurp-chomp down the green slime!\n"+
                          "  You feel a little disgusted.\n");
    slime->set_eating_mess(TPN+" slurp-chomps down some green slime!\n");
    MO(slime,TP);
  RE;
  }
else {
write("You failed to scrape any slime.\n");
RE;
}
}

catch_drop(str) {
  if(!str) { write("Catch what?\n"); RE; }
  if(str == "drop" || str == "liquid") {
    write("You catch a drop of greenish liquid in your mouth!\n"+
          "  You feel kinda funny...\n");
    say(TPN+" catches a drop of greenish liquid in "+GEN+" mouth!\n");
    TP->heal_self(random(20)-10);
  RE;
  }
}
