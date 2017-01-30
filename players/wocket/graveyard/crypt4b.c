#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/graveyard/"
inherit "/players/wocket/graveyard/crypt1.c";
int l;

reset(arg){
l = 1;
  ::reset(arg);
  if(arg) return ;
long_desc = ""+
"   There is a heap of dryant bodies in the middle of the room.  The\n"+
"corpses in this room seem more distinquished then others.  They are laid\n"+
"out in more natural posiitons, all having there own space to rest.\n"+
"Dirt has still managed to encrust the walls but small torches light\n"+
"the room somewhat.  Shadows fill the corners.\n";
items += ({
"shadows","They are cast from the torches and fill the corners",
"torches","They cast a little light upon the encroaching darkenss",
"corpses","They are layed out and look more distinquished",
});
dest_dir = ({
  PATH+"crypt2b.c","north",
});
}

init(){
  ::init();
  add_action("search","search");
 call_out("flicker",1);
}

exit(){
  ::exit();
  remove_call_out("flicker");
return 1;
}
flicker(){
if(random(20) == 2){
  say("The torches flicker in the darkness.\n");
}
if(random(20) == 2){
  say("The shadows move along the walls.\n");
}
call_out("flicker",random(10));
}
search(){
if(l != 1){
  write("You find nothing of interest.\n");
  return 1;
}
write("You search around.\n"+
      "Something begins to move in the corner.\n"+
     MAG+"Lady Vreeland"+NORM+" steps out from the shadows.\n");
say(MAG+"Lady Vreeland"+NORM+" steps out from the shadows.\n");
move_object(clone_object(PATH+"lady.c"),this_object());
l++;
return 1;
}
