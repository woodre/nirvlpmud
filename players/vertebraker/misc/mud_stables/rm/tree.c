#include "lib.h"

inherit ROOM;

string *rms;

void reset(int x) {
  if(x) return;
  set_light(1);
  set_short("Atop a tree");
  set_long("\
  Atop a majestic hickory tree several dozen feet above\n\
the ground, the branches still maintain a great deal of\n\
weight.  From here, you can \"call\" down to passersby\n\
or \"look\" in a specific direction to see the surrounding\n\
areas to the northwest and southeast.\n");
  set_exits(({
    AREA+"yard2","down"}));
  add_listen("main","\
From here, you can hear everything going on beneath you.\n");
  add_item(({"hickory tree","tree"}), long_desc);
  add_item("branches",
   "The thin branches can maintain quite a sum of weight.\n"+
   "Otherwise, they would have broken apart by now");
}

void init() {
  ::init();
  add_action("cmd_call", "call");
  add_action("cmd_overlook", "overlook");
}

int cmd_call(string str) {
  if(!str)
  {
    write("Usage: 'call <whatever>'\n");
    return 1;
  }
  else
  {
    object    room, relay;
    int       x;

    write("You call out to anyone that can hear: "+str+"\n");
    say(tpn+" calls out: "+str+"\n");

    str="Someone calls out:"+str+"\n";
    if(!rms)
      rms=({"yard2","yard1","stable1","stable2"});

    x=sizeof(rms);
    while(x--)
      if((room=find_object(AREA+rms[x])) &&
       (relay=present("spy_relay",room)))
        tell_room(room,str,({relay}));
    return 1;
  }
}

int cmd_look(string str)
{
  string        file;

  if(str == "northwest" || str == "nw")
  {
    str="northwest";
    file=AREA+"stable1";
  }
  else if(str == "southeast" || str == "se")
  {
    str="southeast";
    file=AREA+"yard1";
  }
  else
    return ::cmd_look(str);

  write("\n\tYou look to the "+str+"...\n\n");
  say((string)tp->qn+" looks to the "+str+"...\n");

  move_object(tp, file);
  command("look", tp);
  move_object(tp, to);

  return 1;
}
