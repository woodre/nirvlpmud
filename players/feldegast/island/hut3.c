#include "/players/feldegast/defines.h"
inherit ROOM;
reset(arg) {
  object parrot;
  string adj;
  int x;
  if(!present("parrot")) {
    while(x<4) {
      x++;
      switch(random(5)) {
        case 0: adj=HIB;break;
        case 1: adj=HIY;break;
        case 2: adj=HIR;break;
        case 3: adj=HIG;break;
        case 4: adj=HIG;break;
        case 5: adj=HIY;break;
        default: adj=HIC;break;
      }
      parrot=clone_object("/obj/monster");
      parrot->set_name("parrot");
      parrot->set_short("A"+adj+" parrot"+NORM);
      parrot->set_long(
"This is a"+adj+" parrot"+NORM+".  It's a large tropical\n"+
"bird with multi-colored feathers.\n"
      );
      parrot->set_race("bird");
      parrot->set_level(1);
      parrot->set_wc(5);
      parrot->set_ac(3);
      parrot->set_hp(15);
      parrot->set_al(0);
      parrot->set_chat_chance(15);
      parrot->load_chat("Parrot squawks: Polly wants a cracker.\n");
      parrot->load_chat("Parrot squawks: The parrots are coming!\n");
      parrot->load_chat("Parrot squawks: Aye matey!\n");
      parrot->load_chat("Parrot squawks: Hoo-ha!\n");
      parrot->load_chat("Parrot squawks: Who is Polly?\n");
      parrot->load_chat("Parrot squawks: I don't even like crackers!\n");
      parrot->load_chat("Parrot squawks: No new taxes!\n");
      parrot->load_chat("Parrot squawks: Just say no!\n");
      parrot->load_chat("Parrot squawks: I am the parrot king!\n");
      parrot->load_chat("Parrot squawks: Oh Kevin!  Oh Kevin!\n");
      parrot->set_a_chat_chance(5);
      parrot->load_a_chat("Parrot squawks dangerously.\n");
      parrot->set_dead_ob(this_object());
      move_object(parrot,this_object());
    }
  }
  if (arg) return;
  set_light(1);
  short_desc="A yard";
  long_desc=
"     This is a small yard formed by tall bamboo fences in\n"+
"front of a large hut to the north.  To the south you can\n"+
"see a fountain in the road.\n";
  items=({
    "hut","A large hut made out of bamboo poles oles"
  });
  dest_dir=({
    "/players/feldegast/island/hut3a","north",
    "/players/feldegast/island/village2","south"
  });

}
monster_died(ob) {
  object feather;
  string adj;
  feather=clone_object("/obj/treasure");
  feather->set_id("feather");
  switch(random(4)) {
    case 0: adj=HIG;break;
    case 1: adj=HIB;break;
    case 2: adj=HIY;break;
    case 3: adj=HIR;break;
    case 4: adj=HIM;break;
    default: adj=HIC;
  }
  feather->set_short(adj+"feather"+NORM);
  feather->set_long(
"A beautiful bird feather.\n"
  );
  feather->set_value(30);
  feather->set_weight(0);
  move_object(feather,environment(ob));
}
