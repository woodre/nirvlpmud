#include <ansi.h>
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "/players/daranath/closed/monster1.c";

reset(arg){
  ::reset(arg);
  if (!arg){
          
set_name("FrightCrawler");
set_short("A deep blue undead Lizard");
set_alias("lizard");
set_alt_name("gravemon");
set_race("undead");
set_gender("creature");
set_long("A blue undead lizard that infests the old keep within Qual'tor, it\n"+
         "runs along the pathways and scavenges for anything to eat. Bright\n"+
         "blue streaks run along its backside, perhaps an indication or\n"+
         "warning of some kind.\n");
set_level(15);
set_ac(15);
set_wc(14+random(4));
/* High AC, low WC to emulate a quick little lizard. Main attack from special */
set_hp(200+random(80));
set_al(-(250+random(350)));
set_aggressive(0);
set_dead_ob(this_object());

set_chance(60);
set_spell_dam(15+random(50));
set_spell_mess1("Electricity runs down the spine of the FrightCrawler.\n");
set_spell_mess2("The FrightCrawlers shudders violently then unleashes a\n"+
     "\n"+HIY+"     <><><><> --- LIGHTNING BOLT --- <><><><> "+NORM+"  \n"+
     "\nin your direction. You can feel its power through your armor.\n");

     }
    }

monster_died() {
write("A pair of small crystals fall from the corpse of the FrightCrawler.\n");
move_object(clone_object(ROOT+"obj/light_cryst.c"),environment(this_object()));
move_object(clone_object(ROOT+"obj/light_cryst.c"),environment(this_object()));
return 0;
}

