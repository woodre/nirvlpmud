inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"
reset(arg){

  set_id("snake skin");
  set_alias("skin");
  set_short("A green snake skin");
  set_long(
"This is the skin of a green forest snake.  It is in fairly bad condition,\n"+
"looking as though it was hacked off by a total amateur.  There are\n"+
"several small holes in it, and it is fairly bloody.  However it is still\n"+
"somewhat valuable.  Just find someone willing to 'barter' for it.\n");
  set_weight(1);
  set_value(100+random(500));
}
