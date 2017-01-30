inherit "/obj/monster";
#include "/players/jareel/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("skeleton");
set_alias("bones");
   set_race("skeleton");
    set_al(-500);
    set_level(15);
    set_aggressive(1);
    set_hp(60);
    set_wc(100);
    set_gender("male");
    set_short(""+BOLD+YEL+"Skeleton"+NORM+"");
    set_long(
      "The frail gathering of bones seem to move without any\n"+
      "form of mucle structure.  Its holow skull has a darkness\n"+
     "in its eye hols that seem to peer right into you..\n");
 set_spell_mess2(""+BOLD+YEL+"Skeleton bone shards\n"+
 "splinter off slashing your skin.'"+NORM+"\n");
 set_chance(60);
set_spell_dam(1+random(50));
}
heart_beat(){
string ATT_NAME,msg;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
    msg =""+BOLD+YEL+"Skeletal bone shards slash "+ATT_NAME+"."+NORM+"\n";
  set_spell_mess1(msg);
::heart_beat();
}
