inherit "obj/monster";
#include "/players/catt/AREAS/base_defines.c"
  reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("ice dragon");
   set_alias("dragon");
   set_short("Ice Dragon");
   set_long(
      "A very large Ice Dragon, it looks as though it is guarding\n"+
      "something of great importance, you can't quite see what it\n"+
      "is. The dragon itself is a perfect white. Large claws and\n"+
      "teeth make it a dangerous foe for even the most powerful.\n"+
      "Its rumored frost breath even furthers your assessment that\n"+
      "You shouldn't mess with him unless you really think your\n"+
      "tough\n");
   set_level(30);
   set_race("dragon");
   set_hp(2000);
   set_al(-1000);
   set_wc(25);
   set_ac(15);
   set_chance(15);
   set_spell_dam(35);
   set_spell_mess1("Dragon breathes a frosty breath chilling you.\n");
   set_spell_mess2("You are frost bitten as the Dragon breathes on you.\n");
}
init() {
   add_action("alcove","alcove");
   ::init();
       }
alcove() {
  object who;
  who = this_player();
   write("The Dragon looks at you icily.\n"+
         "Dragon says: You can't go there while I yet live mortal!\n");
call_other(who, "move_player",
         "shimmers#"+MOUNT+"mount_peak");
   return 1;
}
