make_shark() {
  object ob;
  string *hmsg;

  ob= clone_object( "players/balowski/obj/monster");
  ob->set_name( "tigershark");
  ob->set_race( "shark");
  ob->set_level( 18);
  ob->set_hp( 450);
  ob->set_wc( 26);
  ob->set_ac( 15);
  ob->set_short( "A tigershark");
  ob->set_long( "\
The tigershark is moving gracefully around in the sea. Its slimness and\n\
elegance somewhat hides its size, which is by no means great, yet it must\n\
measure around 7 or 8 foot from tip of nose to tailfin. This species of shark\n\
is infamous for its voracity, and is known to have killed human beings.\n");
  ob->set_dead_ob( this_object());
  hmsg= ob->query_hmsg(0);
  hmsg[5]= hmsg[7]= hmsg[9]= "bit";
  hmsg[3]= "tore a big piece of flesh from";
  hmsg[2]= "";
#ifdef NIRVANA
  ob->set_a_chat_chance( 5);
  ob->load_a_chat( "The shark circles you for a better angle of attack.\n");
#endif
  return ob;
}

int monster_died( object monster) {
  object money, corpse;
#include "arm.c"
  corpse= present( "corpse of tigershark");
  move_object( arm, corpse);

  money= clone_object( "players/balowski/obj/money");
  money->set_money( 500 + random( 200));
  money->set_short( "A pile of gold coins");
  move_object( money, corpse);

  write( "\
With your final blow you gut the shark. From its belly falls items from less\n\
fortunate adventurers.\n");
  return 0;	/* allow destruct */
}
