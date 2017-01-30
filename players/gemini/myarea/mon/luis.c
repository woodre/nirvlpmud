/*
 *      File:                   luis.c
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
  set_name("luis");
  set_alias("luis");
  set_short("Luis");
  set_long(
"     Tank is a member of the Crips Gang. He looks very strong and\n"+
"puzzled. He is wearing blue jeans and a matching shirt. He is a weak\n"+
"member in his gang, and still in the initiation phase. As you look at\n"+
"him he shifts his weight as if he was nervous.\n"
);
  set_gender("male");
  set_race("human");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(150);
  set_al(0);
  set_chat_chance(4);
  load_chat("Luis sighs deeply.\n");
  load_chat("Luis tells you: Are you going to hit me?\n");
  load_chat("Someone tells you: Why are you picking on Luis?\n");
  load_a_chat("Luis tries to run and hide but fails!\n");
  load_a_chat("Luis tries to call his friends but fails!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object cphone;
  write("Luis breathes in his last breath of air and falls down.\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed \n",
            ({ this_player() })
  );
  cphone=clone_object("/obj/treasure");
  cphone->set_id("cellphone");
  cphone->set_short("Luis's cellphone");
  cphone->set_long(
"This is a broken cell phone. It still might be worth some cash.\n"
  );
  cphone->set_value(450);
  cphone->set_weight(1);
  move_object(cphone,environment(ob));

}

