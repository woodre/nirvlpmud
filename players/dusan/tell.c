#include "/players/dusan/ansi.h"
inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("title"); }
init() {
  ::init();
  add_action("title","title"); }
title() {
this_player()->set_guild_name("omegasymb");
this_player()->set_title(""+BOLD+""+GRN+"the Death of Dreams"+NORM+"");
this_player()->set_pretitle("Life is but a dream...all dreams must end..");
this_player()->set_al_title("Scary");
 return 1; }


