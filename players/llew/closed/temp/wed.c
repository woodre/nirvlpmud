#include "/players/llew/closed/ansi.h"
#define ep environment(this_player())

inherit "obj/treasure";
string who,who2,perform;


reset(arg) {
   if(arg) return;
   set_id("wed");
   set_value(0);
   set_weight(0);
}

init() {
   ::init();
   add_action("marry","marry");
   add_action("rings","rings");
   add_action("spells","spells");
   add_action("talk","talk");
}

marry(str) {
   object ring1,ring2;
   if(!str) { write("Command:  marry [who] and [who2]\n"); return 1; }
   if(!sscanf(str,"%s and %s",who,who2) == 2) {
      marry("Command:  marry [who] and [who2]\n");
      return 1;
   }
   if(!present(who,environment(this_player())) && !present(who2,environment(this_player()))) {
      write("They must both be present in order to marry them.\n");
      return 1;
   }
   perform=this_player()->query_name();
   write("You give the rings away to the now married couple.\n");
   say(format(perform+" hands the rings to "+capitalize(who)+" and "+capitalize(who2)+".\n",70));
   ring1=clone_object("players/bastion/closed/ring");
   ring2=clone_object("players/bastion/closed/ring");
   ring1->set_spouse(find_player(who)->query_real_name());
   ring2->set_spouse(find_player(who2)->query_real_name());
   move_object(ring1, (find_player(who2)));
   move_object(ring2, (find_player(who)));
   shout(RED+"@"+GRN+"}---   "+NORM+BOLD+capitalize(who)+" and "+capitalize(who2)+" are joined "+
      "in marriage.   "+NORM+GRN+"---{"+RED+"@\n"+NORM);
   return 1;
}

spells(str) {
   if(str== "1") {
      write("You read your hand forward and trace the sigil of Partnership.\n");
      say(this_player()->query_name()+" traces a magical sigil with "+this_player()->query_possessive()+" finger.\n");
      tell_room(ep,"\n"+
         BLU+"\t\t    __________       \n"+
         "\t\t   /          \\      \n"+
         "\t\t  /"+HIB+BLINK+"    ||\\\\  "+NORM+BLU+"  \\     \n"+
         "\t\t / "+HIB+BLINK+"    || \\\\ "+NORM+BLU+"   \\    \n");
      tell_room(ep,
         "\t\t/  "+HIB+BLINK+"    || //   "+NORM+BLU+"  \\   \n"+
         "\t\t\\ "+HIB+BLINK+"     ||//   "+NORM+BLU+"   /   \n"+
         "\t\t \\ "+HIB+BLINK+"    ||     "+NORM+BLU+"  /    \n");
      tell_room(ep,
         "\t\t  \\ "+HIB+BLINK+"   ||     "+NORM+BLU+" /     \n"+
         "\t\t   \\__________/      \n"+ 
         "\n"+NORM);
      return 1;
   }
   if(str== "2") {
      write("You reach your hand forward and trace the sigil of Sacrifice.\n");
      say(this_player()->query_name()+" traces a magical sigil with "+this_player()->query_possessive()+" finger.\n");
      tell_room(ep,"\n"+
         BLU+"\t\t    __________       \n"+
         "\t\t   /          \\      \n"+
         "\t\t  / "+HIB+BLINK+" //  ___   "+NORM+BLU+"\\     \n"+
         "\t\t / "+HIB+BLINK+" //   |_ /   "+NORM+BLU+"\\    \n");
      tell_room(ep,
         "\t\t/  "+HIB+BLINK+"//     //__   "+NORM+BLU+"\\   \n"+
         "\t\t\\  "+HIB+BLINK+"\\\\    /__ / "+NORM+BLU+"  /   \n"+
         "\t\t \\  "+HIB+BLINK+"\\\\_____// "+NORM+BLU+"  /    \n");
      tell_room(ep,
         "\t\t  \\  "+HIB+BLINK+"\\_____/  "+NORM+BLU+" /     \n"+
         "\t\t   \\__________/      \n"+ 
         "\n"+NORM);
      return 1;
   }
   if(str== "3") {
      write("You reach your hand forward and trace the sigil of Love.\n");
      say(this_player()->query_name()+" traces a magical sigil with "+this_player()->query_possessive()+" finger.\n");
      tell_room(ep,"\n"+BLU+
         "\t\t    __________       \n"+
         "\t\t   /          \\      \n"+
         "\t\t  /"+HIB+BLINK+" ||       "+NORM+BLU+"  \\     \n"+
         "\t\t / "+HIB+BLINK+" ||   ||    "+NORM+BLU+" \\    \n");
      tell_room(ep,
         "\t\t/   "+HIB+BLINK+"||___||_||   "+NORM+BLU+"\\   \n"+
         "\t\t\\  "+HIB+BLINK+" |__  ____|  "+NORM+BLU+" /   \n"+
         "\t\t \\  "+HIB+BLINK+"   ||      "+NORM+BLU+" /    \n");
      tell_room(ep,
         "\t\t  \\  "+HIB+BLINK+"  ||      "+NORM+BLU+"/     \n"+
         "\t\t   \\__________/      \n"+ 
         "\n"+NORM);
      return 1;
   }
}
talk(str) {
   if(!str) return 0;
   tell_room(ep,format(BOLD+this_player()->query_name()+" speaks, \""+NORM+str+BOLD+"\"\n",70));
   tell_room(ep,NORM);
   return 1;
}

rings() {
   write("You reach forward and bring together the three glowing sigils\n"+
         "to form the rune of Marriage.\n");
   say(this_player()->query_name()+" reaches forward and combines the three glowing sigils\n"+
       "to form the rune of marriage.\n");
   tell_room(ep,"\n"+BLU+
      "\t           _____                \n"+
      "\t          /"+HIB+BLINK+" |\\"+NORM+BLU+"  \\               \n"+
      "\t    _____/  "+HIB+BLINK+"|/  "+NORM+BLU+" \\_____         \n");
   tell_room(ep,
      "\t   /"+HIB+BLINK+"/   "+NORM+BLU+" \\ "+HIB+BLINK+" |   "+NORM+BLU+" /"+HIB+BLINK+"|  "+NORM+BLU+"  \\        \n"+
      "\t  /"+HIB+BLINK+"/  /_  "+NORM+BLU+"\\_____/ "+HIB+BLINK+"|___|"+NORM+BLU+" \\       \n");
   tell_room(ep,
      "\t  \\"+HIB+BLINK+"\\___/ "+NORM+BLU+" / __  \\ "+HIB+BLINK+"  | "+NORM+BLU+"  /       \n"+
      "\t   \\_____/"+HIB+BLINK+" /  \\ "+NORM+BLU+" \\_____/        \n"+
      "\t         \\ "+HIB+BLINK+"\\__/"+NORM+BLU+"  /               \n");
   tell_room(ep,
      "\t          \\_____/               \n"+
      "\t                                \n"+
      "\n"+NORM);
   return 1;
}

