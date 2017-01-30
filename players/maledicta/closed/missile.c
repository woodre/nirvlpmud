#include "/players/maledicta/ansi.h"

int launched;
object dope;
 
id(str) { 
if(!launched){
return str == "missile"; 
 }
}
 
short() { 
if(!launched){
return HIB+"A big ol' Huge Missile"+NORM; }
} 

long() { 
write("This is a very large missile. You can 'launch' it\n"+
      "at the ones you love.\n");
      return 1; 
      }
 
init() {
if(!launched) add_action("launch_it","launch");
if(launched) add_action("dodge_it", "dodge");
  }

dodge_it(str){
 write("Oops...guess you can't.\n"); 
 return 1; 
 }
 
launch_it(str){
if(!str){ 
 write("launch at who?\n"); 
 return 1; 
 }
 dope = find_living(str);

if(!dope){
  write("The missile can't find them.\n");
  return 1; 
  }
tell_object(dope,
HIR+"OH MY GOD!!! INCOMING!!! DODGE DODGE DODGE!!!"+NORM+"\n");
move_object(this_object(), dope);
launched = 1;
call_out("hit_em", 4);
return 1;
}

hit_em(){
launched = 0;
tell_object(dope,
"A missile falls out of the sky and slams into you.\n\n");
tell_object(dope,
HIR+"  ********   *******  *******   ***    ***\n"+
"  **     **  **   **  **   **    ***  *** \n");
tell_object(dope,
"  ********   **   **  **   **    ** ** ** \n"+
"  **     **  **   **  **   **    **    ** \n"+
"  ********   *******  *******   ***    ***"+NORM+"\n\n");
tell_object(dope,
"Awwww...now look what a mess you made =( \n");
destruct(this_object());
return 1;
}



drop(){
  return 0;
  }