#include "/players/laera/closed/ldef.h"
#include "/players/laera/closed/ansi.h"

inherit "/obj/treasure.c";

reset(arg)
{
  if(arg) return;
  set_short(MAG + "Strand of Darkness" + NORM);

}
id(str) { return str == "ltell" || str == "teller" || str == "darkness" || str == "strand"; }

extra_look(){ write(MAG + "A barely visible strand of darkness undulates around " + tpn + ".\n"+ NORM); return; }

long() {
  write("A strand of darkness through which you can speak to Laera.\n"+
  HIW+"'"+ NORM + MAG +"tl " + NORM + HIW + "<message>'" + NORM +" enables you to speak.\n"+
  HIW+"'"+ NORM + MAG +"tle " + NORM + HIW + "<emote>'" + NORM +" enables you to show your feelings.\n");
}

query_auto_load() { return "/players/laera/closed/ltellAL.c:"; }


/*query_auto_load()
{
    if(Class) return AUTOLOAD;
}*/

init() {
add_action("cmd_st", "tl");
/*add_action("cmd_stx", "lt!");*/
add_action("cmd_ste","tle");
}

cmd_st(str) {
  object who;
  string what;
  who = find_player("laera");
  if(!who)
    {
      notify_fail(MAG + "The darkness reaches out but cannot find Laera.\n"+NORM);
      return 0;
    }
  /*if(in_editor(sob))
  	{
    write("Jaraxle is busy "+HIY+"coding"+NORM+".\nTry again later.\nYou can use "+HIY+"'"+HIW+"jt! <message>"+HIY+"'"+NORM+" if this is an "+BLINK+""+HIR+"emergency"+NORM+"!\n");
    return 1;
  	}*/
  write(MAG+"You whisper through the dark, " + "'" + NORM + HIW + str + NORM + MAG + "'" + ".\n" + NORM);
  tell_object(who,MAG + tpn + " whispers in the dark, " + "'" + NORM + HIW +  str + NORM + MAG + "'" + ".\n" + NORM);
  return 1;
}
/*cmd_stx(str) {
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
}*/

cmd_ste(str) {
  object who;
  string what;
  who = find_player("laera");
  if(!who)
    {
      notify_fail(MAG + "The darkness reaches out but cannot find Laera.\n"+NORM);
      return 0;
    }
  /*if(in_editor(sob)) {
    notify_fail("Jaraxle is busy "+HIY+"coding"+NORM+".\nTry again later.\nYou can use "+HIY+"'"+HIW+"jt! <message>"+HIY+"'"+NORM+" if this is an "+BLINK+""+HIR+"emergency"+NORM+"!\n");
    return 0;
  }*/
  write(MAG + "Through the darkness, " + tpn + NORM + HIW + " " + str + ".\n" + NORM);
  tell_object(who,MAG + tpn + NORM + HIW +" "+ str + " " + NORM + MAG +"through the darkness.\n"+NORM);
  return 1;
}


status get() { return 1; }
drop(){
destruct(this_object());
return 1; }

