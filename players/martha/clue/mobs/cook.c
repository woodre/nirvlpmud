#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("cook");
  set_alt_name("ho");
  set_race("human");
  set_short(HIC+"The Cook"+NORM);
  set_long(
    "  The Cook, whose real name is Mrs. Ho, is of oriental descent.  She\n"+
"is an overweight woman with jet black hair that is cropped close to her\n"+
"head.  Her gray and white uniform is snug on her large frame.  She is\n"+
"wearing a clean, white apron that will protect her uniform from becoming\n"+
"dirty while she prepares dinner for the guests.  She wears comfortable\n"+
"white shoes that enable her to stand for hours on end with less discomfort.\n"+
"The Cook is not being blackmailed, however one of the guests here tonight\n"+
"used to employ her and she has given information about that person to a\n"+
"certain unnamed host.\n");
  
  add_money(3000);
  set_level(20);
  set_hp(500);
  set_al(0);
  set_ac(17);
  set_wc(30);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
  
  load_chat("The Cook says 'Don't tell anyone, but they are eating monkey brains!'\n");
  load_chat("Mrs. Ho chops some meat into tiny pieces.\n");
  load_a_chat("The Cook throws spices in your face!!\n");
  load_a_chat("Mrs. Ho screams 'Put this in your kettle and boil it bitch!\n");
   
  add_spell("jab","The #MN#$B$ J$N$C$ A$N$B$ B$N$C$ S$N$ you in the eye with the knife sharpener!\n",
  				  "#CTN# cries out in pain as $R$ B L O O D$N$ pours from #TP# eye socket!\n",
  				  50,50);
   /*move_object(clone_object("/players/martha/clue/weps/apron.c"), this_object());
	init_command("wear apron");
	move_object(clone_object("/players/martha/clue/weps/sharpener.c"), this_object());
	init_command("wield sharpener");
	 */
}
