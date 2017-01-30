inherit "/obj/monster";
int lvl,wcc;

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
   gold->set_money(1000);
  move_object(gold,this_object());
ob2 = clone_object("/players/emerson/armor/hat.c");
move_object(ob2,this_object());
ob3 = clone_object("/players/emerson/armor/jacket.c");
move_object(ob3,this_object());
init_command("wear hat");
init_command("wear jacket");
     set_name("driver");
set_short("Driver of the Month");
     set_race( "human");
set_long("This driver stands out from the rest, you notice his hat and jacket\n"+
"are different. He looks alot tougher than the others, better be careful!\n");
     set_level(19);
     set_ac(16);
     set_wc(28);
     set_hp(475);
     set_al(-500);
     set_aggressive(0);
     set_chance(45);
     set_spell_dam(15);
    set_spell_mess1("Driver flails his arms about wildly!\n");
    set_spell_mess2("Drivers flails his arms at you!\n");
     set_chat_chance(30);
     set_a_chat_chance(35);
      load_chat("The driver pushes you out of his way!\n");
      load_chat("The driver yells : What's my next delivery?!\n");
      load_chat("The driver tries to look busy while waiting for his next run.\n");
      load_chat("The driver mumbles something about getting stiffed again.\n");
      load_a_chat("The Driver Scratches your face with his keys.\n");
      load_a_chat("Driver screams : See if I deliver to you ever again!\n");
      load_a_chat("Driver Kicks you Between the Legs.\n");
   }
}
