/* A deckhand, Created <5/12/00> by Jara */

/* I'm aware that this monster is slightly off from the
   standard monster chart, and I am approving it anyway
   because I consider it fairer. -Feldegast */

inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

object ob;

  ob = clone_object("/players/jara/area1/docks/wep/dagger.c");
move_object(ob,this_object());

  add_money(890);
  init_command("wield dagger");
  set_name("deckhand");
  set_short("A deckhand");
  set_race("human");
  set_long("The young deckhand has blonde hair, bleached by the sun. His\n"+
    "muscles are visible beneath his torn, white shirt, and his skin\n"+
    "is darkened by a well defined tan.\n");
  set_level(16);
  set_ac(13);
  set_wc(22);
  set_hp(400);
  set_al(100);
  set_aggressive(0);
  set_chat_chance(15);
  set_a_chat_chance(10);
  load_chat("The deckhand glances up at the horizon.\n");
  load_chat("The deckhand arranges the nets.\n");
  load_chat("The young deckhand wipes the sweat from his brow.\n");
  load_a_chat("The deckhand slices you with his dagger.\n");
  load_a_chat("The deckhand bashes your chin with the hilt of his dagger.\n");
  load_a_chat("The dagger just misses your throat.\n");
   }
}
