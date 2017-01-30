inherit "obj/monster.c";
#include <ansi.h>

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
set_name("dragon");
set_alias("king");
set_alt_name("mortankoria");
set_race("dragon");
set_short(BOLD+"Mortankoria, King of the "+HIG+"Green "+NORM+GRN+"Dragons"+NORM);
set_long(
"This is large and vicious looking dragon with power pouring\n\
from him. This is no doubt the King of the Green Dragon clan.\n\
Even with all of his power, he is still graceful with a long\n\
body, elegant lines and perfectly balanced. His scales are\n\
dark green on his back and transform to a lighter shade on\n\
his underside; perfect camouflage for a flying terror. Smoke\n\
billows from his nostrils and his gaping jaws. His claws\n\
make huge gouges in the granite rock and his tail spikes are\n\
over three feet long.\n");
set_level(30);
set_hp(3000+random(500));
set_al(-100);
set_wc(65);
set_wc_bonus(95);
set_dead_ob(this_object());
set_ac(55);
set_heart_beat(1);
set_chance(30);
set_spell_dam(40);
set_spell_mess1(
"The King of the"+HIG+" Green "+NORM+GRN+"Dragons"+NORM+" bites down on its opponent!\n");
set_spell_mess2(
"You feel your flesh tear apart under the assault of the Kings bite!\n");
set_chat_chance(10);
load_chat("The King glares at you with hatred.\n");
load_chat("The King hisses,'How dare you invade my home...'\n");
load_chat("The King of the green dragons lifts its head and stares down at you.\n");
}

heal_self(int i){
 if(i < 0){
  tell_room(environment(), "The King shrugs off your attack!\n"); 
  return 1;
  }
 ::heal_self(i);
 }

heart_beat(){
int rnum;
object *peeps;
object *peeps2;
int dam_amt;
int i;
int j;
int yup;
::heart_beat();

rnum = random(100);
dam_amt = random(180) + 50;

if(attacker_ob && environment()->query_first_room() && query_hp() < 800){
tell_room(environment(),
"\n\n\n"+HIG+"With a fierce snarl Mortankoria rises up high into the air fleeing\n"+
"into the large opening overhead. You noticed that before he left he\n"+
"grabbed something from the dais."+NORM+"\n\n");
move_object(this_object(), "/players/dragnar/SevenSpires/rooms/gdragon/r17.c");
attacker_ob = 0;
alt_attacker_ob = 0;
} 

if(query_hp() < 1000 && random(100) < 20){ 

/* added environment check so shit dont break -mizan */
  if(environment())  tell_room(environment(),
  GRN+"<><><><><>"+NORM+" The King lets out a roar of anger!\n\n"+
  GRN+"<><><><><>"+NORM+" You draw back in fear as his strikes begin to rip apart the surrounding area!\n");
  weapon_class += random(5);
  }

if(attacker_ob && random(100) < 50 && !bdelay){
 
  peeps = all_inventory(environment());
  for(i = 0; i < sizeof(peeps); i++){
     if(peeps[i] != this_object() && living(peeps[i]) && !call_other(peeps[i], "id", "cont_dragon")){
      yup += 1;
      }
  }
 if(yup){
tell_room(environment(),
   "The "+HIG+"Green "+NORM+GRN+"Dragon"+NORM+" raises its head high...\n\n\n"+
   "                "+HIR+"F L A M E"+NORM+"\n\n"+
   "                        Engulfs its enemy!\n");
   peeps = all_inventory(environment());
   dam_amt = dam_amt / yup;
   for(j = 0; j < sizeof(peeps); j++){
    if(peeps[j] != this_object() && living(peeps[j]) && !call_other(peeps[j], "id", "cont_dragon")){
      if(!present(peeps[j], environment())) continue;
      tell_object(peeps[j], HIR+"You are burned by the King's breath!"+NORM+"\n");
      peeps[j]->hit_player(dam_amt, "other|fire");
      bdelay = 3;
      }
    }    
  }
}

if(bdelay){  bdelay -= 1; }

if(bdelay && attacker_ob){

if(random(100) < 70 && attacker_ob){
   if(!present(attacker_ob, environment())) return;
   tell_room(environment(),
"The King of the "+HIG+"Green "+NORM+GRN+"Dragons"+NORM+" slashes its opponent with its HUGE claws!\n",
({ attacker_ob }));
tell_object(attacker_ob,
"You feel a terrible pain as the King rakes you with his claws!\n");
   attacker_ob->hit_player(random(30) + 15);
   }
else{
   if(!present(attacker_ob, environment())) return;
   tell_object(attacker_ob,
   "You barely dodge the long claws of the Dragon!\n");
   }

if(attacker_ob && alt_attacker_ob && random(100) < 30){
if(!present(attacker_ob, environment()) || 
   !present(alt_attacker_ob, environment())) return;
tell_object(alt_attacker_ob,
"You are "+HIR+"SLAMMED"+NORM+" by the long spiked tail of the King!\n");
   alt_attacker_ob->hit_player(random(25) + 14);
/* trying this as an experiment - mizan */
/*tell_room(environment(),
"The King's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");
*/
say("The King's tail lashes out and strikes furiously!\n");

   }
 }
}

monster_died(){
object corpse;
  corpse = present("corpse", environment()); 
tell_room(environment(),
"  The King falls forward and over the rim of the volcano. Landing\n"+
"  with a splash in the "+HIR+"Lava"+NORM+" below.\n\n"+
"  Something remains on the ledge...\n");  
  move_object(clone_object("/players/dragnar/SevenSpires/obj/gdragon/scimitar.c"),
  environment(this_object()));
if(corpse) destruct(corpse);
return 1;
}
