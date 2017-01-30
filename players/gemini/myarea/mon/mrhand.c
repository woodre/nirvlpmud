/*
 *      File:                   mrhand.c
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
  set_name("Mr. hand");
  set_alias("hand");
  set_short("Mr. Hand");
  set_long(
"     Mr. Hand is a teacher who is always riding Jeff Spicoli's\n"+
"butt. He is tired of Spicoli being absent and late.\n"+
"Someday he hopes that Jeff Spicoli amounts to something.\n"
);
  set_gender("male");
  set_race("human");
  set_level(13);
  set_wc(17);
  set_ac(10);
  set_hp(195);
  set_al(0);
  set_chat_chance(2);
  load_chat("Mr. Hand looks at you.\n");
  load_chat("Mr. Hand asks you: What do you know about American History?\n");
  load_chat("Mr. hand is convinced everyone is on dope.\n");
  load_a_chat("Mr. Hand hits you in the head with a history Book!\n");
  load_a_chat("Mr. Hand steals some of your free time.\n");
  set_dead_ob(this_object());
}

monster_died(ob) {
  object book;
  write("Mr.Hand was a great teacher...\n");
  tell_room(environment(),
            this_player()->query_name()+" has killed the history teacher!\n",
            ({ this_player() })
  );
  book=clone_object("/obj/treasure");
  book->set_id("book");
  book->set_short("A history book");
  book->set_long(
"This is a history book. It's well worn and unreadable.\n"
  );
  book->set_value(600);
  book->set_weight(1);
  move_object(book,environment(ob));

}
