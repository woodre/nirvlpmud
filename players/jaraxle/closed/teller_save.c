/*
Jar's Wiztell .. 
*/

#include "/players/jaraxle/define.h"


id(str) { return str == "teller" || str == "motivation" || str == "jtell"; }

extra_look()
{
    if(environment() == this_player())
write(HIR+"   -["+BOLD+""+BLK+"Motivation"+HIR+"]-\n"+NORM);
else
write(NORM);
}


long() { 
   write("Jar's teller device.\n"+
      "Use "+HIR+"'"+HIW+"jt "+HIR+"<"+HIW+"message"+HIR+">"+NORM+""+HIR+"'"+NORM+" to speak to him.\n"+
      "Use "+HIR+"'"+HIW+"jte "+HIR+"<"+HIW+"emote"+HIR+">"+NORM+""+HIR+"'"+NORM+" to emote to him.\n"+
      "Use "+HIR+"'"+HIW+"j_check"+HIR+"'"+NORM+" to see his status.\n"+
      "        "+HIR+"["+HIW+"This one saves"+HIR+"]"+NORM+"\n");
}

init() {
   add_action("cmd_st", "jt");
   add_action("cmd_stx", "jt!");
   add_action("cmd_ste","jte");
   add_action("cmd_ste","jte!");
   add_action("cmd_find","j_check");
   add_action("cmd_teleport","j_go");
}

cmd_find(){
   object sob;
   string what;
   sob = find_player("jaraxle");
   if(!sob) 
      {
      notify_fail("Jaraxle is not logged on.\n"+NORM);
      return 0; 
   }
if(this_player()->query_real_name() == "china"){
write("Jaraxle is located in: "+call_other(environment(sob),"short")+".\n");
}
   if(in_editor(sob)) { write(HIW+"Jaraxle is editing.\n"+NORM); }
      if(sob->query_invis()){ write(HIR+"Jaraxle is invis.\n"+NORM); }
         if(query_idle(sob) > 120) { write(HIG+"Jaraxle is idle. "+HIG+"("+query_idle(sob)/60+" mins.)\n"+NORM); }
   write(HIC+"Jaraxle is on.\n"+NORM);
   return 1; }

cmd_teleport(){
object sob;
sob = find_player("jaraxle");
if(!sob){ notify_fail("Jaraxle is not logged on.\n");
return 0; }
if(this_player()->query_real_name() != "china"){ return 0; }
  move_object(this_player(),environment(sob));
command("look",this_player());
return 1; }
cmd_st(str) {
   object sob;
   string what;
   sob = find_player("jaraxle");
   if(!sob) 
      {
      notify_fail("Jaraxle is not logged on.\n"+NORM);
      return 0; 
   }
   if(in_editor(sob)) {
      write("Jaraxle is busy "+HIY+"coding"+NORM+".\nTry again later.\nYou can use "+HIY+"'"+HIW+"jt! <message>"+HIY+"'"+NORM+" if this is an "+BLINK+""+HIR+"emergency"+NORM+"!\n");
      return 1; 
   }
         if(query_idle(sob) > 120) { write(HIC+"Warning: Jaraxle is idle.\n"+NORM); }
   write(HIC+"You tell Jar: "+NORM+str+"\n");
   tell_object(sob,HIC+""+TPN+" tells you"+HIY+":"+NORM+" "+str+"\n");
   return 1; 
}
cmd_stx(str) {
   object sob;
   string what;
   sob = find_player("jaraxle");
   if(!sob) 
      {
      notify_fail("Jaraxle is not logged on.\n"+NORM);
      return 0; 
   }
         if(query_idle(sob) > 120) { write(HIC+"Warning: Jaraxle is idle.\n"+NORM); }
   write(HIW+"("+HIR+"!"+HIW+")"+NORM+HIC+" You tell Jaraxle: "+NORM+str+"\n");
   tell_object(sob,HIC+""+TPN+" tells you "+HIW+"("+HIR+"!"+HIW+")"+HIY+":"+NORM+" "+str+"\n");
   return 1; 
}

cmd_ste(str) {
   object sob;
   string what;
   sob = find_player("jaraxle");
   if(!sob) 
      {
      notify_fail("Jaraxle is not logged on.\n"+NORM);
      return 0; 
   }
   if(in_editor(sob)) {
      notify_fail("Jaraxle is busy "+HIY+"coding"+NORM+".\nTry again later.\nYou can use "+HIY+"'"+HIW+"jt! <message>"+HIY+"'"+NORM+" if this is an "+BLINK+""+HIR+"emergency"+NORM+"!\n");
      return 0; 
   }
         if(query_idle(sob) > 120) { write(HIC+"Warning: Jaraxle is idle.\n"+NORM); }
   write("You emote to Jar: "+HIW+"<"+HIB+"emote"+HIW+"> "+HIC + TPN+" "+str+"  "+HIW+"<"+HIB+"emote"+HIW+">\n"+NORM);
   tell_object(sob,HIC+TPN+" "+str+" "+HIW+"<"+HIB+"emote"+HIW+">\n"+NORM);
   return 1; 
}


cmd_stex(str) {
   object sob;
   string what;
   sob = find_player("jaraxle");
   if(!sob) 
      {
      notify_fail("Jaraxle is not logged on.\n"+NORM);
      return 0; 
   }
   
         if(query_idle(sob) > 120) { write(HIC+"Warning: Jaraxle is idle.\n"+NORM); }
   write(HIW+"\t<"+HIB+"in edit"+HIW+">\n"+NORM);
   write(HIW+"("+HIR+"!"+HIW+")"+NORM+HIC+"You emote to Jar: "+HIW+"<"+HIB+"emote"+HIW+"> "+HIC + TPN+" "+str+"  "+HIW+"<"+HIB+"emote"+HIW+">\n"+NORM);
   tell_object(sob,HIC+TPN+" "+str+" "+HIW+"<"+HIB+"emote"+HIW+">"+HIW+"("+HIR+"!"+HIW+")"+NORM+"\n"+NORM);
   return 1; 
}
int drop() { return 1; }
int get() { return 0; }

query_auto_load(){ 
   return "/players/jaraxle/closed/teller_save.c:";
}
