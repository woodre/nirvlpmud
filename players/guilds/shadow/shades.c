#include "/players/guilds/shadow/define.h"
#include "/players/guilds/shadow/shadow_lib/color.h"
#define PMARK present("shadow-mark", TP)

int shades_on;

id(str) { return str == "glasses" || str == "shades" ||
                 str == "shadow-shades";
}

short() {
    return "Shadow Shades";
}

long() {
    write("This is your shadow sunglasses.  Stay cool.\n");
    write("To bypass the emotes here, type 'shades off'.\n");
    write("To include them, type 'shades on'.\n");
}

query_weight() {
   return 0;
}

get() { 
   return 1;
}

reset(arg) {
   
    if(!arg) {

    shades_on = 1;
    
   }
}

query_auto_load() {
   return "/players/guilds/shadow/shades.c:"+shades_on;
}

init_arg(str) {
   sscanf(str, "%d", shades_on);
}

init() {

   add_action("shades_toggle", "shades");   
   add_action("new_shades", "new");

   if(shades_on == 1) {

      add_action("em_grin", "grin");
      add_action("em_smile", "smile");
      add_action("bold_say", "SAY");
      
   }
}

re_init() {
   move_object(TO, find_object("/room/void.c"));
   move_object(TO, TP);
   return 1;
}

shades_toggle(str) {
   if(!str) return;
   if(str == "on") {
      shades_on = 1;
      write("Shades are ON.\n");
      re_init();
      return 1;
   }
   if(str == "off") {
      shades_on = 0;
      write("Shades are OFF.\n");
      re_init();
      return 1;
   }
   return;
}

new_shades(str) {
   string poss;
   poss = query_possesive();
   if(str && str == "shades") {
      move_object(clone_object("/players/guilds/shadow/shades.c"), TP);
      write("You remove your shades and they crumble to dust.\n");
      say(CN + " removes "+ poss +" shades.  They crumble to dust.\n");
      write("You hold out your palm, and a blackness gathers.\n");
      say(CAP(query_pronoun()) + " holds out "+poss+" and a blackness "+
         "gathers.\n");
      say("From the blackness, a new pair of shadeses form.\n");
      write("From the blackness, a new pair of shades form.\n");
      destruct(TO);
      return 1;
   }
}

query_possesive() {
   if(TP->query_gender() == "male") return "his";
   if(TP->query_gender() == "female") return "her";
   return "its";
}

query_pronoun() {
   if(TP->query_gender() == "male") return "he";
   if(TP->query_gender() == "female") return "she";
   return "it";
}



em_grin(str) {
   if(str) return;
   write("You grin darkly, chilling the room.\n");
   say(CN + " grins darkly, sending a chill through your spine.\n");
    return 1;
}

em_smile(str) {
   if(str) return;
   write("You smile cleverly.");
   say(CN + " smiles cleverly.");
   tell_room(ENVTP, BOLD+BLINK+":"+NOSTYLE+")\n");
   return 1;
}

bold_say(str) {
   if(!str) {
      write("SAY what?\n");
      return 1;
   }
   if(!PMARK->less_pts(5)) return;
   write("You say: "+BOLD+str+NOSTYLE+"\n");
   say(CN +" says: "+BOLD+str+NOSTYLE+"\n");
   return 1;
}
