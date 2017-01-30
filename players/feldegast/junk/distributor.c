#include "/players/feldegast/defines.h"

inherit "obj/treasure";

void reset(int arg)
{
  if(arg)return;
  set_id("wand");
  set_short("Wand of distribution");
  set_long("Just 'wave wand' to distribute the invitations.\n");
  set_weight(0);
  set_value(0);
}
void init()
{
  add_action("cmd_wave","wave");
}
int cmd_wave(string str)
{
  object *world;
  int i;
  world=users();
  if(!str || str!="wand") return 0;
  write("You have the wand and send messengers off to all the players on the mud.\n");
  for(i=0; i < sizeof(users()); i++)
  {
     if((int)world[i]->query_level() < 20 && !present("invitation",world[i]) &&
        member_array((string)TP->query_real_name(),({ "jenny","wulfgar" }))!=-1)
     {
       tell_object(world[i],"A servant in blue and white livery walks in and hands you a scroll, then\n"+
                            "departs as quickly as he came.\n");
    move_object(clone_object(OBJ_PATH+"scroll-tourney"),world[i]);
    }
  }
  return 1;
}
