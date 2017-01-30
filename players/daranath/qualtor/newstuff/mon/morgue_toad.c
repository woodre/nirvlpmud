#include <ansi.h>
inherit "/players/daranath/closed/monster1.c";
object gold;

reset(arg){
  ::reset(arg);
  if (!arg){

gold = clone_object("obj/money.c");
gold->set_money(301+random(600));
/* average coins of 600 exactly per monster guide */
move_object(gold,this_object());
          
set_name("Morgue Toad");
set_short("A small, undead Toad");
set_alias("toad");
set_alt_name("gravemon");
set_race("undead");
set_gender("creature");
set_long("The negative energy that washes over the ruined City of Qual'tor\n"+
         "creates a variety of unusal monstrosities, but none more so then\n"+
         "the Morgue Toad. A normal toad in appearance, the skin has\n"+
         "worn through revealing more about the toad then you ever\n"+
         "wanted to know.\n");
set_level(13);
set_ac(10);
set_wc(17);
set_hp(160+random(100));
set_al(-(250+random(350)));
set_aggressive(1);

set_chance(20);
set_spell_dam(10+random(40));
set_spell_mess1("Morgue Toad croaks loudly.\n");
set_spell_mess2("Morgue Toad breathes a cloud of toxic gas at you.\n");

     }
    }

