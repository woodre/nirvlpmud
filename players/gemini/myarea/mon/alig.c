/*
 *      File:                   alig.c
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
  set_name("Ali-G");
  set_alias("ali");
  set_short("Ali G");
  set_long(
"     Ali G is wearing a yellow jumpsuit and a tight fitting hat\n"+
"to hide his 'fro'. He is from Staines England and thinks he\n"+
"is a Los Angeles gangster. He even has a movie made about him!\n"+
"He appears to get along very well with the ladies\n"
);
  set_gender("male");
  set_race("human");
  set_level(11);
  set_wc(15);
  set_ac(9);
  set_hp(165);
  set_al(0);
  set_chat_chance(2);
  load_chat("Ali G says: Big ups to you!\n");
  load_chat("Ali G scratches his groin.\n");
  load_chat("You gasp as you see the bulge in Ali G's pants!\n");
  load_a_chat("Ali G tells you: STOP THE VOILENCE!\n");
  load_a_chat("You feel weaker as your killing spree continues.\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object fro;
  write("Ali G falls to the ground... Lifeless...\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed Ali G!\n",
            ({ this_player() })
  );
  fro=clone_object("/obj/armor");
  fro->set_id("afro");
  fro->set_short("Ali G's afro");
  fro->set_long(
"This is an afro wig.\n"+
"It might look good on you.\n"
  );
  fro->set_value(500);
  fro->set_weight(1);
  fro->set_type("helmet");
  fro->set_ac(1);
  move_object(fro,environment(ob));

}
