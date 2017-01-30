#include "/players/puppy/define.h"
inherit "/players/vertebraker/closed/std/room.c";

int KAT;
realm() { return "NT"; }
reset(arg) {
   KAT = 0;
set_short("A Short");
   set_long(
"A Long.\n");
   set_light(1);
add_listen("main", "You year something.");
add_smell("main", "You smell something.");
   items = ({
"something", "You look at something",
"something1", "You look at something else"});
   dest_dir = ({
"/players/puppy/workroom.c", "puppy",
"/players/katya/workroom.c", "katya"});
   
}
init(){
   ::init();
   add_action("grab_monster","grab");
}

grab_monster(str){
   if(KAT >=1){
write("OH NO!!!\n");
      return 1; }
   
   if(str == "mon" || str == "monster" || str == "a big monster"){
say(this_player()->query_name()+" finds a big monster.\n");
move_object(clone_object("/players/puppy/EX/mob.c"),this_object());
      KAT +=1;
      return 1; }
}
