/* Changed aggressive from 0 to 1, added spell chance, message, and damage. */
/* -Snow */
inherit "obj/monster";
reset(arg){
   object gold,meat,knife;
   ::reset(arg);
   if(arg) return;
   set_name("igor");
   set_race("human");
   set_alias("butcher");
   set_short("Igor, the butcher");
   set_long("Igor wears blood soaked clothes.  He has a large knife in his\n"+
            "hands.\n");
   set_level(20);
   set_hp(500);
   set_al(300);
   set_wc(30);
   set_ac(17 );
   set_aggressive(1);
   set_chance(25);
  /* Added by Feldegast 6-18-2000 */
  set_spell_mess1("Igor brandishes his cleaver!\n");
   set_spell_mess2("Igor rips your stomach open with his cleaver!\n");
   set_spell_dam(35);
   set_chat_chance (5);
   load_chat("Igor shows his knife off.\n");
   load_chat("Igor cuts some meat.\n");
   load_chat("Igor says: Hey look at this meat, it still seems alive!\n");
   set_a_chat_chance(15);
   load_a_chat("Igor throws his knife at you.\n");
   load_a_chat("Igor tackles you to the ground.\n");
   gold=clone_object("obj/money");
   gold->set_money(3950+random(51));
   move_object(gold,this_object());
   meat=clone_object("/players/trix/castle/town/monst/meat");
   move_object(meat,this_object());
   knife=clone_object("/players/trix/castle/town/monst/knife");
   move_object(knife,this_object());
}
