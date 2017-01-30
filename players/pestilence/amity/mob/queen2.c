/* Assistance code provided by Jaraxle, Jenny */
#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
object leg, leg1, leg2, leg3;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
          leg=clone_object("/players/pestilence/amity/wep/leg2.c"),
        move_object(leg, this_object());
		        leg1=clone_object("/players/pestilence/amity/wep/leg2.c"),
        move_object(leg1, this_object());
		        leg2=clone_object("/players/pestilence/amity/wep/leg2.c"),
        move_object(leg2, this_object());
		        leg3=clone_object("/players/pestilence/amity/wep/leg2.c"),
        move_object(leg3, this_object());
		leg1->offwield( this_object() );
		leg2->offwield( this_object() );
		leg3->offwield( this_object() );
  set_name(""+HIY+"Queen Ant"+NORM+""); 
  set_alt_name("queen");
  set_alias("queen ant");
  set_short(""+HIY+"The Queen Ant"+NORM+"");
  set_long("This is the "+HIY+"Queen Ant"+NORM+".  She is twice the size of the other ants.\n"+
           "She is very large and black with 6 extremely dangerous legs.\n");
  set_race("ant");
  set_gender("female");
  set_level(25);
  set_wc(46);
  set_ac(22+random(4));
  set_hp(950+random(200));
  set_ac_bonus(8);
  set_wc_bonus(94);
  set_heal(5,5);
  set_hp_bonus(150);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-700);
  load_chat("The "+HIY+"Queen Ant"+NORM+" circles around you.\n");
  set_chat_chance(20);
  load_a_chat(""+HIY+"Queen Ant"+NORM+" throws you to the ground causing much pain.\n");
  load_a_chat("A leg impales you leaving "+RED+"blood"+NORM+" dripping.\n");
  set_a_chat_chance(30);
add_spell("gouge",
"#MN#  gouges you, spewing your $HR$flesh and blood$N$ allover.\n",
"#MN# gouges #TN#, out, spewing #TN#'s $HR$flesh and blood$N$ allover.\n",
 15,60,"physical",6);
add_spell("frenzy",
"#MN# goes into an insane frenzy, unleashing $HR$P A I N$N$ into your body.\n",
"#MN# goes into an insane frenzy, unleashing $HR$P A I N$N$ into #TN#'s body.\n",
 40,200,"other|evil",3);

}

id(str) { return (::id(str) || str == "insect"); }
init() {
  ::init();
add_action("stop","jump");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("The "+HIY+"Queen Ant"+NORM+" grabs you, and screams: STAY AWAY FROM THERE.\n");
return 1; }
}


monster_died() {
if(leg) destruct(leg); 
  if(leg1) destruct(leg1);
if(leg2) destruct(leg2);
  if(leg3) destruct(leg3);

  move_object(clone_object("/players/pestilence/amity/wep/leg.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As the queen falls to the ground one of her legs breaks off.\n");
write_file("/players/pestilence/amity/log",""+attacker_ob->query_real_name()+" "+attacker_ob->query_level()+"+"+attacker_ob->query_extra_level()+" killed the queen -> "+ctime()+"\n");
return 0; }



flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say("The "+HIY+"Queen "+RED+"tears into"+NORM+" "+ATT_NAME+", spewing "+HIR+"blood"+NORM+" all over.\n");
       tell_object(attacker_ob,
"The "+HIY+"Queen "+RED+"tears into"+NORM+" you, spewing "+HIR+"blood"+NORM+" all over.\n");
if(attacker_ob->query_npc())
attacker_ob->heal_self(-random(80));
else
attacker_ob->add_hit_point(-random(80));
}

flesh_impale(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say("The "+HIY+"Queen Ant"+NORM+" impales "+ATT_NAME+" with one of her legs.\n");
       tell_object(attacker_ob,
"The "+HIY+"Queen Ant"+NORM+" impales you with one of her legs.\n");
if(attacker_ob->query_npc())
attacker_ob->heal_self(-50-random(50));
else
attacker_ob->add_hit_point(-50-random(50));
}

mass_attack() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say(""+HIY+"A leg from the queen grazes "+ATT_NAME+" on the arm"+NORM+".\n"+
        ""+HIR+"A leg from the queen evicerates "+ATT_NAME+""+NORM+".\n"+
        ""+HIY+"The Queen bites into "+ATT_NAME+", leaving a large "+RED+"gash"+NORM+".\n");
       tell_object(attacker_ob,
        ""+HIY+"A leg from the queen grazes you on the arm"+NORM+".\n"+
        ""+HIR+"A leg from the queen evicerates you"+NORM+".\n"+
        ""+HIY+"The Queen bites into you, leaving a large "+RED+"gash"+NORM+".\n");
if(attacker_ob->query_npc())
attacker_ob->heal_self(-50-random(50));
else
attacker_ob->add_hit_point(-50-random(50));
}

flesh_heal() {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    say(""+HIY+"The Queen feeds off of "+ATT_NAME+"'s flesh, healing her slightly.\n");
       tell_object(attacker_ob,
""+HIY+"The Queen feeds off of your flesh, healing her slightly.\n");
heal_self(20+random(15));
if(attacker_ob->query_npc())
attacker_ob->heal_self(-random(40));
else
attacker_ob->add_hit_point(-random(40));
}


heart_beat(){
int i,z,a;
  ::heart_beat();
if(attacker_ob && present(attacker_ob,environment(this_object()))){
z = 2;
for(a=0;a<z;a++){
    already_fight = 0;
    this_object()->attack(attacker_ob);
if(attacker_ob){
i = random(45);
switch(i){


    case 0..3: flesh_tear();
  break;

    case 4..6: flesh_impale();
  break;

    case 7..9: flesh_heal();
  break;

    case 10..14: mass_attack();
  break;

    case 15..44: return 0;
  break;
    }
  }
}
}
}
