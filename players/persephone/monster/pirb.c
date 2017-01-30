#include "/players/persephone/rooms.h"
reset (arg){
 object sab;
 object pat;
 ::reset(arg);
  if(!arg){
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(50+random(100));
   move_object(gold, TOB)
   pat = clone_object("players/persephone/closed/patch");
   move_object(pat, TOB);
   sab = clone_object("players/persephone/weapon/sabr");
   move_object(sab, TOB);
   init_command("wield sabre");
   set_name("henchmen");
   set_alias("pirate");
   set_short("Pirate Henchman");
   set_long("The loyal and devoted followers of Vvladimir they seem to scowl\n" +
            "at you as you look at them. I would not have messed with them if\n" +
            "I were you\n");
   set_level(15);
   set_wc(20);
   set_ac(12);
   set_hp(225);
   set_al(-500);
   set_aggressive(1);
   set_gender(0);
   set_chance(10);
   set_spell_dam(15);
   set_spell_mess1("The Pirate Henchman twirls his Sabre around.");
   set_spell_mess2("The Pirate Henchman beats your guard and slashes fiercely.");
  }
}

