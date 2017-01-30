/*=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
=-=
=-=	elf_eg.c
=-=
=-=	An elite elven guard
=-=
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=*/

inherit "/obj/monster";
#include "/players/pain/color.h"

reset(arg) {
int number;
  ::reset(arg);
  set_short(BOLD+GREEN+"Elite Elven Guard"+END+" \(elven "+BOLD+"guardian"+END+"\)");
  set_long("The "+BOLD+GREEN+"Elite Elven Guard"+END+
	"is a protector of the\n"+
	"upper flet. He is a fearsome looking elf, with a look\n"+
	"tainted with experience and righteous wrath. It would\n"+
	"be wise to obey his commands and not arouse his anger.\n");
  set_level(17);
  set_race("elf");
  set_hp(500+random(100));
  load_a_chat("Long live the Elven Kings!\n");
  move_object(clone_object("/players/pain/NEW/flet/Wep/rblade"),this_object());
  init_command("wield runeblade");
  number=random(2);
  if(number == 0) {
	move_object(clone_object("/players/pain/NEW/flet/Arm/eg_helm"),this_object());
	init_command("wear helm");
  }
  if(number == 1) {
 	move_object(clone_object("/players/pain/NEW/flet/Arm/eg_boots"),this_object());
	init_command("wear boots");
  }
  set_ac(12);
  set_wc(20);
}

