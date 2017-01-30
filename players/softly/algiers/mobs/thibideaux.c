#include "/players/softly/closed/ansi.h"
inherit "/players/softly/closed/std/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
   
  set_name("thibideaux");
  set_alt_name("teacher");   
  set_alias("mr");
  set_long("\nMr. Thibideaux is a rather delicate middle-aged man who\n\
wears a shiny dark blue suit, badly pressed white shirt and\n\
a blue necktie with thin white stripes.  His thin hair is\n\
receding at his forehead which is perspiring in the heat.\n\
He peers over the top of his thick glasses at his restless\n\
charges.\n");
  set_short("Mr. Thibideaux, a teacher");
  set_race("human");
  set_gender("male");
  set_level(12);
  set_al(-210);
  set_aggressive(0);
  set_chat_chance (5);
  load_chat("Mr. Thibideaux drones: times 7 is 35.  Six times 7 is .....\n");
  load_chat("Mr. Thibideaux screeches: Will you sit down in your chair?!\n");
  load_chat("The chalk screeches on the board .... screeeeee\n");
  add_money(350+random(200));
}
