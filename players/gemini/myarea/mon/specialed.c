/*
 *      File:                   specialed.c
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
  set_name("Special Ed");
  set_alias("ed");
  set_short("Special Ed");
  set_long(
"     This is Special Ed. He is not a wiz on the computer, and\n"+
"his knock knock jokes are pretty lame, but he does a good job at\n"+
"cleaning the tables at Yanker burger. Ed lives with his Grandma\n"+
"in the Yankerville suburbs. He likes fried chicken, Hawaii, scooters\n"+
"and Snowglobes. He hates ghosts and spiders to a scary degree.\n"
);
  set_gender("male");
  set_race("human");
  set_level(3);
  set_wc(7);
  set_ac(4);
  set_hp(45);
  set_al(0);
  set_chat_chance(2);
  load_chat("Special Ed says: Yayyyyyy! I GOT MAIL!\n");
  load_chat("Special Ed says: Yayyyyyy! Hey Lady! Knock Knock!\n");
  load_chat("Special Ed says: Hey lady! You're pretty! You look like my mommy!\n");
  load_a_chat("Special Ed says: I GOT YOU! YAYYYYYYY!\n");
  load_a_chat("Special Ed drools on you!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object yay;
  write("Special Ed's helmet falls to the ground.\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed Special Ed.\n",
            ({ this_player() })
  );
  yay=clone_object("/obj/armor");
  yay->set_id("helmet");
  yay->set_short("Special Ed's safety helmet");
  yay->set_long(
"This is Special Ed's safely helmet.\n"+
"It has a chin strap on it, so you do not get hurt.\n"
  );
  yay->set_value(120);
  yay->set_weight(1);
  yay->set_type("helmet");
  yay->set_ac(1);

  move_object(yay,environment(ob));

}

