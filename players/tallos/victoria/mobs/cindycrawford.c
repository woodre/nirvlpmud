inherit "/obj/monster.c";
#include "/obj/ansi.h"
#define tpn this_player()->query_name()

object bra;
reset(arg) {
  ::reset(arg);
  if(arg) return;


  set_name("cindy");
  set_race("human");
  set_short(BOLD+HIM+"Cindy Crawford"+NORM);
  set_long(
    "  Before you stands the worlds first and most beautiful supermodel\n"+
    "She models for you in her rainbow bra and matching panties. She is\n"+
    "extremely fit. It might now be a good idea to attack her.  she was\n"+
    "married to Richard Gere after all... \n"+
    " \n"+
    "Measurements: 34C-24-35\n");
  
  add_money(5000);
  bra = clone_object("/players/tallos/victoria/objects/ipexbrarainbow.c");
  move_object(bra, this_object());
  command("wear bra", this_object());
  set_level(27+random(5));
  set_hp(2000+random(1000));
  set_al(0);
  set_ac(19+random(11));
  set_wc(40+random(6));
  set_aggressive(0);
  set_multi_cast(0);
  add_spell("Sissor Kick",
  "#MN# jumps into the air and preforms a crushing...\n"+
  " \n"+
  "   "+RED+"SSSSSS IIII SSSSSS SSSSSS OOOOOO RRRRR    KK  KK  IIII CCCCCC KK  KK\n"+
  "   SS      II  SS     SS     OO  OO RR  RR   KK KK    II  CC     KK KK  \n"+     
  "   SSSSSS  II  SSSSSS SSSSSS OO  OO RRRRR    KKKK     II  CC     KKKK\n"+
  "   SSSSSS  II  SSSSSS SSSSSS OO  OO RR  RR   KK KK    II  CC     KK KK\n"+      
  "       SS  II      SS     SS OO  OO RR  RR   KK  KK   II  CC     KK  KK\n"+
  "   SSSSSS IIII SSSSSS SSSSSS OOOOOO RR  RR   KK   KK IIII CCCCCC KK   KK"+NORM+"\n"+
  " \n",
  "#MN# leaps into the air and preforms a dealy...\n"+
  " \n"+
  "         "+HIR+" S I S S O R    K I C K !"+NORM+"\n"+
  " \n",
    15,100,"other|physical");
  add_spell("matrix leg kick",
  "#MN# moves with lightning speed. Time seems to slow for you as Cindy leaps into the air and the camera angle shifts as she does a move from "+HIB+"THE"+NORM+"\n"+
  " \n"+
  "    "+HIB+" MMM       MMM     AAAA    TTTTTTTTT   RRRRRRRR    IIIIIII  XXXX     XXXX\n"+
  "     MMMM     MMMM    AAAAAA      TTT      RRR   RRR     III     XXXX   XXXX\n"+
  "     MMMMM   MMMMM   AAA  AAA     TTT      RRR   RRR     III      XXXX XXXX\n"+ 
  "     MMM MM MM MMM   AAA  AAA     TTT      RRRRRRRRR     III       XXXXXXX\n"+
  "     MMM  MM   MMM   AAAAAAAA     TTT      RRRRRRRR      III       XXXXXXX\n"+
  "     MMM       MMM   AAAAAAAA     TTT      RRR   RRR     III      XXXX XXXX\n"+
  "     MMM       MMM   AAA  AAA     TTT      RRR    RRR    III     XXXX   XXXX\n"+
  "     MMM       MMM   AAA  AAA     TTT      RRR    RRR    III    XXXX     XXXX\n"+
  "     MMM       MMM   AAA  AAA     TTT      RRR    RRR  IIIIIII XXXX       XXXX"+NORM+"\n"+
  " \n",
  "#MN# raises into the air as time slows down. Cindy preforms a dramantic.......\n"+
  " \n"+
  "             "+HIM+"SLOW MOTION "+HIB+"MATRIX"+HIM+" STYLE MID AIR HEAD KICK!!!!"+NORM+"\n"+
  " \n",
    5,200,"other|physical");  

}
