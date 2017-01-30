/*
 * COMMUNE command for Ascension
 * guild channel tell, emote, muffle
 */
#include "../def.h"

status main(string str) {
   int i, glev;
   string msg, emote, type;
   object *people;
   object ob;
   if(!str) {
       write("Commune a message: commune <message>\n"+
            "Commune an emote : commune :<emote>\n"+
            "Muffle commune   : commune :on/off\n");
       return 1; 
       }
   
   glev = ((int)IPTP->query_setting(CLASS));
   type = ((string)LEVELD->get_being(glev));
   if(sscanf(str, ":%s", emote)) {
     if(emote == "on")  { 
       IPTP->set_setting(SILENCE, 0); 
       IPTP->save_me();
       write("You join in commune with other spirits.\n"); 
       return 1; }
     if(emote == "off") { 
       IPTP->set_setting(SILENCE, 1); 
       IPTP->save_me(); 
       write("You leave commune with other spirits.\n"); 
       return 1; }
     msg = "("+type+") ";
     emote = TPN+" "+emote;
     }
   else {
     emote = str;
     msg = "("+type+" "+TPN+") ";
     }

   if(IPTP->query_setting(SILENCE)) {
     write("You cannot commune while muffled.\n");
     return 1; }

   people = users();
   for(i=0; i<sizeof(people); i++) {
      ob = people[i];
      if(IPOB) {
        if(IPOB->query_setting(SILENCE)) {}
        else {
          if(IPOB->query_setting(COLOR))
            tell_object(ob, RED+msg+END+emote+"\n");
          else
            tell_object(ob, msg+emote+"\n");
          }
        }
      }
   return 1;
}
