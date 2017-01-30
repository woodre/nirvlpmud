inherit "/players/vertebraker/closed/std/monster";
#include "/sys/lib.h"
#include <ansi.h>


reset(arg)
{
  object gold,armor,weapon;
int random_index;
int hair_index;
  ::reset(arg);
  if(arg) return;
random_index=random(10);
hair_index=random(4);
/* Sami addition remove if u like see what u like*/
set_armor_params("other|physical",0,10,0);
set_armor_params("other|evil",0,10,0);
set_armor_params("other|magical",0,50,0);
set_armor_params("other|fire",0,-50,0);
set_name( ({"dale","mo","billy","robby","jack","tony","richard","charlie","jeff","randy"})[random_index] );
set_alt_name("worker");
set_race("human");
set_alias("roughneck");
set_short( ({""+BOLD+"Dale"+NORM+"",""+BOLD+"Mo"+NORM+"",""+BOLD+"Billy"+NORM+"",""+BOLD+"Robby"+NORM+"",""+BOLD+"Jack"+NORM+"",""+BOLD+"Tony"+NORM+"",""+BOLD+"Richard"+NORM+"",""+BOLD+"Charlie"+NORM+"",""+BOLD+"Jeff"+NORM+"",""+BOLD+"Randy"+NORM+""})[random_index]);
set_long(
query_name() + " has " + (({"blonde","brown","red","black"})[hair_index])+" hair but his hair is mostly covered by his\n"+
"hard hat.  He has a name tag on his chest that says "+query_name()+"\n"+
"|ROUGHNECK| and it is slightly covered by reflective gear.\n"+
query_name()+" has the following attributes:\n"+
"\n"+
"Body Build: "+BRED+"HUGE"+NORM+"\n"+
"Height: "+BRED+"Tall"+NORM+"\n"+
"Demeanor: "+BRED+"Pissed"+NORM+"\n"+
"\n"+
"\n"+
"\n");
set_level(19);
set_hp(1300 + random(200));
set_ac(9 + random(5));
set_wc(25 + random(5));
set_al(0);
set_heal(10,1);
set_multi_cast(1);
add_money(15000 + random(2500));
  set_chat_chance(5);
load_chat(query_name()+" looks pissed about something.\n");
load_chat(query_name()+" says: I've been working here 20 years! I know it all!\n");
set_chance(30);
armor=clone_object("/players/mo/rig/AC/helmet.c");
  move_object(armor, this_object());
  command("wear helmet", this_object());
armor=clone_object("/players/mo/rig/AC/gear.c");
  move_object(armor, this_object());
 weapon=clone_object("/players/mo/rig/WEP/wrench.c");
move_object(weapon, this_object());
weapon=clone_object("/players/mo/rig/WEP/wrench.c");
move_object(weapon, this_object());
command("wield wrench", this_object());
command("wear vest", this_object());

add_spell("slam","#MN# grabs you and\n"+
"\n"+
"\n"+
"               "+BOLD+"S L A M S"+NORM+" you to the ground!\n",
"#MN# "+BOLD+"S L A M S"+NORM+" #TN# to the ground!\n",
60,25,"physical");
add_spell("bam","#MN# takes his pipe in one hand, and wrench in the other and...\n"+
"\n"+  
"\n"+               
""+BRED+"BBBBB        AAA        MMMM       MMMM    !!!\n"+
"BBBBBB      AAAAA       MMM MM   MM MMM    !!!\n"+
"BB  BB     AA   AA      MMM  MMMM   MMM    !!!\n"+
"BBBBB     AAAAAAAAA     MMM   MMM   MMM    !!!\n"+
"BBBBBB    AAAAAAAAA     MMM         MMM    !!!\n"+
"BB  BB    AAA   AAA     MMM         MMM    !!!\n"+    
"BBBBBB    AAA   AAA     MMM         MMM\n"+
"BBBBB     AAA   AAA     MMM         MMM    !!!"+NORM+"\n"+
"\n"+
"#MN# hits you with a "+BBLU+"barrage of attacks!"+NORM+"\n",
"#MN# hits #TN# with a "+BBLU+"barrage of attacks!"+NORM+"\n",
15,125,"physical");
add_spell("charge","#MN# CHARGES AT YOU.......\n"+
"\n"+
"\n"+
"\n"+
" "+BOLD+"                              #MN# tackles you to the ground!\n"+
"\n"+
"                 #MN# pins you down and repeatedly hit you in the face!\n"+
" "+NORM+"  \n"+
"\n"+
"\n"+
"                     You slowly get back up with "+BRED+"BLOOD"+NORM+" gushing out your nose!!!\n"+
"\n",
"\n"+
" "+BOLD+"                              #MN# tackles #TN# to the ground!\n"+
"\n"+
"                #MN# pins #TN# down and repeatedly hits them in the face!\n"+
" "+NORM+"\n"+
"\n"+
"\n"+
"   #TN# slowly gets back up with "+BRED+"BLOOD"+NORM+" gushing out their nose!!!\n"+
"\n",
35,80,"physical");
add_spell("kick","#MN# kicks you in the shin! \n"+
"\n"+
"\n"+
"               "+BOLD+"OUCHIE! OUCHIE! OUCHIE!\n",
"#MN# "+BOLD+" kicks "+NORM+" #TN# in their shin!\n",
75,20,"physical");

  add_spell("Heal_spell",
    BOLD+"#MN#"+NORM+" takes a"+HIR+" Potion"+NORM+" in a bottle from under his cloak.\n",
    BOLD+"#MN#"+NORM+" drinks the"+HIY+" Potion"+NORM+" and feels"+HIG+"Rejuvenated"+NORM+".\n",
   20,"20-30",0,3,"heal_me");
}
 heart_beat() {
  object       ob;
  ::heart_beat();

  if(!attacker_ob) {
    return;
  }}

heal_me( object target, object room, int damage ) {
  int amt;
  amt = 50 + random(80);
  damage = 25 + random(25);
  set_hp_bonus( hp_bonus + amt );
  heal_self(amt);
}

