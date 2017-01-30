/******************/
/* Rabbit         */
/* Hogath         */
/* created 05/11  */ 
/**************** */

#include <ansi.h>

inherit "/obj/monster";

string color;

reset(arg) {
    ::reset(arg);
    if (!arg)  {
       
          switch (random(3))  {
           case 0: color=HIW; break;
           case 1: color=YEL; break;
           case 2: color=WHT; break;
           default: color=HIW; break;
                              }
       

        set_name("Rabbit");
        set_alt_name("bunny");
        set_alias("bunny");
        set_short(color+"Rabbit Worker"+NORM);  
        set_race("rabbit");
        set_long(
"This is a rabbit worker.  He is responsible for the maintence\n"+
"and upkeep of the rabbit tunnel.\n");
        set_gender("male");
        set_level(10);
        set_ac(6);
        set_wc(18);
        set_hp(200);
        set_al(-100);}
        set_chat_chance(5);
        load_chat(color+"Rabbit"+NORM+" hops.\n");
        load_chat(color+"Rabbit"+NORM+" digs.\n");
        set_dead_ob(this_object());
}
id(str){return (::id(str) || str == "rabbit" || str == "worker" || str == "rabbit worker" || str == "bunny" || str == "wabbit");} 
monster_died(ob)  {
    object hide;

    write("You deftly skin the "+color+"rabbit"+NORM+" garnering it's furry hide!\n");
    tell_room(environment(),
        this_player()->query_name()+" skins a rabbit!\n",
        ({ this_player()})
);

  hide = clone_object("/obj/treasure");
  hide->set_id("hide");
  hide->set_short(color+"Rabbit"+NORM+" hide");
  hide->set_long(
"This is a rabbit's hide, it looks like you might be able to\n"+
"sell it for some coins.\n");
  hide->set_value(300+random(100));
  hide->set_weight(1);

  move_object(hide,environment(ob));

}
