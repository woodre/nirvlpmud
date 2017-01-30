inherit "/obj/monster.c";
#include <ansi.h>
#include "/players/fred/defines.h"
string col;
int q;

reset(arg) {
  ::reset(arg);
  if(arg) return;
   
  q = random(3);
   switch(q){
    case 0: col = "grey"; break;
    case 1: col = "white"; break;
    case 2: col = "brown"; break; }
      
  set_name("rat");
  set_race("critter");
  set_short("A "+col+" rat");
  set_long(
    "  A large "+col+" rat with beady little "+RED+"eyes"+NORM+" that\n"+
    "has made this place his home after its years of abandonment.\n");
  set_level(8);
  set_al(-(random(500)));
  set_ac(7);
  set_wc(12);
  set_hp(100+((this_object()->query_level() * q)));
  set_gender("male");
  set_dead_ob(this_object());
  set_aggressive(0);
  set_chat_chance(5);
   load_chat("The "+col+" rat scurries over your feet...\n");
   load_chat("The "+col+" rat makes some squeaking noises...\n");
   load_chat("The "+col+" rat races between your legs...\n");
  }
  
  monster_died(){
   move_object(clone_object("/players/fred/asylum/obj/rskin.c"),
   environment(this_object())); 
   return 1;  
  }
