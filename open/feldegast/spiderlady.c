/*
File: spiderlady.c
Author: Feldegast
Date: 2-24-02
Description:
  A sorceress with a spider obsession.  She has web and venom attacks,
as well as several spells.  Found in the spider cave in Caladon.
*/

#include "/players/feldegast/defines.h"

inherit MONSTER;

int venom;
int web;

reset(arg) {
  ::reset(arg);
  venom = 0; web = 0;
  if(arg) return;
  set_name("arachnia");
  set_alt_name("widow");
  set_alias("sorceress");
  set_short(HIR+"Arachnia"+NORM+", the "+BOLD+BLK+"Black Widow"+NORM);
  set_long(
    "  Arachnia is a voloptuous woman in an alluring leather outfit.\n"+
    "She was once a popular socialite and a rising star in the field of\n"+
    "magic.  Her obsession with spiders and her carnivorous tendencies in\n"+
    "regard to her mates caused her to become an outcast.  Her sanity has\n"+
    "declined drastically, but at least she is no longer distracted from\n"+
    "her spiders... Or her magic.\n"
  );
  set_al(-700);
  set_gender("female");
  set_race("human");
  set_level(22);
  set_wc(37);
  set_ac(22);
  set_hp(700);
  set_dead_ob(this_object());
  set_chat_chance(5);
  load_chat("Arachnia stares at you with a look of utter madness.\n");
  load_chat("Arachnia says: I could just eat you all up!\n");
  set_a_chat_chance(5);
  load_a_chat("Arachnia surrounds herself in a "+BLU+"protective field"+NORM+".\n");
  load_spell(20,50,0,
    "\nArachnia points at you with her finger and shoots a "+HIR+"jet of flame"+NORM+"!\n\n",
    "\nArachnia points at #ATT# with her finger and shoots a "+HIR+"jet of flame"+NORM+"!\n\n");
}

heart_beat() {
  object spider;
  ::heart_beat();
  if(attacker_ob) {

    /* Random chance of casting webs at the player. */

    if(attacker_ob->query_attrib("luc")+attacker_ob->query_attrib("sta") < random(45) &&
       web < 4 && !present("web_token", attacker_ob)) 
    {
      move_object(clone_object("/players/feldegast/obj/web_token.c"),attacker_ob);
      say(YEL+"\nArachnia points at "+attacker_ob->query_name()+" with both hands as she bends her wrists.\n"+
          "A stream of webs shoot from her arms, binding "+attacker_ob->query_name()+" in webs!\n\n"+NORM);
      web++;
    }

    /* Random chance of poisoning the player. */

    else if(attacker_ob->query_attrib("luc") + attacker_ob->query_attrib("sta") < random(45) &&
            venom < 2 && !present("poison", attacker_ob)) 
    {
      move_object(clone_object("/players/feldegast/obj/poison2.c"), attacker_ob);
      say(GRN+"\nMoving with remarkable speed, Arachnia opens her mouth to reveal hideous\n"+
              "fangs.  She swiftly closes upon "+attacker_ob->query_name()+" and injects her venom!\n\n"+NORM);
      venom++;
    }

    /* Random chance of summoning a spider. */
    else if(!random(8))
    {
      spider = clone_object(MON_PATH+"spider.c");
      move_object(spider, environment());
      spider->set_master(this_object());
      spider->attacked_by(attacker_ob);
      say("A spider skitters in and leaps to defends its mistress!\n");
    }

    /* Occasionally hit more than once, just so I can get in an example for Coldwind. */
    if(!random(20) && !attacker_ob->query_dead())
    {
      already_fight=0;
      attack();
    }
  }

}

