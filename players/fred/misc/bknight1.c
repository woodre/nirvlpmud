#include "/players/fred/ansi.h"
#include "/players/fred/defines.h"
inherit "/obj/monster.c";
#define moose this_object()->query_attack()
#define moosen capitalize(moose->query_name())

int v, verte, heh;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("blood knight");
  set_alias("knight");
  set_race("human");
  set_short(BOLD+RED+"Blood"+NORM+" Knight");
  set_long(
    "  Looming before you is a tall massive figure whose dark\n"+
    "lifeless eyes seem to pierce your soul.  As you glance down\n"+
    "you notice a large blood stained saber gripped tightly in his\n"+
    "powerful hand, and an old shield rested in his other.  His eyes\n"+
    "seem to light up for a moment and then quickly grow dim as he\n"+
    "stands poised for battle.\n");
  add_money(2000+random(2000));
  set_level(24);
  set_al(-(random(500)));
  set_hp(1200);
  set_hp_bonus(150);
  MO(CO("players/fred/misc/bshield.c"), TO);
  MO(CO("players/fred/misc/saber1.c"), TO);
  command("wear shield", TO);
  command("wield sword", TO);
  set_ac(20+random(5));
  set_wc(50+random(5));
  set_wc_bonus(10);
  set_heal(3,1);
  set_gender("male");
  set_aggressive(0);
  set_dead_ob(this_object());
  set_chat_chance(5);
    load_chat("The"+RED+" Blood"+NORM+" Knight stares at you with dark clouded eyes.\n");
    load_chat("The"+RED+" Blood"+NORM+" Knight asks 'Why do you disturb me?'\n");
    load_chat("Screams fill the cave and echo off the walls around you.\n");
    load_chat("The"+RED+" Blood"+NORM+" Knight screams 'Leave now or I shall be forced to kill you!'\n");
    load_chat("The stench of mold and decay invade your senses making you feel ill.\n");
  enable_commands();
  v = 0;   
  verte = 10+random(5);
  heh = 0;
}

monster_died(){
 tell_object(moose,
  "\n"+RED+"Blood"+NORM+" sprays from the Knight's mouth as his lifeless body falls to the ground.\n\n");
 write_file("/players/fred/log/knight", attacker_ob->query_name() + " beat down the Blood Knight " + ctime()[4..15] + "\n");
 return 1; }

heart_beat(){
  int qqq;
  qqq = random(100);
  ::heart_beat();
   if(!environment()) return;
   if(v > 0){
    verte--; 
    if(heh < 1){ 
    if(verte < 1){
      tell_room(environment(this_object()),
       BOLD+BLK+"\n    The "+NORM+RED+"Blood"+BOLD+BLK+" Knight sensing that the end is near\n"+
       "      goes on the defensive trying to survive."+NORM+"\n\n");
       weapon_class = 55;
       set_ac(45);
       heh = 1;
       }
     }
   }
   if(!moose) return;
     if(qqq < 81){
       rage();
      }
     else if(qqq > 85){
       drinkage();
      }
     else if(qqq > 81){
       talk_about_unhappy();
      }
    }

rage(){
  object shield;
  int mal, hal;
  mal = TO->query_mhp();
  hal = TO->query_hp();
  shield = present("yup_yup", TO);
  if(v > 0){ return 1; } 
   if(hal < ((mal/10)*4)){
     tell_room(environment(moose),
     BOLD+BLK+"\n    The "+NORM+RED+"Blood"+BOLD+BLK+" Knight throws his shield to the ground in\n"+
       "     rage and attacks with a barrage of precise blows."+NORM+"\n\n");
   destruct(shield);
   MO(CO("players/fred/misc/bshield.c"), environment(TO));
   weapon_class = (85+random(5)); 
   set_ac(15);
   v = 1;
  }
}

drinkage(){
  int floppy, mr_squishy_ball, purple_gorilla_guy;
  floppy = moose->query_attrib("wil");
  mr_squishy_ball = moose->query_attrib("pie");
  purple_gorilla_guy = random(100);
  if((floppy+mr_squishy_ball) > purple_gorilla_guy){
    tell_room(environment(moose),
    BOLD+BLK+"\n    The "+NORM+RED+"Blood"+BOLD+BLK+" Knight feeds upon your "+NORM+RED+"blood"+BOLD+BLK+" making him stronger!"+NORM+"\n\n");
    TO->heal_self(purple_gorilla_guy);
    moose->heal_self(-(purple_gorilla_guy));
   }
 }

talk_about_unhappy(){
  object *inv;
  int lil_doggy, i;
  inv = all_inventory(EN);
  lil_doggy = sizeof(inv);
  tell_room(environment(moose),
  BOLD+BLK+"\n    The"+NORM+RED+" Blood"+BOLD+BLK+" Knight lunges at you..."+RED+"\n\n"+
           "            HACKING ! !\n"+
           "                SLASHING ! !\n"+
           "                    RIPPING ! !"+BLK+"\n\n");
  tell_room(environment(moose),
           "                        ...away at your flesh."+NORM+"\n\n");        
   for(i = 0; i < lil_doggy; i++)
   {
     if(inv[i]->query_name() != "Blood knight")
     {
       if(living(inv[i]))
       {
         inv[i]->hit_player(150 + random(50));
       }
     }
   }
 }  

