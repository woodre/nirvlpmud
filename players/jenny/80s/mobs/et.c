inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "e.t." ||  str == "et" || str == "alien" || str == "E.T."; } 
reset(arg)
{
   ::reset(arg);
    if (arg) return;
set_name("E.T.");
    set_race("alien");
    set_al(100+random(30));
    set_level(4);
    set_hp(60);
    set_wc(9+random(2));
    set_ac(4);
    set_short(HIB+"E.T."+NORM);
    set_long(
     "E.T. is a short little alien with a big, kinda flat head.  He was stranded\n"+
      "on earth.  He befriended a boy named Elliot and was finally able to\n"+
      "communicate with his spaceship and go home.  This Stephen Spielberg\n"+
     "movie shattered the box office records of the time.\n");
}
