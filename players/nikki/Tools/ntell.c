#include "/players/nikki/ansi.h"
inherit "/obj/treasure";

string color;

/*short() { 
  return (HIR+""+NORM);
}*/

long() { 
   write("    A teller. 'nt <msg>' to tell, 'nte <msg>' to emote. \n"); 
}

id(str) { 
   return str == "teller"; 
}


init() {
   if(!environment()) detruct(this_object());
   if(this_player()->query_real_name() != "nikki") destruct(this_object());
   add_action("wiz_tell", "nt");
   add_action("wiz_mote", "nte");
   add_action("wiz_ech", "nec");
}
wiz_tell(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) { 
      write("Tell what?\n"); 
      return 1; 
   }
   if(sscanf(str,"%s %s",who,what) != 2) {
      write("Tell <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { 
      write(capitalize(who)+" is not online now.\n");
      return 1; 
   }
   if(in_editor(find_player(who))) { write("Person is in edit...\n"); return 1; }
   tell_object(plyr,HIB+"/^/^("+HIG+"**"+HIB+")^\\^\\ "+NORM+myname+" tells You: "+what+"\n");
find_player(who)->add_tellhistory("Nikki tells you: "+what);
   write("You tell "+capitalize(who)+": "+color+what+NORM+"\n");
   return 1;
}

wiz_mote(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) {
      write("Emote what?\n");
      return 1;
   }
   if(sscanf(str,"%s %s",who,what) != 2) {   
      write("Emote <who> <what>?\n");
      return 1;
   }
   plyr = find_living(who);   
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) {
      write(capitalize(who) +" is not online now.\n");
      return 1;
   }
   if(in_editor(find_player(who))) { write("Person is in edit...\n"); return 1; }
   tell_object(plyr,HIB+"/^/^("+HIG+"**"+HIB+")^\\^\\ "+NORM+myname+" "+what+"\n");
   write("Emoted to "+capitalize(who)+": "+color+myname+" "+what+NORM+"\n");
   return 1;
}
wiz_ech(str) {
   object plyr;
   string who, what, myname;
   choose_color();
   if(!str) { 
      write("Echo what?\n"); 
      return 1; 
   }
   if(sscanf(str,"%s %s",who,what) != 2) {
      write("Echo <who> <what>.\n"); 
      return 1; 
   }
   plyr = find_living(who);
   myname = capitalize(this_player()->query_real_name());
   if(!plyr) { 
      write(capitalize(who)+" is not online now.\n");
      return 1; 
   }
   if(in_editor(find_player(who))) { write("Person is in edit...\n"); return 1; }
   tell_object(plyr,color+what+NORM+"\n");
   write("You echo to "+capitalize(who)+": "+color+what+NORM+"\n");
   return 1;
}
drop() { return 1; }

choose_color() {
   int blah;
   blah = random(13);
   switch(blah) {
   case 0:	color = RED; break;
   case 1:      color = GRN; break;
   case 2:      color = YEL; break;
   case 3:	color = BLU; break;
   case 4:	color = MAG; break;
   case 5:	color = CYN; break;
/* case 6:      color = BOLD+BLK; break;*/
   case 6:      color = HIR; break;
   case 7:	color = HIG; break;
   case 8:	color = HIY; break;
   case 9:	color = HIB; break;
   case 10:	color = HIM; break;
   case 11:	color = HIC; break;
   case 12:     color = HIW; break;
   }
   return 1;
}


   
