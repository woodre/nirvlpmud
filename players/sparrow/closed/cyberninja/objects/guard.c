#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
::reset();
  if(arg) return;
set_name("guard");
set_alt_name("ninja");
getshort();
set_long("Dressed completely in black, this ninja moves from shadow to shadow\n"+
          "with ease.  His eyes shift to avoid your gaze constinatley watching\n"+
          "your every move.\n");
set_level(20);
set_hp(500);
set_ac(50);
set_wc(30);
set_heal(10,1);
set_chance(30);
set_spell_mess1("Swish...swish swish.. swish... swish swish swish....\nThrowing stars leap from the hands of this ninja.\nPain begins to set in as blood pour from your open wounds...\n");
set_spell_mess2("Throwing stars leap from the hands of this ninja.\n");
set_spell_dam(60);
}

getshort(){
    switch(random(3)){
case 0: set_short("Testing 1");
case 1: set_short("Testing 2");
case 2: set_short("Testing 3");
}
}
