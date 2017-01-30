/*  Lets me read players' tellhistories. */
#include <ansi.h>
tellh_cmd(str){
 object x;
 if(!str) return 0;
 x = find_player(str);
 if(!x) return 0;
 write(BOLD+BLK+"You focus the shadows upon "+
	 capitalize((string)x->query_real_name())+"....\n\n"+NORM);
 x->write_tellhistory();
 return 1; 
}

