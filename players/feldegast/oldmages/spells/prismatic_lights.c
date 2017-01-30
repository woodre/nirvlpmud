#define MAGEPATH "/players/feldegast/mages/"
#include "/players/feldegast/defines.h"

inherit "/players/wocket/mages/obj/page.c";

reset(arg) {
  if(arg) return;
  spell="prismatic lights";
  spell_short="Prismatic lights";
  spell_desc=
"  The spell 'Prismatic lights' is unique among illusion spells\n\
in that it can be used not just defensively but also in a directly\n\
offensive manner.  It was used to devastating effect by its\n\
creator, Ali Hamar in his infamous duel with Servel V'taal.  As he\n\
lay dying in the sand, it is said that Servel's last words were,\n\
\"I can't believe I was beaten by a bunch of pretty lights!\"\n";
  time=4;
  size=12;
  spcost=120;
  hpcost=0;
  type="illusion";
}
int check_spell(object mage, string str) {
  if(present("prismatic lights",mage)) {
    tell_object(mage,"You already have prismatic lights.\n");
    return 0;
  }
  return 1;
}
void cast_spell(object mage, string str) {
  object arm;

  arm=clone_object(MAGEPATH+"obj/pris_lights.c");
  arm->wear(mage);
  move_object(arm,mage);
  tell_object(mage,
"You hum a little ditty as you start pulling colorful lights out of\n\
thin air and sending them gyrating around the room.\n");
  mage->remote_say(
mage->query_name()+" hums a ditty as "+mage->query_pronoun()+" pulls colorful\
lights out of the air\nand sends them gyrating around the room.\n");
}

