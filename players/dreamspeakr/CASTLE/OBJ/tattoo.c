#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

string bonus, ldesc;

/*prevent_insert() {
    write("Now how are you going to do that?  Its attached to you!\n");
    return 1;
}
*/
reset(arg){
   if(arg) return;
   set_weight(1);
   set_id( "tattoo" || "dream_tattoo" );   
   set_short(HIG+"A mark of the gods tattoo"+NORM);
}

long(){
   write("A tattoo purchased from the Mark of the God's studio.\n");
   write("\n");
   write("This tattoo appears to give a bonus of:  "+bonus+"\n");
   write("\n");
   write("You can:  Remove_tattoo - erases your tattoo.\n");
   write("          Show_tattoo - brags to everyone about it.\n");
   write("\n");
   write(""+MAG+"                  Another creation from Dreamspeakr\n"+NORM );
}

init(){
   add_action("show_tattoo","show_tattoo");
   add_action("remove_tattoo","remove_tattoo");
      switch( random(9) ){
        case 0:  this_player()->raise_will_power(1);
                 bonus="+1 will power";
                 break;
                 return 1;
        case 1:  this_player()->raise_piety(1);
                 bonus="+1 piety";
                 break;
                 return 1;
        case 2:  this_player()->raise_stealth(1);
                 bonus="+1 stealth";
                 break;
                 return 1;
        case 3:  this_player()->raise_luck(1);
                 bonus="+1 luck";
                 break;
                 return 1;
        case 4:  this_player()->raise_intelligence(1);
                 bonus="+1 intellegence";
                 break;
                 return 1;
        case 5:  this_player()->raise_strength(1);
                 bonus="+1 strength";
                 break;
                 return 1;
        case 6:  this_player()->raise_stamina(1);
                 bonus="+1 stamina";
                 break;
                 return 1;
        case 7:  this_player()->raise_magic_aptitude(1);
                 bonus="+1 magic";
                 break;
                 return 1;
       default:  this_player()->raise_stealth(1);
                 bonus="+1 stealth";
                 break;
                 return 1;
      }
}

show_tattoo(){
   write("\n");
   write("You stick out your chest with pride as you show off your cool tattoo.\n");
   write("\n");
   say("\n");
   say(this_player()->query_name()+" sticks out "+this_player()->query_possessive()+" chest showing off "+this_player()->query_possessive()+" new tattoo.\n");
   say(HIW+"\n");
   return 1;
}
remove_tattoo(){
  write("You take out a sample of alcohol and rub off your tattoo.\n");
  destruct( present("dream_tattoo",this_player()) );
  return 1;
}

query_save_flag() { return 1; }
