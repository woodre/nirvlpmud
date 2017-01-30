/*
 *      File:                   tron.c
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
  set_name("Tron");
  set_alias("tron");
  set_short("Tron the Silicon Warrior");
  set_long(
"     Tron seems like an ordinary warrior, But he emits a strong\n"+
"source of righteousness. He stands hiding his weapon behind him.\n"+
"His attack is swift and quick. His armor glows blue and seems like\n"+
"a great defense. You begin to doubt your ability to beat him.\n"
);
  set_gender("male");
  set_race("human");
  set_level(17);
  set_wc(24);
  set_ac(14);
  set_hp(350);
  set_al(0);
  set_chat_chance(2);
  load_chat("Tron glows brighter.\n");
  load_chat("Tron asks you: Have you ever fought the MPC?\n");
  load_chat("Your knees begin to wobble.\n");
  load_a_chat("Tron whips out his disc and throws it at you!\n");
  load_a_chat("Your attack is deflected by Tron's armor.\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object disc;
  write("Tron ceases to glow.\n");
  tell_room(environment(),
            this_player()->query_name()+" scowls as Tron's glowing armor disinitigrates as it his the ground.\n",
            ({ this_player() })
  );
  move_object(clone_object("/players/gemini/myarea/obj/disc"),this_object());
}

