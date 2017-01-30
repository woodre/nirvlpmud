#include "/players/coldwind/ansi.h"
inherit "/obj/treasure";
reset(arg) {
  if(arg) return;
  set_id("title"); }
init() {
  ::init();
  add_action("title","title"); }
title() {
this_player()->set_guild_name(0);
this_player()->set_title(NORM+HIR+"*"+NORM+RED+"--"+NORM);
this_player()->set_pretitle("("+BLINK+HIK+"!"+NORM+")"+RED+" --"+HIR+"*"+HIK);
this_player()->set_al_title(BLINK+HIK+"!"+NORM);
 return 1; }


