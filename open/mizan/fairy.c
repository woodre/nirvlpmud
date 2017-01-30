#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("Queen Fairy");
set_alias("fairy");
set_alt_name("queen fairy");
set_race("fairy");
set_short("Queen Fairy");
set_gender("female");
set_long(
  "A strange looking fairy, her skin has a wooden look to it.  Her\n"+
  "hair is dark green, and shaped like thin blades of grass.  She\n"+
  "has two wide wings on her back which flap slowly.\n");

set_level(20);
set_hp(500+random(100));
set_al(1500);
set_ac(15);
set_wc(26);
set_dead_ob(this_object());

set_chat_chance(5);
   load_chat("The fairy flutters her wings.\n");
   load_chat("The fairy zips through the air.\n");
set_a_chat_chance(15);
   load_a_chat("The fairy dodges your attack!\n");

gold = clone_object("obj/money");
gold->set_money(5000+random(1001));
move_object(gold,this_object());
}

monster_died() {
  tell_room(environment(this_object()),
       "The dead fairy plops to the ground.\n");
  MOCO("/players/jaraxle/3rd/silence/items/ring_piece5.c"),environment(this_object()));
return 0; }

THORNS()
{
   string ATT_NAME,ATT_LVL,ATT_LVL2;
   if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
   if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
   if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();

   /* We don't want to be attacking a ghost */
   if(attacker_ob && !attacker_ob->query_ghost())
   {
      /* Tell attacker they are about to get hit. */
      say("The fairy claps her hands.\n\tThorns crash down from the trees!\n");

      /* Cascade down the levels, higher lev players get whacked more */
      if(ATT_LVL2 >= 4) /* querying extralevels */
      {
         say("\t\tThe thorns thunder into "+ATT_NAME+"'s body!\n"); 
         attacker_ob->hit_player(20+random(11));
      }
      else if(ATT_LVL >= 17)
      {
         say("\t\tThe thorns slash "+ATT_NAME+"'s body painfully!\n"); 
         attacker_ob->hit_player(10+random(11));
      }
      else if(ATT_LVL >= 12)
      {
         say("\t\tThe thorns scratch across "+ATT_NAME+"'s body!\n"); 
         attacker_ob->hit_player(5+random(6));
      }
      else if(ATT_LVL >= 2)
      {
         say("The thorns zip past "+ATT_NAME+".\n");
         attacker_ob->hit_player(10+random(10));
      }
   } /* end if attacker_ob && query_ghost() */
} /* end thorns */

WIND(){
 string ATT_NAME,ATT_LVL,ATT_LVL2;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
 if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   say("Queen Fairy whips up a gust of wind...\n");
   if(ATT_LVL >= 2){
   say("A breeze whisks by "+ATT_NAME+".\n");
   attacker_ob->hit_player(10+random(10));
}
  if(ATT_LVL >= 12){
   say("\t"+HIB+"Winds blow into "+ATT_NAME+".\n"+NORM);
   attacker_ob->hit_player(3+random(6));
}
  if(ATT_LVL >= 17){
   say("\t"+HIW+"A gust of wind pushes "+ATT_NAME+" to the floor!"+NORM+"\n");
   attacker_ob->hit_player(15+random(11));
}
  if(ATT_LVL2 > 4){
   say("\t"+HIB+"Thunderous winds punish "+ATT_NAME+".\n"+NORM);
   attacker_ob->hit_player(25+random(16));
}
}
SUN(){
 string ATT_NAME,ATT_LVL,ATT_LVL2;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
 if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   say("Queen Fairy raises her hands to the sky...\n");
   if(ATT_LVL >= 2){
   say("A ray of light barely misses "+ATT_NAME+".\n");
   attacker_ob->hit_player(10+random(10));
}
  if(ATT_LVL >= 12){
   say("\t"+HIY+"A ray of light beams to the ground and tans "+ATT_NAME+"!\n"+NORM);
   attacker_ob->hit_player(10+random(6));
}
  if(ATT_LVL >= 17){
   say("\t"+HIW+"The light burns into "+ATT_NAME+"!"+NORM+"\n");
   attacker_ob->hit_player(15+random(16));
}
  if(ATT_LVL2 > 4){
   say("\t"+HIY+"Rays of light beam down, burning "+ATT_NAME+" to a "+HIR+"crisp"+HIY+"!"+NORM+"\n");
   attacker_ob->hit_player(25+random(21));
}
}
LEAVES(){
 string ATT_NAME,ATT_LVL,ATT_LVL2;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
 if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
    say("Queen Fairy swarms up a "+HIG+"tornado of leaves."+NORM+"\n");
   if(ATT_LVL >= 2){
   say("The "+HIG+"leaves"+NORM+" dance around "+ATT_NAME+".\n");
   attacker_ob->hit_player(10+random(10));
}
  if(ATT_LVL > 12){
    say("\tThe "+HIG+"tornado of leaves"+NORM+" glance softly at "+ATT_NAME+".\n");
   attacker_ob->hit_player(5+random(5));
}
  if(ATT_LVL >= 17){
    say("The "+HIG+"tornado of leaves"+NORM+" snap dangerously at "+ATT_NAME+".\n");
   attacker_ob->hit_player(5+random(6));
}
  if(ATT_LVL2 > 4){
    say("\tThe "+HIG+"tornado of leaves"+NORM+" lash "+HIR+"violently"+NORM+" at "+ATT_NAME+".\n");
   attacker_ob->hit_player(15+random(11));
}
}
FLOWER(){
 string ATT_NAME,ATT_LVL,ATT_LVL2;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
 if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   say("Queen Fairy waves her hands in a swooping motion...\n");
   if(ATT_LVL >= 2){
   say("A shower of petals dance around the fairy.\n");
   this_object()->heal_self(10+random(10));
}
  if(ATT_LVL >= 12){
   say("\tA rain of "+HIM+"flower petals"+NORM+" dance around the fairy.\n");
    this_object()->heal_self(10+random(6));
}
  if(ATT_LVL >= 17){
   say("\tTwirling "+HIM+"flowers"+NORM+" fall from the forest.\n");
    this_object()->heal_self(15+random(16));
}
  if(ATT_LVL2 > 4){
   say("\t\tThorned "+HIR+"roses"+NORM+" shoot into "+ATT_NAME+" like arrows!\n");
   attacker_ob->hit_player(20+random(16));
}
}
ALL(){
 string ATT_NAME,ATT_LVL,ATT_LVL2;
  if(attacker_ob)  ATT_NAME = attacker_ob->query_name();
 if(attacker_ob)  ATT_LVL = attacker_ob->query_level();
 if(attacker_ob)  ATT_LVL2 = attacker_ob->query_extra_level();
   say("The Queen Fairy rises high above you and spreads her wings wide apart...\n");
   say("   She holds out her palms...\n");
   if(ATT_LVL >= 2){
   say("\tA shower of "+HIM+"petals"+NORM+" dance around the Queen Fairy.\n"); 
   say("\t\tA gust of "+HIB+"wind"+NORM+" lifts "+ATT_NAME+" in the air.\n");
   say("\t"+GRN+"Leaves"+NORM+" twirl up from the ground circling "+ATT_NAME+".\n");
   say("\t\t"+HIW+"Rays o"+HIY+"f sunshine"+NORM+" shoot through the "+GRN+"leaves"+NORM+" into "+ATT_NAME+".\n");
   say("\tThorns shower in through the "+HIW+"rays o"+HIY+"f light"+NORM+"!\n");    this_object()->heal_self(10+random(1));   
   attacker_ob->hit_player(20+random(16));
}
  if(ATT_LVL >= 12){
   say("\tA rain of "+HIM+"flower petals"+NORM+" dance around the Queen Fairy.\n"); 
   say("\t\tA gust of "+HIB+"wind"+NORM+" lifts "+ATT_NAME+" in the air.\n");
   say("\t"+GRN+"Leaves"+NORM+" shoot into "+ATT_NAME+" like darts!\n");
   say("\t\tArrows of "+HIW+"light"+NORM+" penetrate "+ATT_NAME+"'s body!\n");
   say("\tTree branches drive into "+ATT_NAME+"'s chest!\n");
    this_object()->heal_self(20+random(6));
    attacker_ob->hit_player(20+random(16));
}
  if(ATT_LVL >= 17){                  
   say("\tTwirling "+HIM+"flowers"+NORM+" fall from the forest over the Queen Fairy.\n");
   say("\t\tA "+HIB+"tornado of winds"+NORM+" spin "+ATT_NAME+" in place.\n"); 
   say("\tA "+GRN+"giant leaf"+NORM+" slaps around "+ATT_NAME+".\n");
   say("\t\tA "+HIY+"giant beam of "+HIW+"light"+NORM+" drops down from the sky, and "+HIR+"~"+NORM+RED+"BURNS"+HIR+"~"+NORM+" "+ATT_NAME+" to a crisp!\n");
   say("\tGiant log spears drive through "+ATT_NAME+"'s body!\n");   this_object()->heal_self(25+random(16));    
   attacker_ob->hit_player(30+random(26));
}
  if(ATT_LVL2 > 4){
   say("\t\tThorned "+HIR+"roses"+NORM+" shoot into "+ATT_NAME+" like arrows!\n"); 
   say("\tSwirling "+HIB+"winds"+NORM+" swarm the room with razor sharp "+GRN+"leaves"+NORM+"!\n");      
   say("\t\tRazor sharp "+GRN+"leaves"+NORM+" slice into "+ATT_NAME+", spraying "+RED+"blood"+NORM+" everywhere!\n");
   say("\tAn aura of light surrounds the Queen Fairy...\n"+
       "\t\tQueen Fairy drops a bubble of light onto "+ATT_NAME+"!\n");
   say("\tGiant log spears drive through "+ATT_NAME+"'s body!\n");
   attacker_ob->hit_player(45+random(21));
}
}

heart_beat(){
int i;
  ::heart_beat();
if(attacker_ob){
i = random(18);
switch(i){

    case 0..1: SUN();
  break;
    case 2..3: WIND();
   break;
    case 4..5: LEAVES();
   break;
    case 6..7: FLOWER();
   break;
    case 8..11: ALL();
   break;
    case 12..13: THORNS();
   break;
    case 14..17: return 0;
   break;
    }
  }
}
