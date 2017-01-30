inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"
string *cc;

reset(arg) {
   ::reset(arg);
   if (arg) return;

  cc =({ "chest", "arm", "shoulder", "leg", "thigh", "hand", "foot", });

  set_name("bow");
  set_short("A finely crafted bow");
  set_type("bow");
  set_long(
"This is a very finely made bow.  It appears as though it was crafted\n"+
"quite some time ago and has been taken very good care of by its owners.\n"+
"The bow is strung and ready to be fired, as long as you have a quiver\n"+
"of arrows to use with it.  Without arrows it would be pretty useless.\n");
  set_value(500);
  set_weight(3);
  set_class(17);
  set_hit_func(this_object());
}

int weapon_hit(object x){
  object quiver;
  if(environment()->is_npc()) return 0;
  quiver = present("zeus_quiver", environment());
  if(quiver && quiver->query_arrows() && random(3))
  {
    string hitc;
    hitc = cc[random(sizeof(cc))];
    tell_object(environment(),
      "\n\tYou fire an arrow at "+x->query_name()+"...  It strikes "+
      x->query_objective()+" in the "+hitc+"!\n\n");
    tell_room(environment(),  environment()->query_name()+
      " fires an arrow at "+x->query_name()+"!\n", ({ environment() }));
    quiver->use_arrow();
    if(x->query_hp() > 10)
      x->hit_player(10);
    return 8;
  }
  else if(quiver && quiver->query_arrows())
  {
    tell_object(environment(),
      "You fire an arrow at "+x->query_name()+" but it misses by a mile.\n");
    tell_room(environment(),  environment()->query_name()+
      " fires an arrow at "+x->query_name()+" but it misses by a mile.\n",
      ({ environment() }));
    quiver->use_arrow();
  }
  else if(quiver && !quiver->query_arrows())
  {
    tell_object(environment(), "You toss your empty quiver away.\n");
    destruct(quiver);
  }
  else if(!quiver)
    tell_object(environment(), "You have no arrows left for the bow.\n");
  return -10;
}
