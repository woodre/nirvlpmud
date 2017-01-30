#include "DEF.h"

file(str) {
if(!str) return 0;
  write_file("/players/eurale/WORKREPORT",
    "   "+ctime(time())+"     "+str+".\n");
  write_file("/log/WR/eurale_workreport",ctime(time())+"   "+str+".\n");
write("report done.\n");
return 1; }
