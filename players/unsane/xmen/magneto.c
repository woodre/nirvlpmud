inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("magneto");
set_alias("magnus");
set_short("Magneto");
    set_race("villian");
    set_long(
"  This is Magneto, arch villian.  He is the leader of the brotherhood of \n"+
"evil mutants.  He seeks to advance mutantkind at the expense of humankind\n"+
"He and Charles have been friends through the years, even though they disagree\n"+
"with one another on how the world should get along.  These two men have\n"+
"fought side by side and against each other in some notable battles.  You\n"+
"better hope one is not erupting now, or the whole world may suffer the\n"+
"consequences.\n");
gold = clone_object("obj/money");
gold -> set_money (random (2000) + 1000);
move_object(gold, this_object());
move_object(clone_object("/players/unsane/xmen/cowl.c"),this_object());
   set_level(20);
   set_ac(20);
   set_wc(30);
   set_hp(800);
   set_al(-600);
set_chance(20);
set_spell_dam(60);
set_spell_mess2("Magneto causes the metal objects in the room to attack you.");
set_spell_mess1("Magneto impales his foe with a myriad of metal objects!");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Magneto says: Charles listen to this plan of mine.\n");
load_chat("Magneto says: We dominate humankind and take our place as rightful leaders!\n");
load_chat("Magneto strikes the desk and swears.\n");
load_chat("Magneto says: Humankind and Mutantkind cannot leave together peacefully.\n");
load_chat("Magneto says: Give up this childish dream Charles.\n");
load_a_chat("Magneto makes a magnetic force field.\n");
load_a_chat("Magneto says: You pittiful wretch...you dare to attack me?!\n");
load_a_chat("Magneto says: I will destroy you!\n");
load_a_chat("Magneto flushes with anger.\n");
}
}
