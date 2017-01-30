#include <ansi.h>
inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("white");
  set_alt_name("mrs");
  set_race("human");  
  set_short(BOLD+HIW+"Mrs. White"+NORM);
  set_long(
    "  Mrs. White is a petite woman with chin length black hair.\n"+
"She walks around with pursed lips that are colored a bright shade\n"+
"of red.  She appears to be in mourning and wears a dark black dress,\n"+
"black shoes, and a dark black veil to cover her face.  She has lost\n"+
"five husbands and notices that a mistress of one of her former dead\n"+
"husbands is also present this evening.  Mrs. White is being blackmailed\n"+
"for the disappearance of her latest husband, and while his body has yet\n"+
"to be found, she pays the blackmailer to avoid a scandal!\n");

  add_money(2000+random(900));
  set_level(20);
  set_hp(500+random(100));
  set_al(-900);
  set_ac(21+random(4));
  set_wc(32);
  set_aggressive(0);
  set_chat_chance(10);
  set_a_chat_chance(10);
    
  load_chat("Mrs. White says 'Flames..flaming...burning...heaving...'\n");
  load_chat("Mrs. White says 'Husbands should be like kleenex - soft, strong and disposable!'\n");
  load_chat("Mrs. White says 'Flies are where men are most vulnerable!'\n");
  load_a_chat("Mrs. White blinds you with her veil!\n");
  load_a_chat("Mrs. White chortles you with the rope!'\n");
  
  add_spell("tighten","Mrs. #MN# $C$T I G H T E N S$N$ the rope around your neck, leaving you gasping for air!\n",
  					  "#CTN# loses consciousness as the rope $C$T I G H T E N S$N$ around #TP# neck!\n",
  					  50,50);
   /*move_object(clone_object("/players/martha/clue/weps/rope.c"), this_object());
	init_command("wield rope");
	move_object(clone_object("/players/martha/clue/weps/veil.c"), this_object());
	init_command("wear veil");
	move_object(clone_object("/players/martha/clue/weps/tissues.c"), this_object()); */
}
