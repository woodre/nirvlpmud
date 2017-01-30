#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  set_short("A wooden sign");
  set_alias("sign");
  set_long(""+BOLD+"The legendary spear of Yelm unleashes itself...."+NORM+"\n"+
"\n"+
"                                                       "+BOLD+HIY+" ,___  ____"+NORM+"\n"+
"            "+YEL+".__________________    ______________    "+BOLD+HIY+"__/   /__\\  '\\"+NORM+"\n"+ 
"            "+YEL+"||_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\"+NORM+YEL+"_"+HIY+"\\\\"+NORM+YEL+"________"+MAG+"|==|"+YEL+"__"+HIY+"\\"+NORM+YEL+"__"+HIY+"\\"+NORM+YEL+"__"+HIY+"\\"+NORM+YEL+"_____"+MAG+"|==|"+BOLD+HIY+"__ "+RED+"- --"+HIY+"___"+RED+" --"+BOLD+HIY+" >"+NORM+"     \n"+
"                                                       "+BOLD+HIY+"\\___\\  /__,/"+NORM+" \n"+
"\n"+
"\n"+
"\n"+
""+BOLD+"                                                 .........Solar energy burns flesh"+NORM+"\n"+
"\n");


}
get() { return 0; }
