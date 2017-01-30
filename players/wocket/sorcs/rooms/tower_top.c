#include "../defs.h"

inherit ROOM;

void reset(int arg)
{
  if(arg)return;
  set_light(1);
  short_desc=CYN+"Atop the "+TOWER;
  long_desc=
"  You stand high atop the misty tower, its crenelations the only thing\n\
standing between you and a fall to your death.  The roof is flat and\n\
circular.  A mighty horn, easily three meters in length and carved out\n\
of bone sits atop the tower.  A covered stairwell leads inside.\n";
  dest_dir=({
    ROOMPATH+"tower6.c","down",
  });
  items=({
    "horn","A horn, constructed out of bone and easily three meters\n"+
           "in length",
    "stairwell","It leads back inside the misty tower",
  });
}

void init()
{
  ::init();
  call_out("wind",random(10));
  add_action("cmd_blow","blow");
}

void wind()
{
  while(remove_call_out("wind")!=-1) ;
  tell_room(this_object(),"A chill wind blows.\n");
  if(random(5))
    call_out("wind",20+random(20));
}

int cmd_blow(string arg)
{
  notify_fail("Blow what?\n");
  if(!arg || arg!="horn") return 0;
  if(!present("khazanth"))
  {
    while(remove_call_out("summon_dragon")!=-1) ;
    call_out("summon_dragon",20);
    write("You blow the horn, and are nearly deafened by the loud, echoing\n"+
          "sound it makes.\n");
  }
  else 
    write("The dragon is already here.\n");
  return 1;
}

void summon_dragon()
{
  call_other(NPCDIR+"khazanth","???");
  move_object(NPCDIR+"khazanth.c",this_object()); /* Only one at a time */
  tell_room(this_object(),
"A huge black dragon, his scales as black as coal, descends upon the\n\
tower and lands deftly.\n");
  call_out("wait_dragon",4);
}

void wait_dragon()
{
  tell_room(this_object(),"The dragon seems to wait expectantly.\n");
}

query_loc() { return 1; }
