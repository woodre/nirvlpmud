inherit "/obj/treasure.c";
#define PATH "players/zeus/closed/circle_member/"
#include "/players/zeus/closed/all.h"
object *peeps;
string why;
int chh, x, guild_exp;

reset(arg){

  set_short("CirGXP pill");
  set_long(
"Type cirgxp\n"+
"This is a small white pill.  The shell is made of a solid white plastic.\n"+
"Written in black lettering on the pill are the letters:  ZP1\n");
  set_weight(1);
  set_value(0);
}

id(str){ return str == "pill"; }

  init(){
  ::init();
    add_action("swallow_pill", "cirgxp");
}


swallow_pill(){
  write("You swallow the pill.\n");
  say(TP->QN+" pops a pill.\n");
  peeps = get_dir("/players/zeus/closed/circle_member/");
  chh = sizeof(peeps);
  for(x = 0; x < chh; x++)
  {
    sscanf(peeps[x], "%s.", why);
    if(restore_object(PATH+why))
    {
      if(guild_exp == 8000000)
        write(HIY+pad(why,12)+" "+guild_exp+NORM+"\n");
      else
        write(pad(why,12)+" "+guild_exp+"\n");
    }
    why = 0;
  }
  write("\n");
  return 1; 
}
