#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
object shroom; 
 ::reset(arg);
  if(arg) return;
shroom = clone_object("/players/wocket/mushrooms/shroom.c");
shroom->set_money(5000);
move_object(shroom,this_object());
set_name("nonge");
set_short("A "+MAG+"dark"+NORM+" nonge");
set_long("Covered in black robes, little of this nonges fur can be seen.  Hidden\n"+
         "in the darkness for many generations his eyes glow a dull yellow.  Sashes\n"+
          "hang from his neck decorated with many ancient symbols.  His paws sparkle\n"+
         "with electricity.\n");
set_alias("darknonge");
set_level(20);
set_hp(500);
set_wc(30);
set_ac(17);
set_al(-1000);
/* autoattack */
ac_bonus += 3;
/* lightblast attack */
wc_bonus += (60*4)/12;
}

init(){
::init();
add_action("attackme");add_xverb("");
}

attackme(){
if(!attacker_ob && random(20) == 1){
if(this_player()->is_player()){
  tell_object(this_player(),"Nonge notices you and attacks.\n");
attacker_ob = this_player();
}
}
return 0;
}

lightblast(){
say(BLU+"Blue engery crackles between the hands of this dark nonge.\n"+
    "A blast of light "+HIB+"FLASHES"+NORM+BLU+" as "+attacker_ob->query_name()+" is knocked to the ground.\n"+NORM);
attacker_ob->add_hit_point(-50-random(20));
}

peace(){
object *ob;
int i,size;
ob = all_inventory(environment(this_object()));
for(i=0,size=sizeof(ob);i<size;i++){
  if(ob[i]->query_attack()){
    ob[i]->query_attack()->stop_fight();
    ob[i]->stop_fight();
}
}
say(HIM+"A magenta light hazes from the dark nonge and all the fighting stops.\n"+NORM);
say("->>");
}

heal(){
say(CYN+"The dark nonge is enveloped with a cyan light.\n"+
      "It's wounds "+HIC+"HEAL"+NORM+CYN+" themselves before your eyes.\n"+NORM);
hp_bonus += 50;
this_object()->heal_self(50);
}

failing(){
    say("Power radiates from the dark nonge then sizzles.\n");
}
heart_beat(){
int i;
  ::heart_beat();
if(attacker_ob){
i = random(12);
switch(i){
case 0:  lightblast();
break;
case 1:  peace();
break;
case 2:  heal();
break;
case 3:  failing();
break;
case 4:  lightblast();
break;
case 5:  lightblast();
break;
case 6:  lightblast();
break;
case 7:  failing();
break;
case 8:  heal();
break;
case 9:  failing();
break;
case 10: failing();
break;
case 11: failing();

}}
}
