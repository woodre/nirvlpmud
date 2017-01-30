#define tp this_player()->query_name()
#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/amon/forest/monster1";
reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("hinotori");
  set_alias("firebird");
  set_race("spirit");
  set_short("The Spirit of the Firebird- Hinotori");
  set_long(RED+"The Great Spirit of Nature's Raw Power flies above you.\n"+
       NORM+"Feathers of rainbow colors and ruby eyes. The bird's beauty\n"+
            "is breathtaking.  It cocks its head at you and stares into\n"+
            "your eyes...  You feel helpless and small.  You recall an\n"+
            "interesting legend about the Hinotori- one who drinks of its\n"+
            "blood will live again...  perhaps gain immortality.\n");
  set_hp(2000);
  set_level(30);
  set_al(0);
  set_wc(40);
  set_ac(23);
  set_heal(10,15);
  set_aggressive(1);
  set_can_kill(1);
  set_pet_command();
  set_dead_ob(this_object());
  set_chat_chance(10);
  set_a_chat_chance(15);
  load_chat("The Hinotori soars above- you stand in awe at its beauty.\n");
  load_chat("The Firebird begins to sing a song of pureest music.\n");
  load_a_chat("The Firebird swoops down and attacks with its deady claws.\n");
  load_a_chat("Firey wings beat at you, burning you!\n");
  set_chance(50);
  set_spell_dam(150);
  set_spell_mess1("The Firebird screams aloud!  \n"+
                   "You feel great pain as your eardrums shatter!\n");
  set_spell_mess2("The Firebird screams aloud!  \n"+
                    "You feel great pain as your eardrums shatter!\n");
  set_mass_chance(45);
  set_mass_dam(100);
  set_mass_spell(HIR+"\n\tThe Firebird EXPLODES!\n\n"+NORM+
       "You "+BOLD+"SCREAM"+NORM+" in pain as fire spears through you!\n\n");  
  set_pet_cmd1("The Firebird glares at its little followers!\n");   
  set_pet_cmd2("The Hinotori commands its followers!\n");
  set_mult(5);
  set_mult_dam1(10);
  set_mult_dam2(40);
  set_mult_chance(75);
  set_light(15);
  call_out("fun",10);
}

monster_died() {
object ob, ob2, laff;
      laff=first_inventory(environment(this_object()));
      tell_room(environment(this_object()),
      "The Hinotori suddenly bursts into a ball of pure light and heat!\n\n"+
   HIR+"\t\t*     B  L  A  S  T     *\n\n"+NORM+"Then there is nothing...\n");
      while(laff) {
      	if(living(laff) && laff->query_ghost() !=1 && 
      	laff->query_name() != this_object()->query_name()) {
      		call_other(laff,"hit_player",random(100)+50);
      	}
      	laff=next_inventory(laff);
      	laff;
      }
  ob=clone_object("/players/mythos/amisc/forest/vial.c");
  move_object(ob,this_object());
  ob2=clone_object("/players/mythos/amisc/forest/feather.c");
  move_object(ob2,this_object());
/*
  write_file("/players/mythos/logs/ob",ctime(time())+"\t"+
      (this_object()->query_attack())->query_real_name()+"\t\t"+
      (this_object()->query_attack())->query_level()+"\thi\n");
*/
  return 0;
    } 
#include "/players/mythos/amon/hb_ag.h"

fun() {
  if(!environment(this_object())) return 1;
  heal_self(random(30));
call_out("fun",random(10)+3);
return 1; }
