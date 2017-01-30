inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("buck bundy");
    set_alt_name("buck");
set_race("dog");
    set_al(159);
    set_level(13);
    set_hp(200);
MOCO("/players/jenny/bundy/items/collar.c"),this_object());
init_command("wear collar");

    set_ac(10);
   set_ac_bonus(1);
    set_wc(18);
    set_aggressive(1);
    set_gender("male");
    set_short(""+YEL+"Buck"+NORM+"");
    set_long(
      "Buck is the Bundy's loyal dog.  He is shaggy, lazy, and rarely\n"+
      "gets fed.  Some people think Buck is the most intelligent Bundy.\n");
}
init() {
  ::init();
add_action("stop","north");

}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else {
if(TP->query_level() <20) {
write(""+CYN+"Buck grabs a hold of your leg and keeps you from moving."+NORM+"\n");
return 1; }}
}
