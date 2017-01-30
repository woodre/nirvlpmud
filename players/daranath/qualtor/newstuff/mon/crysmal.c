/* Low WC, high Ac monster made from pure crystal, primary damage comes
   from spell attack       -Dar */
#define ROOT "/players/daranath/qualtor/newstuff/"
#include <ansi.h>
inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
set_name("Crysmal");
set_short("A small "+GRN+"Crysmal"+NORM);
set_alias("crysmal");
set_race("elemental");
set_gender("creature");
set_long("A merging of both crystal and stone, the Crysmal's scorpion-like\n"+
         "shape is formed wholly of minerals. Six curved crystalline\n"+
         "shards provide locomotion, while a wicked point of jagged\n"+
         "crystal forms a perfect stinger.\n");
set_level(8);
set_ac(10);
set_wc(5);
set_hp(100+random(50));
set_al(0);
set_dead_ob(this_object());
set_aggressive(1);

set_chance(50);
set_spell_dam(15+random(40));
set_spell_mess1("Crysmal rears forward and "+GRN+"stings"+NORM+" its foe!\n");
set_spell_mess2("Crysmal lashes out and "+GRN+"stings"+NORM+" you with its tail.\n");

     }
    }

monster_died() {
object ob;
  ob = clone_object(ROOT+"obj/crystal.c");
  move_object(ob, environment(this_object()));
write("A piece of crystal drops to the floor.\n");
return 0;
}
