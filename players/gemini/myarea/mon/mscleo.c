/*
 *      File:                   mscleo.c
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
  set_name("Ms. Cleo");
  set_alias("cleo");
  set_short("Ms. Cleo the TV Fortune teller");
  set_long(
"     Ms. Cleo looks just like how she does in her commercials. She\n"+
"is a busty black woman with curly hair, red hairpiece and all kinds\n"+
"of jewelery. She wants to tell you your future, but you know better.\n"+
"She looks like she could be extremely powerful if aggravated.\n"
);
  set_gender("female");
  set_race("human");
  set_level(17);
  set_wc(24);
  set_ac(14);
  set_hp(350);
  set_al(0);
  set_chat_chance(7);
  load_chat("You hold out your palm for Ms. Cleo to read.\n");
  load_chat("Ms. Cleo tells you: You are in for a world of pain. Leave now!\n");
  load_chat("You think Ms. Cleo is full of crap.\n");
  load_a_chat("Ms. Cleo tells you: I KNEW THIS DAY WOULD COME. YOU DIE TODAY!\n");
  load_a_chat("MS. Cleo calls upon the spirits to defend her!\n");
  load_a_chat("You get hit with a second attack.\n");
  load_a_chat("You feel sleepy and let your guard down.\n"+
              "Ms. Cleo hits you a second time!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object cearring;
  write("Ms. Cleo throws her fist in the air and puts a curse on you!\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed \n",
            ({ this_player() })
  );
  cearring=clone_object("/obj/armor");
  cearring->set_id("earring");
  cearring->set_short("Ms. Cleo's gold earring");
  cearring->set_long(
"This Ms. Cleo's gold earring.\n"+
"It should only be worn by Ms. Cleo herself.\n"
  );
  cearring->set_value(2100);
  cearring->set_weight(1);
  cearring->set_type("misc");
  cearring->set_ac(1);
  move_object(cearring,environment(ob));

}

