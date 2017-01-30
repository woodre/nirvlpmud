inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
set_name("mindstab thrull");
set_alias("thrull");
set_short("Mindstab Thrull");
    set_race("mindstab");
    set_long(
"  A thrull is a hideous creation, made by the Order of the Ebon hand.  It is\n"+
"a disgusting compilation of arms, legs and a head all thrown together without\n"+
"thought given to symmetry or the laws of nature.  You grow sick to your stomach\n"+
"when you see these creatures.  The live and spawn in this slime and they know\n"+
"only killing.  Be afraid.\n"
);
move_object(clone_object("/players/unsane/closed/extra/skin.c"),this_object());
move_object(clone_object("/players/unsane/closed/extra/device.c"),this_object());
gold = clone_object("obj/money");
gold -> set_money (random (50) + 10);
move_object(gold, this_object());
   set_level(20);
   set_ac(18);
   set_wc(34);
   set_al(-300);
set_chance(20);
set_spell_dam(40);
set_spell_mess2("Thrull sticks it's probing device into your cranium.");
set_spell_mess1("Thrull mutilates his foe with a probing device.\n");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_a_chat("Thrull hisses.\n");
load_a_chat("Thrull begins laughing maniacally\");
load_a_chat("Thrull licks blood from it's device.\n");
}
}
