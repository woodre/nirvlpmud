/* Changing to sys/ansi.h - Rumplemintz - Dec-07-2009
#include "/players/wocket/closed/ansi.h"
*/
#include <ansi.h>
inherit "/obj/monster.c";
/* object LIPPARD;  - Not sure what this is for - Rumplemintz
 */

reset(arg){
    if(arg) return;
/*  LIPPARD=this_object();  - Not sure what this is for - Rumplemintz
 */
    ::reset(arg);
    set_name("lippard");
    set_short();
    set_long("The lippard moves silently along the walls, blending in perfectly as\n"+
      "its scaled skin changes colors to match the background.  Sharp claws\n"+
      "reflect the soft violet light of the mucus, as it gazes upon you.  The\n"+
      "lippard is tracking you as if getting ready to pounce.\n");
    set_level(20);
    set_hp(500);
    set_wc(50);
    set_ac(17);
    set_a_chat_chance(40);
    load_a_chat("Claws rip deeply into you.\n");
    load_a_chat("You lose sight of the lippard.\n");
    load_a_chat("The lippard pouces upon you shreading you with it's claws.\n");
    set_al(-1000);
    set_chat_chance(5);
    load_chat("The lippard grins.\n");
    load_chat("The lippard moves silently along the wall.\n");
    load_chat("The lippard crouches.\n");
 move_object(clone_object("/players/wocket/caves/OBJ/sliver.c"),this_object());
    /* autoattacks (no peace) */
    ac_bonus += 4; 
    /* 1/3 chance follow if attacking */
    wc_bonus += 3;
}

init(){
    ::init();
#ifndef __LDMUD__
   add_action("attackme");add_xverb("");

#else
   add_action("attackme","", 3);

#endif
}

catch_tell(str){
    string name,dir;
    if(this_player() && this_player()->is_player()) /* added by verte 6.9.01 */
	if(sscanf(str,"%s leaves %s.",name,dir) == 2){
	    if(attacker_ob){
		if(name = attacker_ob->query_name()){
		    if(random(3)==1){
			tell_object(attacker_ob,"The lippard anticipates your move.\n");
			command(dir);
		    } } } } }

attackme(){
    if(!attacker_ob && random(10) == 1){
	if(this_player()->is_player()){
	    tell_object(this_player(),"The lippard notices you and attacks.\n");
	    attacker_ob = this_player();
	}
    }
    return 0;
}
