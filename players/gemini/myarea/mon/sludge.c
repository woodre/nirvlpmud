/*
 *      File:                   sludge.c
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
  set_name("Sludgeman");
  set_alt_name("sludgeman");
  set_alias("man");
  set_short("The Sludgeman");
  set_long(
"    A human shape form, covered in sludge steals your glare. It is\n"+
"hard to tell is it is a friend or foe. It is brown and black in\n"+
"color with glowing red eyes. At one time this slimey monster might\n"+
"have been human. Maybe he is one of your peers banished to this form.\n"
);
  set_gender("male");
  set_race("human");
  set_level(17);
  set_wc(24);
  set_ac(14);
  set_hp(350);
  set_al(0);
  set_chat_chance(2);
  load_chat("You quiver in fear!\n");
  load_chat("The sludge slows down your movement.\n");
  load_chat("Sludgeman moans: Heeelllpppp meeeeeeee!\n");
  load_a_chat("Your attack is weak this round!\n");
  load_a_chat("You try to run, but the sludge prevents you!\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object crap;
  write("Sludgeman turns into a pile of mud before you.\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed \n",
            ({ this_player() })
  );
  crap=clone_object("/obj/treasure");
  crap->set_id("crap");
  crap->set_short("A piece of crap");
  crap->set_long(
"This is a piece of crap.\n"+
"It might have a little value.\n"
  );
  crap->set_value(2100);
  crap->set_weight(1);
  move_object(crap,environment(ob));

}

