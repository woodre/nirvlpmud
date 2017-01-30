#include "/players/coldwind/ansi.h"
inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("title"); }
init() {
  ::init();
  add_action("title","title"); }
title() {
this_player()->set_title();
this_player()->set_pretitle(HIY+"Nirvana's lil Angel"+NORM+" ...");
this_player()->set_al_title();
 return 1; }


