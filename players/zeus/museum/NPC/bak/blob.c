
inherit "/obj/monster";
#include "/players/zeus/closed/all.h"
int ehay, tofay, karflay;
object golay;

reset(arg) {
   ::reset(arg);
   if (!arg) {

  karflay = 0;  /* no burnies */
  ehay = 0;  /* no yummies */
  tofay = 0;  /* inside */
  set_name("Boul-Goruk");
  set_alias("blob");
  set_alt_name("king");
  set_short("King Boul-Goruk of Asytaine");
  set_gender("male");
  set_race("blob");
  set_level(22);
  set_ac(22);
  set_wc(50);
  set_hp(1100);
  set_heal(4,1);
  set_chance(10);
  set_spell_dam(55);
  set_spell_mess1("Boul-Goruk explodes in a monsterous rage!\n");
  set_spell_mess2("Boul-Goruk explodes in a monsterous rage!\n");
  set_chat_chance(4);
  set_a_chat_chance(1);
  load_chat("Boul-Goruk grins.\n");
  load_chat("Boul-Goruk waves his mace at you.\n");
  load_chat("Boul-Goruk asks, \"Why are you here?\"\n");
  load_chat("Boul-Goruk says, \"I am the King of Asytaine.\"\n");
  load_chat("Boul-Goruk says, \"Leave now mortal.\"\n");
  load_a_chat("Boul-Goruk laughs at you!\n");
  load_a_chat("Boul-Goruk absorbs your hit!\n");
  load_a_chat("Boul-Goruk rebuilds himself!\n");
  set_dead_ob(this_object());
  call_out("drookok", 60);
} }

long(){
  if(!environment()) return;
  if(present(this_player(), this_object()))
  {
    write(
      "You are inside the green blob.  You find that breathing is\n"+
      "almost impossible, and your flesh is being burned away!  You\n"+
      "had better get out of here as fast as possible.\n");
  }
  else {
  write(
  "The creature which sits before you appears to be a gigantic blob of\n"+
"dark green matter.  He is about eight feet tall, six feet wide and\n"+
"six feet long, with a small tail visible on its posterior.  He has\n"+
"two wide, white eyes, a barely visible nose and a gigantic mouth,\n"+
"which seems to be grinning.  A decorative cloak is tied around his\n"+
"thick neck.  In his right hand is a unique looking mace.\n");
  }
}

realm(){ return "NT"; }  /* no escape for you baby! :) */

monster_died()
{
	if(!environment()) return 0; /*
  write_file("/players/zeus/log/museum", ctime(time())+"   "+
	  capitalize((string)TP->QRN)+" defeated Boul-Goruk.\n"); */
  tell_room(environment(),
    "Boul-Goruk slouches to the ground...\n");
  MO(CO("/players/zeus/museum/OBJ/mace.c"), environment());
/*
   "/players/zeus/museum/lounge.c"->npc10(); */
   return 1;
}

heart_beat()  /*  thuk, thuk, thuk, thuk */
{
  ::heart_beat();
  if(!environment()) return;
  if(!attacker_ob) return;
  golay = attacker_ob;
  if(attacker_ob == this_object())
  {
    this_object()->stop_fight();
    this_object()->stop_fight();
  }
  if(!random(27) && !ehay)
    absorb();
  if(hit_point <= 420 && !ehay)
    absorb();
  if(!attacker_ob && golay)
    clukcluk();
  if(!random(4))
    guklunk();
  if(!random(8))
    burnyoo();
}

burnyoo()  /*  aawwwwuuugghgghg  auughghghg!!!  */
{
  if(!present(attacker_ob, environment())) return;
  tell_object(attacker_ob,
    "Boul-Goruk spits a stream of "+HIG+"TOXIC ACID"+NORM+" on you!\n"+
    "You writhe in agony as the acid burns away your flesh!\n");
  attacker_ob->add_hit_point(-100);
  if((int)attacker_ob->query_hp() <= 0)
    attacker_ob->hit_player(666);
}

guklunk()   /*  oh yeah, dual hits baby!  */
{
  int x;
  if(!present(attacker_ob, environment())) return;
  if(!attacker_ob->query_ghost())
  {
      weapon_class = random(41);
      already_fight = 0; ::attack();
  }
  weapon_class = 40;
}

clukcluk()   /*  can't peace me, foo!  */
{
  string xy;
  if(!golay) return;
  if(!sscanf(file_name(environment(golay)), 
	"players/zeus/museum/arena/%s", xy)) return;
  if(!present(golay, environment()) ||
      present(golay, this_object())) return;
  tell_room(environment(), "Boul-Goruk snarls!\n");
  this_object()->attack_object(golay);
}

drookok()  /* can't run from me! **/
{
  string xy;
  call_out("drookok", 60);
  if(!golay) return;
  if(!sscanf(file_name(environment(golay)), 
	"players/zeus/museum/arena/%s", xy)) return;
  if(present(golay, environment()) ||
      present(golay, this_object())) return;
  tell_object(golay, "\nYou are ripped back by Boul-Goruk!\n\n");
  move_object(golay, environment());
  this_object()->attack_object(golay);
}

qvub()  /*  OOH, OOH it burns!!!  aughh!!  */
{
  if(!golay) return;
  if(present(golay, this_object()))
  {
    if(golay->query_ghost()) return;
    if(!random(2))
      tell_object(golay, "Acid burns your skin!\n");
    else
      tell_object(golay, "Toxic fumes burn your flesh!\n");
    golay->hit_player(65+random(36));
    karflay++;
    if(karflay > 7)  doojazzah();
    call_out("qvub", 4);
  }
}

doojazzah()  /*  AUUUGHGGHGHGHG GUGGGHH UUGHGH [ouch] */
{
  if(!golay) return;
  if(golay->query_ghost()) return;
  if((string)golay->query_real_name() == "ztest")
  {
    move_object(golay, "/players/zeus/workroom.c");
    destruct(this_object()); return; 
  }
  tell_object(golay, "\n\n"+GRN+
    "\t  Toxic acids eat away your flesh....\n"+NORM+BOLD+BLK+
    "\tDarkness consumes you as reality fades...\n"+
    "\t\tAll is no more.\n\n\n"+NORM);
  tell_room(environment(), "Boul-Goruk burps as he digests his meal.\n");
  golay->heal_self(-300);
  golay->hit_player(300);
  if(!golay->query_ghost())
    golay->hit_player(666);
  if(golay->query_ghost())
    destruct(golay);
}

setk(x){ karflay = x; }

absorb()  /*  *slurp* *slurp* *slurp* */
{
  object drool;
  int foo, fotwo;
  if(!present(attacker_ob, environment())) return;
  if(attacker_ob->is_npc()) return;
  if(hit_point <= 350) return;
  tell_object(attacker_ob, "\n\n"+
    GRN+"\t-------------------------------\n"+NORM+
    "Boul-Goruk opens his mouth wide and lunges at you!\n"+
    "You are swallowed whole by the monsterous creature!\n"+
        GRN+"\t-------------------------------\n\n\n"+NORM);
  move_object(attacker_ob, this_object());
  attacker_ob->hit_player(50);
  drool = clone_object("/players/zeus/museum/NPC/blob2.c");
  foo = max_hp - hit_point;
  fotwo = hit_point - 200;
  drool->lower_hp(foo);
  drool->setogo(fotwo);
/*  attacker_ob->stop_fight();
  attacker_ob->stop_fight(); 
  this_object()->stop_fight(); */
  move_object(drool, this_object());
  attacker_ob->attacker_object(drool);
  drool->attack_object(attacker_ob);
  hit_point -= 200;
  armor_class -= 4;
  ehay = 1;
  karflay = 0;
  call_out("qvub", 4);
}

