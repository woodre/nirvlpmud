/*
 *      File:                   spicoli.c
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
  set_name("Spicoli");
  set_alias("spicoli");
  set_short("Spicoli");
  set_long(
"     Jeff Spicoli...\n"+
"This guy is a total burnout, all he does is smoke the Mary J.\n"+
"He walks around with a surfboard and no shirt. He is always\n"+
"late for class. It is rumored that he is still in HighSchool.\n"+
"He has shoulder length hair of a typical surfer 'dude'.\n"
);
  set_gender("male");
  set_race("human");
  set_level(7);
  set_wc(11);
  set_ac(6);
  set_hp(105);
  set_al(0);
  set_chat_chance(2);
  load_chat("Spicoli rolls up a joint.\n");
  load_chat("Spicoli smiles at you and seems to almost fall.\n");
  load_a_chat("Spicoli smokes a joint and looks stronger!\n");
  load_a_chat("You feel weaker when fighting Spicoli!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object joint;
  write("Spicoli takes his last hit... and dies!\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed Spicoli!\n",
            ({ this_player() })
  );
  joint=clone_object("/obj/treasure");
  joint->set_id("joint");
  joint->set_short("A joint");
  joint->set_long(
"A badly rolled joint that looks pretty old.\n"
  );
  joint->set_value(300);
  joint->set_weight(1);
  move_object(joint,environment(ob));

}
