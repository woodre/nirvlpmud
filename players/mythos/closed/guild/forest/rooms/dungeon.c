#include "/players/mythos/closed/guild/def.h"
object dfd, sto;
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(-2);
    short_desc = HIK+"Forbidden Castle "+NORM+"["+HIK+"Dungeon"+NORM+"]";
    long_desc = HIK+
    "You feel a gripping dread as you step down into the\n"+
    "depths of the castle.  It is dark and everything is still.\n"+
    "You see a door before you- from which you feel a great repulsion.\n"+NORM;
  items = ({
    "up","Leads to the main castle area",
    "enter","Do not enter......",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/forest/rooms/castle5.c", "up",
    "/players/mythos/closed/guild/forest/rooms/dungeon2.c", "enter",
  });
} }
realm() { return "NT";}

init() {
  ::init();
    if(tp)
    this_player()->set_fight_area();
      /* added by verte 6.11.01 */
    if(tp && !tp->is_player()) return;
    if(!pp) { tell_object(tp,HIR+"\n\n\t\tYOU WERE WARNED!\n\n\n"+NORM+
              "Defenses on.\n");
    dfd = clone_object("/players/mythos/closed/guild/forest/mon/defend.c");
    move_object(dfd,this_object());
    move_object(clone_object("/players/mythos/closed/guild/spells/level_dest.c"),
    dfd);
    dfd->attack_object(tp);
    dfd = clone_object("/players/mythos/closed/guild/forest/mon/defend.c");
    move_object(dfd,this_object());
    move_object(clone_object("/players/mythos/closed/guild/spells/level_dest.c"),
    dfd);
    dfd->attack_object(tp);
    dfd = clone_object("/players/mythos/closed/guild/forest/mon/defend.c");
    move_object(dfd,this_object());
    move_object(clone_object("/players/mythos/closed/guild/spells/level_dest.c"),
    dfd);
    dfd->attack_object(tp);
    dfd = clone_object("/players/mythos/closed/guild/forest/mon/defend.c");
    move_object(dfd,this_object());
    move_object(clone_object("/players/mythos/closed/guild/spells/level_dest.c"),
    dfd);
    dfd->attack_object(tp);
    }
}
