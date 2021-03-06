#include "/sys/lib.h"
#include "/players/pestilence/ansi.h"
inherit "/players/vertebraker/closed/std/monster";
#define TPN this_player()->query_name()
#define TPP this_player()->query_possessive()
#define attacker attacker_ob
int i;
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
/*
  move_object(clone_object("/players/pestilence/CONTARMY/rustysword.c"),
        this_object());
  command("wield");
  move_object(clone_object("/players/pestilence/CONTARMY/rustyshield.c"),
        this_object());
  command("wear shield");
*/
  set_name(""+HIW+"Skeletal Warrior"+NORM+""); 
  set_alt_name("skeletal warrior");
  set_alias("warrior");
  set_short(""+HIW+"a Skeletal Warrior"+NORM+"");
  set_long("This is a skeleton warrior.  The body is of what appears to be\n"+
           "the skeleton of a human.  The bones are a grey in color.  This\n"+
           "warrior appears to be in a very bad mood.  There seems to be a\n"+
           "magic that holds the bones together, keeping the warrior alive\n");
  set_race("undead");
  set_gender("male");
  set_level(4);
  set_wc(7+random(4));
  set_ac(3+random(2));
  set_hp(60+random(20));
  set_ac_bonus(0);
  set_wc_bonus(3);
  set_heal(1,15);
  add_money(0);
  set_aggressive(0);
  set_dead_ob(this_object());
  set_al(-700);
  load_chat(""+HIW+"The Skeletal Warrior looks at you with disgust"+NORM+".\n");
  load_chat(""+HIW+"The Skeletal Warrior growls fiercely"+NORM+".\n");
  set_chat_chance(20);
  load_a_chat("The "+HIW+"Skeletal Warrior"+NORM+" swings his sword, just missing you.\n");
  set_a_chat_chance(20);
  set_spell_mess2("The "+HIW+"Skeletal Warrior"+NORM+" slices you across your arm.\n");
  set_spell_mess1("The "+HIW+"Skeletal Warrior"+NORM+" slices his attacker across the arm.\n");
  set_chance(15);
  set_spell_dam(5);
/*
add_spell("magic missile",
"#MN# waves #MP# hand, and several $M$magic missiles$N$\n speed toward you.#RET#"+
"#MN# waves #MP# hand, and another $M$magic missile$N$\n speeds toward you.\n",
"#MN# waves #MP# hand, and several $M$magic missiles$N$ speed toward #TN#.\n",
40,({6,6,6,6,6}),({"magic","magic","magic","magic","magic"}),3);
*/
add_spell("flesh",
"#MN# waves #MP# hand, and several $M$magic missiles$N$\n speed toward you.#RET#"+
"#MN# waves #MP# hand, and another $M$magic missile$N$\n speeds toward you.\n",
"#MN# waves #MP# hand, and several $M$magic missiles$N$ speed toward #TN#.\n",
80,0,0,0, "flesh_tear" );
}

id(str) { return (::id(str) || str == "skeleton" || str == "skeletal"); }


monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  tell_room(environment(this_object()),
        "As the "+HIW+"Skeletal Warrior"+NORM+" hits the ground, the magic holding the bones together.\n"+
        "ceases to exist, causing the bones smash into dust.\n");
/*
  move_object(clone_object("/players/pestilence/CONTARMY/bdust.c"),
      environment(this_object()));
*/
 if(corpse)
    destruct(corpse);
return 0; }



flesh_tear( object target, object room, int damage ) {

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 
    say("The "+HIW+"Skeletal Warrior"+NORM+"\n\n"+HIR+"         D  E  V  A  S  T  A  T  E  S"+NORM+"\n\n"+ATT_NAME+" with a solid blow.\n");
attacker_ob->hit_player(random(10), "other|dark");
heal_self(100+random(15));



}



/*
heart_beat(){
 ::heart_beat();

if(attacker_ob){
i = random(20);
switch(i){


    case 0..5: flesh_tear();
  break;

    case 6..20: return 0;
  break;

    }
  }
}
*/
