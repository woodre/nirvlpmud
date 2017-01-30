#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";
object LIPPARD;

reset(arg){
  ::reset(arg); 
 if(arg) return;
LIPPARD=this_object();
set_name("nyddle");
set_short("A small nyddle");
set_long("This small little lizard looks very similar to a rabbit as it\n"+
         "hops around the room carelessly.  It's large feet comform well\n"+
         "to the rocky terrain as it moves painlessly.  Though cute small\n"+
         "teeth show through the nice exteror, giving a hint of danger.\n");
set_level(6);
set_hp(60);
set_wc(50);
set_ac(6);
set_aggressive(0);
set_a_chat_chance(40);
load_a_chat("Teeth slice into you.\n");
load_a_chat("The nyddle runs between your legs.\n");
load_a_chat("The nyddle screeches.\n");
set_al(-100);
set_chat_chance(5);
load_chat("The nyddle hops around.\n");
load_chat("The nyddle chases it's tail.\n");
load_chat("The nyddle smiles.\n");
load_chat("The nyddle wiggles it's nose.\n");
/*autoattack*/
ac_bonus += 4;
/*follow */
ac_bonus += 4;
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
  if(this_player() && (this_player()->is_player())) /* la!  verte 11.16.01 */
  if(sscanf(str,"%s leaves %s.",name,dir) == 2){
        if(random(8) < 5){
          say("The nyddle hops around.\n");
          command(dir);
} }     }

attackme(){
if(!attacker_ob && random(15) == 1){
  tell_object(this_player(),"The nyddle pounces on you and attacks.\n");
attacker_ob = this_player();
}
return 0;
}
