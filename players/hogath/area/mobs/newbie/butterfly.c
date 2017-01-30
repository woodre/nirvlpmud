/******************/
/* Hogath         */
/* created 3/04   */ 
/**************** */

#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      

        set_name("Butterfly");
        set_alt_name("bug");
        set_alias("butterfly");
        set_short(BOLD+"Butterfly"+NORM);
        set_race("bug");
        set_long(
"A beautiful Butterfly.  It has made this field it's home\n");
        set_gender("male");
        set_level(5);
        set_ac(5);
        set_wc(9);
        set_hp(75);
        set_al(1);
        }
        set_chat_chance(2);
        load_chat(BOLD+"Butterfly flutters\n"+NORM);
        load_chat(BOLD+"Butterfly lands on your nose\n"+NORM);
        set_dead_ob(this_object());
}

monster_died(ob)  {
    object wings;

    write(BOLD+"You rip off the butterfly's wings!\n"+NORM);
    tell_room(environment(),
        this_player()->query_name()+" rips the wings off the butterfly.\n",
        ({ this_player()})
);

  wings = clone_object("/obj/treasure");
  wings->set_id("wings");
  wings->set_short(BOLD+"A Butterfly's Wings"+NORM);
  wings->set_long(
"These are the wings from a butterfly.  They could be valuable.\n"
  );
  wings->set_value(150+random(50));
  wings->set_weight(1);

  move_object(wings,environment(ob));

}
