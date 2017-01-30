inherit "/obj/monster.c";
#include <ansi.h>
#define tpn this_player()->query_name()
#define attacked this_object()->query_attack()
#define att attacker_ob->query_name()
object gloves, robe, key;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("Dr. Meyers");
  set_alias("meyers");
  set_race("spirit");
  set_short("Dr. Meyers");
  set_long(
    "  A ghostly form that used to be Dr. Clarence F. Meyers.\n"+
    "A short balding doctor that used to be the chief operator\n"+
    "in charge of administering the electroshock treatments.\n");
  
  set_level(18);
  set_al(-(random(500)));
  set_ac(14+random(4));
  set_hp((this_object()->query_ac())*35);
  set_wc(26);
  set_gender("male");
  set_heal(3,1);
  set_aggressive(0);
  set_chat_chance(5);
   load_chat("Dr. Meyers carefully checks over the electroshock therapy table.\n");
   load_chat("Dr. Meyers looks around impatiently and yells: NEXT!\n");
   load_chat("Dr. Meyers gazes up at you and smiles evilly.\n");
  set_chance(20);
  set_spell_dam(20);
  set_spell_mess1(
    "\nDr. Meyers "+HIB+"S H O C K S "+NORM+"his attacker with two large cables!\n");
  set_spell_mess2(
    "\nYour body is filled with"+HIY+" ELECTRICITY"+NORM+" as Dr. Meyers hits you with two large cables!\n");
  set_dead_ob(this_object());
  }

monster_died(){
  object corpse;
  corpse = present("corpse", environment());
  tell_object(attacked,
  "\nAs Dr. Meyers"+BOLD+" vanishes"+NORM+" some of his belongings fall to the floor.\n");
  move_object(clone_object("/players/fred/asylum/obj/rgloves.c"),
  environment(this_object())); 
  move_object(clone_object("/players/fred/asylum/obj/robe.c"),
  environment(this_object()));
  if(corpse)
    destruct(corpse);
  return 1; }

crap(){
  object freak;
  if(!environment()) return;
    freak = first_inventory(environment(this_object()));
  if(!environment(this_object())) return;
  if(this_object()->query_attack()){
    tell_room(environment(this_object()),
       "\nThe electroshock table starts to"+HIY+" spark"+NORM+" and releases energy into the room!\n\n"+  
       BOLD+HIB+"     *      *      *         *      *       *    *     "+NORM+"\n"+
           BOLD+"       *       *        *      *         *          *  "+NORM+"\n");
       tell_room(environment(this_object()),
       BOLD+HIY+"          *       *        *        *      *     *     "+NORM+"\n"+
       BOLD+GRN+"     *       *         *       *      *       *       *"+NORM+"\n");
       tell_room(environment(this_object()),
       BOLD+RED+"       *        *        *      *      *           *   "+NORM+"\n"+
       BOLD+MAG+"         *          *        *      *      *    *    * "+NORM+"\n");

  while(freak) {
   if(freak->query_name() != "Dr. Meyers") {
     if(freak->is_player()){
       tell_room(environment(this_object()),
       freak->query_name()+" writhes in pain!\n"); 
       freak->add_hit_point(-(15+random(10)));
       freak->add_spell_point(-(10+random(5)));
      }
     }
   freak = next_inventory(freak);
    }
   }
  }

heart_beat(){  
  int nut;
  nut = random(20);
  ::heart_beat();
  if(!environment())
    return;
  if(!attacker_ob)
    return;
  if(nut < 3)
    crap();
  }
 
 
