#include "/players/jenny/define.h"
main(str) {
   object freak;
   if(!str) return 0;
   freak = find_player(str);
   if(!freak) {
      write("Freak not logged on.\n");
      return 1; }
   freak->write_tellhistory();
   return 1; }
