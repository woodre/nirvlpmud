#include "DEFS.h"
inherit "room/room";
int FD;

reset(arg) {
FD = 0;
  if(arg) return;
set_light(0);

short_desc = "The Abyss";
long_desc =
  "  The swirling darkness is very disorienting.  You can feel the evil\n"+
  "presence getting closer and closer.  The screams are much clearer\n"+
  "here..... if you listen carefully you can probably make out the\n"+
  "words.  What are those poor tortured souls screaming?  Deeper into\n"+
  "the abyss it appears to be getting lighter but is that possible?\n";

dest_dir = ({
	"players/eurale/Abyss/a3.c","up",
	"players/eurale/Abyss/a5red.c","down",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("down","down");
  add_action("listen","listen");
}

down() {
object ob;
if(present("fetch")) {
  write("The looming fetch steps in front of you blocking your way!\n");
  say("The looming fetch blocks "+capitalize(TPRN)+"'s way...\n");
  return 1; }
if(FD != 1) {
  ob = clone_object("players/eurale/Abyss/NPC/fetch5.c");
    ob->set_hp(TP->query_mhp() * 2);
    ob->set_al(TP->query_alignment());
    ob->set_wc(8 + (2 * TPL));
    move_object(ob,"/players/eurale/Abyss/a5red.c");
    FD = 1;
    TP->move_player("darkness#players/eurale/Abyss/a5red.c");
    return 1; }
else {
  TP->move_player("disappears#players/eurale/Abyss/a5red.c");
  return 1; }
}

listen(str) {
if(!str) { write("You'll have to listen more carefully..\n"); return 1; }
if(str == "carefully") {
  write("You close your eyes and concentrate very carefully on the\n"+
	"screaming........ and it seems to be saying.....\n"+
    "desssssssppppooooiiiiiiiinnnnnnnnaaaaaaa.......\n"+
    "dddddeeeesssssssppppppppooooooooiiiiiiiinnnnnnnnaaaaaa....\n");
  say(capitalize(TPRN)+" closes his eyes momentarily in thought....\n");
  return 1; }
}
