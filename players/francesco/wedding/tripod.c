#include "/players/francesco/univ/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "/obj/treasure.c";
int x, play;
string dummy;

reset(arg) {
  if(arg) return;
set_short("A stand") ;
set_long ("A tripod which holds a sign to 'read'.\n");
}

id(str) { return str =="stand" || str =="tripod";}

init(){
      ::init();
      add_action("read","read");
      add_action("show","show");
      }

read(str){
   if(str=="sign")
    {write("Today wedding is:\n\n"+HIW+
           "                    Sir Fantasy and Lady Ceres"+NORM+"\n");
    return 1;}
  notify_fail("Read what?\n");
  return 0;
}

show(str){
   object item;
   if(str=="invite")
     {if(!present("invite",this_player())) {
       write("The usher gently asks:  Are you sure you got the invite to this wedding?\n");
       return 1;}
     write("The usher takes the invite and examines it, then snaps his fingers,\n"+
           "a limo arrives and brings you to the wedding of Sir Fantasy and Lady Ceres.\n\n\n\n");
     this_player()->move_player("to attend the wedding of Sir Fantasy with Lady Ceres#players/francesco/wedding/room1.c");
     return 1;}
  notify_fail("Show what?\n");
  return 0;
} 


get(stri) {
    if(stri == "stand" || stri =="tripod") {
        notify_fail("Please, dont remove the tripod from this room. \n");
        return 0;
    }
    return 0;
}

