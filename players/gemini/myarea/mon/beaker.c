/*
 *      File:                   beaker.c
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
  set_name("beaker");
   set_alt_name("assistant");
  set_alias("beaker");
  set_short("Beaker the Assistant");
  set_long(
"     Beaker is the Scientist's assistant. He is wearing a white\n"+
"labcoat. Beaker has orange hair, and a funny shaped mouth. He doesn't\n"+
"really speak an understandable language. He is a good assistant, but\n"+
"always seems to fumble something up.\n"
);
  set_gender("male");
  set_race("human");
  set_level(5);
  set_wc(9);
  set_ac(5);
  set_hp(75);
  set_al(0);
  set_chat_chance(2);
  load_chat("Beaker mumbles something.\n");
  load_chat("Beaker shuffles his feet.\n");
  load_chat("Beaker points to the ceiling and shrieks\n");
  load_a_chat("Beaker swings a thermometer at you!\n");
  load_a_chat("Beaker screams!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object therm;
  write("Beaker falls down, gripping his thermometer\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed \n",
            ({ this_player() })
  );
  therm=clone_object("/obj/treasure");
  therm->set_id("thermometer");
  therm->set_short("Beaker's thermometer");
  therm->set_long(
"Beakers thermometer, it is long and filled with mercury\n"+
"It looks pretty expensive for a thermometer.\n"
  );
  therm->set_value(200);
  therm->set_weight(1);
  move_object(therm,environment(ob));

}

