/*
 *      File:                   mspiggy.c
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
  set_name("Ms. Piggy");
  set_alias("piggy");
  set_short("Ms. Piggy");
  set_long(
"     You see a pig standing on 2 legs.\n"+
"Ms. Piggy is a very plump pig, with a large snout.\n"+
"She is constantly chasing Kermit around looking for love.\n"+
"Her skin looks similar to Kermit's but is a different color.\n"+
"She can be very aggressive if provoked.\n"
);
  set_gender("frmale");
  set_race("pig");
  set_level(3);
  set_wc(7);
  set_ac(4);
  set_hp(45);
  set_al(0);
  set_chat_chance(2);
  load_chat("Ms. Piggy always tries to kiss kermit, but always gets dissed.\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object skin;
  write("Ms. Piggy tells you: Thank you!\n"+
        "Ms. Piggy tells you: I would rather be dead than not\n"+
        "                    have Kermie's love forever...\n"+
        "Ms. Piggy kisses you.\n"+
        "You blush...\n");
  tell_room(environment(),
            this_player()->query_name()+" has slain the pink whore!\n",
            ({ this_player() })
  );
  skin=clone_object("/obj/treasure");
  skin->set_id("foot");
  skin->set_short("a pig foot");
  skin->set_long(
"Yummy, a delicious pig foot!\n"+
"Too bad its way past its expiration date.\n"
  );
  skin->set_value(120);
  skin->set_weight(1);
  move_object(skin,environment(ob));

  {
    call_other(this_object()->query_attack(), "frog_curse", 0);
  }

}
