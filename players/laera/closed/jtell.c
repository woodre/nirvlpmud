/*
  Jar's Wiztell .. 
*/

#include "/players/jaraxle/define.h"


id(str) { return str == "teller" || str == "motivation" || str == "jtell"; }

extra_look(){ write(HIR+"   -["+BOLD+""+BLK+"Motivation"+HIR+"]-\n"+NORM); return; }

long() { 
  write("Jar's teller device.\n"+
  "Use "+HIY+"'"+HIW+"jt <message>"+HIY+"'"+NORM+" to speak to him.\n"+
  "Use "+HIY+"'"+HIW+"jte <emote>"+HIY+"'"+NORM+" to emote to him.\n");
}

init() {
add_action("cmd_st", "jt");
add_action("cmd_stx", "jt!");
add_action("cmd_ste","jte");
}

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
  write("You emote to Jar: "+HIC+""+TPN+" "+str+" "+HIW+"<"+HIB+"afar"+HIW+">\n"+NORM);
tell_object(sob,HIC+""+TPN+" "+str+" "+HIW+"<"+HIB+"afar"+HIW+">\n"+NORM);
  return 1; 
}


status get() { return 1; }
drop(){
destruct(TO);
return 1; }

