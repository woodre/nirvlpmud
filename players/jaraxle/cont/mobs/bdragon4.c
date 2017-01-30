#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



int bdelay;

object scale;

object scale2;



reset(arg)  {



  ::reset(arg);

  if(arg) return;

set_name("dragon");

set_alt_name("cont_dragon");

set_race("dragon");

set_short(HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" [elite guard]");

set_long(

"This huge blue dragon belongs to the elite guard of the\n"+

"King. It is the largest of the soldier class, and holds\n"+

"more devastating power than any two. Its body is over\n"+

"140 feet in length, and is coveblue in a tough blue plate\n"+

"scale. Its head is covered in small spikes, with two\n"+

"large horns jutting out to the back. Its forearms end\n"+

"in huge claws, capable of rending any armor. It is a\n"+

"terrible sight to behold.\n");

set_level(23);

set_hp(850);

set_al(-1000);

set_wc(45);

set_wc_bonus(60);

set_ac(20);

set_aggressive(1);

set_heart_beat(1);

set_chance(15);

set_spell_dam(25);

set_spell_mess1(

"The "+HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" bites down on its opponent!\n");

set_spell_mess2(

"You feel your flesh tear apart under the assault of the dragons bite!\n");

set_chat_chance (10);

load_chat("The Blue Dragon glares at you with hatred.\n");

load_chat("The Blue Dragon's huge tail swishes back and forth.\n");

scale = clone_object("/players/jaraxle/cont/rdragon/blue_dragonscale.c");

move_object(scale, this_object());

scale2 = clone_object("/players/jaraxle/cont/rdragon/blue_dragonscale.c");

move_object(scale2, this_object());

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

dam_amt = random(100) + 50;







if(attacker_ob && random(100) < 50 && !bdelay){

 

  peeps = all_inventory(environment());

  for(i = 0; i < sizeof(peeps); i++){

     if(peeps[i] != this_object() && living(peeps[i]) && !call_other(peeps[i], "id", "cont_dragon")){

      yup += 1;

      }

  }

 if(yup){

tell_room(environment(),

"The "+HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" sucks in a deep breath and...\n\n\n"+
"                "+HIY+"B O O M"+NORM+"\n\n"+
"Discharges a bright flash of lightning from its huge maw!\n");



   peeps = all_inventory(environment());

   dam_amt = dam_amt / yup;

   for(j = 0; j < sizeof(peeps); j++){

       if(peeps[j] != this_object() && living(peeps[j]) && !call_other(peeps[j], "id", "cont_dragon")){

      if(!present(peeps[j], environment())) continue;

      tell_object(peeps[j], HIB+"You are electrified by the lightning of the Dragon!"+NORM+"\n");

      peeps[j]->hit_player(dam_amt, "other|lightning");

      bdelay = 4;

      }

    }    

  }

}



if(bdelay){  bdelay -= 1; }



if(bdelay && attacker_ob){



if(random(100) < 70 && attacker_ob){

   if(!present(attacker_ob, environment())) return;

   tell_room(environment(),

   "The "+HIB+"Blue "+NORM+BLU+"Dragon"+NORM+" slashes its opponent with its gleaming claws!\n",

   ({ attacker_ob }));

   tell_object(attacker_ob,

   "You feel a terrible pain as the Dragon rakes you with its claws!\n");

   attacker_ob->hit_player(random(25) + 13);

   }

else{

   tell_object(attacker_ob,

   "You barely dodge the long claws of the Dragon!\n");

   }



if(attacker_ob && alt_attacker_ob && random(100) < 30){

   if(!present(attacker_ob, environment()) || 

      !present(alt_attacker_ob, environment())) return;

   

   tell_object(alt_attacker_ob,

   "You are "+HIR+"SLAMMED"+NORM+" by the long tail of the Dragon!\n");

   alt_attacker_ob->hit_player(random(20) + 11);

  if(alt_attacker_ob)
   tell_room(environment(),

   "The dragon's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");

   }

 }

}



