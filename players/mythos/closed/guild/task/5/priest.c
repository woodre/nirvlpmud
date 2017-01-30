#include "/players/mythos/closed/guild/def.h"
object targ;
int oo, a1, a2, a3, mk;
inherit "players/mythos/closed/guild/spells/monster2";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("cardiou");
  set_short("A small man");
  set_alias("priest");
  set_race("man");
  set_long("A small man.  He is dressed in a long flowing\n"+
           "robe.  And he carries a small wand.  Power seems\n"+
           "to flow from him and you tremble at his gaze.\n");
  set_hp(3000);
  set_level(30);
  set_al(0);
  set_wc(60);
  set_ac(20);
  set_aggressive(0);
  set_heal(20,5);
  set_dead_ob(this_object());
  set_chat_chance(3);
  set_a_chat_chance(15);
  load_chat("The wind blows...\n");
  load_chat("Time seems endless...\n");
  set_chance(25);
  set_spell_dam(100);
  set_spell_mess1("Mist gathers.\n");
  set_spell_mess2("\nYou feel great pain as Cariou lashes out with coldfire!\n");
  set_mult(3);
  set_mult_chance(90);
  set_mult_dam1(20);
  set_mult_dam2(50);
  oo = a1 = a2 = a3 = mk = 0;
}

monster_died() {
   move_object(this_object()->query_attack(),"/players/mythos/mroom/masakado.c");
   environment(this_object())->over();
return 0;
}

init() {
  ::init();
  add_action("ask","ask");
  add_action("Aanswer","answer");
}

ask() {
if(!oo) {
  write("The small man nods at you and speaks:\n"+
        "          I am Cardiou the Souless, one of your founders.\n"+
        "          I am here to test you and if I find you wanting\n"+
        "          then I am to kill you.  I shall show no mercy.\n"+
        "          So, first I shall ask you a set of three questions.\n"+
        "          You only get one chance for each question.\n");
 targ = tp;
 oo = 1;
 call_out("ask2",6); }
return 1;
}

ask2() {
   tell_object(targ,"Cardiou speaks:\n"+
                    "      The Sakura is beautiful.\n"+
                    "      The leasves are red and the ground seems to groan.\n"+
                    "      What is hidden beneith?\n");
   tell_object(targ,"type <answer 1> <your answer>\n");
return 1;}

Aanswer(str) {
int num;
string ans;
object tree;
  tree = present("sakura",environment(this_object()));
  if(!str) return 0;
  if(sscanf(str,"%d %s",num,ans) != 2) return 0;
  if(num != 1 && num != 2 && num != 3) return 0;
  if(num == 1) {
    if(ans == "a corpse" || ans == "corpse" || ans == "A corpse") {
    tree->set_quest1();
    mk = 1;
    }
    tell_object(targ,"Cardiou nods and speaks:\n"+
                     "       What is to keep the tree alive?\n");
    tell_object(targ,"type <answer 2> <your answer>\n");
    return 1;}
    if(num == 2) {
    if(ans == "knowledge" || str == "Knowledge") {
    tree->set_quest2();
    mk = 1;
    }
    tell_object(targ,"Cardiou nods and speaks:\n"+
       "     What was Star?\n");
    tell_object(targ,"type <answer 3> <your answer>\n");
    return 1;}
    if(num == 3) {
  if(ans == "a bard" || ans == "bard" || ans == "a Bard" || ans == "Bard") {
    tree->set_quest3();
    mk = 1;
    }
    if(!mk) { 
    tell_object(targ,"Cardiou nods and speaks:\n"+
                     "       You have not answered any correct!\n"+
                     "He gestures.\n");
    this_object()->zap_object(targ);
    return 1;}
    tell_object(targ,"Cardiou nods and speaks:\n"+
                     "       Now find what is below...\n");
     return 1;}
return 1;}
