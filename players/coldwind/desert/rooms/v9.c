#include "/players/coldwind/define.h"

inherit "room/room";
int secret_att;

reset(arg) {	
  if(arg) return;
set_light(1);

short_desc = ""+HIY+"Dahna desert"+NORM+"";
long_desc =
"    Before you is a graveyard.  Thousands of signs stand marking the\n"+
"graves and spreading fear and despair in the atmosphere.  An old sign\n"+
"is posted at the begining of a stone road.  The road was made \n"+
"with great care and it heads west to the heart of the desert.  The \n"+
"angry sun glares at you sending it's burning sunrays directly at you,\n"+
"while the hot sand is being blown at you by an invisible force.\n";

items = ({
  "desert",
  "Yellow sand expands in every direction",
  "graveyard",
  "Thousands of signs mark the graves, sending a strange feeling of fear and despair\n"+
  "through your veins", 
  "sand",
  "Hot sand covers the face of desert. The wind blows the sand directly at you",
  "sun",
  "The sun looks angry as it glows hot sending it's burning sunrays\n"+
  "directly at you",
  "road",
  "A stone road, that was built with great care, starts here leading\n"+
  "west toward the desert",
  "signs",
  "A sign mark each grave. Briefly, the lives of the buried is written on the signs",
  "graves",
  "Each grave is marked with a sign. Some graves have been left "+BOLD+"opened"+NORM+"",
  "sign",
  "An old sign posted at the begining of the road",
  "opened graves",
  "They look like the other graves except that they are opened. Maybe \n"+
  "you can "+BOLD+"search"+NORM+" them",   
  "open graves",
"They look like the other graves except that they are opened. Maybe \n"+
  "you can "+BOLD+"search"+NORM+" them",     
  
});

dest_dir = ({
  "/players/coldwind/desert/rooms/v8.c","west",
});
}
set_secret_att(int n){  secret_att=n;}
query_secret_att(){ return secret_att; }

init(){
  ::init();
  add_action("search_graves", "search");
  add_action("read_sign", "read");
  }
  
  search_graves(string str){
  object leader;
    if(!str){ write("Search what?\n"); return 1; }
  	if(str == "graves", "opened graves", "open graves"){
write("You search the opened graves carefully...\n");
if(query_secret_att() == 0){
write("A fearsome winged ape flies out of an opened grave as it notices\n"+
      "your searching. The ape takes advantage of your surprise\n"+
	  "and sinks its claws deep in your "+HIR+"FLESH"+NORM+"...\n");
	  leader = clone_object("/players/coldwind/desert/mobs/leader.c");
          this_player()->hit_player(25);
          leader->attack_object(this_player());

move_object(leader, this_object());
          set_secret_att(1);
		    command("look", tp);
          return 1;
          } 
 say(tpn+" searches the opened graves carefully.\n");
 return 1;
 }}
		  
read_sign(string str){
  if(!str){ write("Read what?\n"); return 1; }
	if(str == "sign"){
write(BOLD+" THe  Caverns  of  Al'  EL'  Man our"+NORM);
say(""+tpn+" reads the sign!");
return 1;
}
}