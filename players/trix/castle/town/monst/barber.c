/* Changed level from 20 to 18, hp from 500 to 420, ac from 17 to 14, money from 2950 to 300 (keeps razor) and added spell chance and damage */
inherit "obj/monster";
reset(arg){
   object gold,razor;
   ::reset(arg);
   if(arg) return;
   set_name("edge");
   set_race("human");
   set_alias("barber");
   set_short("Edge, the barber");
  set_long(
"A gentle and handsome man dressed in white and with a shining razor in one\nhand.\n");
   set_level(18);
   set_hp(420);
   set_al(300);
   set_wc(30);
   set_ac(14 );
   set_aggressive(0);
   set_chance(20);
   set_spell_dam(25);
   set_spell_mess2("Edge slashes at you with a savage violence!\n");
   set_chat_chance (5);
   load_chat("Edge sharpens his razor.\n");
   load_chat("Edge looks at you and smiles.\n");
   load_chat("Edge says: Hey!  Look at that beard!  It needs a shaving!\n");
   set_a_chat_chance(15);
   load_a_chat("Edge hurts you with his razor.\n");
   load_a_chat("Edge grins and says: I love sharpened blades!\n");
   gold=clone_object("obj/money");
   gold->set_money(2950+random(51));
   move_object(gold,this_object());
   razor=clone_object("/players/trix/castle/town/monst/razor");
   move_object(razor,this_object());
}
