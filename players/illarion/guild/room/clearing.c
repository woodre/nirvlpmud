/* clearing.c - only purpose is as a trainer for the blademaster
                trainer.c
 */

#include "/players/illarion/guild/def.h"
inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;

  if(!present("lan"))
    move_object(GMON+"trainer",TO);

  set_light(1);
  set_short("A small forest clearing");
  property=({"no_fight"});
  set_long(
"Surrounded by a ring of oak trees, this clearing fairly exudes power.\n"+
"The ground is rocky, with only grass and other short plants, and a\n"+
"number of roots from the oaks.  On the east and west sides of the\n"+
"clearing, a path leads between two trees.");
  add_item("oak","A tall, ancient oak tree, that looks to have stood in "+
                 "its place for a very long time.");
  add_item("tree","A tall, ancient oak tree, that looks to have stood in "+
                 "its place for a very long time.");
  add_item("trees","The oak trees surround the clearing like a ring of "+
                   "sentinels.");
  add_item("ground","While mostly flat, the ground of the clearing is "+
                    "cluttered by rocks, roots, and weeds.");
  add_item("grass","Just...  grass.  Plants characterized by a single "+
                   "long green blade.");
  add_item("rocks","The rocks on the ground range in size from pebbles to "+
                   "boulders.  Some are covered in moss, others are bare "+
                   "of it, and hardly sunk into the ground at all.");
  add_item("roots","The roots from the oak trees wind throughout the "+
                   "clearing, ready to trip an unsuspecting foot.");
  add_item("path","A path, a path, a path!  Leave the path, and you may "+
                  "encounter the Knights who say Ni...  no, just kidding.");
  add_exit("east","/players/illarion/poke/room/ontrail.c");
  add_exit("west",GROOM+"smithy");
}


status query_no_fight() { return 1; }

