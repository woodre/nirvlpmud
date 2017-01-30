#include "/players/feldegast/defines.h"
#define HIVE_MIND "/players/feldegast/realm/JalHab/hive_mind.c"
inherit MONSTER;

void call_for_help();

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("Myrmidar Queen");
  set_alias("queen");
  set_short(BOLD+BLK+"Myrmidar "+HIY+"Queen"+NORM);
  set_long(
"The Myrmidar Queen is fat and bloated, like a huge thirty meter long\n\
earthworm with rows of wasted and useless limbs near her hideous face.\n\
A row of spikes runs along the base of her spine and her ample belly\n\
appears milky white.\n"
  );
  set_level(21);
  set_wc(34);
  set_ac(20);
  set_hp(5000);
  set_race("myrmidar");
  set_dead_ob(this_object());
  set_chat_chance(4);
  load_chat(short_desc+" expels a gust of humid air from her mammoth body.\n");
  load_spell(60,25,0,
    BOLD+"\n>> The Queen raises her body high into the air and then crushes you. <<\n\n"+NORM,
    BOLD+"\n>> The Queen raises her body high into the air and then crushes #ATT#. <<\n\n"+NORM
  );
  load_spell(55,35,0,
    RED+"\n\t* The Queen snaps forward with improbable speed *\n"+
        "\t* and bites you with her sharp fangs!           *\n\n"+NORM,
    RED+"\n\t* The Queen snaps forward with improbable speed *\n"+
        "\t* and bites #ATT# with her sharp fangs!           *\n\n"+NORM
  );


}

void heart_beat()
{
  ::heart_beat();
  if(attacker_ob && !random(3)) 
    call_for_help();
  if(attacker_ob && !random(3))
  {
    if((int)HIVE_MIND->call_help()==1)
      say(short_desc+BOLD+" bellows for help, her cry echoing through the tunnels!\n"+NORM);
  }
}

void monster_died(object ob)
{
  object corpse;
  int i;
  corpse=present("corpse",environment());
  for(i=2+random(5); i > 0; i--)
  {
    switch(random(5))
    {
      case 0: move_object(clone_object(HEAL_PATH+"myrm-blood"),corpse);
              break;
      case 1: move_object(clone_object(WEP_PATH+"myrm-spike"),corpse);
              break;
      case 2: move_object(clone_object(ARM_PATH+"myrm-plate"),corpse);
              i--;
              break;
      case 3: move_object(clone_object(ARM_PATH+"myrm-shield"),corpse);
              break;
      case 4: move_object(clone_object(HEAL_PATH+"myrm-heart"),corpse);
              break;
    }
  }
  write_file("/players/feldegast/log/monsters.log",ctime(time())+" "+TPRN+" killed Myrmidar Queen\n");
}
void call_for_help()
{
  object ob;
  ob=first_inventory(environment());
  while(ob)
  {
    if(!((int)ob->query_attack()) && (int)ob->id("myrmidar") && ob!=this_object())
    {
      tell_room(environment(),(string)ob->short()+" comes to "+short()+"'s aid.\n");
      ob->attack_object(attacker_ob);
    }
    ob=next_inventory(ob);
  }
}
