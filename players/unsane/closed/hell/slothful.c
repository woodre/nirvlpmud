object gold;
inherit "obj/monster";

object mane;
reset(arg) {
::reset(arg);
if(!arg) {
set_alias("the slothful");
set_alt_name("soul");
    set_name("slothful");
set_short("A Slothful Soul");
    set_race("demon");
set_long(
"   Theses people just let life pass them by in a state of lacadasical \n"+
"indifference.  You notice that now they have reached their place in hell.\n"+
"they have come to resemble the slow turtle, but just slightly.  Their faces\n"+
"have flattened out some and their skin has taken on a leathery appearance.\n"+
"The beginning of a shell has also begun forming on their back as well.\n"+
"They don't appear to be very vicious, but they do seem to be well \n"+
"equipped for defense.\n");
gold =  clone_object("obj/money");
gold->set_money(random(2000)+200);
move_object(gold, this_object());
set_chat_chance(2);
load_chat("A slothful soul blubbers and creeps.\n");
load_chat("A slothful soul falls asleep.\n");
set_a_chat_chance(5);
load_a_chat("A Slothful soul tries to ignore you.\n");
load_a_chat("A slothful one appears to be bothered by you.\n");
   set_level(15);
   set_ac(25);
   set_wc(12);
   set_al(-500);
  set_aggressive(0);
set_can_kill(0);
}
}
