#include "/players/feldegast/defines.h"

inherit ROOM;

int is_here;

reset(arg) {
  object crab;
  int x;
  if(!present("crab")) {
    while(x<6) {
      x++;
      crab=clone_object("obj/monster");
      crab->set_name("crab");
      crab->set_short("Crab");
      crab->set_long(
"     A vicious little crustacean with sharp claws and a hard\n"+
"shell.\n" 
      );
      crab->set_race("crustacean");
      crab->set_level(1);
      crab->set_wc(5);
      crab->set_ac(3);
      crab->set_hp(15);
      crab->set_al(0);
      crab->set_dead_ob(this_object());
      move_object(crab,this_object());
    }
  }
  is_here=1;
  if (arg) return;
  set_light(1);
  short_desc="A damp cave";
  long_desc=
"     This is a damp cave carved out by water and the passage\n"+
"of time.  A hole high up in the cave lets some light in.  Behind\n"+
"a pile of rocks is a ragged skeleton.\n";
  items=({
    "skeleton","The skeleton's skull lies a few feet away.\n"+
               "You don't think he died naturally.  You\n"+
               "see something glinting in the shadows.  Perhaps\n"+
               "you should search them",
    "hole","Another product of natural erosion",
    "rocks","They look to be dark igneus rocks approximately five\n"+
            "centimeters in diameter"
  });
  dest_dir=({
    "/players/feldegast/island/beach4","out"
  });
}
init() {
  ::init();
  add_action("search","search");
}
search(str) {
  object shears;
  if(present("crab")) {
    write("You can't search anything with all these crabs running around.\n");
    return 1;
  }
  if(!str) {
    write("Search what?\n");
    return 1;
  }
  if(str=="shadows" && is_here) {
    write("You find a rusty old pair of shears lying on the floor.\n");
    shears=clone_object("/players/feldegast/island/shears");
    move_object(shears,this_player());
    is_here=0;
    return 1;
  }
  write("You find nothing.\n");
  return 1;
}      

monster_died(ob) {
  object shell;
  shell=clone_object("/obj/treasure");
  shell->set_id("shell");
  shell->set_short("A crab shell");
  shell->set_long(
"This is a hard pinkish crab shell.  It might be worth something.\n"
  );
  shell->set_value(30);
  shell->set_weight(0);
  move_object(shell,ob);
}   
