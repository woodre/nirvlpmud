#include <ansi.h>

inherit "/obj/monster";

reset(arg) {
    ::reset(arg);
    if (!arg)  {
      

        set_name("rat");
        set_short(HIB+"A Rat"+NORM);
        set_race("rat");
        set_long(
	"   This is a standard house rat.  It has beady black eyes and\n"+
"is gray.  The tail of the rat is very long and moves rapidly back\n"+
"and forth.  The rat opens its mouth, showing sharp, pointy teeth,\n"+
"ready to gnaw away!\n");
        set_level(10);
        set_ac(8);
        set_wc(14);
        set_hp(150);
        set_al(-100);}
        set_chat_chance(10);
        set_a_chat_chance(10);
        
        load_chat("The rat bears its teeth.\n");
        load_chat("The rat goes 'Squeeeeeeeeeek, Squeeeeeeeeeek'\n");
        load_a_chat("The rat jumps on your leg and sinks its teeth in!\n");
        set_dead_ob(this_object());
}

monster_died(ob)  {
    object tail;

    write(BOLD+"You rip off the rats long, hairless tail!\n"+NORM);
    tell_room(environment(),
        this_player()->query_name()+" rips the tail off the rat!\n",
        ({ this_player()})
);

  tail = clone_object("/obj/treasure");
  tail->set_id("tail");
  tail->set_short(BOLD+"A Rat Tail"+NORM);
  tail->set_long(
"This is the tail of a standard house rat.  It may be valuable.\n"
  );
  tail->set_value(350+random(50));
  tail->set_weight(1);

  move_object(tail,environment(ob));

}

