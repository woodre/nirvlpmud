#include <ansi.h>;

inherit "/obj/weapon.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("tail");
  set_short("An "+MAG+"A"+HIK+"lien"+NORM+"'s tail with a spiked tip");
  set_long("This is a deadly whip formed from the tail of a recently slain\n"+
           "alien drone. There is a spike on the very end that could pierce\n"+
           "kevlar and diamond alike. It is very maneuverable and light\n");
  set_type("whip");
  set_class(17);
  set_weight(3);
  set_value(1050+random(300));
}

void init()
{
  ::init();
  add_action("wield", "wield");
}
int wield(string str)
{
  int w;
  w = wielded;
  if(!::wield(str))
    return 0;
  if(w) return 1;
  write("You grab the tail by the base and feel the still-fresh alien blood burn your hand.\n");
  say("The tail whips around and makes a *CRACK* sound.\n");
  this_player()->add_hit_point(-15+random(-35));
  this_player()->add_spell_point(-5+random(-10));
  this_player()->heal_self(-0);
  return 1;
}
