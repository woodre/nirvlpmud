#include "/players/dragnar/Jedi/NPC/master_defs.h"
inherit "obj/monster";


#define Space "             "
#define MAX 10      /* Max skill level */

reset(arg){
   ::reset(arg);
   if(arg) return;
   skills = ({ "aid","mend","dodge","absorb",});
   Info = ({ "force","code","dedication", });
   set_name("kiran");
   set_race("human");
   set_gender("male");
   set_alias("master");
   set_short("Kiran ["+HIG+"jedi master"+NORM+"]");
   set_long("Kiran wears a black cloak around his body with the hood pulled\n"+
            "over his head.  The details of his face are lost in the darkness,\n"+
            "but you can feel when he looks at you.  His gaze is intense, and it\n"+
            "seems as if he is looking into your soul.  Kiran is not a tall man,\n"+
            "but you get the feeling that he is able to take care of himself.\n"+
            "You can't help wonder if he could teach you about the Jedi ways.\n");
   set_level(20);
   set_hp(2000);
   set_al(random(800));
   set_wc(40);
   set_ac(20);
   gob = clone_object("/players/dragnar/Jedi/jedi.c");
   move_object(gob, this_object());
   gob->set_wep_life(1000);
   gob->adj_skill("saber",10);
   gob->adj_skill("physical",10);
   gob->adj_skill("telepathy",10);
   gob->adj_skill("telekinesis",10);
   command("colorwep HIY",this_object());
   set_aggressive(0);
   set_heart_beat(1);
}

/*****************************************************************
 **   Helper functions for training and talking to the player   **
 *****************************************************************/

void InfoMsg(int num) {
  if(!Trainee) return;
  switch(num) {
  case 0:
    tell_object(Trainee, "\nKiran says: \"The Force is the energy that surrounds us, binds us.\n"+
      Space+"Life creates it, make it grow.  A Jedi feels the Force, and uses\n"+
      Space+"it to do his will.  But, there is a Darkside of the Force.  A Jedi\n"+
      Space+"must beware of it.  Calm, peace, and inner reflection are the \n"+
      Space+"allies of a Jedi.  Hate, fear, and aggression will lead you down \n"+
      Space+"the dark path.  Forever will it consume you.\n");
    break;
  case 1:
    tell_object(Trainee, "\nKiran says: \"The code the Jedi must live by is not an easy one.  A\n"+
      Space+"Jedi walks the world of Nirvana, serving the Council in what\n"+
      Space+"is what good and just.  The Council is a group of Jedi Masters\n"+
      Space+"that decides as a body what items the Jedi will face.  A Jedi\n"+
      Space+"may be called upon at any time to serve a request from the \n"+
      Space+"Council.  And every duty must be carried out with the highest \n"+
      Space+"regard to the Light Side of the Force.\"\n");
    break;
  default:
    tell_object(Trainee, "\nKiran says: \"The dedication of a Jedi must be a lifelong commitment.\n"+
      Space+"A Jedi's life is based on training and serving the Force.  From\n"+
      Space+"the time a Jedi first becomes an apprentice, they sacrifice their\n"+
      Space+"entire lives to training and gaining knowledge about the force.\n"+
      Space+"Becoming an apprentice is not easy however.  The canidate must\n"+
      Space+"be identified by a Jedi Master and then must be approved by\n"+
      Space+"the Council.  And that is the begining of the journey.\"\n");
    break;
  }
}

void SkillInfo(int num) {
  if(!Member || !Trainee) return;
  switch(num) {
  case 0:
    tell_object(Trainee, "\nKiran says: \"Aid is a spell that will enable you to help your friends\n"+
    Space+"in combat.  It will cause you to rush to the front of the\n"+
    Space+"battle, keeping your ally from harm.  A well trained Jedi will\n"+
    Space+"even be able to heal their friend while running into battle.  To\n"+
    Space+"use your power, just type: aid <person>.\"\n");
    break;
  case 1:
    tell_object(Trainee, "\nKiran says: \"Mend is a powerful Jedi skill that enables the Jedi to\n"+
      Space+"call on the force to increase the rate of regeneration in\n"+
	  Space+"the users body. This effect is instantaneous, sealing wounds\n"+
	  Space+"and wiping away the pains of battle. It can also be used on a\n"+
	  Space+"Jedi's allies for the same effect. To use your power, type: \n"+
	  Space+"mend <ally> (defaults to the caster).\"\n");
    break;
  case 2:
    tell_object(Trainee, "\nKiran says: \"Dodge is a skill that comes directly from the force. \n"+
      Space+"A Jedi is able to foresee an attack, therefore, dodging\n"+
      Space+"it before it can cause them bodily harm. This ability \n"+
      Space+"takes the form of a superpowerful instinct, and is not \n"+
	  Space+"controlled by the Jedi, but occurs auto-matically \n"+
	  Space+"during combat.\n");
    break;
  default:
    tell_object(Trainee, "\nKiran says: \"Absorb allows a Jedi to summon the living force \n"+
      Space+"around their body, taking part of the kinetic energy \n"+
      Space+"concentrated on them and redirecting it harmlessly away.\n"+
      Space+"To use this skill type: absorb.\"\n");
    break;
  }
}

#include "/players/dragnar/Jedi/NPC/master.h"
