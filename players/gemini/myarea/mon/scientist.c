/*
 *      File:                   example.c
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
  set_name("Dr. Bunsen");
   set_alt_name("bunsen");
  set_alias("scientist");
  set_short("Dr. Bunsen the Scientist");
  set_long(
"     Dr. Bunsen is short and bald. He wears a blue lab coat with\n"+
"a red tie. He squints through his glasses and returns your stare.\n"+
"He is always shouting at Beaker for something, but everyone knows\n"+
"that the experiments messing up are due to the Doctor himself.\n"
);
  set_gender("male");
  set_race("human");
  set_level(17);
  set_wc(24);
   set_ac(14);
  set_hp(350);
  set_al(0);
  set_chat_chance(5);
  load_chat("Dr. Bunsen says: Beaker did it. Damn him!\n");
  load_chat("Dr. Bunsen jumps up and down franticly!\n");
  load_chat("You start at Dr. Bunsen's beady little eyes\n");
  load_a_chat("Dr. Bunsen reaches for a sharp object!\n");
  load_a_chat("Dr. Bunsen screams for help!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object dglasses;
  write("Dr. Bunsen falls down, his glasses falling off as he hits the ground\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed \n",
            ({ this_player() })
  );
  dglasses=clone_object("/obj/treasure");
  dglasses->set_id("glasses");
  dglasses->set_short("Dr. Bunsen's glasses (broken)");
  dglasses->set_long(
"These are Dr. Bunsen's glasses\n"+
"Unfortunately they are broken\n"
  );
  dglasses->set_value(2100);
  dglasses->set_weight(1);
  move_object(dglasses,environment(ob));

}

