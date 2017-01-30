inherit "/obj/treasure.c";
#include <ansi.h>
#define ATT ppl[i]->query_attack()
#define ATTN ppl[i]->query_name()

reset (arg) {
	set_id("guitar");
      set_weight(1);
	set_short("Catacomb's "+HIB+"BASS"+NORM+" Guitar");
	set_long(
      "  This is my bass guitar.  It has the normal 4 strings\n"+
      "for blasting out some sweet riffs.\n"); 
      
}

init(){
  ::init();
     add_action("blastem", "blast");
     add_action("gnamer", "gnset");
     add_action("alignset","alset");
     add_action("getmyshit","gs");   
     add_action("help","helpG");
     add_action("whonew","catwho");  
}

blastem(str){
  object who;
  if(!str) 
  { 
    write("Who do you want to blast?\n");
    return 1; 
  }
  who = find_player(str);
  if(!who)
  {
    write("You can't find the person to impress with your mad skills.\n");
    return 1;
  }
  write("You grab the pick and aim the amplifier at "+capitalize(str)+".\n");
  tell_object(who, capitalize(this_player()->query_name())+" aims the amplifier to his bass guitar at you.\n\n"+
     "            COVER YOUR EARS!!!!\n\n");
  tell_object(who, capitalize(this_player()->query_name())+" brings down the pick and releases a low\n"+
     " "+HIY+"            EEEEEEEEEEEEEEEEEEEEEEE      \n"+
            "             EEEEEEEEEEEEEEEEEEEEEEE      \n"+
            "             EEEEEEE                      \n"+
            "             EEEEEEE                      \n"+
            "             EEEEEEEEEEEEEEEE             \n"+
            "             EEEEEEEEEEEEEEEE             \n"+
            "             EEEEEEE                      \n"+
            "             EEEEEEE                      \n"+
            "             EEEEEEEEEEEEEEEEEEEEEEE      \n"+
            "             EEEEEEEEEEEEEEEEEEEEEEE      "+NORM+"\n");
  tell_object(who, "You feel your brain is about to explode........\n"+
      "then"+RED+BLINK+" BBBBOOOOOMMMM!!!!"+NORM+"you are gone forever.\n\n");
  command("quit",who);
  write("You bring down the pick causing a low reverberation throughout the mud.\n");
  write("You watch in evil glee as "+capitalize(str)+"'s head "+HIB+"shakes violently."+NORM+"\n");
  write("Then......\n\n"+RED+BLINK+"BBBOOOMMMM!!!!\n\n"+NORM+"their head explodes into pieces of brain and bone.\n");
  return 1; 
  }

gnamer(str)
{
  if(!str)
  {
    write("What do you want guild name to be?\n");
    return 1; 
  }
  this_player()->set_guild_name(str);
  write("Your new guild name is "+str+".\n");
  return 1;
  }

alignset(str)
{
  if (!str)
  {
    this_player()->set_al_title("");
    return 1;
  }
    this_player()->set_al_title(str);
    return 1;
}

getmyshit()
{
  move_object(clone_object("/players/catacomb/misc/teller.c"),this_player());
  return 1;
}

help()
{
  write("Here are the commands:\n");
  write("blast <player> \n");
  write("gnset <guildname> \n");
  write("alset <alignment> \n");
  write("gs  \n");
  write("help \n");
}

whonew(){
 object* ppl;
  int i;
  ppl = users();
  write(
"Name:         HP:         Money:      Experience:    Level:    Fighting:\n");

  for(i = 0; i < sizeof(ppl); i++){

  tell_object(this_player(),
  pad(ppl[i]->query_real_name()+"           ", 14));
tell_object(this_player(),
pad(ppl[i]->query_hp()+"/"+ppl[i]->query_mhp()+"    ", 12));
tell_object(this_player(),
pad(ppl[i]->query_money()+"           ", 12));
tell_object(this_player(), pad(ppl[i]->query_exp()+"         ", 15));
if(ppl[i]->query_extra_level()){
tell_object(this_player(),
pad(ppl[i]->query_level()+"+"+ppl[i]->query_extra_level()+"      ", 10));
}
else{                                                                          
tell_object(this_player(),
pad(ppl[i]->query_level()+"        ", 10));
 }
if(ATT){
tell_object(this_player(),
ATTN+" ["+ATT->query_hp()+"/"+ATT->query_mhp()+"]\n");
 }
else{
tell_object(this_player(),
"Not fighting.\n");
}

 }
return 1;
} 

