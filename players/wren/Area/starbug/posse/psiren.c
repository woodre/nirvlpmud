	/*Psiren*/

#include <ansi.h>
inherit "/obj/monster";
int X;

reset(arg)  {   if(arg) return;  change_shape();
     ::reset(arg);
     if(!arg)  {


object ob;

    ob = clone_object("/players/wren/Area/starbug/items/straw.c");
         move_object(ob,this_object());

 
set_name("psiren");

set_alias("bug");

set_short("A psiren");

set_race("psiren");

set_long("These large gelfs appear something like a big ass cockroach. They \n"+
	 "are psychic and have a taste for human and intellegent animal flesh. \n"+
         "Particularly the brains. eww. Well, they'll only get a snack around \n"+
         "these parts. Its recommended by the surgeon general that you not let \n"+
         "that plastic straw near your ear if you want to keep your frontal lobe.\n");

set_level(14);

set_ac(12);

set_wc(19);

set_hp(random(50)+200);

set_al(-1000); 			 /*alignment*/

set_aggressive(0);		 /*0 not, 1 is*/

set_chat_chance(10);		 /*chance per heartbeat load_chat messages*/

set_a_chat_chance(15);		 /*combat chance chance*/

set_chance(10);

load_chat("A strange chirping sound echos around the room.\n");
load_a_chat("Psiren projects illusion around you to disorient you.\n");

set_spell_dam(20);
set_spell_mess1("Psiren sneak up and JABS a straw into "+attacker_ob+" 's ear.\n");    /*others*/
set_spell_mess2("Psiren stabs you in the ear with a straw. OUCH \n");    /*attacker*/

    }
}

heart_beat(){  ::heart_beat();
if(!random(20)) change_shape(); }
            

change_shape() {

switch(random(5)) {

       case 4: set_short("Kryten");
               set_long("Kryten is a service android built to do cleaning and light labor around the home.\n"+
	                "Unfortunately he was left alone on an asteroid for too long and became a bit off. \n"+
                        "Lister has been trying to teach him how to break his programming and he learned  \n"+
                        "several bad habits of which he is quite proud.\n");
               set_alt_name("kryten");

	       load_chat("Kryten stands with his hand behind his back.  \n");
               load_chat("Kryten says 'Come on sir, I have something to show you\n");
	       load_a_chat("Kryten demonstrates his anger with mindless violence skill.\n");     
               load_a_chat("Kryten says: 'I'm sorry but this is going to delay lunch.\n");

               break;


       case 3:
               set_short("Pete Trater's sister ");
               set_long("This is the scantally clad sister of Pete Trater. She was \n"+
                        "the object of Lister's adolescent lust. Now she stands before\n"+
                        "you looking like the hottest thing this side of Centari Prime.\n"+
                        "Long blond hair framing, sensual lips and dark eyes. Wait, how \n"+
                        "did she get here and damn she doesn't look three million years old? \n");
               set_alt_name("sister");

               load_chat("Pete Trater's sister says 'You lusted after me all through your adolescense'.  \n");
               load_a_chat("Pete Traters's sister says 'When was the last time you were with a woman?' \n");      

               break;

       case 2:
               set_short("Professor Mamet");
               set_long("Creator of the 4000 series android. Professor Mamet in a way\n"+
                        "could be called Kryten's mum. She modeled the line after her\n"+
                        "overbearing ex-fianchee. Kryten and all his kin are powerless\n"+
                        "to resist her orders. She is wearing glasses and a lab coat.\n"+
                        "something just not quite right about her though. \n");
               set_alt_name("professor");
               set_alias("mamet");
               
               load_chat("Professor Mamet says 'Hello Kryten'.  \n");
               load_a_chat("Professor Mamet says 'Why don't you be a good chap and get in the compactor now'. \n");      

               break;

       case 1:
               set_short("A beautiful woman from a space colony");
               set_long("This is one of the hottest females you've seen outside the cinema.\n"+
                        "She and her two million sisters are stranded on a world that has \n"+
                        "lost all its men to war and disease. If they are to survive they \n"+
                        "need men to...ahem...well, you know. She eyes you hungrily. \n");
               set_alt_name("woman");    
              
               load_chat("Woman says 'We need your help, there are barely two million of us left'.  \n");
               load_chat("Woman says 'We need men to spread there seed. Save us, save us all'.\n");
               load_a_chat("Woman smiles and you knock your head against a low pipe while distracted. \n");      

               break;

       case 0:
               set_short("Dave Lister");
               set_long("Dave Lister, last human in existance. Well that was true now things have changed\n"+
                        "He was put into stasis for smuggling a cat on board through quarintine. It would \n"+
                        "have been a beauty of a plan, he'd joined Space Corp for a free ride back to earth.\n"+
                        "This offense would have net him 3 months without having to do anything. Unfortunaly.\n"+
                        "the statsis leak that killed the crew took 2 million years to dissipate. Now he's \n"+
                        "one of the biggest slobs in the universe. Occupation BUM. Beware his guitar playing.\n"+
                        "it NORMALLY hurts a lot. \n");
               set_alt_name("lister");
               
               load_chat("Lister says 'Hey hey guys, whats up'. \n");
               load_a_chat("Lister truely rocks out on the guitar. You are amazed by his skill. \n");      

               break;

             }
       if(environment())
       tell_room(environment(),"Psiren changes into "+alt_name+".\n");
             }



