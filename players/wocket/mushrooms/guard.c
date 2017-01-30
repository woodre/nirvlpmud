#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg){
object shroom;
    ::reset(arg);
  if(arg) return;
    set_name("guard");
    set_alias("nonge");
    set_race("seussain");
    set_al(750);
    set_gender("male");
    set_level(21);
    set_hp(620);
    set_wc(42);
    set_ac(20);
    set_short("A "+MAG+"member of the royal"+NORM+" guard");
    set_long("\
A member of the royal guard stands at attention.  His markings\n\
project fear with its yellow and red streaks.  The tufts of fur\n\
on his ears flare outwards.  His eyes are stone cold and his\n\
breathing is very steady.  He wears red robes along with the\n\
normal sash and kilt uniform.  Many awards decorate this\n\
proud nonge.\n");

  shroom = clone_object("/players/wocket/mushrooms/shroom.c");
  shroom->set_money(4000);
  move_object(shroom,this_object());
}

heart_beat() {
object att;
  if(!query_attack()) {
if(present("guard",environment(this_object()))){
  if(att = present("guard",environment(this_object()))->query_attack()){
if(random(3) == 1){ attack_object(att); say(HIR+"The nonge guard rushes to defend his companion.\n"+NORM); }
}}
if(present("guard 2",environment(this_object()))){
if(att = present("guard 2",environment(this_object()))->query_attack()){
if(random(3) == 1){ attack_object(att); say(HIR+"The nonge guard rushes to defend his companion.\n"+NORM); }
}}
     if(present("priest",environment(this_object()))) {
          if(att = present("priest",environment(this_object()))->query_attack()) {
if(random(2) == 1) { attack_object(att); say(HIR+"The nonge guard rushes to defend his companion.\n"+NORM); }
}}}
   ::heart_beat();
}
