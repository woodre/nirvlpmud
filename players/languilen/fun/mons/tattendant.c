#include "/players/languilen/closed/ansi.h"
#define TP this_player()
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("attendant");
set_race("human");
set_short("The Dunk Tank Attendant");
set_long(
  "He has a black and white striped suit and a crazy hat that spins in circles. \n");

set_level(20);
  set_hp(550);
  set_al(0);
  set_wc(30);
  set_ac(15);
  set_aggressive(0);

set_chat_chance(5);
  load_chat("Dunk your neighbor!  Dunk your friends!  Dunk your enemies...Ha haa!\n");
  load_chat("If you want something to throw i'm the guy to know!\n");
  load_chat("Just pay me an' you'll get three!  Three softballs, three chances!\n");

}
init(){
    ::init();
    add_action("paidfor","pay");
}
paidfor(str){
    if(!str || str != "attendant"){
       notify_fail("Are you trying to 'pay' the 'attendant'?\n");
       return 0;
    }
    if(this_player()->query_money() < 30) {
       write("You don't have enough money to pay me! \n");
       return 1;
    }
    if(!call_other(TP,"add_weight", 3 )) {
       write("You can't carry that much!\n");
       return 1;
    }
    this_player()->add_money(-30);
    move_object(clone_object("/players/languilen/fun/objs/softball.c"),this_player());
    write("The attendant hands you three softballs.\n");
    say(capitalize(TP->query_real_name())+" buys some softballs. \n");
    return 1;
}
