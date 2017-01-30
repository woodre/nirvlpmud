#include "def.h"

inherit AROOM;

object tree;
int is_tree;

int trap;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc=GRN+"Forest"+NORM;
  long_desc=
"  Thick green foliage covers the stout trees of these woods.  You see\n"+
"a plateau over the trees to the north.  Moldy-green moss covers a\n"+
"slick grey rock that sticks up out of the grass.  The lower branches\n"+
"of a gnarly old oak tree lie temptingly close to the ground.\n";
  
  items=({
    "foliage","The trees of the forest are thick with abundant, green life",
    "plateau","A tall plateau stands over the forest",
    "trees","The trees of the forest are thick with abundant, green life",
    "moss","A thick carpet of gritty green stuff covering a rock",
    "rock","A slick grey rock covered with moss",
    "grass","You notice a bear trap hidden in the grass",
    "trap","The bear trap's rusted iron jaws gape menacingly.  You\n"+
           "can <"+BOLD+"set"+NORM+"> the trap if you want to",
    "branches","The lowest branch of the gnarled oak tree is just about\n"+
               "the right height for a handhold",
    "tree","This wizened old oak tree is just the right height for you to <"+BOLD+"climb"+NORM+">n"
  });
  dest_dir=({
    PATH+"m3","north",
    PATH+"m5","west",
    PATH+"m9","south"
  });
  is_tree=1;
  enable_commands();
}
long(str) {
  if(str=="plateau") view_room(PATH+"m3");
  else ::long(str);
}
init() {
  ::init();
  if(trap) {
    if(TP->query_attrib("ste") < random(30)) {
      write("Rusty iron jaws bite into your leg as you step into a bear trap!\n");
      say("Rusty iron jaws bite into "+TP->query_name()+"'s leg as "+TP->query_possessive()+" \nsteps into a bear trap.\n");
      TP->hit_player(40);
      trap=0;
    }
    else
      write("You narrowly avoid stepping into a bear trap.\n");
  }
  add_action("cmd_set","set");
  add_action("cmd_climb","climb");
}
cmd_set(str) {
  notify_fail("Set what?\n");
  if(!str || str!="trap") return 0;
  if(TP->query_attrib("str") < random(35)) {
    write("You try to pry open the jaws of the trap, but you fail.\n");
    say(TPN+" kneels down in the grass and fiddles with something.\n");
    return 1;
  }
  trap=1;
  write("You pry open the jaws of the trap and set the pin.\n");
  say(TPN+" kneels down in the grass and fiddles with something.\n");
  return 1;
}
cmd_climb(str) {
  notify_fail("Climb what?\n");
  if(!is_tree) return 0;
  if(!str || str!="tree") return 0;
  write("You climb high up into the tree.\n");
  say(TPN+" climbs up into the oak tree.\n");
  move_object(TP,PATH+"m6b");
  return 1;
}

catch_tell(str) {
  tell_room(PATH+"m6b","~"+str);
}

remove_exit(str) {
  if(str=="m6b") {
    is_tree=0;
    tell_room(this_object(),"The gnarly oak tree falls with a crash.\n");
  }
  ::remove_exit(str);
}
