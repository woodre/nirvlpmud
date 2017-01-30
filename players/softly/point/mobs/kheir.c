#include "/players/softly/closed/ansi.h"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (arg) return;

   set_name("kheir");
   set_short(BOLD + "Ghost" + NORM + " of Kheir-ed-din Barbarossa");
   set_alias("ghost");
   set_long("\
  This large fierce man has an angry countenance and a\n\
bright red beard.  He looks very much like his brother.\n");
   set_race("ghost");
   set_level(19);
   set_ac(16);
   set_wc(28);
   set_hp(450);
   set_al(-20);
   set_chance(20);
   set_spell_dam(35);
   set_spell_mess1("Kheir lashes out with his fists.\n");
   set_spell_mess2("\nKheir "+BOLD+"smashes "+NORM+"you with his fists.\n");
   add_money(3300+random(700));   

}
void init() {
  ::init();
add_action("block_exit", "up");
}
block_exit(){
  if(this_player()->query_level() < 20){
    attack_object(this_player());
    write("Kheir snarls angrily and attacks you.\n");
  return 1;
  }
return;
}
