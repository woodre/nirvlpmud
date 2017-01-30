inherit "obj/monster";

reset(arg){
   object gold,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("Goliath");
   set_alias("goliath");
   set_short("Goliath");
   set_long("Goliath is a large man with huge, bulging muscles. You see he needs all of them to swing the massive broadsword he wields.\n");
   set_level(15);
/* Changed hp from 150 to 225 -Snow */
   set_hp(225);
   set_al(-1000);
   set_wc(20);
   set_ac(12);
set_chat_chance(15);
load_chat("Goliath exclaims: You are mine now little adventurer!\n");
set_chance(15);
set_spell_dam(15);
set_spell_mess1("Goliath slices down at his opponents neck with a hard chop!");
set_spell_mess2("Goliath's sword almost takes your head off with a deep cut!");
weapon=clone_object("/players/nightshade/weap/goliath");
   move_object(weapon, this_object());
gold=clone_object("obj/money");
gold->set_money(450);
move_object(gold, this_object());
}

/*  wc was 15, ac was 9 - mythos <6-17-96> */
