#include "/players/maledicta/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
string st1,st2,st3,st4;

reset(arg) {
  if(arg) return;
set_light(1);
st1 = "red";
st2 = "blue";
st3 = "yellow";
st4 = "green";
short_desc = BOLD+"The Fortress of Spirits"+NORM;
long_desc = 
RED+"[The Fortress of Spirits]"+NORM+"\n"+
BOLD+"This is the portal chamber of the Order of the\n"+
"Night. A pedastal stands to the right of a large\n"+
"archway that leads no where. To the south is the\n"+
"main chamber.\n"+NORM;
items = ({
"archway",
"A large black stone archway that stands in the center of the room",
"pedastal",
"A black pedastal that holds 4 gems. They are colored "+HIB+"Blue"+NORM+",\n"+
HIR+"Red"+NORM+", "+HIY+"Yellow"+NORM+", and "+HIG+"Green"+NORM+"\n"+
"You may arrange their order on the table to choose locations.\n"+
"Type 'arrange' for instructions"
});


dest_dir = ({
  "/players/maledicta/noctis/rooms/n1.c","south",
});

}

init(){
  ::init();
  add_action("arrange_stones", "arrange");
  add_action("port_me", "teleport");
  add_action("stone_map", "stones");
  }

stone_map(){
string stc1,stc2,stc3,stc4;
if(st1 == "green")  stc1 = HIG+"green"+NORM;
else if(st1 == "blue")   stc1 = HIB+"blue"+NORM;
else if(st1 == "yellow") stc1 = HIY+"yellow"+NORM;
else if(st1 == "red")    stc1 = HIR+"red"+NORM;
else stc1 = "error";
if(st2 == "green")  stc2 = HIG+"green"+NORM;
else if(st2 == "blue")   stc2 = HIB+"blue"+NORM;
else if(st2 == "yellow") stc2 = HIY+"yellow"+NORM;
else if(st2 == "red")    stc2 = HIR+"red"+NORM;
else stc2 = "error";
if(st3 == "green")  stc3 = HIG+"green"+NORM;
else if(st3 == "blue")   stc3 = HIB+"blue"+NORM;
else if(st3 == "yellow") stc3 = HIY+"yellow"+NORM;
else if(st3 == "red")    stc3 = HIR+"red"+NORM;
else stc3 = "error";
if(st4 == "green")  stc4 = HIG+"green"+NORM;
else if(st4 == "blue")   stc4 = HIB+"blue"+NORM;
else if(st4 == "yellow") stc4 = HIY+"yellow"+NORM;
else if(st4 == "red")    stc4 = HIR+"red"+NORM;
else stc4 = "error";
write(
"The current order of stones is:\n\n"+
"               "+stc1+"\n"+
"  "+stc2+"                     "+stc3+"\n"+
"               "+stc4+"\n");
return 1;
}

arrange_stones(str){
string old;
string first,second;
if(!str){
write(
"To arrange the stones, choose the color you wish to move\n"+
"and then the color you wish to switch it to.\n"+
"example: arrange red to blue\n"+
"To see where the stones are currently located\n"+
"type: stones\n"+
"When you have arranged the stones to where you want\n"+
"them, then type 'teleport' to activate the arch.\n");
return 1;
}
if(sscanf(str, "%s to %s", first, second) == 2){
 if(first == second){ write("You cannot move a stone to the same location!\n"); return 1; }
   if(st1 == first){
      if(st2 == second){      old = st1; st1 = st2; st2 = old; } 
      else if(st3 == second){ old = st1; st1 = st3; st3 = old; }   
      else if(st4 == second){ old = st1; st1 = st4; st4 = old; }  
      }
   else if(st2 == first){
      if(st1 == second){      old = st2; st2 = st1; st1 = old; } 
      else if(st3 == second){ old = st2; st2 = st3; st3 = old; }   
      else if(st4 == second){ old = st2; st2 = st4; st4 = old; }  
      }
   else if(st3 == first){
      if(st1 == second){      old = st3; st3 = st1; st1 = old; } 
      else if(st2 == second){ old = st3; st3 = st2; st2 = old; }   
      else if(st4 == second){ old = st3; st3 = st4; st4 = old; }  
      }
   else if(st4 == first){
      if(st1 == second){      old = st4; st4 = st1; st1 = old; } 
      else if(st2 == second){ old = st4; st4 = st2; st2 = old; }   
      else if(st3 == second){ old = st4; st4 = st3; st3 = old; }  
      }
   else{ write("arrange <color> to <color>\n"); return 1; }
   write("You move "+first+" to "+second+"\n");
   return 1; 
   }
write("arrange <color> to <color>\n");
return 1;
}

port_me(){
string dest;
     if(st1 == "red" && st2 == "blue" && st3 == "yellow" && st4 == "green")
        dest = "/room/church";
else if(st1 == "red" && st2 == "green" && st3 == "blue" && st4 == "yellow")
        dest = "/players/mythos/enterance";
else if(st1 == "yellow" && st2 == "green" && st3 == "blue" && st4 == "red")
        dest = "/players/eurale/RMS/warp";
else if(st1 == "yellow" && st2 == "blue" && st3 == "red" && st4 == "green")
        dest = "room/south/sshore1";
else if(st1 == "green" && st2 == "yellow" && st3 == "red" && st4 == "blue")
        dest = "/players/feldegast/darkcity/street2";
else if(st1 == "green" && st2 == "blue" && st3 == "yellow" && st4 == "red")
        dest = "/players/wocket/mushrooms/mg2";
else if(st1 == "blue" && st2 == "red" && st3 == "yellow" && st4 == "green")
        dest = "/players/dragnar/rooms/entrance";
else if(st1 == "blue" && st2 == "green" && st3 == "red" && st4 == "yellow")
        dest = "/room/ravine";
else{
write("Nothing happens.\n");
return 1;
  }
tell_room(this_object(),
HIY+"A bright flash of light fills the pedestal's stones. Its lashes\n"+
"out through the air and strikes the archway, filling it with\n"+
"energy! A glowing portal has opened to somewhere"+NORM+BOLD+"..."+NORM+"\n");
tell_room(this_object(),
this_player()->query_name()+" enters the archway and disappears.\n",({ this_player() }));
tell_object(this_player(),
HIY+"You enter the portal.."+NORM+"\n");
move_object(this_player(), dest);
command("look", this_player());
tell_object(this_player(), HIY+"And arrive somewhere else.."+NORM+"\n");
tell_room(environment(this_player()), this_player()->query_name()+" arrives in a flash of light.\n", ({this_player()}));
return 1;
}