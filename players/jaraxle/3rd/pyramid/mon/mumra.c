#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

int x;
reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name(BLK+BOLD+"Mumm-Ra"+NORM);
   set_alias("mumm-ra");
   set_alt_name("mumm ra");
   set_race("evil");
   set_level(25);
   set_hp(1000+random(151));
   set_al(-1500);
   set_ac(17+random(6));
   set_aggressive(0);
   set_wc(45+random(6));
   set_wc_bonus(40);
   set_ac_bonus(20);
   set_dead_ob(this_object());
   gold = clone_object("obj/money");
   gold->set_money(5000+random(1001));
   move_object(gold,this_object());
}
short(){ return ""+BLK+BOLD+"Mumm-Ra"+NORM+""; }
long(){
              write("The essence of Evil.  Mumm-Ra is the the source\n"+
                    "of all the evil in Third Earth.  He is the most\n"+
                    "powerful adversary of the ThunderCats.  He towers\n"+
                    "at about eight feet tall.  His body is thick and\n"+
                    "muscular, with a grey tone.  He wears a golden\n"+
                    "crown on his head.  There is a red circle on his\n"+
                    "chest with two black snakes intertwined.  Bandages\n"+
                    "flow around his body as if a breeze were always\n"+
                    "around him.\n"); }

monster_died() {
   tell_room(environment(this_object()),
     "The spirit fades to nothingness.\n");
   x = present("corpse",environment(this_object()));
   destruct(x);
   MOCO("/players/jaraxle/3rd/pyramid/items/void.c"),environment());
 if(this_player())
write_file("/players/jaraxle/3rd/pyramid/m_kill.log",ctime(time())+" "+HIW+""+this_player()->query_name()+""+NORM+" killed "+BLK+BOLD+"Mumm-Ra"+NORM+".\n");
return 0; }


DARKNESS(){

    say("Mumm-Ra summons the "+BLK+BOLD+"Spirits of the Dark"+NORM+" to swarm the room!\n\n");
MOCO("/players/jaraxle/3rd/pyramid/items/dark.c"),environment());

}

EYES(){

string ATT_NAME,msg;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();

    say(BLK+BOLD+"Mumm-Ra"+NORM+" shoots a beam of "+HIR+"red light"+NORM+" through his eyes...\n"+
     "\tThe beams "+HIW+HBRED+"~R I P~"+NORM+" through "+ATT_NAME+"!\n");
    attacker_ob->add_hit_point(-100-random(76));
    attacker_ob->hit_player(10);
}
}

SLAM(){
 string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();

    say(BLK+BOLD+"Mumm-Ra"+NORM+" grabs "+ATT_NAME+" by the neck and slams them to the ground!\n");
    attacker_ob->hit_player(-10-random(26));
}
}

SHAKE_EM(){
 string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();

    say(BLK+BOLD+"Mumm-Ra"+NORM+" stomps on the ground with might!\n"+
    "\t"+HIW+"~"+NORM+"The ground RiPpLeS beneath you!"+HIW+"~"+NORM+"\n");
  attacker_ob->hit_player(-26-random(16));
}
}

heal_me(){

    say(BLK+BOLD+"Mumm-Ra"+NORM+" asks the "+BLK+BOLD+"Ancient Spirits of Evil"+NORM+" to grant him health.\n");
    this_object()->heal_self(10+random(31));
}

HELP_ME(){

    say(BLK+BOLD+"\nMumm-Ra"+NORM+" summons minions to aid his battle.\n");
MOCO("/players/jaraxle/3rd/pyramid/mon/scorpion.c"),environment());
    say("\t"+HBWHT+BLK+BOLD+"A scorpion enters the room!\n"+NORM);
}
CHEST(){
 string ATT_NAME;
if(attacker_ob && present(attacker_ob)) { ATT_NAME = attacker_ob->query_name();

    say(BLK+BOLD+"Mumm-Ra"+NORM+" boldy sticks his chest out...\n"+
       "\tTwo "+HIR+"f"+NORM+RED+"l"+HIY+"a"+NORM+YEL+"m"+HIR+"i"+NORM+RED+"n"+HIY+"g"+NORM+" snakes burst from his chest engulfing "+ATT_NAME+" in "+HIR+"fl"+HIW+"am"+HIR+"es"+NORM+"!\n");
  attacker_ob->add_hit_point(-20-random(11));
}
}


heart_beat(){
int i;
  ::heart_beat();
  if(!this_object()) return;
if(attacker_ob){
i = random(18);
switch(i){

    case 0..2: DARKNESS();
  break;

    case 3: EYES();
  break;

    case 4..6: heal_me();
  break;
   
    case 7: HELP_ME();
  break;

    case 8..9: SLAM();
  break;

    case 10..12: SHAKE_EM();
  break;

    case 13..14: CHEST();
  break;

   case 15..17: return 0;
  break;
    }
  }
}

