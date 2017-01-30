/******************/
/* Fish           */
/* Hogath         */
/* cc 2004        */ 
/**************** */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      
       

        set_name("Trout");
        set_alt_name("trout");
        set_alias("fish");
        set_short(BOLD+"Trout"+NORM);
        set_race("fish");
        set_long(
"A trout that was swimming up stream, and has been caught\n"+
"in this pool by the current.\n");
        set_gender("male");
        set_level(8);
        set_ac(7);
        set_wc(12);
        set_hp(120);
        set_al(0);
        }
        set_dead_ob(this_object());
}

monster_died(ob)  {
    object tail;

    write("With precision you slice off a Trout's tail\n");
    tell_room(environment(),
        this_player()->query_name()+" cuts off a trout's tail.\n",
        ({ this_player()})
);

  tail = clone_object("/obj/treasure");
  tail->set_id("tail");
  tail->set_short("A fish's tail");
  tail->set_long(
"This is a Trout's tail.  It might be worth something\n"
  );
  tail->set_value(200+random(100));
  tail->set_weight(1);

  move_object(tail,environment(ob));

}
