#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

int x;
reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("pyramid defender");
   set_alias("jar_mummy");
   set_alt_name("statue");
   set_race("undead");
   set_short("Statue");
   
   set_level(20);
   set_hp(550+random(50));
   set_al(-1000);
   set_ac(17);
   set_aggressive(1);
    set_wc(36+random(5));
   set_ac_bonus(4);
   set_wc_bonus(20);
   set_dead_ob(this_object());
   
   set_a_chat_chance(15);
   load_a_chat("The Pyramid defender SLAMS you into the wall!\n");
   
   gold = clone_object("obj/money");
   gold->set_money(3300+random(2101));
   move_object(gold,this_object());
}
long(){ write("A large, dirty statue of about seven feet in height.\nThe statue is dark brown in color from the dust and\nsand that has coverd the statue over time.  A large\nscythe sits in the statue's huge hands, resting against\nits chest.  A suit of plated armor made from leathers\nand gold plate cover its body.  A helmet, which looks\nlike a dog's head covers the statues head.\n"); }

monster_died() {
   tell_room(environment(this_object()),
     "The statue crumbles into a pile of rubble.\n");
   x = present("corpse",environment(this_object()));
   destruct(x);
   MOCO("/players/jaraxle/3rd/pyramid/items/d_armor.c"),environment());
   MOCO("/players/jaraxle/3rd/pyramid/items/rubble.c"),environment());
return 0; }


spear_slice(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("\nThe Statue swings its scythe in an upward arc.\n"+
          "The blade of the scythe "+BOLD+""+BLK+"_ - "+HIW+"SLICES"+BLK+" - _"+NORM+" through "+ATT_NAME+"!\n\n");

    attacker_ob->hit_player(-15-random(11));
}

spear_stab(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("The Statue stabs its scythe into "+ATT_NAME+"'s chest!\n"+
        ""+RED+"Blood"+NORM+" and flecks of skin fly out of "+ATT_NAME+"'s back!\n");

    attacker_ob->add_hit_point(-20-random(6));
}

heal_me(){

    say("Your weapon bounces uneffectively off the Statue with a loud "+HIW+"PING"+NORM+"!\n");
    this_object()->heal_self(10+random(11));
}

heart_beat(){
int i;
  ::heart_beat();
  if(!this_object()) return;
if(attacker_ob){
i = random(10);
switch(i){

    case 0..1: spear_slice();
  break;

    case 2: spear_stab();
  break;

    case 3..4: heal_me();
  break;
   
    case 5..9: return 0;
  break;
    }
  }
}
