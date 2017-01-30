#include "DEFS.h"
inherit "room/room";
int FD,FE,FW;

reset(arg) {
FD = 0;
FE = 0;
FW = 0;
  if(arg) return;
set_light(0);

short_desc = "The Abyss";
long_desc =
  "  As you descend deeper and deeper into the abyss, you can feel the\n"+
  "evil of it digging into your soul.  The incessant wailing is begin-\n"+
  "ning to get on your nerves and make you very edgy.  You can sense\n"+
  "that you are not alone but it's impossible to make anything out in\n"+
  "the surrounding darkness.\n";

dest_dir = ({
	"players/eurale/Abyss/a2.c","up",
	"players/eurale/Abyss/a4.c","down",
});

}

init() {
  ::init();
  add_action("east","east");
  add_action("west","west");
  add_action("down","down");
}

east() {
object ob;
if(FE != 1) {
  call_other("players/eurale/Abyss/a9.c","???");
  ob = clone_object("players/eurale/Abyss/NPC/fetch4.c");
    ob->set_hp(TP->query_mhp() * 2);
    ob->set_al(TP->query_alignment());
    ob->set_wc(2 + (2 * TPL));
  move_object(ob,"/players/eurale/Abyss/a9.c");
  FE = 1;
  TP->move_player("darkness#players/eurale/Abyss/a9.c");
  return 1; }
else {
  TP->move_player("disappears#players/eurale/Abyss/a9.c");
  return 1; }
}

west() {
object ob;
if(FW != 1) {
  call_other("players/eurale/Abyss/a8.c","???");
  ob = clone_object("players/eurale/Abyss/NPC/fetch3.c");
    ob->set_hp(TP->query_mhp() * 2);
    ob->set_al(TP->query_alignment());
    ob->set_wc(2 + (2 * TPL));
  move_object(ob,"/players/eurale/Abyss/a8.c");
  FW = 1;
  TP->move_player("darkness#players/eurale/Abyss/a8.c");
  return 1; }
else {
  TP->move_player("disappears#players/eurale/Abyss/a8.c");
  return 1; }
}

down() {
object ob;
if(FD != 1) {
  call_other("players/eurale/Abyss/a4.c","???");
  ob = clone_object("players/eurale/Abyss/NPC/fetch2.c");
    ob->set_hp(TP->query_mhp() * 2);
    ob->set_al(TP->query_alignment());
    ob->set_wc(3 + (2 * TPL));
  move_object(ob,"/players/eurale/Abyss/a4.c");
  FD = 1;
  TP->move_player("disappears#players/eurale/Abyss/a4.c");
  return 1; }

else {
  TP->move_player("disappears#players/eurale/Abyss/a4.c");
  return 1; }
}

realm() { return "NT"; }
