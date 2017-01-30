#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";


reset(arg){
    if (arg) return;
   

set_id("flier");
  set_alias("flier");
set_short(HIW+"A flier about the kale contest"+NORM);
set_long("A colored flier. Read it for more info.\n");

}


init() {
  ::init();
    add_action("read_book","read");
    add_action("apply","apply");
if(this_player() != environment(this_object())) 
  return; 
}

read_book(stri) {
     if (!stri) {write("Read what?\n");return 1;}
     if(stri == "flier") {
      write("The flier has several pages, you can read "+HIC+"title, "+NORM+GRN+"\nidea, "+NORM+HIY+
            "rules,"+NORM+HIW+" prizes,"+NORM+HIM+" ranking, "+NORM+HIR+"strategy,"+NORM+HIB+" misc,"+NORM+"\n"+
            ""+HIW+"results."+NORM+"\n");
      return 1;}
     if(stri == "title"){
      write(""+HIW+"T H E    "+HIR+"K A "+NORM+YEL+"L E "+HIY+"I D "+HIG+"O S "+HIB+"C O "+HIM+"P E "+HIW+"   C O N T E S T"+NORM+"\n");
      return 1;}
     if(stri == "idea"){ 
      write("\n"+GRN+"                    T H E   I D E A \n"+NORM+""+
            "As you might know already, nobody knows the exact number of the \n"+
            "kaleidoscopes within this area, neither is known the quality of \n"+
            "those items (either white, blue or yellow).  So, i wondered what\n"+
            "would be the maximum attainable.  And then, why not make it a\n"+
            "challenge?\n"+ 
            "The contest is based on the largest number of kaleidoscopes gotten\n"+ 
            "within one single reboot.  Those three who will get the most\n"+
            "kaleidoscopes will share the prizes.\n\n");
      return 1; }
     if(stri == "prizes"){
      write("\n"+HIW+"                    T H E   P R I Z E S\n"+NORM+""+ 
            "A pool will be made by the overall fees paid, increased by 50%, \n"+
            "courtesy of the administrators.  This grand total will be shared\n"+
            "within the top three players as per 60%, 30% and 10%, respectively.\n"+
            "If only two players will play, they will share it at 65% and 35%, \n"+
            "respectively.  Finally, if only one player will play, well, we \n"+
            "will congratulate him/her and close the contest, for lack of \n"+
            "participants.  \n"+
            "The prizes will be awarded during the next week after each contest.\n\n");
      return 1;}
     if(stri == "rules"){
      write("\n"+HIY+"                    T H E   R U L E S\n"+NORM+""+
            "1. The contest will begin at Monday morning and will last for the\n"+
            "   entire week through the next Monday morning reboot, Nirvana time. \n"+
            "2. Players can enter the contest several times within the week.\n"+
            "3. Each reboot they must pay a fixed fee of 2000 coins.\n"+
            "4. Each fee is valid for one and only reboot.\n"+
            "5. The command to enter the contest is 'apply for contest' and\n"+
            "   must be typed in this room.\n"+
            "6. Only the best weekly performance is considered for the final \n"+
            "   placement.\n"+
            "7. Only the kale's collected after registering and regularly cashed \n"+
            "   will be counted.\n\n");
      return 1;}
     if(stri == "ranking"){
      write("\n"+HIM+"                    T H E   R A N K I N G \n"+NORM+""+
            "The ranking will be made accordingly to both the number and the\n"+
            "type of the kaleidoscopes collected.  Each white will count 3\n"+
            "points, each blue will count 2 points and each yellow will count\n"+
            "1 point.  So, three white's, 1 blue and 4 yellow's will total\n"+
            "3x3 + 1x2 + 4x1 = 15 points.\n\n");
      return 1;}
     if(stri == "strategy"){
      write("\n"+HIR+"                    T H E   S T R A T E G Y\n"+NORM+""+ 
            "Every strategy is allowed, unless it hurt Nirvana overall rules.\n"+
            "Players can party, can give the kale's each other, can drop them\n"+
            "at hotel room for later pickup, everything is allowed.  \n"+
            "Yet, be aware, again, that only the kales regularly cashed will \n"+
            "be counted.  Moreover, the credits will be given only to the \n"+
            "player who actually cashed them, provided he/she already registered.\n\n");
      return 1;}
     if(stri == "misc"){
      write("\n"+HIB+"                    M I S C E L L A N E O U S \n"+NORM+""+
            "We will try to let you be informed about the current standings, \n"+
            "approximatively, by posting messages in this room, no guarantee.\n"+
            "First contest will start at Monday October 7th, after the morning\n"+
            "reboot, Nirvana time.\n"+
            "Please, read this flier carefully, no whining will be allowed.\n"+
            "Acknowledgement:  Daranath, Dune, Eurale, Wren.\n"+
            "Hope you enjoy this new contest.\n\n"+
            "\n                                 fran\n\n");
      return 1;}
     if(stri == "results"){
      write("\n"+HIB+"                     R E S U L T S  \n"+NORM+""+
            "Week #1, October 7th -> October 14th 2002.\n"+
            "Number of participants: 30    Total prize: 90,000\n"+
            ""+HIW+"Winners   "+HIR+"Curse 153     "+HIB+"Caravelle 48     "+HIC+"Tallos 37"+NORM+"\n"+
            "          54,000        27,000            9,000\n"+
            ""+HIM+"Others"+NORM+"    Roland 30, Tower 24, Smokey 24, Mosh 23, Orb 21\n"+
            "          Sylvan 18, Ravennight 13, Tartis 6. \n"+
            "Several others have collected kales but didnt register \n"+
            "properly so their scores cannot be counted.  We will only\n"+
            "mention Roland, which totaled 126 points, and whom we will\n"+
            "give a special prize of 5,000 coins, for his good attitude.\n"+
            "Thank you very much for participating into this new contest.\n"+
            "Hope you enjoyed it, and see you for the next one already \n"+
            "started and enduring until next Monday October 21st 2002.\n"+
            "\n                                 fran\n\n");
      return 1;}
return 1;}


apply(str){
  if(!str) { notify_fail("Apply for what?\n"); return 1;}
  if(str == "for contest") {
     write("The contest is temporarily over. \n"+
          "It will be updated and come back later.\n"+
          "Thanks all for the interest shown.\n"+
          "\n                           fran\n"); 
    return 1;}
/**      {
   if(this_player()->query_money() < 2000) {
     notify_fail("You do not have enough money to enter the contest! \n");
     return 0; }
    this_player()->add_money(-2000);
    write("You pay the fee for the contest and then you are now qualified\n"+
          "for the final prizes.  Happy kaleidoscoping and good luck!\n");
    write_file("/players/francesco/kale/log/"+this_player()->query_name()+"",ctime(time())+" enrolled \n");
    return 1;}
**/
return 1;}

get(stri) {
    if(stri == "flier") {
        notify_fail("Please, dont remove the flier from this room.  It would fail its goal.\n");
        return 0;}
return 0;}
