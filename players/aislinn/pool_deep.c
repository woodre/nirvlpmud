#include "std.h"

object pshark;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!pshark || !living(pshark)) {
  object chain, ring;
    pshark = clone_object("obj/monster");
    call_other(pshark, "set_name","pool shark");
    call_other(pshark, "set_alias","shark");
    call_other(pshark, "set_level", 20);
    call_other(pshark, "set_hp", 650);
    call_other(pshark, "set_wc", 40);
    call_other(pshark, "set_ac", 17);
    call_other(pshark, "set_aggressive", 1);
    call_other(pshark, "set_al", -400);
    call_other(pshark, "set_short", "A pool shark");
    call_other(pshark, "set_long",
      "A pool shark, swimming steadily and showing his teeth.\n");
    move_object(pshark, this_object());
    chain = clone_object("obj/treasure");
    call_other(chain, "set_id", "chain");
    call_other(chain, "set_short", "A thick, gold chain");
    call_other(chain, "set_long",
      "A heavy, gaudy, excessively expensive gold chain\n");
    call_other(chain, "set_value", 2200);
    call_other(chain, "set_weight", 1);
    transfer(chain, pshark);
  }
}
 
ONE_EXIT("players/aislinn/pool_medium", "west",
	 "The Deep End....",
    "You are now in the deep end of the pool.  If you let yourself sink,\n" +
    "you can approximate the depth to around 15 feet.  Several children\n" +
    "are doing cannoballs off of the high diving board, trying to make\n" +
    "the biggest splash.  A woman is doing sedate laps from side to side,\n" +
    "apparently ignoring the children.....\n" +
    "    \n", 1)
