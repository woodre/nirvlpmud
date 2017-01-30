inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("sabertooth");
set_alias("sabretooth");
set_short("Sabretooth");
    set_race("villain");
    set_long(
"  This is the X-men's foe, Sabretooth.  He has apparently made it past all\n"+
"of their security and he appears to be ready to wreak havok!  You are\n"+
"the last obstacle standing in his way and it might not be for long.  \n"+
"Sabertooth is an experianced killer and can even fight Wolverine to a\n"+
"standstill.  Just looking at his claws gets you frightened.\n");
gold = clone_object("obj/money");
gold -> set_money (random (2000) + 1000);
move_object(gold, this_object());
move_object(clone_object("/players/unsane/xmen/bomb.c"),this_object());
   set_level(20);
   set_ac(20);
   set_wc(33);
   set_hp(900);
   set_al(-700);
set_chance(20);
set_spell_dam(30);
set_spell_mess2("Sabertooth rakes his claws across your face.");
set_spell_mess1("Sabertooth rips his foe to shreds!");
  set_aggressive(1);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Sabertooth says: You're dead!\n");
load_a_chat("Sabertooth screams: You can't stop me!\n");
load_a_chat("Sabertooth says: This whole place is going up\n");
load_a_chat("Sabertooth goes insane with bloodlust.\n");
}
}
