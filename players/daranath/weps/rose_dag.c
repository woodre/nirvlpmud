#include <ansi.h>
#define tp this_player()
#define tpn tp->query_name()

int charges;

inherit "/obj/weapon.c";

reset(arg){
  ::reset(arg);
  if(arg) return;

  charges=5;

  set_name("dagger");
  set_alias("rose");
  set_alt_name("rose dagger");
  set_short("A rose hilted dagger");
  set_long("A short, sharp blade with a rose cut into the hilt of the\n"+
           "weapon, the rose hilted dagger is an item of extreme beauty.\n");
  set_class(18);
  set_weight(1);
  set_value(1250);
  set_hit_func(this_object());

  }

  query_save_flag(){return 0;}
  /* return 1 no save */

  weapon_hit(attacker){

  if(random(3)==0){
     write("You slash at your foe with the rose-hilted blade.\n");
     say(tpn +" slashes wickedly with the rose hilted dagger.\n");
    return 7; }
    return 0;
  }

  init() {
    ::init();
    add_action("hurl","hurl_dagger",4);
    add_action("blast","blast");
    /* add_action("hurl"); add_xverb("hurl"); */
  }

  hurl(){
    /* if(tp->query_attack()){ */
    write("You hurl the dagger at your opponent, imbedding it deeply.\n"+
          "The dagger magical returns to your grasp.\n");
    say(tpn+" hurls");
    (tp->query_attack())->hit_player(50);
    return 1;
  }

  blast(str){
    object target;
    if (charges<1){
    write("There are no more charges.\n");
    return 1;
    }
    target=present(str,environment(tp));
    if(!target){
    write("That is not the fucking target!!!\n");
    return 1;
    }
    charges--;
    if(living(target) && target->query_npc()){
    write("           "+HIY+"SONIC BOOM!!!!"+NORM+"   \n");
    say(tpn+" blast the target, wee...\n");
    /* tell_room(environment(this_player()),"boom!!!"); */
    return 1;
    }
    write("hah hah Mas is teasing you...\n");
    return 1;
  }










  


