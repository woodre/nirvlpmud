#define NAME "katya"

#define DEST "room/south/sforst6"

#include <ansi.h>

#define TP this_player()

id(str) { return str == "portal" || str == "forgotten realm" || str == "castle" || str == "realm"   ;}

short() {
    return ""+HIM+"Forgotten Realm"+NORM+"";
}
long() {
    write("\Dare to enter the Forgotten Realm and take an adventure to different worlds.\n");
}
init () {
     add_action ("enter_realm","enter");
     }

enter_realm(str) {
   if(!str) { write("Enter what?\n");
       return 1;}
  if(str=="realm" || str == "forgotten realm"  || str == "castle") {
  TP->move_player("into the Forgotten Realm#/players/katya/area/realm.c");  
     say(this_player()->query_name()+" enters the Forgotten Realm.\n");
     write("You have entered the Forgotten Realm.\n");
     return 1;}

}
reset(arg) {
    if (arg)
        return;

    move_object(this_object(), DEST);
}is_castle(){return 1;}

