#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("conan");
  set_alias("librarian");
  set_race("avatar");
  set_short("Conan- the Librarian");
  set_long("Conan is here to teach you a lesson.\n"+
            "He is big and tough- and you do not want\n"+
            "to fight him....\n");
  set_hp(2000);
  set_level(30);
  set_al(0);
  set_wc(69);
  set_ac(27);
  set_heal(3,10);
  set_aggressive(0);
  set_pet_command();
  set_chat_chance(40);
  load_chat(BOLD+"Conan says: follow the rules of the Library!\n"+NORM);
  load_chat("Conan tells you: You have been bad!\n");
  set_chance(50);
  set_spell_dam(50);
  set_spell_mess1("Conan strikes out with a great fist!\n");
  set_spell_mess2("Conan strikes out with a great fist!\n");
  set_mass_chance(50);
  set_mass_dam(50);
  set_mass_spell("Conan glares at you:  Fear floods you!\n");  
  set_pet_cmd1("Conan laughs and flicks aside the little ones!\n");   
  set_pet_cmd2("Conan smiles and calls nature to his command!\n");
  set_mult(7);
  set_mult_dam1(10);
  set_mult_dam2(45);
  set_mult_chance(50);
}
