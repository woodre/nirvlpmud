/*
 *  A dream that you can fight.  Note the random features used
 *    for its vital stats.
 *  Read KISSBANDIT.c first.
 *                                                      -- Saber
 */

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(101) + 550);
  move_object(gold,this_object());

     set_name("dream");
     set_short("A featureless dream");
     set_race( "spirit");
     set_alias("ghost");
     set_long("Your eyes can not make out the distinct features of a dream.\n");
     set_level(12);
     set_ac(8 + random(3));
     set_wc(15 + random(3));
     set_hp(160 + random(40));
     set_al(-500);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The dream fades from view.\n");
     load_chat("The dream moves very slowly.\n");
     load_a_chat("The dream tries to fade away.\n");
     load_a_chat("The dream drains part of your soul.\n");
   }
}
