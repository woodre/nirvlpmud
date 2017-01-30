inherit "obj/monster.c";
#include "/players/persephone/rooms.h"
reset (arg){
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(500+random(700));
   move_object(gold, TOB);
   set_name("huorn");
   set_alias("tree");
   set_short("Huorn");
   set_long("Huorn's are basically nothing more than animated trees they\n" +
            "serve the Ents their Shepherds in time of need. They are often\n" +
            "agressive unless an ent controls them\n");
   set_level(11);
   set_wc(15);
   set_ac(9);
   set_hp(165);
   set_al(0);
   set_aggressive(1);
   set_gender(0);
   set_race("animal");
   set_chance(10);
   set_spell_dam(10);
   set_spell_mess1("The Huorn swings it's branches violently as if there were a storm");
   set_spell_mess2("The Huorn pummels you with bare fists");
  }
}
