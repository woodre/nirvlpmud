
#define me this_object()
inherit "/obj/armor";

reset()
{
   int lifespan;
   set_name("sring");
   set_alias("ring");
   set_short("Ring of Stealth");
   set_long("This is one of the Master's finest creations. This ring glows\n"+
            "with pulsating power. It has the ability to increase your\n"+
"stealthness if you have already maxed it out.\n");
   set_ac(1);
   set_value(1500);
   set_type("ring");
   lifespan =this_player()->query_level() * 30 + 1080;
   call_out("destruct_me",lifespan);
}

init() {
  ::init();

  add_action("wear_ring",   "wear");
  add_action("remove_ring", "remove");
  add_action("remove_ring", "unwear");
}

wear_ring(str) {
  if (!str || str!="ring") return 0;
  if (this_player()->query_attrib("ste") >= 20) {
    this_player()->raise_stealth(80);
  }
  return 0;
}

remove_ring(str) {
  if (!str) return 0;
  if (str!="ring" && str!="all") return 0;
  this_player()->raise_stealth(-80);
  remove_call_out("destruct_me");
  return 0;
}

drop() {
  if (worn)
    return 1; /* no dropping if worn */
  else
    return 0;
}

destruct_me()
{
   environment(me)->raise_stealth(-80);
   tell_room(environment(me), me->short() + " crumbles into dust!\n");
   destruct(me);
}
