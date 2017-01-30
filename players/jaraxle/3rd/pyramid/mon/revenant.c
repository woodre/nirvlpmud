#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int x;

id(str) { return (::id(str) || str == "mummy"); }

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("dark revenant");
   set_alias("jar_mummy");
   set_alt_name("revenant");
   set_race("undead");
   set_short(BLK+BOLD+"Dark Revenant"+NORM);
   
   set_level(20);
   set_hp(550+random(50));
   set_al(-1000);
   set_ac(17);
   set_aggressive(0);
   set_wc(35+random(6));
   set_wc_bonus(20);
   set_ac_bonus(6);
   set_dead_ob(this_object());
   
   set_a_chat_chance(15);
   load_a_chat("The Mummmy yells, 'Noc Mahut MARAH!'\n");
   
   gold = clone_object("obj/money");
   gold->set_money(100+random(501));                              
   move_object(gold,this_object());
/*
   set_assist("/players/jaraxle/3rd/pyramid/mon/scorpion.c", 3, 10, 10);
*/
   set_wander(30, 0, ({ "out" }));

} 
long(){ write("This mummy looks very young, and vibrant.  The bandages wrapped around\nhis body are still bright tan with hints of white.  The mummy's face\nis partially wrapped, his eyes are still in working shape yet the mouth\nis rotted and decayed.\nThe mummy holds a large pouch in its hand.\n"); }

monster_died() {
   tell_room(environment(this_object()),
      "The mummy turns to ashes, the bandages slump to the ground in a pile.\n");
   x = present("corpse",environment(this_object()));
   destruct(x);
   MOCO("/players/jaraxle/3rd/pyramid/items/bandages.c"),environment());
   MOCO("/players/jaraxle/3rd/pyramid/items/ash.c"),environment());
switch(random(5)){
case 0:
   MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),environment());
break;
case 1:
   MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),environment());
   MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),environment());
break;
case 2:
   MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),environment());
   MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),environment());
   MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),environment());
break;
case 3..4:
return 0;
break;
}

return 0; }


jar_smash1(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("\nWith a mighty swing the Mummy breaks a canopic jar onto the ground!\n"+
          ""+HIM+"A suffoctating mist enshrouds"+HIW+" "+ATT_NAME+""+HIM+"!"+NORM+"\n\n");

    attacker_ob->hit_player(-15-random(11));
}

jar_smash2(){

string ATT_NAME,msg;
 if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("\nWith a mighty swing the Mummy breaks a canopic jar onto the ground!\n"+
        ""+YEL+"A blast of sand rips through "+HIW+""+ATT_NAME+"'s"+NORM+" "+YEL+"chest!"+NORM+"\n\n");

    attacker_ob->add_hit_point(-20-random(6));
}

jar_smash3(){

string ATT_NAME,msg;
 if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("\nWith a mighty swing the Mummy breaks a canopic jar onto the ground!\n"+
        ""+HIW+"Spirits of the dead"+NORM+" float through "+ATT_NAME+"'s body.\n\n");

    attacker_ob->add_hit_point(-20-random(6));
}

open_mouth(){

string ATT_NAME,msg;
 if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("\nThe Mummy opens his mouth...\n"+
        ""+HIY+"  A beam of light escapes from the Mummy's mouth..."+NORM+"\n"+
        ""+HIY+"    The light envelopes "+HIW+""+ATT_NAME+""+HIY+" in "+HIR+"pain"+HIY+" and "+HIB+"suffering!"+NORM+"\n\n");

    attacker_ob->add_hit_point(-55-random(31));
}

heal_me(){

    say("\nWith a mighty swing the Mummy breaks a canopic jar onto the ground!\n"+
        "A "+HIC+"hazy blue mist"+NORM+" enshrouds the Mummy."+NORM+"\n\n");
    this_object()->heal_self(20+random(21));
}

heart_beat(){
int i;
  ::heart_beat();
if(attacker_ob){
i = random(17);
switch(i){

    case 0..2: jar_smash1();
  break;

    case 3..5: jar_smash2();
  break;

    case 6..7: jar_smash3();
  break;
 
    case 8..10: heal_me();
  break;

    case 11: open_mouth();
  break;

    case 12..16: return 0;
  break;
    }
  }
}
