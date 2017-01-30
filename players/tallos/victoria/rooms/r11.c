inherit "/players/vertebraker/closed/std/room.c";
#include "/players/tallos/ansi.h"
reset(arg) {
   if(arg) return;
   set_light(1);
   set_short(""+CYN+"Downtown Manhattan"+NORM+"");
set_long("   "+CYN+"This is a busy "+HIY+""+BLK+"city street"+NORM+""+CYN+" in downtown "+HIC+"Manhanttan"+NORM+""+CYN+".  There\n"+
         "are many "+GRN+"pedestrians"+CYN+" walking in large lines along the street\n"+
         ""+HIY+"Cars"+NORM+""+CYN+" buzz by with little regard for human safety.  You would\n"+
         "be advised to watch your step.  Across the street a new "+HIB+"club\n"+   
         ""+NORM+""+CYN+"is being built.    To the north is a huge "+HIM+"shop"+NORM+""+CYN+" with a set of \n"+ 
         ""+YEL+"double doors"+CYN+". The "+HIM+"sign"+NORM+""+CYN+" above the entrance says:\n"+ 
         ""+HIM+"Victoria's Secret "+HIR+"SUPER STORE!!!"+NORM+"\n");

add_exit("/players/tallos/victoria/rooms/r7","enter");
add_exit("/players/tallos/victoria/rooms/r10","west");
   add_item("victoria","This is the largest"+HIM+" Victoria's Secret"+NORM+" in the world! The doors are made from sold titatium\n"+
                       "and adorned with "+NORM+""+YEL+"gold trim"+NORM+". Sexy models stand in the window displaying the latest in bras\n"+
                       "and underwear fashion. You can't help but 'enter'.");
   add_item("shop","This is the largest "+HIM+"Victoria's Secret"+NORM+" in the world! The doors are made from sold titatium\n"+
                       "and adorned with "+NORM+""+YEL+"gold trim"+NORM+". Sexy models stand in the window displaying the latest in bras\n"+
                       "and underwear fashion. You can't help but 'enter'.");   
   add_item("store","This is the largest "+HIM+"Victoria's Secret"+NORM+" in the world! The doors are made from sold titatium\n"+
                       "and adorned with "+NORM+""+YEL+"gold trim"+NORM+". Sexy models stand in the window displaying the latest in bras\n"+
                       "and underwear fashion. You can't help but 'enter'.");
   add_item("building","This is the largest "+HIM+"Victoria's Secret"+NORM+" in the world! The doors are made from sold titatium\n"+
                       "and adorned with "+NORM+""+YEL+"gold trim"+NORM+". Sexy models stand in the window displaying the latest in bras\n"+
                       "and underwear fashion. You can't help but 'enter'.");
   add_item("cars","They drive quickly along the street around some construction to the west.");
   add_item("construction","New York is known for its massive contruction projects. It blocks your exit to the east.");
   add_item("north","To the north is a huge "+HIM+"Victoria's Secret "+HIR+"SUPER STORE"+NORM+"!");
   add_item("club","There seems to be a new club being built across the street. There is a poster on the door.");
   add_item("poster","              "+HIB+"   CLUB UNTZ UNTZ  "+NORM+"                 \n"+
                     ""+HIC+"Your wildest dreams, are about to come true...\n"+
                     "                "+HIY+"  Coming Soon! "+NORM+"                   ");
   add_item("street","A busy New York city street across the street you can see the great 7 Tigers Inn.");
   add_item("doors","A huge set of double doors made of titanium and adorned with "+YEL+"gold"+NORM+"!");
   add_item("pedestrians","They move quickly along the street. They pay no attention to you.");
   add_item("manhattan","This is the great upclass area of New York City. Large buildings and shops make up its bulk.");
   add_item("city","New York City...what a town!");
   add_item("sign",""+HIM+"VVV    VVV IIII CCCCCC TTTTTT OOOOOO RRRRR  IIII   AA  ''' SSSSSS    SSSSSS EEEEEE CCCCCC RRRRR  EEEEEE TTTTTT\n"+
                   " VVV  VVV   II  CC       TT   OO  OO RR  RR  II   A  A  '' SS        SS     E      CC     RR  RR E        TT\n"+
                   "    VVVVVV    II  CC       TT   OO  OO RRRRR   II   AAAA   ' SSSSSS    SSSSSS EEE    CC     RRRRR  EEEE     TT\n"+
                   "     VVVV     II  CC       TT   OO  OO RR  RR  II   A  A         SS        SS E      CC     RR  RR E        TT\n"+
                   "      VV     IIII CCCCCC   TT   OOOOOO RR  RR IIII  A  A     SSSSSS    SSSSSS EEEEEE CCCCCC RR  RR EEEEEE   TT\n"+
                   "       "+NORM+"               \n"+
                   ""+HIR+"SSSSSSSSSS UUU   UUU PPPPPPPP  EEEEEEEEE RRRRRRRR     SSSSSSSSS TTTTTTTTT OOOOOOOOO RRRRRRRR  EEEEEEEEE\n"+
                   "SSSSSSSSSS UUU   UUU PPPPPPPPP EEEEEEEEE RRRRRRRRR    SSSSSSSSS    TTT    OOOOOOOOO RRRRRRRRR EEEEEEEEE\n"+
                   "SSS        UUU   UUU PPP   PPP EEE       RRR   RRR    SSS          TTT    OOO   OOO RRR   RRR EEE\n"+
                   "SSS        UUU   UUU PPP   PPP EEE       RRR   RRR    SSS          TTT    OOO   OOO RRR   RRR EEE\n"+
                   "SSSSSSSSSS UUU   UUU PPPPPPPPP EEEEEEE   RRRRRRRR     SSSSSSSSS    TTT    OOO   OOO RRRRRRRR  EEEEEEE\n"+
                   "SSSSSSSSSS UUU   UUU PPPPPPPP  EEEEEEE   RRRRRRRRR    SSSSSSSSS    TTT    OOO   OOO RRRRRRRRR EEEEEEE\n"+
                   "         SSS UUU   UUU PPP       EEE       RRR   RRR          SSS    TTT    OOO   OOO RRR   RRR EEE\n"+
                   "         SSS UUU   UUU PPP       EEE       RRR   RRR          SSS    TTT    OOO   OOO RRR   RRR EEE\n"+
                   "SSSSSSSSSS UUUUUUUUU PPP       EEEEEEEEE RRR   RRR    SSSSSSSSS    TTT    OOOOOOOOO RRR   RRR EEEEEEEEE\n"+
                   "SSSSSSSSSS UUUUUUUUU PPP       EEEEEEEEE RRR   RRR    SSSSSSSSS    TTT    OOOOOOOOO RRR   RRR EEEEEEEEE"+NORM+"");                                                                      
} 
