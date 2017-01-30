#include "/players/snow/dervish/def.h"

sand_transfer() {
  object mygob;
  mygob = present(GID, TP);
  if(TP->query_level() < 7) {
    write("You are not advanced enough to do this.\n"); return 1; }
  if(mygob->query_transfer()) {
    write("Sand transference rescinded.\n");
    mygob->set_transfer(0); mygob->save_me(); return 1; }
  write(BOLD+"You pray to the Sands for energy transference.\n"+OFF);
  mygob->set_transfer(1); mygob->save_me(); return 1; }
