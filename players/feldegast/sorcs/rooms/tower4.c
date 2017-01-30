#include "defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg) return;
  set_light(1);
  short_desc=TOWER;
  long_desc=
"  The ancient marble steps ascend the tower in a counterclockwise\n\
fashion.  The steps level out shortly before a long landing about\n\
twenty feet wide and covered in a velvety red carpet.  A few high-\n\
backed antique chairs are pushed against the inside wall, and an oval\n\
mirror with a golden scroll-worked frame is on the wall opposite them.\n\
To the east and west are silverwood doors with iron bands on them.\n";
  items = ({
    "steps","These ancient steps have seen the passage of scholars, magicians, and wizards\n"+
            "for centuries.  Watch your step",
    "carpet","A velvety red carpet",
    "chairs","Antique mahogany chairs with high backs and cushioned seats",
    "mirror","Special..",
    "amulet","You see an amulet around your neck in the mirror.  The illusion is so\n"+
             "powerful that you could probably even 'touch' it",         
    "doors","Both of the doors are made out of silverwood, an especially strong\n"+
            "and beautiful wood that is said to have magical properties",
  });

  dest_dir=({
    ROOMPATH+"tower5.c","up",
    ROOMPATH+"tower3.c","down",
    ROOMPATH+"library.c","east",
    ROOMPATH+"laboratory.c","west",
  });
}
init(){
  ::init();
  add_action("cmd_touch","touch");
}
long(str) {
  if(!str || str!="mirror") ::long(str);
  else {
    write("You look into the oval mirror and see your own reflection:\n");
    look_at_me(this_player());
  }
}

look_at_me(object me) {
  object person,ob,special;
  person=me;
  person->long();
  special=first_inventory(person);
  while(special) {
    string extra_str;
    extra_str=special->extra_look();
    if(extra_str)
       write(extra_str+".\n");
    special=next_inventory(special);
  }
  write(capitalize(person->query_pronoun())+" is carrying: \n");
  write(HIC+"A glowing amulet"+NORM+".\n");
  ob = first_inventory(person);
  while (ob) {
    string sh;
    sh = call_other(ob, "short");

    if (sh)
    write(sh + ".\n");
    ob = next_inventory(ob);
  }
}
int cmd_touch(string str) {
  notify_fail("Touch what?\n");
  if(!str || str!="amulet") return 0;
  write("Staring carefully at the mirror, you lightly touch the amulet around your\n"+
        "neck.  The image inside the mirror begins to swirl with a rainbow of\n"+
        "mesmerizing colors.  Your eyes unfocus...and when you can see again you\n"+
        "realize you are somewhere else.\n");
  say((string)this_player()->query_name()+" disappears.\n");
  move_object(this_player(),ROOMPATH+"mirror.c");
  return 1;
}
