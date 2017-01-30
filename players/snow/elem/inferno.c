inherit "room/room";
 
reset(arg){
 
 if(!arg){
 
 set_light(0);
  short_desc="A shodowy place";
 long_desc=
"As you peer about this shadowy area, a prickling of fear starts creeping\n"+
"down your back. The flickering shadows seem to take a life of their own.\n"+
"One shadow in particular seems to draw your attention. It is a little\n"+
"darker than the rest and it seems, if shadows can be so, particulary\n"+
"malevolant.\n";
 
items=({
"shadows","Shadows flicker about the room"
          });
 
enter(arg) {
if (arg == "portal") {
write (
"You step into the portal and are transported.\n");
say (
this_player(query_name())+" steps into the portal and disappears.\n");
(move_object(this_player()),"/players/snow/ROOMS/fortress.c");
say (
this_player(query_name())+" suddenly appears.\n");
}}
  }   }
 
 
