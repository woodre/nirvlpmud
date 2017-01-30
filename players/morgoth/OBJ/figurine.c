#include "/players/feldegast/closed/ansi.h"

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("figurine");
  set_alias("jade_quest_figurine");
  set_short("A "+GRN+"jade"+NORM+" figurine");
  set_long(
    "This is a small chunk of jade carved into the shape of a panther.\n"
  );
  set_weight(1);
  set_value(50);
}
