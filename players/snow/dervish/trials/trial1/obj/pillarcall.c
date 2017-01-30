/* 
 * Forbin
 * Created:   2003.08.22
 * Last edit: 2003.08.22 -forbin
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 * This object summons /players/forbin/dervish/NPC/albatross.c
 * to the desert location /players/forbin/dervish/RMS/beach02.c
 * =~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
 */

#include "/players/forbin/define.h"
inherit "/obj/treasure";
#define TOU(x) if(environment()) tell_object(environment(), x);
#define TRU(x) if(environment() && environment(environment())) tell_room(environment(environment()), x, ({ environment() }));
#define USER environment()
#define ROOT "/players/snow/dervish/trials/trial1/"

static int pillars;

id(str) { return str == "pillarcall"; }

drop() { return 1; }

get() { return 1; }

reset(x) {
  if(x) return;
  if(!root())
  call_out("raise_pillars",4 + random(5));
}

init() {
  add_action("cmd_hook"); add_xverb("");
}

cmd_hook(string str) {
  if(this_player()->query_level() > 19) return 0;
  write("The ground trembles beneath you and the air is charged with energy.\n"+
        "You are too confused and frightened to do that.\n");
    return 1;
}

raise_pillars() {

  pillars += 1;

  if(pillars > 3) {
    TOU("With a thunderous clap, the pillars stand towering before you.  Gradually\n"+
        "the dust and sand settle; the air becomes clear.  You feel great power is\n"+
        "guarded by these silent sentinels.\n\n");
    TRU("With a thunderous clap, the pillars stand towering before you.  Gradually,\n"+
        "the dust and sand settle; the air becomes clear.\n\n");
    move_object(clone_object(ROOT+"obj/pillars.c"),environment(environment(this_object())));
    environment(environment(this_object()))->new_look2();
    TOU("\n\nThe ground stops shaking.\n");
    destruct(this_object());
      return;
  }
  else if(pillars > 2) {
    TOU("The heavens above you crackle and hum with a tremendous power.  Inch by\n"+
        "inch the four pillars shoot ever skyward.  The air is clouded by falling\n"+
        "sand, and an ominous wind begins to swirl about the area.\n\n");
    TRU("Four pillars emerge from the desert floor.  Slowly they push skyward.\n\n");
  }
  else if(pillars > 1) {
    TOU("Dirt and dust begin to fly as the four lumps push forth out of the desert's\n"+
        "surface.  Slowly as the sand shakes away from them, four pillars issue\n"+
        "forth from the desert floor.\n\n");
    TRU("The four lumps begin to push upward.\n\n");
  }
  else {
    TOU("With a violent trembling, the desert beneath your feet begins to rend.\n"+
        "The ground moans with creaks and pops as the lumps being to move.\n\n");
    TRU("The ground begins to shake and tremble.\n\n");
  }
  call_out("raise_pillars", 4 + random(11));
}