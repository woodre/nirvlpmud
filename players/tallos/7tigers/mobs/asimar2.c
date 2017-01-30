inherit "/obj/monster.c";
/* changed to use standard ANSI.h -mizan */
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

object sword;
reset(arg) {
  ::reset(arg);
  if(arg) return;


  set_name("asimar");
  set_race("angel");
  set_short(BOLD+HIM+"Asimar Matriarch"+NORM);
  set_long(
    "  This is a leader of the asimar race. She is breathtakingly\n"+
    "beautiful and holy power shines off her in a nimbus of bright light.\n");
  
  add_money(4000);
  sword = clone_object("/players/tallos/7tigers/objects/holylongsword.c");
  move_object(sword, this_object());
  command("wield sword", this_object());
  set_level(21);
  set_hp(1000+random(300));
  set_al(800);
     set_heal(25,5);  
  set_ac(21+random(8));
  set_wc(37+random(8));
  set_aggressive(0);
  set_armor_params("other|good",0,30,0);
  set_armor_params("other|ice",0,20,0);
  set_armor_params("other|light",0,20,0);
  set_armor_params("other|evil",0,-10,0);
  set_multi_cast(0);
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
  add_spell("Holy Nova",
  "#MN# raises her hands high into the sky and calls upon the powers of justice exploding in a:\n"+
  " \n"+
  "                 "+HIC+"*         *   *    *    *    *      *\n"+
  "                  **    *  *  *  *  *  *  *  *  *  *    *\n"+
  "                       * *  *  *  *   *  *  *  *  *   **\n"+ 
  "              ********  *  *  "+NORM+"H O L Y  N O V A"+HIC+" *  * ***********\n"+
  "                   ** *  *  *  *  *  *  *  *  *   *  *\n"+
  "                  *    *  *  * *  *   *  *   *  * **   *\n"+
  "                  * *     *   *   *    *     * *     *   *\n"+
  "                 * *   **   **  **  **  **  **  **    *"+NORM+"\n"+
  " \n",
  "#MN# raises her hands high into the sky and calls upon the powers of justice exploding in a:\n"+
  " \n"+
  "             "+HIC+"H O L Y  N O V A"+NORM+"\n"+
  " \n",
    10,150,"other|good");  

}
