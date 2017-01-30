#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

string emote_action, ast;
reset(arg)  {
   ::reset(arg);
   if(arg) return;
   
   set_name("trixie");
   set_alias("hooker");
   set_race("human");
   set_short("Trixie the hooker");
   set_long("She is rather old, and has not aged well.\n");
   set_level(2);
   set_chat_chance(5);
   load_chat("Trixie smiles at you.\n");
   load_chat("Trixie says, 'Would you like a trick?'\n");
   load_chat("Trixie says, 'Only 10,000 coins for a trick.'\n");
   load_chat("Trixie winks at you seductively.\n");
   set_hp(30);
   set_al(1500);
   set_wc(6);
   set_ac(3);
}

init(){
   ::init();
   add_action("Trixie_action","hug");
   add_action("Trixie_action","smile");
   add_action("Trixie_action","wave");
   add_action("Trixie_action","kiss");
   add_action("Trixie_action","dance");
   add_action("Trixie_action","love");
   add_action("Trixie_action","sigh");
   add_action("Trixie_action","lick");
   add_action("Trixie_action","nod");
   add_action("Trixie_action","shake");
   add_action("Trixie_action","tackle");
   add_action("Trixie_action","tickle");
   add_action("Trixie_action","snuggle");
   add_action("Trixie_action","grin");
   add_action("Trixie_action","poke");
   add_action("Trixie_action","bow");
   add_action("Trixie_action","curtsey");
   add_action("Trixie_action","sex");
}

Trixie_action(who) {
   if(who == "trixie") {
      emote_action = query_verb();
      call_out("Trixie_action2",2,this_player()->query_real_name());
   }
}

Trixie_action2(who) {
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   switch(emote_action) {

      case "sex":
      tell_object(find_player(who),"Trixie gasps, then smacks you!\n");
      say("Trixie gasps, then smacks "+capitalize(who)+"!\n",find_player(who));
      break;
      case "hug":
      tell_object(find_player(who),"Trixie hugs you.\n");
      say("Trixie hugs "+capitalize(who)+".\n",find_player(who));
      break;
      case "lick":
      say("Trixie wipes her face and goes, 'Eewwww!'\n");
      break;
      case "nod":
      tell_object(find_player(who),"Trixie nods at you.\n");
      break;
      case "shake":
      tell_object(find_player(who),"Trixie shakes your hand.\n");
      break;
      case "tackle":
      if(find_player(who)->query_attrib("ste") >= random(13)) {
         tell_object(find_player(who),"Trixie nimbly dodges you.\n");
         say("Trixie nibly dodges from "+capitalize(who)+".\n",find_player(who));
         break;
}
      tell_object(find_player(who),"Trixie tickles you frantically.\n");
      say("Trixie tickles "+capitalize(who)+" frantically.\n",find_player(who));
      break;
      case "smile":
      tell_object(find_player(who),"Trixie smiles back.\n");
      say("Trixie smiles at "+capitalize(who)+".\n",find_player(who));
      break;
      case "wave":
      tell_object(find_player(who),"Trixie waves with a smile.\n");
      say("Trixie waves at "+capitalize(who)+" with a smile.\n",find_player(who));
      break;
      case "kiss":
      if(find_player(who)->query_gender() == "male") {
         say("Trixie giggles, and hides her face.\n");
         break;
}
      tell_object(find_player(who),"Trixie makes an 'Ick!' face.\n");
      say("Trixie 'Icks!' at "+capitalize(who)+".\n",find_player(who));
      break;
      case "dance":
      tell_object(find_player(who),"Trixie slides back into a dip.\n");
      say(""+capitalize(who)+" dips Trixie gracefully.\n",find_player(who));
      say("Trixie giggles happily.\n");
      break;
      case "love":
      tell_object(find_player(who),"Trixie blushes a deep crimson red.\n");
      say("Trixie blushes at "+capitalize(who)+".\n",find_player(who));
      break;
      case "sigh":
      tell_object(find_player(who),"Trixie gazes at you with a concerned look in her eyes.\n");
      break;
      case "tickle":
      say("Trixie giggles merrily.\n");
      break;
      case "snuggle":
      tell_object(find_player(who),"Trixie holds you tightly..\n");
      say("Trixie holds "+capitalize(who)+" tight.\n",find_player(who));
      break;
      case "grin":
      tell_object(find_player(who),"Trixie winks at you.\n");
      say("Trixie winks at "+capitalize(who)+".\n",find_player(who));
      break;
      case "poke":
      say("Trixie yells, 'Ouch!'.\n");
      break;
      case "bow":
      say("Trixie cursteys.\n");
      break;
      case "curtsey":
      say("Trixie cursteys.\n");
      break;
      }
}

