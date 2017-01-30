inherit "/players/guilds/necro/mon/undead.c";
#include <ansi.h>

setup(){
  ::setup();  
  set_name("skeleton");
  set_short("The skeletal remains of "+BOLD+capitalize(mname)+OFF+" (undead)");
  set_long("The undead skeleton of "+capitalize(mname)+".\n"+
      "It stands erect, held together only by the magical power of "+capitalize(master)+".  If a\n"+
      "skull could have different looks this one would be as blank as an unused\n"+
      "canvas.  It is here only to do its masters bidding."+exp_worth+"\n");
  set_bodypart( "bones" );
  set_color( BOLD );

  /** Spells **/
  add_spell("smite"
    ,"#MN# $HR$SMITES$N$ you with a heavy blow!\n"
    ,"#MN# $HR$SMITES$N$ #TN# with a heavy blow!\n"
    ,5+random(level/2),spell_base);
}
