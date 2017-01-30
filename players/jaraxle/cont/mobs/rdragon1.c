#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



int bdelay;

object att;

object scale;

object scale2;



reset(arg)  {



  ::reset(arg);

  if(arg) return;

bdelay = 0;

set_name("dragon");

set_alt_name("cont_dragon");

set_race("dragon");

set_short(HIR+"Red "+NORM+RED+"Dragon"+NORM+" [soldier]");

set_long(

"  This is a large red dragon.  Its body is covered in thick\n"+

"redish hued plates.  Its head is nearly 6 feet in length, and\n"+

"has several large horns protruding from its maw and crest. Its\n"+

"front and rear paws are tipped with huge claws.  Its body ends\n"+

"in a long tail, of which several spikes jut outward from. Huge\n"+

"wings extend from its shoulders, their size easily enough to\n"+

"carry the weight of this great beast.\n");

set_level(22);

set_hp(750);

set_wc_bonus(40);

set_al(-1000);

set_aggressive(1);

set_wc(40);

set_ac(17);

scale = clone_object("/players/jaraxle/cont/rdragon/dragonscale.c");

move_object(scale, this_object());

if(!random(4)){

scale2 = clone_object("/players/jaraxle/cont/rdragon/dragonscale.c");

move_object(scale2, this_object());

}

set_heart_beat(1);

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

dam_amt = random(100) + 30;







if(attacker_ob && random(100) < 50 && !bdelay){

 

  peeps = all_inventory(environment());

  for(i = 0; i < sizeof(peeps); i++){

     if(peeps[i] != this_object() && living(peeps[i]) && !call_other(peeps[i], "id", "cont_dragon")){

      yup += 1;

      }

  }

 if(yup){

tell_room(environment(),

   "The "+HIR+"Red "+NORM+RED+"Dragon"+NORM+" raises its head high...\n\n\n"+

   "                "+HIR+"F L A M E"+NORM+"\n\n"+

   "                        Engulfs it's enemy!\n");

   peeps = all_inventory(environment());

   dam_amt = dam_amt / yup;

   for(j = 0; j < sizeof(peeps); j++){

     if(peeps[j] != this_object() && living(peeps[j]) && !call_other(peeps[j], "id", "cont_dragon")){

      if(!present(peeps[j], environment())) continue;

      tell_object(peeps[j], HIR+"You are burned by the Dragons breath!"+NORM+"\n");

      peeps[j]->hit_player(dam_amt, "other|fire");



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

   "The "+HIR+"Red "+NORM+RED+"Dragon"+NORM+" slashes its opponent with its gleaming claws!\n",

   ({ attacker_ob }));

   tell_object(attacker_ob,

   "You feel a terrible pain as the Dragon rakes you with its claws!\n");

   attacker_ob->hit_player(random(20) + 10);

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

   alt_attacker_ob->hit_player(random(15) + 8);

   tell_room(environment(),

   "The dragon's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");

   }

 }

}



