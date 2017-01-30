inherit "/obj/monster";
int n;

reset(arg) {
   ::reset(arg);
if (!arg){
object ob, ob2, ob3, ob4, gold;
gold = clone_object("obj/money");
gold->set_money(600);
move_object(gold,this_object());
ob4 = clone_object("/players/saber/armor/orcboots.c");
move_object(ob4,this_object());
ob3 = clone_object("/players/saber/armor/bshield.c");
move_object(ob3,this_player());
ob = clone_object("/players/saber/armor/chainmail.c");
move_object(ob,this_object());
ob2 = clone_object("/players/saber/weapons/bastard.c");
move_object(ob2, this_object());
     set_name("crusher");
     set_short("Crusher the Orc Captain");
     set_race( "orc");
  command("wield sword");
  command("wear armor");
  command("wear shield");
  command("wear boots");
     set_alias("captain");
     set_gender("male");
     set_long(
 "A large orc with a look of intelligence in his dark red eyes.\n"+
 "Crusher is renown for his tactical abilities.\n");
     set_level(19);
     set_ac(16);
     set_wc(28);
     set_hp(475);
     set_al(-900);
     set_aggressive(0);
     set_chat_chance(15);
   set_a_chat_chance(20);
     load_chat("Crusher yells: You orcs!  Line up!\n");
    load_chat("Crusher yells: No no no!  Move THAT way...\n");
     load_chat("Crusher yells: No!  Swing first, bite second...\n");
     load_chat("Crusher yells: Formation!  Formation, damn it!\n");
     load_chat("Crusher yells: You call that a line?\n");
     load_chat("Crusher looks up at the crowd and waves.\n");
     load_chat("The crowd cheers.\n");
    load_a_chat("Crusher punches you across the face!\n");
     load_a_chat("Crusher yells: Orc soldiers, fall in!\n");
     load_a_chat("Crusher yells: Shield wall, position 6.\n");
     load_a_chat("Crusher yells: Call in the Ogres!\n");
     load_a_chat("Crusher yells: Flank them.  Flank them!\n");
     load_a_chat("Crusher yells: Dogpile!\n");
     load_a_chat("The crowd cheers.\n");
     load_a_chat("The crowd cheers.\n");
     set_spell_mess1("Crusher punches his foe in the face.");
     set_spell_mess2("Crusher punches you in the face.");
 set_chance(10);
 set_spell_dam(12);
   }

}
