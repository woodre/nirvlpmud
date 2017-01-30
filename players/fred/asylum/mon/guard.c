inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#define attacked this_object()->query_attack()
string A;
int a;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  a = random(3);
  switch(a){
    case 0: A = "stabbed"; break;
    case 1: A = "burned"; break;
    case 2: A = "bloody"; break; }  
  
  set_name("guard");
  set_race("spirit");
  set_short("Asylum Guard ("+BOLD+GRN+A+NORM+")");
  set_long(
    "  A grossly disfigured ghost of one of the many guards\n"+
    "that used to patrol the halls of the asylum. Most were\n"+
    "killed by patients in cruel inhumane ways. Some of the \n"+
    "luckier ones were burned alive or stabbed to death.\n");
  
  set_level(16);
  set_al(-(random(200)));
  set_ac(13);
  set_wc(22);
  set_hp(300+(-(this_object()->query_alignment())));
  set_gender("male");
  set_dead_ob(this_object());
  set_aggressive(0);
  set_chat_chance(5);
   load_chat("The guard shuffles slowly down the hall...\n");
   load_chat("The guard lets out a pitiful wail...\n");
  }
  
  monster_died(){
   object corpse;
   corpse = present("corpse", environment());
   tell_object(attacked,
     "\n  The "+A+" guard's spirit drifts away with the blow of your final attack.\n\n");
   
     if(A == "stabbed"){
       move_object(clone_object("/players/fred/asylum/obj/baton.c"),
       environment(this_object())); }
     else if(A == "burned"){
       move_object(clone_object("/players/fred/asylum/obj/maglight.c"),
       environment(this_object())); }
     else {
       move_object(clone_object("/players/fred/asylum/obj/baton.c"),
       environment(this_object())); }
     if(corpse)
       destruct(corpse);
       return 1;  
   }
