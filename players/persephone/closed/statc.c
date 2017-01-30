inherit "obj/treasure";
#include "/players/persephone/rooms.h"
reset(int arg){
 set_id("statue");
 set_short("Bronze Statue");
 set_long("Actually a bronze collosus would be more apt of a strong and lordly\n" +
          "figure standing in the saddle of the greatest steed you have \n" +
          "ever seen. In his left hand he appears to be wielding a mighty \n" +
          "and magical looking sword.  As you glance closer you notice that \n"+ 
          "this lordly figure seems to be crying. On the base of the statue \n" +
          "is an adamentite plaque with an important looking message.\n\n");


 set_weight(100);
 set_value(250000);
}
get(){
 return 0;
}
init(){
 ::init();
  add_action("read1","read");
  add_action("salute1","salute");
  add_action("salute1","bow");
  add_action("salute1","curtsey");
}
read1(str){
 if(str=="plaque" || str=="notice"){
  write("           The Lord Storm protector and founder\n" +
        "           of Stormhold.  Legend has it that when\n" +
        "           evil befalls Stormhold mighty warriors\n" +
        "           can revitalize the likeness of Storm into\n" +
        "           living flesh. Such a warrior must be both\n" +
        "           strong and courageous and pledge his\n" +
        "           service to Storm upon completing the\n" +
        "           mission that Storm sets the warrior he\n" +
        "           will receive a great present from this\n" +
        "           once great warrior to match the warriors\n" +
        "           service.\n\n");
  say(CAPTPLNM + " reads the plaque at the base of the collosus.\n");
  return 1;
 }
 write("Please read plaque\n\n");
return 1;
}
salute1(str){
 if(str=="storm" || str=="lord" || str=="statue"){
  write("You salute Storm and he returns back to life in front of your\n" +
        "very eyes.\n");
  say(CAPTPLNM + " salutes the statue of Storm.\n");
  if(!present("storm")){
   move_object(clone_object("players/persephone/closed/stor"), TOB);
  }
  destruct(TOB);
  return 1;
 }
 write ("Who are you saluting\n\n");
 return 1;
} 