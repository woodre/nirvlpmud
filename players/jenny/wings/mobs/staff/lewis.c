inherit "/obj/monster";
#include "/players/jenny/define.h"
id(str) { return str == "dave lewis" ||  str == "dave" || str == "lewis" || str == "Dave Lewis"; } 

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("Dave Lewis");
   set_race("human");
   set_gender("male");
   set_al(250+random(90));
   set_level(15);
   set_hp(255);
   set_wc(21);
   set_ac(12);
   add_money(800+random(400));
   set_short(BOLD+WHT+"Dave Lewis"+NORM);
   set_long(
      "Dave Lewis is an associate coach for the Detroit Red Wings.  He is a\n"+
      "fairly big guy, in his early 50's, with short dark hair and a mustache.\n"+
      "Dave has been an associate coach with Detroit ever since his playing\n"+
      "career ended 15 years ago.  He is mainly responsible for coaching\n"+
      "the team's defensemen.\n");
}
