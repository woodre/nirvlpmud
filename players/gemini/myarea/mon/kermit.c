/*
 *      File:                   kermit.c
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
  set_name("Kermit");
  set_alias("kermit");
  set_short("Kermit the frog");
  set_long(
"     You see a frog.\n"+
"But this not an ordinary frog, this is Kermit 'the' frog from the Muppet Show!\n"+
"He is always looking for love, but ignores Ms. Piggy.\n"+
"Kermit is green in color, and seems to have skin with\n"+
"texture of cloth... Strange...\n"
);
  set_gender("male");
  set_race("frog");
  set_level(3);
  set_wc(7);
  set_ac(4);
  set_hp(45);
  set_al(0);
  set_chat_chance(2);
  load_chat("Kermit always tries to kiss Ms. Piggy, but still is a frog.\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object skin;
  write("Kermit cast a spell on you!\n");
  tell_room(environment(),
            this_player()->query_name()+" turns into a frog.\n",
            ({ this_player() })
  );
  skin=clone_object("/obj/treasure");
  skin->set_id("warts");
  skin->set_short("Some frog warts");
  skin->set_long(
"You get warts when you kill a frog.\n"
  );
  skin->set_value(120);
  skin->set_weight(1);
  move_object(skin,environment(ob));

  {
    call_other(this_object()->query_attack(), "frog_curse", 1);
  }

}
