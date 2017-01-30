#include "../../defs.h"
inherit "/players/wocket/necro/obj/misc/bookstd.c";

reset(){
 ::reset();
  set_title("Handbook for the Necromancer");
  set_alt_title("handbook for the necromancer");
  add_page(DOCS+"/necro_rules.txt");
  add_page(DOCS+"/necro_rod.txt");
  add_page(DOCS+"/necro_value.txt");
  add_page(DOCS+"/necro_parts.txt");
  add_page(DOCS+"/necro_tool.txt");
  add_page(DOCS+"/necro_pouch.txt");
  add_page(DOCS+"/necro_commands.txt");
  add_page(DOCS+"/necro_others.txt");
  add_page(DOCS+"/necro_leaveguild.txt");
}

query_necro_book(){ return 1;}