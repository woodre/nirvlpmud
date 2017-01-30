inherit "/obj/corpse";
#include <ansi.h>

reset(arg) {
  object geld;

  if(arg) return;

  geld = clone_object("/obj/money");
  geld->set_money(random(25000));
  move_object(geld, this_object());
}

init() {
  ::init();
}

remove_object() {
  int skill;
  object tp,gold;

  if( !environment() )
    return;

  tp = this_player();

  if( tp ) {
    skill = tp->query_prestige_skill("gold");
    if( skill && skill > random( skill + 4 ) ) {
      gold = clone_object( "/obj/money" );
      gold->set_money( );
      move_object( gold, tp );
      tell_object( tp, HIY+"Your prestige has brought forth extra wealth!\n"+NORM);
      tell_room( environment(), tp->query_name()+"'s prestige has blessed "+tp->query_possessive()+" wealth!\n");
    }
    /* tell_object( tp, "Corpse dested.\n" ); */
  }
}
