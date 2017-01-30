#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
int num;
object gold;
array *rooms;
reset(arg){
no_clean=1;
   ::reset(arg);
   if(arg) return;
   set_name("firethrower");
   set_alias("fire");
   set_alt_name("thrower");
   set_attrib("str",20);
   set_attrib("ste",20);
   set_race("demon");
   set_short("Firethrower");
   set_long(
      "  A walking pillar of flame.  Firethrower has black beedie eyes which pierce\n"+
      "through the flames of his body.  Firethrower looks human in form, but with\n"+
      "his body nothing but raging fire is far from that which he looks.\n");
   MOCO("/players/jaraxle/3rd/volcano/weaps/krakin.c"),this_object());
    init_command("wield axe");
    set_level(23);
    set_hp(900+random(150));
    set_al(-1000);
    set_light(2);
    set_aggressive(0);
    set_wc_bonus(50);
/* Heal spell */
    set_ac_bonus(20);
    set_dead_ob(this_object());
    set_chat_chance(4);
    load_chat("Flames flick violently over Firethrower.\n");
    load_chat("Firethrower laughs a deep, throaty laugh towards you.\n");
    gold = clone_object("obj/money");
    gold->set_money(4000+random(1400));
    move_object(gold,this_object());
}
id(str){ return (str == "fire" || str == "thrower" || str == "firethrower" || str == "jaraxle_big_fucking_monster"); }

heatwave(){
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("Firethrower blasts the area with a\n\n\t"+HBRED+""+HIW+"*** "+HIY+"HEATWAVE "+HIW+"***"+NORM+"\n\n"+
        ""+ATT_NAME+" staggers in flames!\n");

    attacker_ob->add_hit_point(-50-random(20));
}

flame_tower(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("\nFirethrower swings his hand upward.\n"+
          "   Firethrower roars: "+HIY+"FLA"+HIR+"MING TO"+HIY+"WER"+NORM+"!\n"+
          ""+HIR+"      Flames"+NORM+" rise from the ground punishing "+ATT_NAME+" with "+HBRED+""+HIY+"heat"+NORM+"!\n\n");

    attacker_ob->add_hit_point(-60-random(10));
}

palm_lava(){

string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();

    say("Firethrower ROARS!\nFirethrower opens his palms towards "+ATT_NAME+".\n"+
        "Screaming "+RED+"lava"+NORM+" races towards "+ATT_NAME+", engulfing "+ATT_NAME+" in "+HIR+"flames"+NORM+"!\n");

    attacker_ob->add_hit_point(-45-random(10));
}

heal_me(){

    say("\nFirethrower raises his hands to the air.\n"+
        "Firethrower yells: "+HIR+"FIRE RAIN"+NORM+"!\n\n"+
        "\t"+HIY+"~"+HIR+"."+HIY+"~ "+HBRED+"A rain of fire waves over his body"+NORM+" "+HIY+"~"+HIR+"."+HIY+"~"+NORM+"\n\n"+
        "Firethrower's flames "+HIY+"brighten"+NORM+".\n\n");
    this_object()->heal_self(50+random(25));
}


monster_died() {
  tell_room(environment(this_object()),
        "Firethrowers flames die out.\nHis lifeless, charred corpse drops to the ground with a hard thud.\n");
write_file("/players/jaraxle/3rd/volcano/f_kill.log",ctime(time())+" "+HIY+""+this_player()->query_name()+""+NORM+" killed Fire.\n");
return 0; }     

heart_beat(){
int i;
  ::heart_beat();
if(attacker_ob){
i = random(9);
switch(i){

    case 0: heatwave();
  break;

    case 1: flame_tower();
  break;

    case 2: palm_lava();
  break;

    case 3..4: heal_me();
  break;

    case 5..8: return 0;
  break;
    }
  }
}

move(){
    rooms = ({ "f_cave3","random_cave","a_cave5","b_cave3","c_cave6","d_cave7","e_cave5","f_cave6" });
    num = random(sizeof(rooms));
    if(!environment()) return;
move_object(this_object(),"/players/jaraxle/3rd/volcano/rooms/"+rooms[num]+"");
}

