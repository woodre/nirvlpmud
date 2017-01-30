#include "lib.h"

inherit ROOM;

string *tree_syntax;

void reset(int x) {
  if(x) return;
  set_light(1);
  set_short("A stable yard");
  set_long("\
  Tufts of green grass puff up and break through the cracked\n\
earth.  Tall trees stand sparsely apart around a virtual clearing.\n\
The winding path leads up to the entrance to the stables\n\
northwest of here, or southeast towards the forests.\n");
  set_exits(({
   AREA+"stable1","northwest",
   AREA+"yard1",  "southeast",}));
  add_item(({"tufts","grass","green grass","clearing"}),
   "The small tufts of green grass are beautiful.\n"+
   "You don't even see a spot of brown");
  add_item(({"trees","tall trees","hickory","hickory trees"}),
   "The tall hickory trees stand apart from each other.\n"+
   "Their twisted branches reach in all directions");
  add_item(({"twisted branches","tree branches","branches"}),
   "The tree branches wrap simultaneously up to both the\n"+
   "heavens and the underworld. They seem sturdy enough to\n"+
   "support a great deal of weight");
  add_item(({"cracked earth","earth","soil","crusted earth",
             "breaks"}),
   "You see breaks in the crusted earth where the grass\n"+
   "has grown up through");
  add_item(({"path","winding path","dusty path"}),
   "The dusty path leads northwest towards the stable area,\n"+
   "or southeast into the forests.\n");
  add_listen("main", "You hear the chirping of birds from atop the trees.\n");
}

void init() {
  ::init();
  add_action("cmd_climb","climb");
  add_action("cmd_shake","shake");
}

int cmd_climb(string str) {
  if(!str) {
    notify_fail("Climb what?\n");
    return 0;
  }
  if(!tree_syntax)
    tree_syntax=({"tree","trees","tall tree","tall trees","hickory","a tree"});
  if(member_array(str, tree_syntax) == -1)
  {
    notify_fail("You may only \"climb\" a tree.\n");
    return 0;
  }
  write("You begin climbing up the side of a tree..\n");
  if((int)tp->query_attrib("str") < random(30))
  {
    write("You lose your grip!\n"+
          "You tumble all the way down to the ground!\n");
    tp->hit_player(random((int)tp->query_level() * 5));
  }
  write("\n  You climb up the side of a tree.\n\n");
  tp->mp("up#"+AREA+"tree");
  return 1;
}

int cmd_shake(string str) {
  if(!str) {
    notify_fail("Shake what?\n");
    return 0;
  }
  if(!tree_syntax)
    tree_syntax=({"tree","trees","tall tree","tall trees","hickory","a tree"});
  if(member_array(str, tree_syntax) == -1)
  {
    notify_fail("You may \"shake\" a tree.\n");
    return 0;
  }
  else
  {
    object x, y, tree;
    int    dam;

    write("You shake the sides of a tree.\n");

    if(!(tree=find_object(AREA+"tree")) ||
       !(x=first_inventory(tree)))
      return 1;
    tell_room(tree, "The tree begins to shake...\n");
    dam =(int)tp->query_attrib("str")*3;
    while(x) {
      y=next_inventory(x);
      if((int)x->query_attrib("int") < random(30))
      {
        tell_object(x, "\n\tYou fall out of the tree!\n\n");
        tell_room(tree,
         (string)x->qn +" falls out of the tree!\n");
        move_object(x, this_object());
        x->hit_player(dam);
      }
      else
        tell_room(tree,
         (string)x->qn +" maintains "+possessive(x)
         +" foothold.\n");
      x=y;
    }
  }
}
          

