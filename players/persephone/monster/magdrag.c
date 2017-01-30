inherit "obj/monster";
#include "/players/persephone/rooms.h"
object robe;
reset(arg) {
  ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(3000+random(3000));
   move_object(gold, TOB);
    robe = clone_object("players/persephone/armour/cloak.c");
    move_object(robe, this_object());
    init_command("wear robe");
      set_name("puf");
      set_alias("magdrag");
      set_alias("dragon");
      set_short("Puf the Magic Dragon");
      set_long("Puf who is of course the Famed Magic Dragon looks like no\n"+
               "other Dragon you have seen before, perhaps it could be his\n"+
               "colouration as he seems to be of no solid or stable colour.\n"+
               "It may also be that the mushroom you ate is causing you to\n"+
               "halucinate rather badly you really would prefer not to fight\n"+
               "him\n");
      set_level (20);
      set_wc (28);
      set_ac (16);
      set_hp(700);
      set_al(300);
      set_aggressive(0);
      set_gender (0);
      set_chance(28);
      set_spell_dam(30);
        set_spell_mess1("Puf discharges a blinding flash of electricity");
        set_spell_mess2("Puf smashes you with a blinding flash of lightning");
 }
}
