/*
File: wand-spider.c
Author: Feldegast
Date: 2-24-02
Description:
  A magical wand found on Arachnia in the spider cave in
Caladon.  It can summon spiders or throw webs.
Note to self: Make some sort of shop or wizard in town who
can identify this stuff.
*/
#include "/players/feldegast/defines.h"

inherit "/obj/treasure.c";

int charges;
int delay;

void reset(int arg)
{
  if(arg) return;
  set_id("wand");
  set_short("Wand of Spiders");
  set_weight(1);
  set_info(
    "This wand was created by the Spider-Sorceress Arachnia and can be\n"+
    "activated using the magic words <"+YEL+"werlo"+NORM+"> or <"+BOLD+"aracho"+NORM+">.\n"
  );
  charges = 5+random(6);
}

void init()
{
  add_action("cmd_web", "werlo");
  add_action("cmd_summon", "aracho");
}

query_value() { return 1000*charges; }

long(str)
{
  write(
    "This is a short silver rod with little metal spiders with ruby\n"+
    "eyes crawling along its length.  It has "+charges+" charges remaining.\n"
  );
}

locker_arg() {
  return charges+"";
}

locker_init(arg) {
  sscanf(arg,"%d",charges);
}
    
generic_object() { return 1; } 

restore_thing(str) {
  restore_object(str);
  return 1;
}

save_thing(str) {
  save_object(str);
  return 1;
}

cmd_summon(str)
{
  object targ;
  object spider;
  int i;

  if(charges <= 0)
  {
    notify_fail("There are no more charges remaining.\n");
    return 0;
  }

  if(delay)
  {
    write("Nothing happens.\n");
    return 1;
  }

  if(!str)
    targ = this_player()->query_attack();
  else
    targ = present(str, environment(TP));

  if(!targ)
  {
    notify_fail("You must specify a valid target.\n");
    return 0;
  }

  if(!living(targ) || targ->is_player())
  {
    write("That is not a valid target.\n");
    return 1;
  }

  for(i=0; i < 1+random(4); i++)
  {
    spider = clone_object(MON_PATH+"spider.c");
    spider->set_time(9);
    spider->set_master(TP);
    move_object(spider, environment(TP));
    spider->attacked_by(targ);
  }

  targ->attacked_by(TP);
  TP->attacked_by(targ);

  write("You intone the magic word '"+query_verb()+"' as you wave your wand,\n"+
        "summoning "+i+" small spiders to attack "+targ->query_name()+".\n");
  say(TPN+" waves "+TP->query_possessive()+" wand as "+TP->query_objective()+" summons "+
      "a swarm of spiders to attack "+targ->query_name()+".\n");
  charges--;
  delay = 1;
  call_out("pause", 60);
  return 1;
}

cmd_web(str)
{
  object targ;
  object web;
  int i;

  if(charges <= 0)
  {
    notify_fail("There are no more charges remaining.\n");
    return 0;
  }

  if(delay)
  {
    write("Nothing happens.\n");
    return 1;
  }

  if(!str)
    targ = this_player()->query_attack();
  else
    targ = present(str, environment(TP));

  if(!targ)
  {
    notify_fail("You must specify a valid target.\n");
    return 0;
  }

  if(!living(targ) || targ->is_player())
  {
    write("That is not a valid target.\n");
    return 1;
  }

  if(present("web_token", targ))
  {
    write(targ->query_name()+" is already covered in webs.\n");
    return 1;
  }

  web = clone_object(OBJ_PATH+"web_token.c");
  move_object(web, targ);

  targ->attacked_by(TP);
  TP->attacked_by(targ);

  write("You point the Wand of Spiders at "+targ->query_name()+" as you mutter\n"+
        "the magic word.  A stream of webbing shoots out at "+targ->query_name()+
        ",\nsurrounding "+targ->query_objective()+" in sticky webs.\n");
  say(TPN+" points the Wand of Spiders at "+targ->query_name()+" and mutters a\n"+
      "magic word.  A stream of webbing shoots out at "+targ->query_name()+",\n"+
      "surrounding "+targ->query_objective()+" in sticky webs.\n");
  charges--;
  delay = 1;
  call_out("pause", 60);
  return 1;
}

void pause()
{
  delay = 0;
  if(living(environment()))
    tell_object(environment(), RED+"The wand of spiders flashes ruby.\n"+NORM);
}

