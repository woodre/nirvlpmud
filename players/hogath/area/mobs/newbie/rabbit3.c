/******************/
/* Rabbit         */
/* Hogath         */
/* created 05/13  */ 
/**************** */

#include <ansi.h>
#include "/players/hogath/tools/def.h"

inherit "/obj/monster";

string color;

reset(arg) {
    ::reset(arg);
    if (!arg)  {
       
          switch (random(4))  {
           case 0: color=HIW; break;
           case 1: color=YEL; break;
           case 2: color=WHT; break;
           case 3: color=HIY; break;
           default: color=HIW; break;
                              }
       

        set_name("Rabbit");
        set_alt_name("bunny");
        set_alias("bunny");
        set_short(color+"Rabbit Lord"+NORM);  
        set_race("rabbit");
        set_long(
"This is a Rabbit Lord, he seems to be a little bit bigger than the other.\n"+
"rabbits you have encountered.\n");
        set_gender("male");
        set_level(10);
        set_ac(8);
        set_wc(18);
        set_hp(230);
        set_al(-150);}
        set_chat_chance(5);
        load_chat(color+"Rabbit"+NORM+" munches on roots.\n");
        load_chat(color+"Rabbit"+NORM+" says: I must see the King!\n");
        add_spell("wabbit bite",
                  "\n"+color+"#MN#"+NORM+" "+HIR+"N I B B L E S"+NORM+" on your knee.\n\n",  
                  "\n"+color+"#MN#"+NORM+" "+HIR+"N I B B L E S"+NORM+" #TN#.\n\n",
                  10,20,"physical",6);        
        set_dead_ob(this_object());
}
id(str){return (::id(str) || str == "rabbit" || str == "lord" || str == "rabbit lord" || str == "bunny" || str == "wabbit");} 
monster_died(ob)  {
    object teeth;

    write("You rip teeth from the Rabbit Lord's jaw!\n");
    tell_room(environment(),
        this_player()->query_name()+" rips teeth out of the rabbit's mouth!\n",
        ({ this_player()})
);

  teeth = clone_object("/obj/treasure");
  teeth->set_id("teeth");
  teeth->set_short(color+"Rabbit"+NORM+" teeth");
  teeth->set_long(
"These are some short rabbit "+HIW+"teeth"+NORM+", they are useless to you\n"+
"but you might be able to sell them for some coins.\n");
  teeth->set_value(500+random(100));
  teeth->set_weight(1);

  move_object(teeth,environment(ob));

}
