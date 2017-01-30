/* [addition/change] 2005.03.10 -Forbin
//    changed spell attack to new monster spell code with dtype and
//    added a smaller spell to go with it.  Colorized short 
//    upped level to 23 and set other things to appropriate levels
//    was WAY to easy for a monster that had WC 21 weapon*/
inherit "/obj/monster";
#include "/players/saber/closed/ansi.h"

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object gold;
   gold = clone_object("obj/money");
   gold->set_money(1000+random(3000)); 
   move_object(gold,this_object());
     set_name("lightning elemental");
      set_short(HIW+"A "+HIY+"Lightning "+HIW+"Elemental"+NORM);
     set_alias("lightning");
     set_race( "elemental");
       set_long("A large sphere of softly glowing lightning.\n"+
          "The elemental pulses like a living heart.\n");
     set_level(23);
     set_ac(35);
     set_wc(45);
     set_hp(1200);
     set_al(-750);
     set_aggressive(1);
     set_dead_ob(this_object());       
     set_chat_chance(20);
     set_a_chat_chance(15);
      load_chat("Lightning Elemental pulses softly.\n");
     load_a_chat("Lightning Elemental pulses softly.\n");
     load_a_chat("Lightning Elemental emits a blinding flash of light.\n");

     set_armor_params("other|electric",0,100,0);   /* no damage from other|electric */
     add_spell("lightningelemental_spell1",
       "\n\t\t$HY$--- $HW$FLASH $HY$---$N$\n\n"+
       "You are struck by a mighty bolt of $HY$lightning$N$!\n",
       "\n\t\t$HY$--- $HW$FLASH $HY$---$N$\n\n"+
       "#CTN# is struck by a mighty bolt of $HY$lightning$N$!\n",
       15+random(10), "40-70", "other|electric");
     add_spell("lightningelemental_spell2",
       "$HY$Lightning$N$ crackles across the sky, searing the air!\n",
       "$HY$Lightning$N$ crackles across the sky, searing the air!\n",
       10+random(10), "15-30", "other|electric");
   }
}

monster_died() {
  object treasure;
  tell_room(environment(this_object()),
    "\n\nThere is a bright flash as the "+HIY+"Lightning "+HIW+"Elemental "+NORM+" forms\n"+
    "a brilliant "+HIY+"bolt of lightning"+NORM+".  Some coins lie nearby,\n"+
    "which is likely what the elemental was protecting.\n");
  treasure = clone_object("/players/saber/weapons/lightning.c");
  move_object(treasure, environment(this_object()));
  destruct(present("corpse", environment()));  
  return 1;
}
