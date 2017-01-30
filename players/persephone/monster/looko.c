inherit "obj/monster";
#include "/players/persephone/rooms.h"
object waffle;
object nety;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      nety = clone_object("players/persephone/weapon/net");
      move_object(nety, TOB);
      init_command("wield net");
      set_name("slash");
      set_alias("pirate");
      set_alias("lookout");
      set_short("Slash The Lookout");
      set_long("A slight young lass with quick looking eyes\n"+
               "and a nimble frame.  That is why they put her up\n"+
               "in the crow's nest\n");
      set_level (19);
      set_wc (28);
      set_ac (16);
      set_hp(475);
      set_al(-500);
      set_aggressive(1);
      set_gender ("female");
      set_a_chat_chance(40);
      load_a_chat("Slash screams: Get down from here you scurvy dog\n");
      load_a_chat("Slash says: Your type are not allowed up here\n");
      load_a_chat("Slash yells: Hey get the guards intruders\n");
      set_chance(20);
      set_spell_dam(25);
      set_spell_mess1("Slash throws her net\n");
      set_spell_mess2("Slash throws her net at you tripping you\n");
}

second_life()
{
    waffle=clone_object("players/persephone/closed/dodo");
    move_object(waffle, TPL);
    ::second_life();
}
