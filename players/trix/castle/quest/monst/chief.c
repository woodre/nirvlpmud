inherit "obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"
reset(arg){
   object gold,bracers,helmet,boots,plate;
   ::reset(arg);
   if(arg) return;
   set_name("ox");
   set_race("human");
   set_alias("guard");
   set_alt_name("trixguard");
   set_short("Ox, the chief-guard");
   set_long("The chief-guard, he looks at you from behind his bleary and dusty eyebrows.\n"+
            "His body is huge and muscular but can be quick and agile if necessary.\n");
   set_level(18);
   set_hp(1000);
   set_al(1000);
   set_wc(26);
   set_ac(15);
   set_aggressive(1);
   set_chat_chance (15);
   load_chat("Ox says: How do you dare to challenge me?\n");
   load_chat("Ox says: Oh, you tiny little man!\n");
   set_chance(5);
   set_spell_dam(random(30)+10);
   set_spell_mess1("Ox put his hands at your neck and strangles you.");
   set_spell_mess2("Ox hits you with his naked hand.");
   set_a_chat_chance(10);
   load_a_chat("Ox says: You killed my garrison.\n");
   load_a_chat("Ox says: You'll cry bitter tears for thy insolence.\n");
   gold=clone_object("obj/money");
   gold->set_money(450 + random(50));
   move_object(gold,this_object());
   plate=clone_object("players/trix/castle/quest/monst/plate");
   move_object(plate,this_object());
   bracers=clone_object("players/trix/castle/quest/monst/bracers");
   move_object(bracers,this_object());
   boots=clone_object("players/trix/castle/quest/monst/boots");
   move_object(boots,this_object());
   helmet=clone_object("players/trix/castle/quest/monst/helmet");
   move_object(helmet,this_object());
  move_object(clone_object("/players/dragnar/MKScar/scar"), this_object());
}
