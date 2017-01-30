#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "/players/daranath/closed/monster1.c";

reset(arg){
  ::reset(arg);
  if (!arg){
          
set_name("Ashen Grinder");
set_short(BOLD+BLK+"Ashen Grinder"+NORM);
set_alias("grinder");
set_race("demon");
set_gender("creature");
set_long("A small demon that crawls about on six legs, the Ashen Grinder\n"+
         "kind of resembles a cross between a spider and a large toad.\n"+
         "Its covered in dark ash, and radiates extreme heat from within\n"+
         "its body. The mouth of the Grinder is agape, streaming\n"+
         "red hot ash about the area.\n");
set_level(16);
set_ac(13);
/* WC of 9 is below guide of 22, but most damage is from special */
set_wc(9);
set_hp(300+random(50));
set_al(-(250+random(350)));
set_aggressive(1);
set_dead_ob(this_object());

set_chance(50);
set_spell_dam(20+random(65));
set_spell_mess1("Ashen Grinder breathes a cloud of ash upon its foe!\n");
set_spell_mess2(BOLD+BLK+"Ashen Grinder"+HIR+" breathes "+BOLD+BLK+"a cloud of Ash upon you.\n"+NORM);

     }
    }

monster_died() {
move_object(clone_object(ROOT+"obj/ash_pile.c"),environment(this_object()));
move_object(clone_object(ROOT+"obj/ash_pile.c"),environment(this_object()));
return 0;
}


