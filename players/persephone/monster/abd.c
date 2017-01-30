inherit "obj/monster";
#include "/players/persephone/rooms.h"
reset (arg){
 object dan;
 object cle;
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(500+random(500));
   move_object(gold, TOB);
   dan = clone_object("players/persephone/armour/apr");
   move_object(dan, TOB);
   init_command("wear apron");
   cle = clone_object("players/persephone/weapon/cleav");
   move_object(cle, TOB);
   init_command("wield cleaver");
   set_name("abdhulla");
   set_alias("butcher");
   set_short("Abdhulla the Butcher");
   set_long("Abdhulla is the towns butcher he looks like a strong\n" +
            "overweight and swarthy man.  You definately would not like\n" +
            "to anger him.\n");
   set_level(20);
   set_wc(30);
   set_ac(18);
   set_hp(500);
   set_al(-200);
   set_aggressive(0);
   set_gender("male");
   set_race("monster");
   set_chance(20);
   set_spell_dam(30);
   set_spell_mess1("Abdhulla swings the Cleaver Menacingly");
   set_spell_mess2("Abdhulla starts to butcher you for steaks");
  }
}

