#include "/players/dreamspeakr/closed/ansi.h"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;

     set_name("bow");
     set_alias("warriors bow");
     set_short(YEL+"Warriors Bow"+NORM);
     set_long(
	"This simple bow from the Anasazi warrior is made from the wood \n"+
        "of a pinon pine tree.  Eagle feathers hang from the top of this \n"+
        "hand carved weapon.\n");
     set_type("projectile");
     set_class(13);
     set_weight(3);
     set_value(900);
     set_hit_func(this_object());
}

weapon_hit(attacker){
   int W;
     object theroom;
     theroom=environment(wielded_by);
     W = random(13);
   if(W>9)  {
     tell_room(theroom,"\n");
     tell_room(theroom,this_player()->query_name()+" pulls back the "+YEL+"BOW"+NORM+" and releases...\n");
     tell_room(theroom,"\n");
     tell_room(theroom,HIW+"           \\\\\\"+NORM+"\n");  
     tell_room(theroom,YEL+"           ========"+NORM+WHT+">"+NORM+"\n");
     tell_room(theroom,HIW+"           ///"+NORM+"\n");
     tell_room(theroom,HIW+"                      \\\\\\"+NORM+"\n");  
     tell_room(theroom,YEL+"                      ========"+NORM+WHT+">"+NORM+"\n");
     tell_room(theroom,HIW+"                      ///"+NORM+"\n");
     tell_room(theroom,HIW+"                                 \\\\\\"+NORM+"\n");  
     tell_room(theroom,YEL+"                                 ========"+NORM+WHT+">"+NORM+"\n");
     tell_room(theroom,HIW+"                                 ///"+NORM+"\n");
     tell_room(theroom,HIW+"                                            \\\\\\"+NORM+"\n");  
     tell_room(theroom,YEL+"                                            ========"+NORM+WHT+">"+NORM+"\n");
     tell_room(theroom,HIW+"                                            ///"+NORM+"\n");
     tell_room(theroom,"\n");
     return 3;
     return;
  }

   if(W>6)  {
     tell_room(theroom,"\n");
     tell_room(theroom,HIW+"The "+NORM+YEL+"BOW"+HIW+" quivers as "+this_player()->query_name()+" shoots..."+NORM+"\n");
     tell_room(theroom,"\n");
     return 0;
   }

   if(W>3)  {
     tell_room(theroom,"\n");
     tell_room(theroom,HIW+"The string from the "+YEL+"BOW"+HIW+" goes...\n");
     tell_room(theroom,"\n");
     tell_room(theroom,HIR+"               T  W  A  N  G"+NORM+"\n");
     tell_room(theroom,"\n");
     return 0;
   }

}
