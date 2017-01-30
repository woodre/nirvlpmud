/* Changed from lev20 to 17, hp 500 to 400, wc 30 to 28, ac 17 to 12, and
   added spell effects -Snow */
inherit "obj/monster";
reset(arg){
   object comb,scissors;
   ::reset(arg);
   if(arg) return;
   set_name("pierre");
   set_race("human");
   set_alias("hairdresser");
   set_short("Pierre, the hairdresser");
   set_long(
"This is Pierre, Trixtown's hairdresser.  He's dressed in pink and has a pair\n"+
"of slim moustaches.  He's got a comb and a pair of scissors in his hands.\n");
   set_level(17);
   set_hp(400);
   set_al(300);
   set_wc(28);
   set_ac(12);
   set_aggressive(0);
   set_chance(15);
   set_spell_dam(20);
/* verte added spell_mess1 */
   set_spell_mess1("Pierre whittles away at his enemy like a madman!\n");
   set_spell_mess2("Pierre whittles away at your body like a madman!\n");
   set_chat_chance (5);
   load_chat("Pierre winks suggestively at you.\n");
   load_chat("Pierre says: Oh mon Dieu, your hair really needs a little cut.\n");
   set_a_chat_chance(15);
   load_a_chat("Pierre screams: Que est que tu cherchez?\n");
   load_a_chat("Pierre shouts: Oh mon maman, leave me in peace!!!\n");
   comb=clone_object("/players/trix/castle/town/monst/comb");
   move_object(comb,this_object());
   scissors=clone_object("/players/trix/castle/town/monst/scissors");
   move_object(scissors,this_object());
}
