inherit "/obj/treasure";
int fishies;

reset(arg) {
  fishies=5;
  if(arg) return;
  set_id("fountain");
  set_alias("water");
  set_value(0);
  set_weight(100000);
  set_short("A large fountain");
  call_out("gurgle",0);
}

long() {
  if(!fishies)
    write("The fountain is spewing water into the air for it to return to\n"+
          "the pond at the base with a splash.\n");
  else
  write("The fountain is spewing water into the air for it to return to\n"+
        "the pond at the base with a splash.  You can see "+fishies+" goldfish\n"+
        "in the bottom of the fountain.\n");
  return 1;
}

gurgle() {
  say("The fountain gurgles.\n");
  call_out("gurgle",90);
  return 1;
}

init() {
  add_action("get_fish","get");
  add_action("get_fish","take");
}

get_fish(str) {
  if(!str) return;
  if(str!="fish") return;
  if(!fishies) {
    write("There are no fish in the fountain.\n");
    return 1;
  }
  write("After much deliberation you catch one of the fish.\n");
  fishies--;
  move_object(clone_object("/players/grimm/q/o/fish"),this_player());
  say(capitalize(this_player()->query_name())+" dives into the fountain "+
      "and, after splashing around\nfor a while, returns with a live "+
      "goldfish.\n");
  return 1;
}
