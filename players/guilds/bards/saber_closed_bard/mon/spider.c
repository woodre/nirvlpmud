/*
 * A spider which can be summoned by a bardic cantrip.
 * Bard v3.0
 */

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("spider");
    set_short("A small spider");
    set_race("spider");
    set_alias("summoned");
    set_long("Ewwwwww!  A spider.\n");
    set_level(1);
    set_ac(5);
    set_wc(3);
    set_hp(3);
    set_al(-5);
    set_ep(1);
    set_gender("creature");
    set_chat_chance(10);
    load_chat("The spider scuttles across the floor.\n");
    set_dead_ob(this_object());

        }
        }

monster_died()  {
object ob;
  tell_room(environment(this_object()),
  "  > > >  S P L A T  < < <\n");
  return 0;
        }
