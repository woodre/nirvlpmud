#include "/players/llew/closed/ansi.h"
#include "/players/mythos/closed/guild/name.h"
#define ENV environment()
inherit "/obj/monster";
int waiting_table;
string emote_action;

reset(arg) {
   ::reset(arg);
if(arg) return;
   waiting_table=0;
   no_clean=1;
   set_name("Llew");
   set_level(20);
   set_alias("llew");
   set_race("human");
   set_hp(1000);
   set_al(1000);
   set_short("Llew the Forest Lord");
   set_long("Llew is a tall dark haired man of light build.  His curly\n"+
      "black hair reaches half way to the shoulders.  Brown\n"+
      "eyes gaze at you with a twinkle and a smile.  Though\n"+
      "once a great adventuring bard, Llew has settled down\n"+
      "to a peaceful life of an inn keeper.  He keeps his\n"+
      "mandolin handy for the occasional spin of a story or\n"+
      "fantastic ballad.\n");
   set_wc(40);
   set_ac(25);
/*
   set_move_at_reset("/players/llew/Other/rooms/lazy");
*/
   set_chat_chance(1);
   set_alt_name("lord");
   set_gender("male");
   load_chat("Llew absently tunes his mandolin.\n");
   load_chat("Llew looks up with a sparkle in his eye.\n");
   load_chat("Llew lightly strums the strings of his mandolin.\n"+
      "The image of a melody dances through your mind.\n");
   load_chat("Llew whistles a jig.\n");
   load_chat("Llew winks at you.\n");
   load_chat("The hearth fire crackles warmly.\n");
   load_chat("A candle flickers in the warm heat.\n");
   load_chat("Llew smiles.\n");
}

init() {
   ::init();
   add_action("buy","buy");
   add_action("buy","order");
   add_action("hug","hug");
   add_action("hug","smile");
   add_action("hug","kiss");
   add_action("hug","wave");
   add_action("hug","bhug");
   add_action("hug","dance");
   add_action("hug","wink");
   add_action("hug","love");
   add_action("hug","sigh");
   add_action("hug","ruffle");
   add_action("hug","tickle");
   add_action("hug","snuggle");
   add_action("hug","grin");
   add_action("hug","poke");
}

wait_table(num) {
   if(waiting_table) return 1;
   say("Llew leaves to booth "+num+".\n");
   move_object(this_object(),"players/llew/Other/rooms/booth"+num);
   say("Llew enters the booth.\n");
   say("Llew says, \"Yes?  What may I help you with?\"\n");
   call_out("done_waiting",30);
   waiting_table=1;
}

done_waiting() {
   say("Llew says, \"Be sure to ring the bell if you need anything else.\"\n");
   say("Llew leaves the booth.\n");
   move_object(this_object(),"players/llew/Other/rooms/lazy");
   say("Llew arrives.\n");
   waiting_table=0;
}

buy(str) {
   int cost,heal,strength;
   string type;
   if(!str) {
      write("Llew says, \"You gonna "+query_verb()+" something, or what?\"\n");
      return 1;
   }
   switch(str) {
      case "ale":
         cost=15;
         heal=0;
         strength=5;
         type="drink_alcohol";
         break;
      case "brandy":
         cost=150;
         heal=10;
         strength=9;
         type="drink_alcohol";
         break;
      case "whiskey":
         cost=235;
         heal=25;
         strength=14;
         type="drink_alcohol";
         break;
      case "twilsden":
         cost=500;
         heal=50;
         strength=15;
         type="drink_alcohol";
         break;
      case "cheese":
         cost=125;
         heal=9;
         strength=10;
         type="eat_food";
         break;
      case "bread":
         cost=200;
         heal=18;
         strength=12;
         type="eat_food";
         break;
      case "stew":
         cost=275;
         heal=27;
         strength=14;
         type="eat_food";
         break;
      case "salmon":
         cost=500;
         heal=50;
         strength=16;
         type="eat_food";
         break;
      case "water":
         cost=25;
         heal=3;
         strength=9;
         type="drink_soft";
         break;
      case "milk":
         cost=175;
         heal=15;
         strength=12;
         type="drink_soft";
         break;
      case "nectar":
         cost=250;
         heal=25;
         strength=15;
         type="drink_soft";
         break;
      case "ipocras":
         cost=500;
         heal=50;
         strength=17;
         type="drink_soft";
         break;
   }
   if(!cost) {
      write("Llew looks at you in confusion.\n");
      say("Llew looks at "+this_player()->query_name()+" in confusion.\n");
      tell_room(ENV,"Llew says, \"Say again, friend.  What did you want to order?\"\n");
      return 1;
   }
   write("You order some "+str+".\n");
   say(this_player()->query_name()+" orders some "+str+".\n");
   if(type=="drink_alcohol" && present(fear,this_player())) {
      tell_room(ENV,"Llew sighs.\n");
      tell_room(ENV,"Llew says, \"I'm afraid it has been decreed by one more\n"+
         "            powerful than I that I cannot sell you alcohol.\"\n");
      return 1;
   }
   if(this_player()->query_money() < cost) {
      tell_room(ENV,"Llew smiles pleasantly.\n"+

         "Llew says, \"You'd better show me some coin first.\n"+
         "            I don't believe you have enough to pay for that.\"\n");
      return 1;
   }
   if(!call_other(this_player(),type,strength) == 1) {
      write("Llew chuckles at you.\n");
      say("Llew chuckles at "+this_player()->query_name()+".\n");
      tell_room(ENV,"Llew says, \"Whoa, hold it there, buddy.  You've had too much.\"\n");
      return 1;
   }
   write("Llew takes your "+cost+" coins happily, giving you the "+str+".\n");
   say("Llew takes "+this_player()->query_name()+"'s money happily, giving "+this_player()->query_objective()+" the "+str+".\n");
   tell_room(ENV,"Llew says, \"Thanks, friend, enjoy.\"\n");
   this_player()->add_money(-cost);
   this_player()->heal_self(heal);
   give_stats();
   if(waiting_table) {
      remove_call_out("done_waiting");
      call_out("done_waiting",30);
   }

    return 1;
}

give_stats() {
   write(BOLD+"\tHP: "+NORM);
   write(this_player()->query_hp()+BOLD+"["+NORM+this_player()->query_mhp()+BOLD+"]  "+NORM);
   write(BOLD+"SP: "+NORM);
   write(this_player()->query_spell_point()+BOLD+"["+NORM+this_player()->query_msp()+BOLD+"]\n"+NORM);
}

hug(who) {
   if(who == "llew") {
      emote_action = query_verb();
      call_out("hug2",2,this_player()->query_real_name());
   }
}

hug2(who) {
   if(!find_player(who) || environment(find_player(who)) != environment()) return;
   switch(emote_action) { 
      case "hug":
         tell_object(find_player(who),"Llew hugs you.\n");
         say("Llew hugs "+capitalize(who)+".\n",find_player(who));
         break;
      case "smile":
         tell_object(find_player(who),"Llew smiles happily at you.\n");
         say("Llew smiles happily at "+capitalize(who)+".\n",find_player(who));
         break;
      case "wave":
         tell_object(find_player(who),"Llew smiles and waves back.\n");
         say("Llew smiles at "+capitalize(who)+" and waves.\n",find_player(who));
         break;
      case "kiss":
         if(find_player(who)->query_gender() == "female") {
         say("Llew blushes a deep red.\n");
            break;
         }
         tell_object(find_player(who),"Llew gives you a dirty look.\n");
         say("Llew give "+capitalize(who)+" a dirty look.\n",find_player(who));
         break; 
      case "bhug":
         say("Llew oofs happily.\n");
         break;
      case "dance":
         tell_object(find_player(who),"Llew dances a jig just for you.\n");
         say("Llew dances a jig just for "+capitalize(who)+".\n",find_player(who));
         break;
      case "love":
         tell_object(find_player(who),"Llew ruffles your hair playfully.\n");
         say("Llew ruffle "+capitalize(who)+"'s hair playfully.\n",find_player(who));
         break;
      case "sigh":
         tell_object(find_player(who),"Llew comforts you.\n");
         say("Llew comforts "+capitalize(who)+".\n",find_player(who));
         break;
      case "wink":
         tell_object(find_player(who),"Llew winks back with a sparkle in his eye.\n");
         say("Llew winks back at "+capitalize(who)+".\n",find_player(who));
         break;
      case "ruffle":
         say("Llew says, \"Hey! Not the hair!.\"\n");
         break;
      case "tickle":
         say("Llew giggles.\n");
         call_out("tickle",2);
         break;
      case "snuggle":
         if(find_player(who)->query_gender() == "female") {
            tell_object(find_player(who),"Llew snuggles up with you to stay warm.\n");
            say("Llew snuggles up next to "+capitalize(who)+".\n",find_player(who));
            break;
         }
         tell_object(find_player(who),"Llew gives you a VERY dirty look.\n");
         say("Llew gives "+capitalize(who)+" a VERY dirty look.\n",find_player(who));
         break;
      case "grin":
         tell_object(find_player(who),"Llew grins goodly at you.\n");
         say("Llew grins goodly at "+capitalize(who)+".\n",find_player(who));
         break;
      case "poke":
         say("Llew rubs his sore ribs.\n");
         break;
   }
}

tickle() {
   say("Llew claims, \"I am NOT ticklish!.\"\n");
}

