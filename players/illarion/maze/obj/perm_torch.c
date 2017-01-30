/* perm_torch.c - An always light, unmovable light source to provide light
 * for a randomly generated dungeon.
 *      Illarion 24 Apr 02
 */
#include "/players/illarion/dfns.h"
inherit "obj/treasure";

/* Attached to the wall- immovable
 */
status get(string str) { return 0; }

void reset(status arg) {
  if(arg) return;
  set_light(1);
  
  set_id("torch");
  set_short("A burning torch, attached to the wall");
  set_long(
"Attached to the wall with an iron mount, this torch looks normal, but it\n"+
"gives off no heat or smoke, no matter how long it burns.\n");

}
