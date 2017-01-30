/*
  Scan your guild wolf for health
*/

#include "/players/eurale/defs.h"

/* --------------  check out a monster's % hp level --------------*/
scan_wolf(str) {
  object obj;
  int n;

if(TPL < 17 || TPGEXP < 669 || TP->query_attrib("int") < 18) {
  write("You lack the skills needed for this ability.\n");
  return 1; }

if(TPBPTS < 1) {
  write("You lack the blood energy to scan your wolf.\n");
  return 1; }

obj = present("wolf", ROOM);

if(!obj) { write("You have no wolf present.\n"); return 1; }

if(obj->query_hp() < 16) {
  write("Sorry, your "+BOLD+"wolf"+NORM+" is "+HIR+"TOO WEAK"+NORM+
        " to scan.\n");
  return 1; }
else {
  PFANGS->add_BLOODPTS(-1);
  n = (obj->query_hp() * 10) / obj->query_mhp();
  write(obj->short()+" is "+BOLD+n+"0"+NORM+" percent healthy.\n");
  return 1; }
}
