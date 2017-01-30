#include <ansi.h>;

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("chain");
  set_short("A "+HIW+"Spiked"+NORM+" chain");
  set_long("With spikes lining both sides all down the length of it, this\n"+
           "steel chain could easily rip just about anyone into bloody\n"+
           "ribbons of flesh\n");
  set_type("whip");
  set_class(21);
  set_weight(3);
  set_value(1050+random(300));
}

extra_look() { 
if(wielded && living(environment(this_object())))
return RED+"Blood "+NORM+"drips from "+
           capitalize(environment()->query_real_name() + NORM);
           else { return 0; }
}

void init()
{
  ::init();
  add_action("wield", "wield");
  add_action("unwield", "unwield");
}
int wield(string str)
{
  int w;
  w = wielded;
  if(!::wield(str))
    return 0;
  if(w) return 1;
  write("As you grip the chain, some of the spikes burrow deep into your hand.\n");
  say(""+RED+"Blood"+NORM+" flows as the chain is readied for use.\n");
  this_player()->add_hit_point(-35+random(-35));
  this_player()->lower_attrib(mag(15));
  this_player()->lower_attrib(sta(8));
int unwield(string str)
{
  int u;
  u = unwielded;
  if(!::unwield(str))
    return 0;
  if(u) return 1;
  write("You release your grip on the chain and blood flows from the holes it left.\n");
  say(""+RED+"Blood"+NORM+" flows as the chain is removed.\n");
  this_player()->add_hit_point(-35+random(-35));
  this_player()->lower_attrib(mag(-15));
  this_player()->lower_attrib(sta(-8));
  
  return 1;
}
