/******************/
/* Rabbit         */
/* Hogath         */
/* created 03/04  */ 
/**************** */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      
       

        set_name("Rabbit");
        set_alt_name("bunny");
        set_alias("bunny");
        set_short(HIW+"Rabbit"+NORM);
        set_race("rabbit");
        set_long(
"A little white bunny.  He is occupied with eating up the.\n"+
"contents of the garden.\n");
        set_gender("male");
        set_level(7);
        set_ac(6);
        set_wc(12);
        set_hp(105);
        set_al(1);}
        set_chat_chance(5);
        load_chat("Rabbit hops.\n");
        load_chat("Rabbit munches on "+YEL+"corn"+NORM+".\n");
        load_chat("Rabbit knaws on "+BOLD+"cabbage"+NORM+".\n");
        load_chat("Rabbit chews on a "+RED+"tomato"+NORM+".\n");
        set_dead_ob(this_object());
}

monster_died(ob)  {
    object foot;

    write("With no remorse you lop off a "+WHT+"rabbit's"+NORM+" foot!\n");
    tell_room(environment(),
        this_player()->query_name()+" lops off a rabbit's foot.\n",
        ({ this_player()})
);

  foot = clone_object("/obj/treasure");
  foot->set_id("foot");
  foot->set_short(WHT+"Rabbit's"+NORM+" Foot");
  foot->set_long(
"This is a rabbit's foot, it wasn't lucky for him, but it\n"+
"might be lucky for you if you sell it.\n");
  foot->set_value(175+random(100));
  foot->set_weight(1);

  move_object(foot,environment(ob));

}
