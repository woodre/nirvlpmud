#include "../DEFS.h"

status main(string str) {
  object ob;
  if(!((status)IPTP->item_corpse()) && !IPTP->guild_wiz()) return 0;
  ob = present("corpse", environment(TP));
  if(!ob) {
    write("There is no corpse here!\n");
    return 1; }
  call_other(TP, "heal_self", (int)ob->heal_value());
  write("You dismember a corpse and burn it for fuel.\n");
  say(TPN+" dismembers a corpse and burns it for fuel.\n");
  destruct(ob);
  return 1;
}
