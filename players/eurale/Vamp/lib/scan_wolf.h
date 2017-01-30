/*
  scan_monster.h
*/

#include "/players/eurale/defs.h"

/* --------------  check out a monster's % hp level --------------*/
scan_wolf(str) {
  object obj;
  int n;

if(TPL < 17 || TPGEXP < 669 || TP->query_attrib("int") < 16) {
  write("You lack the skills needed for this ability.\n");
  return 1; }

obj = present("wolf", ROOM);

if(obj->query_hp() < 10) {
  write("Sorry, your "+BOLD+"wolf"+NORM+" is "+HIR+"TOO WEAK"+NORM+
        " to scan.\n");
  return 1; }
else {
  n = (obj->query_hp() * 10) / obj->query_mhp();
  write(obj->short()+" is "+BOLD+n+"0"+NORM+" percent healthy.\n");
  return 1; }
}
