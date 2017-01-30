inherit "obj/clean";
#include "definitions.h"


init() { add_action("raise","raise"); }

id(str) { return str == "moonstone" || str == "stone"; }

get() { return 1; }
drop() { return 0; }
query_weight() { return 1; }
query_value() { return 500; }

short() { return "A moonstone"; }

long()
{
  write(
"     The moonstone looks like a rather ugly piece of rock.\n"+
"It has several holes in its side, and its texture is very rough.\n"+
"Nonetheless, it is a powerful item. Some small runes upon its side\n"+
"read:  When thou art in the Sithi City...\n"+
"      'raise' the moonstone to take you home.\n");
}


raise(string what)
{
  string str, msg;

  if (!what) return 0;
  if (what != "moonstone" && what != "stone") return 0;

  if (TP->query_attack())
  {
    write("You cannot use the moonstone when in combat!\n");
    return 1;
  }

  str = file_name(environment(TP));

  if (sscanf(str,"%sdune%s",msg))
  {
    write("You raise the moonstone over your head... an odd sensation\n"+
          "comes over you. You realize you are in a different place.\n");
    say(TPN+" raises the moonstone and fades out of view.\n");
    randomly_locate(TP);
    return 1;
  }

  write("The moonstone has no power here.\n");
  return 1;
}


randomly_locate(object ob)
{
  int rnd;
  rnd = random(8) + 1;
  switch(rnd)
  {
    case 1:   move_object(ob, CASTLEROOM+"/green13.c"); break;
    case 2:   move_object(ob, CASTLEROOM+"/green11.c"); break;
    case 3:   move_object(ob, CASTLEROOM+"/green8.c"); break;
    case 4:   move_object(ob, CASTLEROOM+"/green14.c"); break;
    case 5:   move_object(ob, CASTLEROOM+"/green9.c"); break;
    case 6:   move_object(ob, CASTLEROOM+"/brown8.c"); break;
    case 7:   move_object(ob, CASTLEROOM+"/brown4.c"); break;
    case 8:   move_object(ob, CASTLEROOM+"/brown1.c"); break;
  }
  return;
}
