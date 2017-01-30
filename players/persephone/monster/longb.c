inherit "obj/monster";
#include "/players/persephone/rooms.h"
object brand;
object dim;
object plat;
reset(arg) {
  ::reset(arg);
    if(arg) return;
      brand = clone_object("players/persephone/armour/fireshield");
      move_object(brand, TOB);
      init_command("wear shield");
      plat=clone_object("players/persephone/closed/key4");
      move_object(plat, TOB);
      set_name("longbeard");
      set_alias("pirate");
      set_alias("brigand");
      set_short("Longbeard The Brigand");
      set_long("Longbeard is perhaps the most feared resident of\n"+
               "Stormhold.  He as seen and survived all the major\n"+
               "power struggles while not as strong as the leaders\n" +
               "he has a certain cunning.\n");
      set_level (21);
      set_wc (34);
      set_ac (19);
      set_hp(600);
      set_al(-1000);
      set_aggressive(0);
      set_gender ("male");
      set_chat_chance(30);
      set_a_chat_chance(40);
      load_chat("Longbeard snickers: It looks like Vvladimir has control\n");
      load_chat("Longbeard whistles an eerie tune.\n");
      load_chat("Longbeard asks: Who will you side with?\n");
      load_chat("Longbeard states: Jeny may be strong but she is hated!\n");
      load_chat("Longbeard claims: While Vvladimir has the hook he can defeat Jeny\n");
      load_a_chat("Longbeard chuckles: So you want to fight\n");
      load_a_chat("Longbeard screams: Your weak you cannot defeat me\n");
      load_a_chat("Longbeard states: You have to do better than that\n");
      set_chance(25);
      set_spell_dam(35);
      set_spell_mess1("Longbeard swings his firebrand\n");
      set_spell_mess2("Longbeard hits you with a red hot firebrand\n");
}
second_life() {
      dim=clone_object("players/persephone/closed/dim");
      move_object(dim, TPL);
      write("Longbeard collapses in a heap as you hear him gasping\n" +
            "for air.\n");
      ::second_life();
}

