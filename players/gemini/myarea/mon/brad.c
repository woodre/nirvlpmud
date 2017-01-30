/*
 *      File:                   brad.c
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
  set_name("brad");
  set_alias("b-rad");
  set_short("Brad");
  set_long(
"     Brad is the whitest gangster you have ever seen. His dad is\n"+
"running for Govenor. He is wearing a Fubu shirt and a pair of white\n"+
"sneakers. He isn't the best rapper, but thinks he is the Shiznit\n"+
"B-rad is wearing a valuable gold chain.\n"
);
  set_gender("male");
  set_race("human");
  set_level(11);
  set_wc(14);
  set_ac(8);
  set_hp(150);
  set_al(0);
  set_chat_chance(4);
  load_chat("Brad says: Traffic, traffic, lookin for my chapstick,\n"+
                        "Feelin' kinda carsick, There's a Ford Maverick!\n");
  load_chat("Brad asks: Yo fool! Are you trying to play me?\n");
  load_chat("Brad tells you: Yo! Are you gonna kill me? Let me go get my gat!\n");
  load_a_chat("Brad puts a cap in yo ass!\n");
  load_a_chat("Brad punches you!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object bchain;
  write("B-rad falls to the ground clutching his gold chain\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed \n",
            ({ this_player() })
  );
  bchain=clone_object("/obj/treasure");
  bchain->set_id("chain");
  bchain->set_short("Brad's Gold chain");
  bchain->set_long(
"This is Brad's Gold chain.\n"+
"Someone ganked this from Brad!\n"
  );
  bchain->set_value(450);
  bchain->set_weight(1);
  move_object(bchain,environment(ob));

}

