#include "/players/mythos/closed/ansi.h"
int base;
inherit "players/mythos/dmon/mon";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("greater sand walker");
  set_alias("sand");
  set_race("sandwalker");
  set_short("Greater Sand Walker");
  set_long("A Greater SandWalker.\n"+
           "A creature made of molten shimmering gold fluid.\n"+
           "It is a mound of flowing pulsating quasi-liquid about\n"+
           "1 1/2 meters tall.  As it moves odd shapes form from\n"+
           "its surface- an arm with a clawed hand, a female head,\n"+
           "a dragon's jaws.  Tremendous heat eminates from it....\n");
  set_level(24);
  set_hp(890);
  if(random(3) > 0) set_al(-random(1000));
  else set_al(random(1000));
  set_wc(40);  
  set_ac(17);
  set_heal(5,10);
  set_light(3);
  if(random(3) > 0) set_aggressive(1);
  set_chat_chance(20);
  set_a_chat_chance(2);
  load_chat("Light flashes into your eyes- blinding you.\n");
  load_chat("The SandWalker warbles.\n");
  load_chat("The golden liquid metal flows around you.\n");
  load_a_chat("The SandWalker screams!\n");   
  load_a_chat("Heat sears the air around you\n");
  set_chance(15);
  set_spell_dam(250);
  set_spell_mess1("The form of the SandWalker flows and strikes out at its enemy!\n");
  set_spell_mess2("Heat burns you as the SandWalker strikes out at you!\n"); 
  set_mult(3);
  base = 17;
  set_dead_ob(this_object());
}

query_prevent_shadow() { return 1; }

monster_died() {
object leave;
   switch(random(2)) {
     case 0: leave = clone_object("/obj/money.c");
             leave->set_money(5000 + random(5000));  /* take a good look at this 
                                                        monster */
             break;
     case 1: leave = clone_object("/players/mythos/dmisc/seed.c");
             break;
   }
  move_object(leave,this_object());
}

heart_beat() {
  set_ac(base);
  set_wc(40);
  set_mult(1 + random(6));
  set_heal(5,10);
  ::heart_beat();
}

hit_player(dam,zap) {
int damm;
  damm = dam;
  if(damm - base > 0) {
    base = base + 1;
    tell_room(environment(this_object()),
      "The SandWalker's surface flashes and great heat surges forth.\n");
  }
  ::hit_player(dam,zap);
}

heal_self(n) {
int damm;
  damm = n;
  if(damm < 0) {
    if(damm + base < 0) { base = base + 2 + random(2); 
    tell_room(environment(this_object()),
      "The SandWalker's surface flashes and great heat surges forth.\n"); }
  damm = damm + base;
  }
  ::heal_self(damm);
}
  