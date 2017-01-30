inherit"obj/monster";
object gold;
reset(arg) {
::reset(arg);
if(arg) return;
set_name("illithid");
set_alias("mind flayer");
set_short("Illithid");
set_long(
"Of all the creatures of Undermouz, the illithid, or mind flayer, is\n"
+ "both the most evil and most inhuman.  It is also the most feared,\n"
+ "for its powers are formidable and it feeds on the brain of any human,\n"
+ "demihuman, or humanoid creature it encounters.  It is six feet tall,\n"
+ "with hideous mauve skin that glistens with slime.  The head resembles\n"
+ "an octopus, with white eyes and four tentacles protruding from where\n"
+ "a mouth should be.\n");
set_level(20);
set_al(-300);
set_race("illithid");
set_hp(500);
set_wc(30);
set_ac(17);
set_aggressive(1);
set_chance(30);
set_spell_dam(30);
set_spell_mess1("The illithid seems to be looking at you funny.");
set_spell_mess2("You are filled with fear and horror as the mind flayer enter you mind!");
gold = clone_object("obj/money");
 gold->set_money(random(3000)+2000);
 move_object(gold,this_object());
}
