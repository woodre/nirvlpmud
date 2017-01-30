#include "../scar.h"

#define COST 25          /* cost to challenge, sps */
#define TIME 900         /* seconds player has to prepare */
#define ChampionMin 10   /* ranks below #1 that can challenge champion */
#define HIGH 25          /* # ranks we can challenge higher than us */
#define LOW 10           /* # ranks we can challenge lower than us */
#define TEMPLE MKDIR+"Temple"
#define LOG LOGDIR+"Challenge"
#define TPN this_player()->query_name()

main(str) {
  int Finished, i;
  object ob,target;
  mapping warriors;
  string *war_keys;

  if (!str) {
    write("Who do you wish to challenge?\n");
    return 1;
  }

  if(this_player()->query_level() < 18) {
    write("You are too weak to challenge someone.\n");
    return 1;
  }
  if (this_player()->query_ghost()) {
    return 1;
  }
  if(previous_object()->QMKChallenge()) {
    write("The current Mortal Kombat Challenge must be finished first.\n");
    return 1;
  }
/*
  if(previous_object()->QCDelay() > 0 ) {
    write("You must wait before challenging again.\n");
    return 1;
  }
*/
  if(previous_object()->QMKRank() == "---" ||
     previous_object()->QMKRank() < 1) {
    write("You are unable to challenge for some reason.\n");
    return 1;
  }
  warriors = WARRIORS;
  war_keys = keys(warriors);
  war_keys -= war_keys[member_array("Goro",war_keys)];
  str = capitalize(str);
  if(str == "Subzero" || str == "Sub-zero") str = "Sub-Zero";
  if(str == "Johnnie" || str=="Cage" || str=="Johnnie cage") str = "Johnnie Cage";
  if(str == "Liu kang" || str=="Kang" || str == "Liu") str = "Liu Kang";
  if(MAP->member_map(str, warriors) > -1) {
/* No NPC fighting at this time - Beck 4/2002 */
write("You may only challenge players right now.\n");
return 1;
    if(previous_object()->QMKVictim(str)) {
      target = warriors[str];
    }
    else {
      i = random(sizeof(war_keys));
      while(sizeof(war_keys) > 0 && previous_object()->QMKVictim(war_keys[i])) {
        war_keys -= war_keys[i];
        i = random(sizeof(war_keys));
      }
      if(sizeof(war_keys) == 0) target = warriors["Goro"];
      else target = warriors[war_keys[i]];
      if( str != target->query_name()) {
        write("Shang Tsung tells you: You are not worthy of challenging "+str+"!\n");
        write("Shang Tsung tells you: You will fight "+target->query_name()+" instead.\n");
        str = target->query_name();
      }
    }
  }
  else {
    str = lower_case(str);
    target = find_player(str);
    }
  if (!target) {
    write(capitalize(str) + " is not logged on.\n");
    return 1;
  }
  /************************************************************
  *              Checks for players only
  ************************************************************/
  if( target->is_player()) {
    if(target->query_level() < 18) {
      write(capitalize(str)+" is too weak for you to challenge.\n");
      return 1;
    }
    if(target->query_level() > 19) {
      write(capitalize(str)+" can't be challenged.\n");
      return 1;
    }
    ob = present("bloodscar",target);
    if(target->query_ghost()) {
      write("That player is dead.\n");
      return 1;
    }
  
    if (target == this_player()) {
      write("A great warrior like you wants to fight yourself?  How weak.\n");
      return 1;
    }

     if(ob->QLoginTime() < TIME) {
      write(capitalize(str)+" has not had time to prepare for battle.\n");
      tell_object(target, capitalize(this_player()->query_name())+" attempted to challenge you.\n");
      return 1;
    }
    if(ob->QMKRank() == 1 && previous_object()->QMKRank() > ChampionMin) {
      write("Your rank is too low to challenge the Champion.\n");
      return 1;
    }
    if(ob->QMKRank() <= previous_object()->QMKRank()) {
      if(previous_object()->QMKRank() - ob->QMKRank() > HIGH) {
        write("Your rank is not high enought to challenge "+capitalize(str)+".\n");
        return 1;
      }
    }
    else {
       if(ob->QMKRank() - previous_object()->QMKRank() > LOW) {
         write(target->query_name()+" is ranked too low for you to challenge.\n");
         return 1;
       }
    }
  }
  else {
    target = target->Target();
    move_object(target, "/room/void");
    ob = present("bloodscar",target);
   }
  
  /************************************************************
  *          Checks both players and NPC's
  ***********************************************************/
  if (!ob) {
    write("You can only fight Champions of Mortal Kombat.\n");
    return 1;
  }
  if(ob->QMKChallenge()) {
    write(capitalize(str)+" has already been challenged by another.\n");
    return 1;
  }
 
  if (this_player()->query_spell_point() < COST){
    write("You don't have enought spell points.\n");
    return 1;
  }
  /***********************************************************/

  this_player()->add_spell_point(-COST);
  ob->Challenged(1, this_player());
  previous_object()->Challenged(0, target);
  previous_object()->SCDelay();  /* Challenge delay */
  write("You have challenged " + capitalize(str) + " to fight to the death in Mortal Kombat!\n");
  tell_object(target, capitalize(this_player()->query_real_name()) +
        " challenges you to fight in Mortal Kombat.\n" +
        "You can either 'accept challenge' or 'forfeit'.\n");
  write_file(LOG, ctime(time())+": "+this_player()->query_name()+" challenged: "+str+".\n");
  /* CHANNELD->broadcast(TPN+" has challenged "+capitalize(str)+" in Mortal Kombat!\n", 0, "Blood"); */
  CHANNELD->transmit_message( CHANNAME, TPN+" has challenged "+capitalize(str)+" in Mortal Kombat!\n" );
  if(!target->is_player()) ob->MKNPC();
  return 1;
}
