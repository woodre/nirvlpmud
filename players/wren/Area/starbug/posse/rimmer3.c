	/*rimmer3*/

#include <ansi.h>
inherit "/obj/monster";
int Z;

reset(arg)  {
     ::reset(arg);
     if(!arg)  {

object ob,ob2;

        ob = clone_object("/players/wren/Area/starbug/items/reddress.c");
          move_object(ob,this_object());
          command("wear dress",this_object());
        ob2 = clone_object("/players/wren/Area/starbug/items/flibble.c");
          move_object(ob2,this_object());
          command("wield flibble",this_object());

set_name("rimmer");
set_alias("viral");
set_short("Holo-Virused Rimmer");
set_race("hologram");
set_long("Rimmer was waiting on the ship when the dwarfers explored the ship	\n"+
	 "that contained the plans and works of the great virus researcher, \n"+
         "Dr. Hildeguard Landstrom. They found her twisted form on the ship and\n"+
         "she managed to upload the virus to Rimmer through the open comm line.\n"+
         "He has developed telepathy, telekinesis, and a sidekick named Mr.Flibble.\n"+
         "Be careful, in this twisted form he could prove to be very dangerous.\n");

set_level(18);
set_ac(16);
set_wc(26);
set_hp(420);
set_al(-500);    	         /*alignment*/
set_aggressive(0);		 /*0 not, 1 is*/
set_chat_chance(5);		 /*chance per heartbeat load_chat messages*/
set_a_chat_chance(5);		 /*combat chance chance*/

load_chat("Rimmer says 'Do you a magic carpet?'\n");
load_chat("Rimmer says 'You must plead with the king of the potato people for your life.\n");
load_chat("Rimmer says 'You are very bad, you must be punished. Two hours W.O.O.'\n");
load_chat("Rimmer says 'I hate crazy people.'\n");

load_a_chat("Rimmer confers with Mr. Flibble on what to do with you.	\n");
load_a_chat("Rimmer says 'You shouldn't toy with me'		\n");

Z = random(5);
set_chance(Z);

if(Z>=3) { 
    set_spell_dam(15);
    set_spell_mess1("Rimmer catches his attacker in a force choke.\n");
    set_spell_mess2("Rimmer chokes you with a gesture.\n");
          }

if(Z=2) {
    set_spell_dam(30);
    set_spell_mess1("Rimmer lashes out with a "+RED+"HEX BOLT"+NORM+". \n");
    set_spell_mess2("Rimmer strikes you down with a "+RED+"HEX BOLT"+NORM+". \n");
        }

if(Z<2) {
    set_spell_dam(50);
    set_spell_mess1("Rimmer "+HIK+ "BLASTS"+NORM+" forth a psychic bolt.\n");
    set_spell_mess2("Rimmer "+HIK+ "BLASTS"+NORM+" you with a psychic bolt.\n");
         }

    }
}

