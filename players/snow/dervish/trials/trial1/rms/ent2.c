/* 
 * Forbin
 * Created:   2003.08.25
 * Last edit: 2003.11.11 -forbin
 * Change log:
 */

#include "/players/forbin/define.h"
inherit "/players/forbin/closed/std/froom.c";
#define ROOT "/players/snow/dervish/trials/trial1/"
#define FIXED_MOSS 6
#define RANDOM_MOSS 8

int done;
string *rooms;

reset(arg) {
  if(arg) return;

  rooms = ({"/players/snow/dervish/trials/trial1/rms/canopy02.c",
            "/players/snow/dervish/trials/trial1/rms/canopy03.c",
            "/players/snow/dervish/trials/trial1/rms/paradise02.c",
            "/players/snow/dervish/trials/trial1/rms/paradise06.c",
            "/players/snow/dervish/trials/trial1/rms/paradise08.c",}); 

  short_desc = HIR+"A "+HIY+"S"+HIG+"t"+HIB+"r"+HIC+"a"+HIM+"n"+HIW+"g"+HIM+"e "+HIC+"P"+HIB+"l"+HIG+"a"+HIY+"c"+HIR+"e"+NORM;
  long_desc = HIK+REV+
    "  Blackness envelopes almost everything, cold embraces your soul\n"+
    "and here in this featureless void, darkness reigns.  A pinpoint \n"+
    "of light marks the way back out, and a purple haze boils forth  \n"+
    "from a cavernous dark hole that swallows the ground.            \n"+
    "    There is one obvious exit: out                              \n"+NORM;
  add_item(({"light","pinpoint","pinpoint of light"}),
    "A pinpoint of light shines off in the distance, it is the way out");
  add_item("ground",
    "A purple mist spews forth from a large hole in the ground");
  add_item("hole",
    "A large gaping hole - it looks as if you could descend into it");
  add_listen("main", 
    "You listen closely and hear your heart pounding.\n");
  no_exit_display = 1;
  add_exit("/players/snow/dervish/hall/desert6.c","out");
  no_clean = 1;
}

short() { return HIR+"A "+HIY+"S"+HIG+"t"+HIB+"r"+HIC+"a"+HIM+"n"+HIW+"g"+HIM+"e "+HIC+"P"+HIB+"l"+HIG+"a"+HIY+"c"+HIR+"e"+NORM; }

init() {
  ::init();
  add_action("cmd_descend","descend");
}

cmd_descend() {
/*
  if(present("dervish mist creature",this_object())) {
    object myst;
    myst = present("dervish mist creature",this_object());
    myst->attack_object(this_player());
    myst->set_short(HIM+"Creature of Mist"+NORM);
    myst->set_name("Creature of Mist");
    myst->set_aggro(1, 100, 50+random(51)); 
      return 1;
  }
*/
  if(!done) initialize_moss();
  write("You gather your fortitude and descend into the hole.\n");
  say(this_player()->query_name()+" descends into a hole in the ground.\n");
  move_object(this_player(),ROOT+"rms/cave.c");
  command("look",this_player());
  say(this_player()->query_name()+" falls out a hole in the ceiling.\n");
    return 1; 
}

initialize_moss() {
  int mossnum;
  int x;
  int moss1, moss2, moss3, moss4, moss5;
  object croom;
  mossnum = FIXED_MOSS + RANDOM_MOSS;
  for(x = 0; x < mossnum; x++) {
    croom = rooms[random(sizeof(rooms))];
    if(x <= FIXED_MOSS) {
      if(!croom->query_moss_fixed()) { croom->set_moss_fixed(1); }
      else croom->add_moss_fixed(1);
    }
    if(x > FIXED_MOSS) {
      if(!croom->query_moss_random()) { croom->set_moss_random(1); }
      else croom->add_moss_random(1);
    }
  }
  done = 1;
  moss1 = rooms[0]->query_moss_fixed() + rooms[0]->query_moss_random();
  moss2 = rooms[1]->query_moss_fixed() + rooms[1]->query_moss_random();
  moss3 = rooms[2]->query_moss_fixed() + rooms[2]->query_moss_random();
  moss4 = rooms[3]->query_moss_fixed() + rooms[3]->query_moss_random();
  moss5 = rooms[4]->query_moss_fixed() + rooms[4]->query_moss_random();
  write_file(ROOT+"moss.log", ctime()[4..15]+" "+ctime()[20..23]+" "+this_player()->query_name()+" ["+this_player()->query_level()+"+"+this_player()->query_extra_level()+"] "+moss1+" "+moss2+" "+moss3+" "+moss4+" "+moss5+"\n");
}

mist_died() {
  add_item(({"haze","purple haze","mist"}),
    "A purple mist floats about low to the ground");
  set_chance(random(3));
    add_msg(HIM+"A purple mist floats about the area."+NORM);
    add_msg(HIM+"Mist oozes out of the hole."+NORM);
    add_msg(HIM+"A purple mist swirls about you."+NORM);
}
