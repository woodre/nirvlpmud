#include "/players/fred/ansi.h"
inherit "/obj/weapon.c";

reset (arg) {
  ::reset(arg);
  if(arg) return;

  set_name("baton");
  short_desc = "A Baton named - Chocolate Gummie Bears";
  long_desc = "Whoop it's a baton. <name_wep>\n";
  set_type("club");
  set_class(16);
  set_weight(2);
  set_value(700);
  }

init(){
  ::init();
    add_action("spork_good","name_wep");
  }

spork_good(str){
  if(!str){ write("You're not very smart are you"); return 1; }
  short_desc = "A Baton named - "+str+"";
  write("Ok.\n");
  return 1; }