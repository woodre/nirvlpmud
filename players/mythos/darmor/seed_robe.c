#include "/players/mythos/closed/ansi.h"
int idset;
inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("robe");
  set_short("Robe of the Seed");
  set_alias("robe of the seed");
  set_type("armor");
  set_long("A shiny robe born from the Golden Seed.\n"+
           "If wrapped around the right Blade it will return\n"+
           "to the seed.\n");
  set_ac(4);
  set_weight(1);
  set_value(1300);
}

init() { ::init(); add_action("fold","wrap"); }

set_idset(n) { idset = n; }
query_idset() { return idset; }

fold(str) {
object blade;
  if(!str) { write("What are you wrapping?\n"); return 1; }
  if(id(str) || str == "blade" || str == "goldenblade") {
    blade = present("goldenblade",this_player());
    if(!blade) { write("You do not have the GoldenBlade.\n"); return 1; }
    if(blade->query_idset() != idset) {
      write("You do not have the proper Blade.\n"); return 1; }
    if(blade == this_player()->query_weapon()) {
      write("Unwield the blade first.\n"); return 1; }
    if(worn) { write("Remove the robe first.\n"); return 1; }
    write("The Blade and the Robe shimmer and a there is a bright FLASH!\n");
    say("Suddenly a bright light flashes before your eyes!\n");
    destruct(blade);
    move_object(clone_object("/players/mythos/dmisc/seed.c"),this_player());
    destruct(this_object());
    return 1; }
}