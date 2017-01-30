#include "/players/mythos/closed/guild/def.h"
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("rosier");
  set_race("ghost");
  set_short("ghost of Rosier");
  set_long("The ghost of Rosier...\n"+
           "This is what is left of what Horlach destroyed....\n");
  set_hp(1000);
  set_level(30);
  set_al(0);
  set_wc(40);
  set_ac(20);
  set_heal(5,5);
  set_dead_ob(this_object());
  set_a_chat_chance(40);
  load_a_chat("Rosier cries out: Why did you give the Taormin to Him?!\n");
  load_a_chat("Rosier weeps.\n");
  set_mult(3);
  set_mult_chance(40);
  set_mult_dam1(10);
  set_mult_dam2(20); 
  call_out("checks",5);
}

checks() {
  if(this_object()->query_attack()) {
    if((this_object()->query_attack()) == this_object()) {
      this_object()->stop_fight();
      this_object()->heal_self(1000);
    }
  }
call_out("checks",5);
return 1;}

monster_died() {
object targ;
targ = this_object()->query_attack();
  if(present(fear,targ)) {
  tell_object(targ,"Suddenly the ghost of Rosier screams....\n"+
                   "She vanishes....\n"+
                   "You feel as if you have set in motion something\n"+
                   "that is far beyond your scope of understanding....\n"+
                   "\nKnowledge has been gained though.....\n");
  present(fear,targ)->set_dark_level(9);
  present(fear,targ)->save_dark();
  command("uu",targ);
  move_object(targ,"/players/mythos/enterance.c"); 
  tell_object(targ,"You feel suddenly very very small.....\n"+
                   "Someone laughs- a deep dark laugh...\n"+
                   "You shiver...\n"+
                   "\nThen all is quiet.....\n\n");}
return 0; }
