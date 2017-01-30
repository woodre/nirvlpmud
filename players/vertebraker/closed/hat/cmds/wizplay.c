#include "../std.h"

mixed main(int mode)
{
   int x; object *us;
   int wiz_cnt, play_cnt;
   us = users();
   write("Wizplayer ratio:\n\n");
   for(x = 0; x < sizeof(us); x ++ )
{
     if((int)us[x]->query_level() < 20) play_cnt ++;
     else wiz_cnt ++;
}
    if(mode) return(wiz_cnt + ":" + play_cnt);
    else write("\t\t" + wiz_cnt + ":" + play_cnt + "\n");
    return 1;
}
