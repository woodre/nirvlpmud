inherit "/obj/monster";
#include "/players/jareel/define.h"

int M;
int dagger;
reset(arg) {
   ::reset(arg);

 if (arg) return;
    set_name("gerak");
    set_race("troll");
    set_alias("kag");
    set_alias("lord");
    set_al(0);
    set_level(20);
    set_aggressive(0);
    set_hp(500);

MOCO("/players/jareel/weapons/chaos/dagger_darkness.c"),this_object());
dagger = present("dagger",this_object());
dagger->set_short(BOLD+BLK+"Dagger"+NORM+" of "+BOLD+BLK+"Darkness "+NORM+BOLD+"[ "+BLK+"Swirling Darkness"+NORM+BOLD+" ]"+NORM);
init_command("wield dagger");
    set_ac(17);
    set_wc(30);
    set_gender("male");
    set_dead_ob(this_object());

set_short(
     "Gerak Kag - "+BOLD+BLK+"Zorak Zoran"+NORM+" Death Lord. (neutral)");

set_long(
     "Mondar is an old wrinkled man.  Having seen many\n"+
     "years of battles, his silver-white hair and scar \n"+
     "ridden body prove he is not someone to mess with.\n"+
     "A small lump rises in the back of your throat as\n"+
     "he catches you looking at him.\n");

}
heart_beat(){
         ::heart_beat();
               if(attacker_ob) {
         M = random(10);
             if(attacker_ob){
             if(M == 6) M_allied();
             if(M == 7) M_bladesharp();
}
}
}


M_bladesharp() {
tell_room(environment(TO),
 "Gerak Kag casts a bladesharp spell over his dagger.\n"+
 "\n"+
 ""+BLINK+CYN+" E N E R G Y "+NORM+" flows over the blade.\n"+
 "\n");
call_other(attacker_ob,"hit_player",random(15)+5);
return;
}

M_allied()  {
tell_room(environment(TO),
  "Gerak Kag summons a spirit from his dagger.\n"+
  ""+BOLD+"\n"+
  "        An enraged Spirit slashes at "+attacker_ob->query_name()+".\n"+
  ""+NORM+"\n");
call_other(attacker_ob,"hit_player",random(50));
return;
}

monster_died() {
dagger->reset();
return 0;}
