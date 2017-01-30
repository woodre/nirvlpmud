#include "/players/feldegast/defines.h"

inherit ROOM;
int is_here;
reset(arg) {
  object lion;
  is_here=1;
  if(!present("lion")) {
    lion=clone_object("/obj/monster");
    lion->set_name("lion");
    lion->set_short(HIY+"A Lion"+NORM);
    lion->set_long(
"This young lion has decided to sun himself on a large stone\n"+
"sitting in the middle of the ruins.  He watches you with his\n"+
"big green eyes and shaggy mane.\n"
    );
    lion->set_gender("male");
    lion->set_race("cat");
    lion->set_level(7);
    lion->set_wc(11);
    lion->set_ac(6);
    lion->set_hp(105);
    lion->set_al(0);
    lion->set_chat_chance(3);
    lion->load_chat("The lion purrs happily.\n");
    lion->load_chat("The lion growls at you for disturbing its sleep.\n");
    lion->set_dead_ob(this_object());
    move_object(lion,this_object());
}
  if (arg) return;
  set_light(1);
  short_desc=BOLD+"A jungle ruin"+NORM;
  long_desc=
"     You've found some ruins in the middle of the jungle.  It\n"+
"appears to have been a temple at one time, but now it lacks a\n"+
"roof and two of its four walls.  The large statue of a lion sits\n"+
"near the center of the ruin.\n";
  items=({
    "statue","This is a beautiful statue done in marble of a lion\n"+
             "standing approximately a meter and a half tall.  A\n"+
             "beautiful crystal tear runs down its face",
    "tear","A beautiful faceted crystal set into the marble"
  });
  dest_dir=({
    "/players/feldegast/island/jungle/jungle21","north"
  });
}
init() {
  ::init();
  add_action("pry","pry");
}
pry(str) {
  object tear;
  if(present("lion")) {
    write("The lion blocks your way.\n");
    return 1;
  }
  if(!str) {
    write("Pry what?\n");
    return 1;
  }
  if(str=="tear" || str=="crystal") {
    if(!is_here) {
      write("The crystal tear is gone!\n");
      return 1;
    }
    write("You pry the crystal tear from the lion statue.\n");
    is_here=0;
    tear=clone_object("/obj/treasure");
     tear->set_short(BOLD+"A lion's tear"+NORM);
    tear->set_long("This is a faceted crystal tear that you got\n"+
                   "from the ruin.\n");
    tear->set_id("crystal_lion_tear");
    tear->set_alias("tear");
    tear->set_value(10);
    tear->set_weight(0);
    tear->set_dest_flag(1);
    move_object(tear,this_player());
    return 1;
  }
  write("Pry what?\n");
  return 1;
}
monster_died(ob) {
  object skin;
  skin=clone_object("/obj/treasure");
  skin->set_id("hide");
  skin->set_short("A lion's hide");
  skin->set_long("This is the raw hide of a young lion.  It could be\n"+
                 "valuable.\n");
  skin->set_value(300);
  skin->set_weight(1);
  move_object(skin,this_object());
}
