/*
  stuff.c - test stuff for scavenger hunt
*/

inherit "obj/treasure";

reset(arg) {
  set_short("Some stuff");
  set_long("Stuff used to test the hunt.\n");
  set_value(0);
  set_weight(0);
}

id(str) { return str=="stuff" ||
                 str=="bag" ||
                 str=="crown" ||
                 str=="fortune cookie" ||
                 str=="gloves" ||
                 str=="light" ||
                 str=="jacket" ||
                 str=="key" ||
                 str=="knife" ||
                 str=="newspaper" ||
                 str=="rope" ||
                 str=="stick" ||
                 str=="water glass" ||
                 str=="axe" ||
                 str=="trash";
}
