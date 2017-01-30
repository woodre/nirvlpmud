#include "/players/jaraxle/define.h"
inherit "obj/monster";
string emote_action, ast;
int DIGI_NAME;

void
init()
{
   ::init();
    add_action("digimotes","digimotes");
   add_action("digi_action","hug");
   add_action("digi_action","smile");
   add_action("digi_action","wave");
   add_action("digi_action","kiss");
   add_action("digi_action","dance");
   add_action("digi_action","love");
   add_action("digi_action","sigh");
   add_action("digi_action","lick");
   add_action("digi_action","nod");
   add_action("digi_action","shake");
   add_action("digi_action","tackle");
   add_action("digi_action","tickle");
   add_action("digi_action","poke");
   add_action("digi_action","sex");
   add_action("dplay","dplay");
   add_action("dsmile","dsmile");
   add_action("dhug","dhug");
   add_action("dkick","dkick");
   add_action("dlick","dlick");
   add_action("dwag","dwag");
   add_action("dcheer","dcheer");
   add_action("dbite","dbite");
}

digimotes(){
   if (!check_ok()) return 0;
    cat("/players/jaraxle/digimon/emote_list");
    return 1;
  }

dbite(who){
  if (!check_ok()) return 0;
 if(!who){ write("Dbite <who>?\n"); return 1; }
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
 tell_object(find_player(who),""+capitalize(DIGI_NAME)+" bites you!\n");
   say(capitalize(DIGI_NAME)+" bites "+capitalize(who)+"!\n");
return 1; }

dcheer(){
   if (!check_ok()) return 0;
    say(capitalize(DIGI_NAME)+" cheers loudly!\n");
return 1; }

dplay(who){
   if(!who){ write("Dplay <who>?\n"); return 1; }
   if (!check_ok()) return 0;
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   tell_object(find_player(who),""+capitalize(DIGI_NAME)+" wants to play!\n");
   say(capitalize(DIGI_NAME)+" plays games with "+capitalize(who)+".\n");
return 1; }

dsmile(who){
   if(!who){ say(capitalize(DIGI_NAME)+" smiles biggly.\n"); return 1; }
   if (!check_ok()) return 0;
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   tell_object(find_player(who),""+capitalize(DIGI_NAME)+" smiles at you, its huge teeth shining brightly.\n");
   say(capitalize(DIGI_NAME)+" smiles brightly at "+capitalize(who)+".\n");
return 1; }

dhug(who){
   if(!who){ write("Dhug <who>?\n"); return 1; }
   if (!check_ok()) return 0;
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   tell_object(find_player(who),""+capitalize(DIGI_NAME)+" hugs you tightly.\n");
   say(capitalize(DIGI_NAME)+" hugs "+capitalize(who)+".\n");
return 1; }

dkick(who){
   if(!who){ write("Dkick <who>?\n"); return 1; }
   if (!check_ok()) return 0;
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   tell_object(find_player(who),""+capitalize(DIGI_NAME)+" kicks you on the shins!\n");
   say(capitalize(DIGI_NAME)+" kicks "+capitalize(who)+" on the shins!\n");
return 1; }

dlick(who){
   if(!who){ write("Dhug <who>?\n"); return 1; }
   if (!check_ok()) return 0;
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   tell_object(find_player(who),""+capitalize(DIGI_NAME)+" licks your face with its huge tongue! (yuck!)\n");
   say(capitalize(DIGI_NAME)+" licks "+capitalize(who)+". (yuck!)\n");
return 1; }

dwag(){
   say(capitalize(DIGI_NAME)+" wags its tail happily.\n");
   if (!check_ok()) return 0;
return 1; }

digi_action(who) {
    if(who == "digimon" || who == ""+DIGI_NAME+""){
      emote_action = query_verb();
      call_out("digi_action2",2,this_player()->query_real_name());
   }
}

digi_action2(who) {
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   switch(emote_action) {
      case "sex":
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
         say(capitalize(DIGI_NAME)+" stares at "+capitalize(who)+" with a confused expression.\n",find_player(who));
         break;
      case "hug":
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" hugs you warmly.\n");
        say(capitalize(DIGI_NAME)+" hugs "+capitalize(who)+" warmly.\n",find_player(who));
         break;
      case "lick":
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" licks you  back!\n");
         say(capitalize(DIGI_NAME)+" licks "+capitalize(who)+".\n");
         break;
      case "nod":
        tell_object(find_player(who),""+capitalize(DIGI_NAME)+" nods at you.\n");
         break;
      case "shake":
        tell_object(find_player(who),""+capitalize(DIGI_NAME)+" looks at its large paws, and shakes its head in confusion.\n");
         break;
      case "tackle":
         if(find_player(who)->query_attrib("ste") >= random(13)) {
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" nimbly dodges you.\n");
        say(""+capitalize(DIGI_NAME)+" nibly dodges from "+capitalize(who)+".\n",find_player(who));
         break;
         }
      case "smile":
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" smiles back.\n");
        say(capitalize(DIGI_NAME)+" smiles at "+capitalize(who)+".\n",find_player(who));
         break;
      case "wave":
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" waves.\n");
         say(capitalize(DIGI_NAME)+" waves at "+capitalize(who)+".\n",find_player(who));
         break;
      case "kiss":
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" blushes.\n");
         say(capitalize(DIGI_NAME)+" blushes at "+capitalize(who)+".\n",find_player(who));
         break;
      case "dance":
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" gets down!\n");
         say(capitalize(DIGI_NAME)+" gets down and boogies with "+capitalize(who)+" !\n",find_player(who));
         say(capitalize(DIGI_NAME)+" says, 'Dance! Dance!'\n");
         break;
      case "love":
          tell_object(find_player(who),""+capitalize(DIGI_NAME)+" looks at you with a confused expression.\n");
         say(capitalize(DIGI_NAME)+" stares at "+capitalize(who)+" with a confused expression.\n",find_player(who));
         break;
      case "sigh":
         tell_object(find_player(who),""+capitalize(DIGI_NAME)+" gazes at you with a concerned look in its eyes.\n");
         break;
      case "tickle":
         say(capitalize(DIGI_NAME)+" laughs, squirming away.\n");
         break;
      case "poke":
         say(capitalize(DIGI_NAME)+" yells, 'Ouch!'.\n");
         break;
   }
}
