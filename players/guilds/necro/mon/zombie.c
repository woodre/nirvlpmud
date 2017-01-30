inherit "/players/guilds/necro/mon/undead.c";
#include <ansi.h>

setup(){
  ::setup();
 
  set_name("zombie");
  set_short("The zombie of "+color+capitalize(mname)+OFF+" (undead)");
  set_long("The undead zombie of "+capitalize(mname)+".\n"+
      "It stands erect, held together only by the magical power of "+capitalize(master)+".  If a\n"+
      "skull could have different looks this one would be as blank as an unused\n"+
      "canvas.  It is here only to do its masters bidding.\n");
  set_bodypart( "flesh" );
  set_color( GRN );
  set_death_msg( "The zombie of "+cap_name+" falls to the ground, forming a pile of rotting flesh.\n" );

  /** Spells **/
  add_spell("bite",
    "\n#MN# lunges suddenly and $R$ B I T E S$N$ you!\n\n",
    "#MN# lunges suddenly and $R$B I T E S$N$ #TN#!\n",
    5+random(level/2),spell_base,"physical");
}
