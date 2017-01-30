#include "../defs.h"
#define JUNK_PATH "/players/feldegast/obj/junk/"

inherit ROOM;

string *junk;

void reset(int arg)
{
  if(arg) return;
  short_desc="Storage Room";
  long_desc=
"  This is an extremely cluttered and extremely dusty storage room.  This\n"+
"is where many pieces of obsolete equipment or useless heirlooms are placed.\n"+
"There is a somewhat uncluttered area near the door, through which is the\n"+
"only source of light.\n";
  set_light(1);
  dest_dir=({
    ROOMPATH+"tower2.c","east",
  });
  items=({
    "equipment","Too much to list here.  You could just 'rummage' through it and\n"+
                "see what you find",
    "heirlooms","Too much to list here.  You could just 'rummage' through it and\n"+
                "see what you find",
  });
  junk=({
    "7broom.c",
    "bottomless_beaker.c",
    "holey_armor.c",
    "infamous_helm.c",
    "noteternal_torch.c",
    "pixie_lint.c",
    "snail_boots.c",
    "talking_sword.c",
    "rag.c",
  });
}
void init()
{
  ::init();
  add_action("cmd_rummage","rummage");
  add_action("cmd_rummage","search");
}

int cmd_rummage(string str)
{
  object ob;
  int n;
  if(sizeof(junk)==0)
  {
    write("You rummage around but you don't see anything else of interest.\n");
    return 1;
  }
  if(!random(10))
  {
    write("You stir up a pack of dust bunnies who chase you around the room.\n");
    return 1;
  }
  if(random(5))
  {
    write("You look around, but you don't find anything.\n");
    return 1;
  }
  n=random(sizeof(junk));
  ob=clone_object(JUNK_PATH+junk[n]);
  junk-=({ junk[n] });
  write("You rummage around the storage room until you find "+(string)ob->short()+"!\n");
  say((string)this_player()->query_name()+" rummages through the storage room.\n");
  move_object(ob,this_object());
  return 1;
}
