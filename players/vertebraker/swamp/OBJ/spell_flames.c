#include "../define.h"
int stats;
inherit ITEM;

reset(arg) {
   if(arg) return;
   set_id("shadowy_flames");
}

init() {
   ::init();
   remove_call_out("do_dmg");
   call_out("do_dmg",10);
}
do_dmg() {
   string m, n;
   string idiot;
   object env;
   idiot = USER->QN;
   env = ENV(USER);
   switch(random(4)) {
      case 0: m="Shadowy Flames scorch "+idiot+"!\n"; n="Shadowy Flames scorch you!\n"; break;
      case 1: m="Darkness enshrouds "+idiot+"...\nPain wracks "+USER->query_possessive()+" body!\n"; n="Darkness enshrouds you...\n\tPain wracks your body!\n"; break;
      case 2: m="Blood races from "+idiot+"'s wounds...\n"; n="Blood races from your shadowed, blackened wounds...\n";  break;
      case 3: m="Evil energy pours throughout "+idiot+"'s body....\n"; n="Evil energy ripples throughout your body...\n"; break;
   }
   n=BOLD+BLK+n+NORM;
   m=BOLD+BLK+m+NORM;
  if(USER->query_ghost()) {
    destruct(this_object());
  }
   tell_object(USER, n);
    if(env)  tell_room(env, m, ({ USER }));
   USER->hit_player(50 + random(30), "other|dark");
   USER->add_spell_point(-(50 + random(30)));
   stats += 1;
   if(stats == 7) {
      tell_room(env,BOLD+BLK+"The shadowy flames die down around "+idiot+"....\n"+NORM);
      destruct(TO);
      return 1; }
   else call_out("do_dmg",6+random(4));
   return 1; }

drop() { return 1; }
