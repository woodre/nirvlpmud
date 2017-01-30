/* **********************************************************************
*
********************************************************************** */

inherit "obj/monster.c";
#include "/players/jareel/define.h"

     reset(arg)  {
       ::reset(arg);
       if(arg) return;

     set_name("Dark Troll");
     set_alt_name("dark");
     set_short(HIK+"Dark Troll"+NORM);
     set_alias("troll");
     set_long(
       "This large hunched over form of a humanoid looms over\n"+
       "you.  Powerful mucles bulge from this intimidating form.\n"+
       "The skin of this Troll is a deep ebony, absorbing the\n"+
       "the surrounding light.\n");
     set_spell_mess1("The sharp claws slash over your soul.\n");
     set_spell_mess2("The sharp claws slash.\n");
     set_chance(25);
     set_spell_dam(70);
     set_race("troll");
     set_al((500-random(1000)));
     set_level(23);
     set_hp(800);
     set_wc(40);
     set_ac(21);
     set_heal(5,1);
     set_aggressive(1);
     add_money(7000+random(1000));
     set_dead_ob(this_object());
     set_armor_params("other|light",0,-100,0); /* Double damage from light */
     set_armor_params("other|dark",0,100,0); /* Immune damage from dark */
     }
     

