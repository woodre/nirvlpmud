#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";
object shroom;

reset(arg){
   int i;
   ::reset(arg);
  if(!arg && !root())
   if("/players/wocket/mushrooms/nonge_tracker"->query_nonges() > 18) {
    call_out("kablooey", 1);
    return;
  }
   if(!arg){
      "/players/wocket/mushrooms/nonge_tracker"->register_nonge();
      set_dead_ob(this_object());
      set_name("nonge");
      set_race("seussian");
      set_al(1000-random(2000));
      if(alignment < -500) set_aggressive(random(2));
      shroom = clone_object("/players/wocket/mushrooms/shroom.c");
      move_object(shroom,this_object());
      
      switch(random(6)){
        case 0: child();    break;
        case 1: wanderer(); break;
        case 2: peasant();  break;
        case 3: femme();    break;
        case 4: monarch();  break;
        case 5: warrior();  break;
      }
   }
}

kablooey() {
  if(environment()) {
   if(!random(2))
    tell_room(environment(), "Far away, a nonge explodes.\n");
  }
  destruct(this_object());
}

warrior(){
   set_short("A "+HIB+"warrior"+NORM+" nonge");
   set_long("\
This nonge stands proud bearing the traditional dress of \n\
the nonge warriors.  A sash runs cross his massive chest\n\
and is pinned against his kilt.  Tuffs of fur along his\n\
pointy ears show the markings of a strong family.\n");
   set_alias("warrior");
   set_level(20);
   set_hp(600);
   set_wc(35);
   set_ac(15);
   shroom->set_money(4500);
}

child(){
   set_short("A "+HIG+"child"+NORM+" nonge");
   set_long("\
His ears are slightly smaller then those of his elders.\n\
He puffs out his chest and tries to look important as he\n\
strolls along.  The eyes of this child are innocent and his\n\
markings have yet to take shape.\n");
   set_alias("child");
   set_level(14);
   set_hp(210);
   set_wc(20);
   set_ac(11);
}

wanderer(){
   set_short("A "+HIM+"wandering"+NORM+" nonge");
   set_long("\
This vagabond wanders the pathways of this mushroom grove\n\
without a care in the world.  His markings show he is of no\n\
family.  With his weathered pack he slowly travels the area.\n");
   set_alias("wanderer");
   set_level(20);
   set_hp(500);
   set_wc(30);
   set_ac(17);
   shroom->set_money(4000);
}

peasant(){
   set_short("A "+HIY+"peasant"+NORM+" nonge");
   set_long("\
Muscles bulge from this peasant.  He has worked many hard\n\
days and nights in the fields.  Ragged clothes he wears and his\n\
fur is unkempt.  What he lacks in markings he makes up in his own pride.\n");
   set_alias("peasant");
   set_level(19);
   set_hp(500);
   set_wc(35);
   set_ac(10);
   shroom->set_money(1500);
}

femme(){
   set_short("A "+HIR+"beautiful femme"+NORM+" nonge");
   set_long("\
She stands a foot lower then most of the male nonge.  \n\
Her eyes gleam in the light and her fur lays flat against her\n\
well developed figure.  Her markings are of a higher class which\n\
only adds to her enticing nature.\n");
   set_alias("femme");
   set_level(17);
   set_hp(425);
   set_wc(25);
   set_ac(13);
   shroom->set_money(500);
}

monarch(){
   set_short("A "+HIC+"monarch"+NORM+" nonge");
   set_long("\
This pompous fellow is of a higher class as can be seen\n\
by the black streaks of color running down his nose.  His ears\n\
are clean shaven so as to try to fit in with an elite group of \n\
nonge.  He is dressed in fine robes and holds his chin a little\n\
too high up.\n");
   set_alias("monarch");
   set_level(20);
   set_hp(625);
   set_wc(25);
   set_ac(17);
   shroom->set_money(4000);
}

heart_beat(){
   ::heart_beat();
   if(hit_point > 0)
   if(hit_point < ((max_hp*42)/100)){
      if(random(4) == 1){ enable_commands(); run_away(); }
   }
}
status monster_died() {
  "/players/wocket/mushrooms/nonge_tracker"->deregister_nonge();
  return 0;
}
