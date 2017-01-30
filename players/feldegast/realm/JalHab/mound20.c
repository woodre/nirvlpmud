#include "defs.h"

inherit MNDROOM;

int found;


void reset(int arg) 
{
  int i;
  if(!present("queen"))
    move_object(clone_object(MON_PATH+"myrm-queen.c"),this_object());
  found=0;
  if(arg) return;
  for(i=1; i < 21; i++)
    call_other(PATH+"mound"+i,"???");
  short_desc=RED+"The Myrmidar Mound"+NORM;
  long_desc=
"  You have entered the very heart of the Myrmidar Mound; the lair of\n\
the queen.  The chamber has been worn completely smooth by centuries of\n\
her movements, trapped in here by her own bulk.  Her body takes up\n\
almost the entire chamber.\n";
  items=({
    "bones","A pile of partially digested bones, from a wide variety of\n"+
            "creatures",
  });
  dest_dir=({
    PATH+"mound19.c","north",
  });
}

void init()
{
  ::init();
  add_action("cmd_search","search");
}

void long(string str) {
  if(!present("queen",this_object()))
    long_desc=
"  You have entered the very heart of the Myrmidar Mound; the lair of\n\
the queen.  The chamber has been worn completely smooth by centuries of\n\
her movements, trapped in here by her own bulk.  Now that the queen is\n\
dead, you can see a pile of partially digested bones in the back of the\n\
cave.\n";
  ::long(str);
}

int cmd_search(string str)
{
  object ob;
  int i;
  if(!str || str!="bones")
  {
    write("You search aimlessly about the chamber, but you find nothing.\n");
    return 1;
  }
  if(present("queen")) {
    return 0;
  }
  if(found) {
    write("You found nothing.\n");
    return 1;
  }
  write("You search among the bones, and find some items of interest.\n");
  found=1;
  for(i=0; i < 5; i++)
  {
    switch(i) {
      case 0: ob=clone_object(WEP_PATH+"winter_light.c");
              break;
      case 1: ob=clone_object(ARM_PATH+"shield.c");
              break;
      case 2: ob=clone_object(ARM_PATH+"tsymbol.c");
              break;
      case 3: ob=clone_object(ARM_PATH+"bplate.c");
              break;
      case 4: ob=clone_object("/obj/money.c");
              ob->set_money(5000+random(2000));
              break;
    }
    move_object(ob,this_object());
    write("Found: "+(string)ob->short()+"\n");
  }
  return 1;
}

int queen_room() { return 1; }
