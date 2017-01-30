#include "/players/jaraxle/ansi.h"

inherit "obj/monster.c";



int bdelay;

object scale;

object scale2;

object scale3;



reset(arg)  {



  ::reset(arg);

  if(arg) return;

set_name("dragon");

set_alt_name("cont_dragon");

set_race("dragon");

set_short(HIR+"Red "+NORM+RED+"Dragon"+NORM+" [duke]");

set_long(

"This is a huge Red Dragon.  Its body is over 100 feet in\n"+

"length, and weighs several tons. The head is adorned by a\n"+

"huge crest of horns and spikes, all blending to form an\n"+

"almost natural crown. Its maw is filled with many sharp\n"+

"teeth, each the size of short swords, and much more deadly.\n"+

"Its wings, when unfurled, are longer than the beasts entire\n"+

"body.  Its fore and back legs end with sharp claws. Two\n"+

"spikes jut outward from the end of the dragons tail, making\n"+

"it a terrible weapon.\n");

set_level(24);

set_hp(950);

set_al(-1000);

set_wc(45);

set_wc_bonus(72);

set_ac(20);

set_heart_beat(1);

set_aggressive(1);

set_chance(15);

set_spell_dam(25);

set_spell_mess1(

"The "+HIR+"Red "+NORM+RED+"Dragon"+NORM+" bites down on its opponent!\n");

set_spell_mess2(

"You feel your flesh tear apart under the assault of the dragons bite!\n");

set_chat_chance (10);

load_chat("The Red Dragons hisses,'Come and face death, come to me!'\n");

load_chat("The Red Dragon's huge tail swishes back and forth.\n");

scale = clone_object("/players/jaraxle/cont/rdragon/dragonscale.c");

move_object(scale, this_object());

scale2 = clone_object("/players/jaraxle/cont/rdragon/dragonscale.c");

move_object(scale2, this_object());

if(!random(4)){

scale3 = clone_object("/players/jaraxle/cont/rdragon/dragonscale.c");

move_object(scale3, this_object());

}



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

dam_amt = random(130) + 50;







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

      tell_object(peeps[j], HIR+"You are burned by the breath of the Dragon!"+NORM+"\n");

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

   "You are "+HIR+"SLAMMED"+NORM+" by the long tail of the Dragon!\n");

   alt_attacker_ob->hit_player(random(20) + 12);

   tell_room(environment(),

   "The dragon's tail lashes out and strikes "+alt_attacker_ob->query_name()+"!\n");

   }

 }

}



