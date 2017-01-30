inherit "/obj/monster";
#include "/players/jenny/define.h"
int num;
id(str) { return str == "john wharton" ||  str == "john" || str == "wharton" || str == "John Wharton"; } 

reset(arg)
{
num = random(3);
   ::reset(arg);
   if (arg) return;
   set_name("John Wharton");
   set_race("human");
   set_gender("male");
   set_al(250+random(90));
   set_level(14);
   set_hp(220);
   set_wc(19);
   set_ac(11);
   if(num == 0){
   add_money(700+random(100));}
   if(num > 0){
   add_money(50+random(100));
   MOCO("/players/jenny/wings/items/shotkey.c"),TO);}
   set_short(BOLD+WHT+"John Wharton"+NORM);
   set_long(
      "John Wharton is the athletic trainer for the Detroit Red Wings.  He\n"+
      "is an average size guy, with short brown hair.  It is his job to help\n"+
      "players rehabilitate their injuries, and to make sure everyone is in\n"+
      "peak physical condition.\n");
}
