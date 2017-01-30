/*
The Soulstone
Made by Feldegast
6-19-2000
Drains corpses for storable heal
Instructions for players are in Castle Magnaarn's Library.
*/
#include "defs.h"
#define WORD1 "korat"
#define WORD2 "tarok"

int power;
int used;

inherit "/obj/treasure.c";

void reset(int arg) {
  if(arg) return;
  set_id("soulstone");
  set_alias("stone");
  set_short(HIM+"Soulstone"+NORM);
  set_long(
    "This is a rounded piece of marble small enough to fit into the palm\n"+
    "of your hand.  The purple and black marble swirls beneath the surface.\n"+
    "It pulses as though it were alive.\n"
  );
  set_weight(1);
  set_value(5000);
}

void init() {
  add_action("cmd_drain", WORD1);
  add_action("cmd_heal", WORD2);
}

string short() {
  string shrt;
  shrt=short_desc;
  if(this_player() && this_player()->query_level() > 20)
    shrt+=" (Charge: "+power+")";
  return shrt;
}

void long(string str) {
  ::long(str);
  if(power) {
    write("It is glowing");
    if(power > 150)
      write(" radiantly");
    else if(power > 100)
      write(" brightly");
    else if(power > 50)
      write(" dimly");
    write(".\n");
  }
}

int cmd_drain(string str) {
  object corpse;
  int value;

  corpse=present("corpse",this_player());

  if(!corpse)
    corpse=present("corpse",environment(this_player()));

  if(!corpse) {
    notify_fail("Nothing happens.\n");
    return 0;
  }

  value=(int)corpse->heal_value();

  if(!value) {
    notify_fail("Nothing happens.\n");
    return 0;
  }

  if(environment(corpse)==this_player())
    this_player()->add_weight((int)corpse->query_weight());

  value*=2;
  power+=value;
  if(power > 200) power=200;
  write("You touch the corpse of "+(string)corpse->query_name()+" with the soulstone.\n"+
        "The corpse's life energy is sucked into it and then\n"+
        "crumbles into dust.\n");
  say(TPN+" dissolves "+(string)corpse->short()+" with the soulstone.\n");
  destruct(corpse);
  return 1;
}

int cmd_heal(string str) {
  int amt;
  amt=random(40);
  if(amt > power) {
    notify_fail("Nothing happens.\n");
    return 0;
  }
  if(used) {
  write("It is still recharging.\n");
  return 1;
  }
  power-=amt;
  this_player()->add_spell_point(amt);
  write("You whisper to the stone, asking it for power.  It grants\n"+
        "your wish with a jolt of energy.\n");
  say(TPN+" is infused by the "+short()+"'s power!\n");
  used=1;
  call_out("unset",3);
  return 1;
}

void unset() {
  used=0;
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

locker_arg() {
  return ""+power;
}

locker_init(str) {
  sscanf(str,"%d",power);
}
