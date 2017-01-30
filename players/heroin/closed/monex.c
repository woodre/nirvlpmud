inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("wolverine");
set_alias("logan");
set_short("Wolverine of the Xmen");
    set_race("xman");
    set_long(
"  Wolverine is a short stocky Canadian with a good haircut.  He is a bit\n"+
"hairy, but still handsome.  He has the face of an experienced killer, and\n"+
"3 admantium claws extending from each hand.  He is smoking on a stogie cigar\n"+
"and grinning at you.  He seems quite sure of himself.\n");
gold = clone_object("obj/money");
gold -> set_money (random (2000) + 500);
move_object(gold, this_object());
move_object(clone_object("/players/unsane/xmen/skeleton.c"), this_object());
move_object(clone_object("/players/unsane/xmen/claws.c"),this_object());
   set_level(20);
call_other(this_object(),"set_heal",20,30);
   set_ac(18);
   set_wc(30);
   set_hp(1000);
   set_al(-300);
set_chance(20);
set_spell_dam(30);
set_spell_mess2("Wolverine stabs you deeply with his claws.");
set_spell_mess1("Wolverine stabs his foe with a sickening sound.");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Wolverine says: Cyke is getting weak.\n");
load_chat("Wolverine says: Old baldie can't tell me what to do.\n");
load_chat("Wolverine calmly smokes his cigar.\n");
load_chat("Wolverine says: you gotta gripe bub?\n");
load_chat("Wolverine says: killing ain't easy.\n");
load_a_chat("Wolverine says: yer dead bub");
load_a_chat("Wolverine says: Dammit Cyke, how'd these punks get in here?\n");
load_a_chat("Wolverine grins.\n");
}
}
