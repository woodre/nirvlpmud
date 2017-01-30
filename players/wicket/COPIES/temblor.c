/*
A warhammer possessed by /pl/s/MONSTERS/cleop.c
It uses player strength, stamina, and level to determine return
This weapon is insanely hard to get. First, players must find the
demon in the catacombs area of the ShadowRealm, then must kill the
demon (extremely tough), then must figure out how to break the gem
they find to release the hammer (this involves making Icingdeath mad)...
*/

#include "/players/snow/closed/color.h"
inherit "obj/weapon.c";
 reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("temblor");
    set_alias("warhammer");
    set_short(BOLD+"Temblor"+OFF);
    set_type("hammer");
    set_long(
"The legendary warhammer, Temblor, is nearly 4 feet in length and is\n"+
"composed of pure adamantium. It appears to be vibrating slightly.\n");
    set_class(19);
    set_weight(5);
    set_value(10000);
/* switched to magical damage by illarion 5 dec 2004
    set_hit_func(this_object());
*/
  set_params("magical",0,"magic_hit");
}

magic_hit(ob) {
  object me;
  int mystr, mysta;
  if(!ob) return;
  if(!environment()) return;
  me = environment();
  if(!living(me)) return;
  if(!me->is_player()) return;
  mystr = me->query_attrib("str");
  mysta = me->query_attrib("sta");
  if(random(100) < ob->query_hp()/3) {
  write(BOLD+"You draw energy from the earth to strengthen your body!\n"+OFF);
    if(random(30) < mysta && random(30) < mystr && random(300) > me->query_hp()) {
    me->heal_self(random(mystr + mysta)/4 + 2);
    }
  }
  if(random(100) < (mystr + mysta) ) {
    tell_room(environment(me),BOLD);
    say(me->query_name()+" shatters "+ob->query_name()+" with "+me->query_possessive()+" warhammer!\n");
    write("Temblor sends waves of energy wracking into "+ob->query_name()+"!\n");
    tell_room(environment(me), OFF);
/* changed heal_self to magical damage */
    ob->hit_player(1+random(mystr/2),"magical");
/* added 1 to return because it's randomized seperately from physical damage */
    return 1+me->query_level()/4;
 
   }
       return;
}

query_wear() { return 0; }
weapon_breaks() { return 1; }
quest_ob() { return 1; }
