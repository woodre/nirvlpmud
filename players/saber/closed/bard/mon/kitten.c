/*
 * A kitten which can be summoned by a bardic cantrip.
 * The kitten can be picked up.
 * Bard v3.0
 */

inherit "/obj/monster";

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("cat");
    set_short("A small cat");
    set_alias("summoned");
    set_race("feline");
    set_long("A small black kitty with long whiskers.\n"+
             "You have a strong desire to hold it.\n");
    set_level(1);
    set_ac(7);
    set_wc(3);
    set_hp(3);
    set_al(100);
    set_ep(1);
    set_gender("creature");
    set_chat_chance(15);
    set_a_chat_chance(15);
    load_chat("The cat looks at you.\n");
    load_chat("The cat purrs.\n");
    load_chat("The kitty meows softly.\n");
    load_chat("The cat grooms itself.\n");
    load_chat("The cat peers at you.\n");
    load_a_chat("The cat hisses.\n");
    load_a_chat("The cat glares at you with dark yellow eyes.\n");
        }
        }

get()  { return 1; }
