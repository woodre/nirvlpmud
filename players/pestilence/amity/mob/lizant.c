/* Assistance code provided by Jaraxle, Jenny */
#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TP this_player()
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name(""+HIG+"Lizant"+NORM+"");
  set_alias("lizant");
  set_short(""+HIG+"Lizant"+NORM+"");
  set_long("This is a mutated form of an ant.  It has the thorax and metasoma of an ant but\n"+
           "the top part is torso and head of a woman.\n");
  set_race("mutant");
  set_gender("female");
  set_level(20);
  set_wc(28+random(5));
  set_ac(15+random(6));
  set_hp(500);
  set_heal(3,3);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-700);
  load_chat("Lizant winks at you.\n");
  set_chat_chance(20);
  load_a_chat(""+HIG+"Lizant throws you to the ground"+NORM+".\n");
  load_a_chat(""+HIG+"Lizant snarls and growls"+NORM+".\n");
  set_a_chat_chance(30);
  set_spell_mess2(""+RED+"Lizant digs her nails into your face"+NORM+".\n");
  set_spell_mess1(""+RED+"Lizant digs her nails into her attacker"+NORM+".\n");
  set_chance(20);
  set_spell_dam(25);
}

id(str) { return (::id(str) || str == "insect"); }

init() {
  ::init();
add_action("stop","west");
}
stop() {
if(TP->query_ghost() == 1) { return 0; }
else{
write("Lizant throws you back to the ground, not allowing you to leave.\n");

return 1; }
}


monster_died() {
  move_object(clone_object("/players/pestilence/amity/obj/thorax.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As Lizant hits the ground, the thorax becomes unattached from her body.\n");
return 0; }




flesh_tear(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say("Lizant "+RED+"tears into "+ATT_NAME+"'s flesh"+NORM+" spewing "+HIR+"blood"+NORM+" all over.\n");
       tell_object(attacker_ob,
"Lizant "+RED+"tears into your flesh"+NORM+" spewing "+HIR+"blood"+NORM+" all over.\n");
    attacker_ob->add_hit_point(-random(80));
}

ant_heal(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say(""+HIB+"Lizant rips a piece of"+HIR+" "+ATT_NAME+"'s flesh and shoves it into her mouth healing her slightly"+NORM+".\n");
       tell_object(attacker_ob,
""+HIB+"Lizant rips a piece of"+HIR+" your flesh and shoves it into her mouth healing her slightly"+NORM+".\n");
      heal_self(20+random(30));
}

heart_beat(){
int i;
  ::heart_beat();
if(attacker_ob){
i = random(10);
switch(i){
    case 0..1: flesh_tear();
  break;

    case 2..3: ant_heal();
  break;
    
    case 4..9: return 0;
  break;

    }
  }
}
