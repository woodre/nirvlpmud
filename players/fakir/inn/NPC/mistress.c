#include "/players/fakir/color.h"
inherit "obj/monster.c";
reset(arg)  {
object treasure;
  ::reset(arg);
  if(arg) return;

set_name("mistress");
set_alias("mistress");
set_race("human");
set_short("Mistress 'al Vere");
set_long(
  "Easily the best cook in the whole Two Rivers countryside, Mistress 'al Vere\n"+
  "is slender of build and of moderate height.  Attractive and simply dressed,\n"+
  "she almost stops you in your tracks with her glowing smile.  Her graying hair\n"+
  "is pulled back in a thick braid and thrown over one shoulder.  She has just\n"+
  "finished rolling out some honeycake dough, and is ready to pop it in the oven\n"+
  "to bake. \n");

set_level(13);
set_hp(195);
set_al(1000);
set_wc(17);
set_ac(10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Mistress says: Come on, honeycakes are almost ready.  Sit down and rest a spell. \n");
  load_chat("Mistress shrugs and says: A man has to eat well to keep up his strength! \n");
   
set_a_chat_chance(15);
  load_a_chat("Mistress says: How dare you attack me in my own kitchen! \n");
  load_a_chat("The mistress takes to hitting you with her rolling pin. \n");
  load_a_chat("Mistress 'al Vere screams out "+RED+" 'BLOODY MURDER' "+OFF+". \n");


treasure=clone_object("/players/fakir/inn/OBJ/rollpin.c");
move_object(treasure,this_object());
}

monster_died() {
  move_object(clone_object("/players/fakir/inn/OBJ/fpurse.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
	"Mistress 'al Vere falls dead and a coinpurse slips from the pocket of her apron.\n");
return 0; }
