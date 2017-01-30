inherit "obj/monster";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
set_name("al");
set_alias("bundy");
set_short("Al Bundy");
    set_race("loser");
    set_long(
" Here sits the most pathetic man that ever graced the planet.  He can't even\n"+
"sell shoes properly.  He is cursed with the worst family that god ever \n"+
"created.  You can often find him here at the nudie bar getting drunk and\n"+
"occaisionally getting into a scrap or two, to forget about his lame life\n"+
"and hide from his nymphomaniac of a wife.  He is the kind of man that you\n"+
"do not want to mess with, as he has nothing to lose.\n");
move_object(clone_object("/players/unsane/closed/extra/shoes.c"),this_object());
move_object(clone_object("/players/unsane/closed/extra/head.c"),this_object());
move_object(clone_object("/players/unsane/closed/extra/suit.c"),this_object());
gold = clone_object("obj/money");
gold -> set_money (random (100) + 800);
move_object(gold, this_object());
   set_level(20);
   set_ac(18);
   set_wc(29);
set_hp(400);
   set_al(-300);
set_chance(20);
set_spell_dam(30);
set_spell_mess2("Al Bundy gives you a vicious headbutt!\n");
set_spell_mess1("Al Bundy jacks up his foe.\n");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Al says: Pour me another one barkeep.\n");
load_chat("Al puts his hand down the front of his pants.\n");
load_chat("Al removes his shoes and begins scratching his feet.\n");
load_chat("Al says: Look at this pathetic loser.\n");
load_a_chat("Al says: Don't you know, the nudie bar is where the Bundy's kick ass!\n");
load_a_chat("Al gives you the Bundy one-two.\n");
}
}
