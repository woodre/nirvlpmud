inherit "/obj/monster";
#include "/players/beck/MortalKombat/MKQuestNPC.h"
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object ob;
 
  ob = clone_object("/players/snow/WEAPONS/greydeath.c");
move_object(ob,this_object());
 
     set_name("Sir Garl");
     set_short("Sir Garl");
     set_race("man");
     set_alias("garl");
     set_long(
"You are looking at one of the most feared ruffians in the \n" +
"land. Sir Garl's reputation for savagery and brutality is \n" +
"well merited. With his gang and magic sword, he has been \n" +
"untouchable so far. \n" +
"\tCan you rid Nirvana of this evil menace?\n");
     set_level(21);
     set_ac(22);
init_command("wield greydeath");
     set_wc(35);
     set_hp(600);
     set_heal(1,10);
     set_al(-1000);
     set_aggressive(1);
      set_dead_ob(this_object());
     set_chat_chance(10);
     set_a_chat_chance(10);
 
     load_chat("Sir Garl says: Look at all that gold, maties!\n");
     load_chat("Sir Garl fingers his sword.\n");
     load_chat("Sir Garl says: Have at 'em, boys!\n");
 
     load_a_chat("Sir Garl says: Throw down your weapons and I'll let you live.\n");
     load_a_chat("Sir Garl easily evades your puny attacks.\n");
     load_a_chat("Sir Garl boasts: None have ever bested me!\n");
set_chance(20);
set_spell_mess1("Sir Garl's sword explodes into his foe!\n");
set_spell_mess2("Sir Garl's sword slices into your body with explosive force!\n");
set_spell_dam(35);
  money = random(2000)+3000;
  move_object(clone_object("/players/dragnar/MKScar/scar"),this_object());
   }
}
 
monster_died() {
  write_file("/players/snow/closed/q/mon", ctime(time())+
    query_attack()->query_real_name()+" killed Sir Garl.\n");
  return 0; }
