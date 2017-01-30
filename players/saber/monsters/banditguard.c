inherit "/obj/monster";

/* < add id of guard - forbin oct2002.04 */
id(str) { return (::id(str) || str == "guard"); }
/* < /add id of guard - forbin > */
reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob2, ob3, gold;
 gold = clone_object("obj/money");
  gold->set_money(random(100));
  move_object(gold,this_object());
  ob2 = clone_object("/players/saber/weapons/mspear.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/armor/fmask.c");
move_object(ob3,this_object());

set_name("Masked bandit"); /* Changed to match the others -Dar */
set_alt_name("bandit");
      set_short("A Bandit Guard");
     set_race( "human");
   set_long("A buff looking bandit armed with a glowing spear.\n");
     set_level(11);
     set_ac(9);
     set_wc(15);
     set_hp(165);
     set_al(-250);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(25);
     load_chat("Bandit grins evilly at you.\n");
      load_chat("Bandit says: Leave now.\n");
      load_chat("Bandit glares at you.\n");
     load_a_chat("Bandit curses at you.\n");
      load_a_chat("Bandit punches you.\n");
   }
}
