#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TP this_player()
#define TPN TP->query_name()
inherit "room/room";

int time;
object dunkee;

reset(arg) {
      if(arg) return;
   set_light(1);

   short_desc = "In the Dunk Tank";
   long_desc =
"   This small room is much taller than it is wide and has been\n\
filled half way up with water.  The wall in front is made of very\n\
strong plexiglass for easy viewing by those outside.  Inside the\n\
boxlike room a small chair is suspended over the water below by a\n\
small metal arm.  To the left is a small window with a timer above\n\
it, but there dosen't seem to be a door or a way out of any kind.\n";

   items = ({
      "lights","Long fluorescent lights brighten the inside of the room",
      "plexiglass","It's there so that those outside may see in",
      "outside","The lights inside make seeing out very difficult",
      "window","The dunk tank attendant peers in at you with a mischievous grin",
      "chair","Comfortable, but small, it is held above the water by the metal arm",
      "arm","It sticks out from the wall and has a chair attached to it",
      "water","The water is clear and probably cold too",
      "timer","There are no numbers but the needle steadily moves toward the\n\
mark at the top",
   });
}
init(){
     ::init();
     if( !TP ){ return; } 
     if(TP->query_level() > 20){
        write("\nYou are a wizard and will not regester as being in the dunk tank.\n"+
              "Please move yourself out of the tank now.\n\n");
        return;
     }
     if(TP->is_player()){
     dunkee = TP;
     time = 0;
     call_out("dtimer", 35);
     }
}

dtimer(){
     object ob;
/*added by wocket */
  if(!dunkee){
    dunkee = 0;
    remove_call_out("dtimer");
    return 1; 
  }

     time++;
     if(time < 4){
        remove_call_out("dtimer");
        switch(time){
               case 1: { tell_object(dunkee, "The timer is a quarter of the way down.\n");
                         break; }
               case 2: { tell_object(dunkee, "The timer is half of the way down.\n");
                         break; }
               case 3: { tell_object(dunkee, "The timer is three quarters of the way down.\n");
                         break; }
        }
        call_out("dtimer", 35);
        return 1;
     }
     remove_call_out("dtimer");
     ob = dunkee;
     dunkee = 0;
     tell_object(ob, "The tank attendant opens a door in the side of the tank and helps you out.\n\n");
     if(find_object(AREA+"tank.c")){ tell_room(AREA+"tank.c", "The attendant releases "+ob->query_name()+" from the tank.\n"); }
     move_object(ob, AREA+"tank.c");
     command("look", ob);
     return 1;
}
dunked(){
     object ob;
     remove_call_out("dtimer");
/* added by wocket */
    if(!dunkee){
    dunkee = 0;
    return 0;
    }
     ob = dunkee;
     dunkee = 0;
     tell_object(ob, "You here a loud thump and suddenly the seat beneath you drops away leaving\n"+
                     "you momentarily suspended above the water below.  Then...\n\n"+
                     "         "+HIB+"S  P  L  A  S  H"+NORM+"  \n\n"+
                     "You are dropped into the chilling water below!\n"+
                     "Luckly the dunk tank attendant quickly opens a hidden panel and pulls you out.\n\n");
     if( !present("wet", ob) ){
        move_object(clone_object(OBJ+"drenched.c"), ob);
     }
     move_object(ob, AREA+"tank.c");
     command("look", ob);
     return 1;
}
object query_dunkee(){ return dunkee; }
realm(){ return "NT"; }
