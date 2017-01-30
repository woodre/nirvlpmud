/*
 *      File:                   goodrat.c
 *      Function:               
 *      Author(s):              Gemini@Nirvana
 *      Copyright:              Copyright (c) 2004 Gemini
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("rat");
  set_alias("good rat");
  set_short("A good rat");
  set_long(
"     This rat is about 4 inches long and does not seem to want to\n"+
"cause you any harm. It has a scar across its back like it got into\n"+
"a brawl with another animal. It is brown in color and does not look\n"+
"to be healthy. It looks very weak.\n"
);
  set_gender("animal");
  set_race("animal");
  set_level(1);
  set_wc(5);
  set_ac(3);
  set_hp(15);
  set_al(0);
  set_chat_chance(2);
  load_chat("Something touches your foot.\n");
  load_chat("Something tickles your leg.\n");
  load_chat("A rat scurries around.\n");
  load_a_chat("The rat bites your ankle *OUCH*\n");
  load_a_chat("The rat jumps up and bites you in the crotch!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object tail;
  write("The poor rat rolls over on its back\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed \n",
            ({ this_player() })
  );
  tail=clone_object("/obj/treasure");
  tail->set_id("tail");
  tail->set_short("Rat's tail");
  tail->set_long(
"This tail belonged to a rat.\n"+
"It has some blood on it.\n"
  );
  tail->set_value(65);
  tail->set_weight(1);
  move_object(tail,environment(ob));

}

