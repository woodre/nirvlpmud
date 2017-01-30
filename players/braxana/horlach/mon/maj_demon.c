inherit "players/braxana/horlach/mon";

#include "/players/mythos/closed/guild/name.h"
string rlong;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dymon");
  set_short("Major Dymon");
  set_alias("major");
  set_race("demon");
  switch(random(3)){
    case 0: rlong = "A tall skinny skeletal looking thing cackles at you.";
            break;
    case 1: rlong = "At first you think it is a puddle of blood,\n"+
                    "but then you see it moves.....";
            break;
    case 2: rlong = "The air is filled with a soft shimmering mist...."; break;
  }
  set_long(rlong+"\n");
  set_level(18);
  set_hp(500 + random(1000));
  set_al(-1000);
  set_wc(30 + random(10));
  set_ac(15);
  set_aggressive(100);
  set_perception(200);
  set_chance(90,0);
  set_spell_tell("The Dymon slices into you with sharp talons!",0);
  set_spell_mess("The Dymon slices into its foe!",0);
  set_spell_dam(40,0);
  set_chance(20,1);
  set_spell_tell("You feel faint as the Dymon drains your life!",1);
  set_spell_mess("The Dymon's foe falters...",1);
  set_spell_dam(150,1);
  set_chance(40,2);
  set_spell_tell("You scream in pain as the Dymon rips into you!",2);
  set_spell_mess("The Dymon's foe screams in pain!",2);
  set_spell_dam(100,2);
  set_chance(5,3);
  set_spell_tell("The pains becomes unbearable as the Dymon feasts on your soul!",3);
  set_spell_mess("The Dymon's foe screams in pain!",3);
  set_spell_dam(400,3);
  set_chat_att_chance(30);
  set_chat_att_mess("The Dymon cackles in horrific glee!\n",0);
  set_chat_att_mess("Death has come!\n",1);
  set_chat_att_mess("You tremble in fear....\n",2);
}

