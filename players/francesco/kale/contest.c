#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";


reset(arg){
    if (arg) return;
   

set_id("flier");
  set_alias("flier");
set_short(HIW+"A flier from Francesco"+NORM);
set_long("A colored four page flier. Read it for more info.\n");

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
      write("The flier has four pages, you can 'read title' 'read idea', \n"+
            "'read rules', 'read prizes'\n");
      return 1;}
     if(stri == "title"){
      write(""+HIW+"THE "+HIR+"KA"+NORM+YEL+"LE"+HIY+"ID"+HIG+"OS"+HIB+"CO"+HIM+"PE"+HIW+" CONTEST"+NORM+"\n");
      return 1;}
     if(stri == "idea"){ 
      write("As you might know already, nobody knows the exact number of the \n"+
            "kaleidoscopes within this area, neither is known the quality of \n"+
            "those items (either white, blue or yellow).  So, i wondered what\n"+
            "would be the maximum attainable.  And then, why not make it a\n"+
            "challenge?\n"+ 
            "The contest is based on the largest number of kaleidoscopes gotten\n"+ 
            "within one single reboot.  Those three who will get the most\n"+
            "kaleidoscopes will share the prizes.\n");
      return 1; }
     if(stri == "prizes"){
      write("A pool will be made by the overall fees paid, increased by 50%, \n"+
            "courtesy of the administrators.  This grand total will be shared\n"+
            "within the first three classified players as per 60%, 30% and 10%, \n"+
            "respectively.  If only two players will play, they will share it\n"+
            "at 65% and 35%, respectively.  Finally, if only one player will \n"+
            "play, well, we will congratulate him/her and close the contest,\n"+
            "for lack of participants.\n");
      return 1;}
     if(stri == "rules"){
      write("The duration of the contest is set in one week.  A player can enter \n"+
            "the contest several times within the week, and each reboot he/she must\n"+
            "'apply contest' and pay 2000 coins as a fee, but only his/her best \n"+
            "performance will be considered for the classment.\n");
      return 1;}
     if(stri == "classification"){
      write("The classification will be made accordingly to both the number and\n"+
            "the type of the kaleidoscopes collected.  Each white will count 3\n"+
            "points, each blue will count 2 points and each yellow will count\n"+
            "1 point.  So, three white's, 1 blue and 4 yellow's will total\n"+
            "3x3 + 1x2 + 4x1 = 15 points.\n");
      return 1;}
return 1;}


apply(str){return 1;}

get(stri) {
    if(stri == "flier") {
        notify_fail("Please, dont remove the flier from this room.  It would fail its goal.\n");
        return 0;}
return 0;}
