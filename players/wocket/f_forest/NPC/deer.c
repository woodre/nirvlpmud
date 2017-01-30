#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

int heals;
reset(arg){
::reset();  
  if(arg) return;
  set_name("deer");
  switch(random(3)){
    case 0:  fawn(); break;
    case 1: buck(); break;
    case 2: doe(); break;
  }
  set_dead_ob(this_object());
}

fawn(){
  set_alt_name("fawn");
  set_short("A fawn");
  set_long("This is a small baby deer.  There doesnt look like there is enough\n"+
     "meat on it's hide to be worth killing.\n");
    set_level(5);
    set_hp(75);
    set_wc(9);
    set_ac(4);
    heals = 0;
}

buck(){
  set_alt_name("buck");
  set_short("A buck");
  set_long("This is a large male deer.  There seems to be a ton of meat on him\n"+
           "to be worth chasing and killing.\n");
  set_level(14);
  set_hp(210);
  set_ac(30);
  set_ac(9);
  heals = 2;
}

doe(){
  set_alt_name("doe");
  set_short("A doe");
  set_long("This is a delecate female deer.  There is a bit of meat hidden underneath\n"+
           "her skin that one might kill for it.\n");
  set_level(13);
  set_hp(195);
  set_ac(20);
  set_ac(10);
  heals = 1;
}

monster_died(){
object corpse;
  if(present("corpse",environment(this_object())))
    destruct(present("corpse",environment(this_object())));
  corpse = clone_object("/players/wocket/f_forest/OBJ/deer_corpse.c");
  corpse->set_ammount(heals);
  move_object(corpse,environment(this_object()));
return 1;
}

heart_beat(){
  ::heart_beat();
  if(attacker_ob && random(3) && environment(attacker_ob) == environment(this_object())){
    run_away();
  }
}

