inherit "obj/monster.c";
#include "/players/jareel/define.h"

int stuff;

reset(arg)  {
  stuff = random(4);
    ::reset(arg);
      if(arg) return;

  set_name("blood demon");
  set_race("chaos");
  set_alt_name("blood");
  set_alias("demon");

  set_short(HIR+"Blood Demon"+NORM);
  set_long(
          HIR+"The demon is an enormous writhing mass, formed out of ropy\n"+
          "blood red tentacles.  Here and there, the demon's surface is \n"+
          "covered with great hungry mouths dripping a vile green acidic\n"+
          "substance.  The demon sprawls over the floor on it's slime  \n"+
          "covered tentacles.  Your soul screams in terror as you look\n"+
          "at it.\n"+NORM);

  set_al(-1000);
  set_level(22);
  set_wc(90);
  set_ac(5);
  set_heal(10,1);
  set_hp(600);
  set_res(10);
  set_ac_bonus(10);

  add_money(2000+random(4000));
  set_armor_params("other|light",0,-30,0); /* +30 damage from light */
  set_armor_params("other|dark",0,30,0); /* -30 damage from dark */
  set_armor_params("magical",0,30,0); /* -30 damage from Magical */
  set_armor_params("other|good",0,-30,0); /* -10 damage from dark */
  
  if(stuff == 0) { 
    MOCO("/players/jareel/heals/stone.c"),this_object());
  }

  if(stuff == 1) { 
    MOCO("/players/jareel/heals/stone.c"),this_object());
  }

  if(stuff == 2) { 
    MOCO("/players/jareel/heals/stone.c"),this_object());
  }  

  if(stuff == 3) { 
    MOCO("/players/jareel/general_stuff/demonhide.c"),this_object());
  }   
   
  set_dead_ob(this_object());
  
  add_spell(
    "Tenticle Whip",
	  "\n\The demon whips its tentacles striking you.\n",
	  "The demon whips its tentacles striking #TN#.\n",
    30,"10-20+30","other|evil", 1);
  }

  init() {
    ::init();
      add_action("nogo","west");
      add_action("nogo","east");
      add_action("nogo","south");
      add_action("nogo","north");

  }

  heart_beat(){
    object ob;
    object att;
    object next;
      if(!environment()) return;
      if(ob = present("chaos", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
    ::heart_beat();
  }

  nogo() {
    write("Demon blocks your path.\n");
  return 1;
  }

  prot_from_light(){  /* -10 resistance */
    write(BYEL+"Intense light sears the demons flesh.\n"+NORM);
  return 1;
  }

  prot_from_dark(){   /* 10 resistance */
    write(HIK+"Darkness is absorbed by the demon.\n"+NORM);
  return 1;
  }
  corpse_loop()    {
    object ob;
      if((ob = present("corpse", environment())) && (int)ob->is_corpse()) {
        tell_room(environment(),
          "Demon takes: "+(string)ob->short()+".\n");
             move_object(ob, this_object());
    corpse_loop();
  }
}

  catch_tell(str){
    string name,dir;
    if(this_player() && this_player()->is_player())
      if(sscanf(str,"%s leaves %s.",name,dir) == 2){
        if(attacker_ob){
          if(name = attacker_ob->query_name()){
            if(random(4)==1){
              tell_object(attacker_ob,"Demon anticipates your move.\n");
                command(dir);
                  } } } } }

  attackme(){
    if(!attacker_ob && random(2) == 1){
      if(this_player()->is_player()){
        tell_object(this_player(),"Demon notices you and attacks.\n");
          attacker_ob = this_player();
        }
    }
    return 0;
}

