inherit "obj/monster";
#include "/players/persephone/rooms.h"
object knife;
reset(arg){
 ::reset(arg);
if (!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(3000+random(4000));
  /*i changed this from 9k + 4k random to 3k + 4k random  as according to the rules
   -mythos  <11-30-95> */
   move_object(gold, TOB);
   knife=clone_object("players/persephone/weapon/knife.c");
   move_object(knife, this_object());
   init_command("wield knife");
    set_name("purple");
    set_alias("eater");
    set_short("Purple People Eater");
    set_long("The famed Purple People Eater of history he looks extremely\n"+
             "mean and hungry and his teeth show that he does indeed eat\n"+
             "people. I would not have disturbed him if I were you.\n");
    set_level(20);
    set_wc(50);
    set_ac(27);
    set_hp(1050);
    set_al(-300);
    set_aggressive(1);
    set_chance(40);
     set_spell_mess1("The Purple People Eater takes a bite out of his victim.");
     set_spell_mess2("The Purple People Eater starts eating you alive");
     set_spell_dam(50);
 }
}

init() {
  ::init();
  add_action("No_way","insanity");
}

No_way() {
  write("The Purple People Eater laughs in your face.\n");
  return 1; }
