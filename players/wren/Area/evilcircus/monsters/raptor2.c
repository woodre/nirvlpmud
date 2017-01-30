	/*D-raptor code start...they aren't gonna like this beastie ;) */
        /* need to come up with something to barter from it...or claws */
        /* perhaps can be taken to somebody and fashioned into wep     */

inherit "/obj/monster";
#include "/players/wren/ansi.h"

int wound;

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

set_name("raptor");
set_alias("d-raptor");
set_short("a bristling D-raptor");
set_race("raptor");

set_long("The dreadful D-raptor was found on a remote swamp world. \n"+
	 "Unlike its smaller cousins from Earth this beast wasn't  \n"+
         "wiped out by a meteorological event and achieved a few   \n"+
         "years further evolution. Its scaly hide and razor jaws   \n"+
         "make it a challenge; serrated talons make it a hazard to \n"+
         "all that dare challenge it. He seems a natural part of   \n"+
         "this violent show. He watches you with intellegent eyes. \n");

set_level(21);
set_ac(19);
set_wc(34);
set_hp(600+random(200));
set_al(0);    			 /*alignment*/
set_gender("male");
set_heal(60,8);
set_chat_chance(1);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(6);		 /*combat chance chance*/

load_chat("D-raptor sniffs the air and scans the room with his yellow eyes. \n");
load_chat("D-raptor chirps oddly and twists his head to listen to something.\n");

load_a_chat("D-raptor hiss and springs at you, raking with its talons. \n");
load_a_chat("D-raptor snaps his jaws shut on your leg and shakes viciously. \n");
load_a_chat("D-raptor pounces suddenly and lands on your back.\n");
load_a_chat("You are spun around by a viscious thump from D-raptor's tail.\n");


set_chance(10);
set_spell_dam(20+random(25));
set_spell_mess1("D-raptor spins and punctures his foe through a gap in their armor. \n");    /*others*/
set_spell_mess2("D-raptor's claw slips through your defenses and pierces your side. \n");    /*attacker*/
    }
}

init() {
 ::init();
 if(!present("keeper_mob",environment(this_object())) && !attacker_ob)
 attack_object(this_player());
 }

heart_beat() {
  ::heart_beat(); /* This calls the heart_beat in monster.c to handle attacks. */

  if(attacker_ob) {
    if(attacker_ob->query_attrib("luc")+attacker_ob->query_attrib("sta") <
    random(70) && !wound) {
      move_object(clone_object("/players/wren/Area/evilcircus/items/neg/wound"),attacker_ob);
      say("D-raptor rakes "+attacker_ob->query_name()+" deeply with its claws leaving a bloody gash. \n");
      wound=1; /* Only one shot of poison. */
    }
  }
}
