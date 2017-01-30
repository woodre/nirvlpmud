inherit "obj/monster";
#include "/players/persephone/rooms.h"
object sab;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      sab = clone_object("players/persephone/weapon/sabr");
      move_object = (sab, TOB);
      init_command = ("wield sabre");
      set_name("pirate");
      set_alias("ruffian");
      set_alias("man");
      set_short("A White Pirate");
      set_long("A burly and strong looking pirate. He seems\n"+
               "to be carrying a large bundle over his shoulder.\n"+
               "By his left side he has a Saber and he looks strong\n");
      set_level (16);
      set_wc (22);
      set_ac (13);
      set_hp(400);
      set_al(100);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(30);
      load_chat("Pirate throws back his head and Cackles Gleefully!!\n");
      load_chat("Pirate says: Haha me hearties this is Jeny's town now\n");
      load_chat("The Pirate Snickers at you\n");
      load_chat("Pirate asks: Did you puny fools think you could beat us?\n");
      load_chat("The Pirate pokes the bundle!\n");
      load_chat("The Pirate spits on the floor.\n");
      set_chance(15);
      set_spell_dam(10);
      set_spell_mess1("The Pirate throws some dust\n");
      set_spell_mess2("The Pirate throws dust in your eyes\n");
}

