#include "defs.h"

status main(string str, int glevel) {
  object gob;

  gob = present(MGOB_ID, this_player());
   
  move_object(clone_object(MGOB), this_player());
  destruct(gob);
  write("Your Masonic seal has been reset.\n");
  return 1;
/*
     new_seal = clone_object("players/angel/masons/seal");
     rank = this_object()->query_guild_rank();
     exp = this_object()->query_guild_exp();
     loan = this_object()->query_guild_loan();
     muffled = this_object()->query_muffled();
     battle = this_object()->query_battle();
     new_seal->set_muffled(muffled);
     new_seal->set_battle(battle);
     new_seal->set_guild_rank(rank);
     new_seal->set_guild_loan(loan);
     new_seal->set_guild_exp(exp);
     move_object(new_seal, this_player());
     destruct(this_object());
     return 1;
*/
}
