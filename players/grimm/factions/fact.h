/* other defines that need to be in your files are:             */
/* #define THISFACTION "stng"   which is the id of your faction */
#define TP        this_player()
#define TO        this_object()
#define GLEVEL    TP->query_guild_rank()
#define NAME      TP->query_real_name()
#define CN        capitalize(NAME)
#define THIS      environment(TO)
#define ENV_THIS  environment(TP)
#define LEVEL     TP->query_level()
#define QRN       query_real_name()
#define QGR       query_guild_rank()
#define QGEXP     query_guild_exp()
#define HEAL_SWAP 10
int MUFFLED;
 
 
/* Don't let the item be dropped */
drop() { return 1; }
 
 
/* Don't let the item be taken */
get() { return 1; }
 
 
/* Get the possessive of the player */
query_possessive() {
  if(TP->query_gender()=="male") return "his";
  else if(TP->query_gender()=="female") return "hers";
  return "its";
}
 
 
/* Get wether the player has the faction lines on or not */
query_muffled() { return MUFFLED; }
 
 
/* This will be used for 'other language says' so only the people who */
/* understand the say, will understand it */
say_it_in_lingo(str) {
  object ob;
  if(!str) {
    write("Say what?\n");
    return 1;
  }
  ob = first_inventory(ENV_THIS);
  while(ob) {
    if(present(THISFACTION,ob) && ob!=TP)
      tell_object(ob,CN+" recites: "+str+"\n");
    else
      if(ob!=TP)
        tell_object(ob,CN+" speaks in a cryptic tongue.\n");
    ob = next_inventory(ob);
  }
  write("You recite: "+str+"\n");
  return 1;
}
 
 
/* The following is used for guild-who's                    */
/* usage is:  low  = lowest guild level to display          */
/*            hi   = highest guild level to display         */
who_is_on(low,hi) {
object people;
string sex;
object bad;
int n;
people = users();
write("-Name-\t\t-Sex-\t-Level-\t-Location-\n");
for(n=0; n<sizeof(people); n++) {
  if(present(THISFACTION,people[n])) {
    if(people[n]->query_invis() > LEVEL) {
      write("");
    } else {
    if(people[n]->QGR<(hi+1) &&
       people[n]->QGR>(low-1)) {
      write(capitalize(people[n]->QRN));
      if(strlen(people[n]->QRN)>7) { write("\t"); }
      else { write("\t\t"); }
      sex=people[n]->query_gender();
      if(sex=="male") sex="M";
      else if(sex=="female") sex="F";
      else sex="C";
      write(sex+"\t");
      write(people[n]->QGR+"\t");
      if(present("badge",people[n])->query_morphed()) {
        write(environment(people[n])->short()+" -> "+
        environment(environment(people[n]))->short());
      } else {
        write(environment(people[n])->short());
      }
      if(people[n]->query_invis() > 0) write("  (invis)");
      bad = present(THISFACTION,people[n]);
      if(bad->query_muffled()==1) write("  (muffled)");
      write("\n");
    }
    }
  }
}
return 1;
}
 
 
/* The following is how to use the who_is_on function above 
guild_who() {
  who_is_on(1,1000);
  return 1;
}
*/ 
 
 
/* This fuction tells the guilders who are in your faction a string */
/* paramaters are:  str    string to tell them                      */
/*                  lt     string on left side of tellers name      */
/*                  rt     string on right side of tellers name     */
tell_the_guilders(str,lt,rt) {
  object people;
  int n;
  people=users();
  for(n=0;n<sizeof(people);n++)
    if(present(THISFACTION,people[n]) && 
       !present(THISFACTION,people[n])->query_muffled())
        tell_object(people[n],lt+CN+rt+": "+str+"\n");
  return 1;
}
 
 
/* The following is an example on how to use the above 
guild_tell(str) {
  if(GLEVEL<10) {
    write("Only guild level 10+ people can use that.\n");
    return 1;
  }
  if(!str) {
    write("What do you want to tell them?\n");
    return 1;
  }
  tell_the_guilders(str,"{","}");
  return 1;
}
*/
 
 
/* The following procedure lessens a players spell points by I amount */
lessp(i) {
  TP->add_spell_point((-1 * i));
  return 1;
}
 
 
/* This procedure lets a person emote something */
/* to the other faction members.                */
guild_emote(str) {
  int i, lev;
  object people;
  lev = 10;
  if(GLEVEL<10) {
    write("You are not a high enough level to do that yet.\n");
    return 1;
  }
  if(!str) {
    write("What do you want to emote?\n");
    return 1;
  }
  people = users();
  for(i=0;i<sizeof(people);i++) {
    if((present(THISFACTION,people[i])
      && people[i]->QGR>lev)) {
      if(!present(THISFACTION,people[i])->query_muffled())
        tell_object(people[i],"\n+>>"+CN+" "+str+"\n");
    }
  }
  lessp(2);
  write("You faction_emote:\n"+CN+" "+str+"\n");
  return 1;
}
 
 
/* The following is a very useful attack interpreting function.  
   an example on how it is used it the HORDE procedure below it */
getem(GLEV,hit,sp,what,writemsg,saymsg) {
  object ob;
  if(GLEVEL<GLEV) {
    write("You are not a high enough level for that yet.\n");
    return 1;
  }
  if(TP->query_sp()<sp) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if(present(what,ENV_THIS))
    ob=present(what,ENV_THIS);
  else { write("That is not here.\n");
          return 1;
    }
  if(!ob->query_npc()) {
    write("That is not a monster.\n");
    return 1;
  }
  TP->attack_object(ob);
  ob->hit_player(hit);
  lessp(sp);
  write(writemsg+".\n");
  say(saymsg+".\n");
  return 1;
}
 
 
/* The following is an example on how to use the GETEM function above
horde(str) {
  string what,cwhat;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("Send a horde on what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem(6,30,30,what,"You send a horde of little dopples to beat the shit out of a "+cwhat,CN+" sends a horde of little dopplegangers against a "+cwhat);
  return 1;
}
*/
 
 
/* Check if the player is above a given level */
lvl_ok(x) {
  if(GLEVEL>(x-1)) return 1;
  write("You are not a high enough guild level for that yet.\n");
  return 0;
}
 
 
/* Swap X coins for healing at a HEAL_SWAP to 1 ratio */
swap_coins_for_healing(x) {
  int amt;
  amt = x / HEAL_SWAP;
  if(TP->query_money()<x) {
    write("You do not have enough coins for that.\n");
    return 1;
  }
  TP->add_money(-x);
  TP->heal_self(amt);
  write("You healed yourself for "+amt+" points.\n");
  say(CN+" healed "+query_possessive()+"elf.\n");
  return 1;
}
