inherit "obj/monster.talk";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
    set_name("cop");
set_alias("cop");
set_short("police");
    set_race("police");
    set_long(
"   This police man is decked out in london's finest...he even\n"+
"has one of those funny pointy hats..old-school police wore.\n"+
"However, seems a bit funny about these police, something almost\n"+
"familiar about their actions and attitudes..If only you could\n"+
"put your finger on it....hmmmm, theyre mean, theyre mean, they're\n"+
"mean....WAIT HOLD ON!!!!!!  STOP THE HUNT!!!!!!!\n"+
"Angst appears and says: Yes, whats wrong???\n"+
"You say: these cops theyre wearing LAPD badges..I dont understand\n"+
"Angst says: Ok,,For the game to run properly I needed some trained\n"+
"killers, not just ordinary men, so I called in the best\n"+
"You nod...but what are they rambling about?\n"+
"Angst says: well i , uhhh, accidently dropped my B-Boy tape\n"+
"Jesus..nobody's perfect..excapt henry the dog\n");
gold = clone_object("obj/money");
gold->set_money(random(100)+5000);
move_object(gold, this_object());
   set_level(30);
   set_ac(1);
   set_wc(1);
   set_hp(1);
   set_al(-300);
set_chance(20);
set_spell_dam(30);
set_spell_mess1("No videotape huh, well Take That then");
set_spell_mess2("The street urchen grips you-please kind sir..damn those nails ripped you open");
  set_aggressive(0);
set_chat_chance(10);
    set_a_chat_chance(10);
load_chat("Cop says: I am the cop with the rop chain...\n");
load_chat("Other cops join in:  just walkin' the beat\n");
load_chat("cop bust: Like a sneakin' time bomb-just tickin..\n");
load_chat("All Together Now: Like the beats to my ryme just kickin'/n");
load_a_chat("The cop pulls something from his pocket\n Oh no. A great big can of Whoop-Ass!\n");
}
}
