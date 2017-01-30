inherit "/obj/monster.c";
/* changed to use standard ANSI - mizan */
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

reset(arg) {
  ::reset(arg);
  if(arg) return;

  set_name("asimar");
  set_race("angel");
  set_short(BOLD+RED+"Asimar Paladin"+NORM);
  set_long(
    "  This creature is a shinning example of goodness and\n"+
    "righteousness. She is one of the planetouched.\n");
  
  add_money(6200);
  set_level(20);
  set_hp(500+random(250));
  set_al(1000);
  set_ac(20+random(6));
  set_wc(30+random(5));
  set_aggressive(0);;
  set_armor_params("other|good",0,20,0);
  set_armor_params("other|ice",0,20,0);
  set_armor_params("other|light",0,10,0);
  set_armor_params("other|evil",0,-10,0);
  set_chat_chance(10);
  load_chat("The asimar says, \"I will seek out injustice and destroy evil.\"\n");
  load_chat("The asimar sharpens her blade.\n");
  add_spell("Holy Smite",
  "#MN# calls upon her powers of light and stikes you with...\n"+
  " \n"+
  "HH  HH OOOOOO LL     YY  YY    "+HIR+"SSSSSS M     M IIII TTTTTT EEEEEE  !!"+NORM+"\n"+
  "HH  HH OO  OO LL      YYYY     "+HIR+"SS     MMM MMM  II    TT   EE      !!"+NORM+"\n"+     
  "HHHHHH OO  OO LL       YY      "+HIR+"SSSSSS MM M MM  II    TT   EEEEE   !!"+NORM+"\n"+
  "HH  HH OO  OO LL       YY      "+HIR+"    SS MM   MM  II    TT   EE"+NORM+"\n"+      
  "HH  HH OOOOOO LLLLLL   YY      "+HIR+"SSSSSS MM   MM IIII   TT   EEEEEE  !!"+NORM+"\n"+
  " \n",
  "#MN# calls upon her powers of light and stikes with...\n"+
  " \n"+
  "             H O L Y  "+HIR+"S M I T E !"+NORM+"\n"+
  " \n",
    25,50,"other|good");
}
