/******************/
/* Lizard         */
/* Hogath         */
/* cc 2004        */ 
/**************** */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      
       

        set_name("Lizard");
        set_alt_name("lizard");
        set_alias("lizard");
        set_short(HIW+"Lizard"+NORM);
        set_race("reptile");
        set_long(
"A Lizard, it is sunning itself on the rocks.\n");
        set_gender("female");
        set_level(7);
        set_ac(6);
        set_wc(12);
        set_hp(105);
        set_al(1);}
        set_chat_chance(5);
        load_chat("Lizard flicks it's tongue at you.\n");
        load_chat("Lizard basks in the sun.\n");
        set_dead_ob(this_object());
}

monster_died(ob)  {
    object tail;

    write("With great gusto you rip off the lizards tail\n");
    tell_room(environment(),
        this_player()->query_name()+" rips the tail off the lizard.\n",
        ({ this_player()})
);

  tail = clone_object("/obj/treasure");
  tail->set_id("tail");
  tail->set_short("A lizard's tail");
  tail->set_long(
"This is a lizard's tail, you can sell it\n"
  );
  tail->set_value(175+random(100));
  tail->set_weight(1);

  move_object(tail,environment(ob));

}

