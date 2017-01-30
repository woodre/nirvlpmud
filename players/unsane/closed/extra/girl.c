inherit "obj/monster";

object gold;
reset(arg) {
::reset(arg);
if(!arg) {
  set_name("nude dancer");
set_alias("dancer");
set_short("A Hideous Nude Dancer");
    set_race("girl");
    set_long(
"  This creature is apparently asexual.  It gyrates its mounds of flesh\n"+
"with a look of gleeful delight.  When it notices you staring it begins \n"+
"swinging its tassles violently and then suffers a bout of coughing.\n"+
"It's a pretty sad sight allright.\n");
gold = clone_object("obj/money");
gold -> set_money (random (100) + 800);
move_object(gold, this_object());
   set_level(15);
set_frog(1);
   set_ac(12);
   set_wc(20);
   set_al(1000);
set_chance(20);
set_spell_dam(15);
set_spell_mess2("Nude dancer whips you with her tassles.\n");
set_spell_mess1("Nude dancer whips her foe with its sparkly tassles.\n");
  set_aggressive(0);
    set_a_chat_chance(10);
   set_chat_chance(10);
load_chat("Dancer grins at you.\n");
load_chat("Dancer blubbers some gibberish\n");
load_chat("You hear the whoosh of the dancer's tassles.\n");
load_chat("Dancer says: Lookey Lookey Lookey\n");
load_a_chat("Dancer begins shaking its blubber to frighten you off.\n");
load_a_chat("Dancer runs around in circles.\n");
}
}
