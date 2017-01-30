inherit "players/braxana/horlach/mon";

#include "/players/mythos/closed/guild/name.h"
string rlong;

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("dymon");
  set_short("Minor Dymon");
  set_alias("minor");
  set_race("demon");
  switch(random(3)){
    case 0: rlong = "A formless blob of goo looks back at you and gibbers.";
            break;
    case 1: rlong = "All you see is a ball of fur spewing slime everywhere.";
            break;
    case 2: rlong = "A black crystaline creatures grins at you."; break;
  }
  set_long(rlong+"\n");
  set_level(13);
  set_hp(10000 + random(100));
  set_al(-1000);
  set_wc(60 + random(50));
  set_ac(10);
  set_aggressive(80);
  set_perception(18);
  set_chance(40,0);
  set_spell_tell("The Dymon hits you with a flurry of blows!",0);
  set_spell_mess("The dymon rushes at its foe!",0);
  set_spell_dam(5,0);
  set_chance(10,1);
  set_spell_tell("Suddenly a mouth full of teeth rips into your skin!",1);
  set_spell_mess("The dymon takes a chunk out of its foe!",1);
  set_spell_dam(80,1);
  set_chat_chance(15);
  set_chat_att_chance(20);
  set_chat_mess("The dymon grins\n",0);
  set_chat_mess("You hear gibbering\n",1);
  set_chat_att_mess("The dymon screams in rage!\n",0);
  set_chat_att_mess("Smoke pours from the dymon!\n",1);
  set_chat_att_mess("The dymon rushes at its foe!\n",2);
}

