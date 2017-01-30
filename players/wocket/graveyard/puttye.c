#include "/players/wocket/closed/ansi.h"

inherit "obj/monster";

reset(arg){
  ::reset(arg);
  if(arg) return ;
  set_name("puttye");
  set_race("seussian");
  set_short("A small "+RED+"Puttye"+NORM+" warrior");
  set_long("This looks to be about a ten year old dressed very sparcely.\n"+
           "He wears warrior paint about his frail body.  The colors seem\n"+
            "to merge and blend forming intricate patterns and to act as\n"+
            "a warning to those that would challenge him.\n");
    set_wc(50);
    set_ac(0);
    set_hp(25);
    set_level(5);
}
