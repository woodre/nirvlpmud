#include "../../defs.h"
inherit "/players/wocket/necro/obj/misc/bookstd.c";

reset(){
 ::reset();
  set_title("The Complete Guide to Spells");
  set_alt_title("the complete guide to spells");
  add_page(DOCS+"/spellguideintro.txt");
  add_page(DOCS+"/abandon.txt");
  add_page(DOCS+"/anguish.txt");
  add_page(DOCS+"/animate_skeleton.txt");
  add_page(DOCS+"/bloodmoon.txt");
  add_page(DOCS+"/bone_portal.txt");
  add_page(DOCS+"/chill.txt");
  add_page(DOCS+"/claim_dagger.txt");
  add_page(DOCS+"/cloak.txt");
  add_page(DOCS+"/consecrate_grave.txt");
  add_page(DOCS+"/consume_corpse.txt");
  add_page(DOCS+"/decay.txt");
  add_page(DOCS+"/disease.txt");
  add_page(DOCS+"/drain_life.txt");
  add_page(DOCS+"/embalm_corpse.txt");
  add_page(DOCS+"/embrace_death.txt");
  add_page(DOCS+"/evoke_ghouls.txt");
  add_page(DOCS+"/gstench.txt");
  add_page(DOCS+"/grafting.txt");
  add_page(DOCS+"/grasp.txt");
  add_page(DOCS+"/pestilence.txt");
  add_page(DOCS+"/reanimate.txt");
  add_page(DOCS+"/wither.txt");
}

query_necro_book(){ return 1;}