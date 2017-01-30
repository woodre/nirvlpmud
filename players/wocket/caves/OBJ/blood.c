#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
set_id("blood");
set_short(RED+"A pool of blood"+NORM);
set_long("This is the blood of a pojoui.  It is very posionious to many\n"+
         "including the dreaded Sinja worm.  Long ago nonges would cover\n"+
         "there weapons with this blood, but it could not save them from\n"+
         "the great attack of the dark ones.\n");
}

init(){
add_action("cover","cover");
  if(environment(this_object()) == this_player()){
    write(RED+"As your hands reach deep into the pool of blood they begin to burn.\n"+
    "Layers upon layers of skin peel away revealing bone.\n"+
    "You scream in terror.\n"+NORM);
say(this_player()->query_name()+" screams in terror.\n");
    this_player()->add_hit_point(-150-random(50));
    destruct(this_object());
}
}

cover(string str){
object wep;
object bloodshadow;
if(!str){
    notify_fail("Cover what?\n");
    return 0;
}
wep = present(str,this_player());
  if(!wep){
    notify_fail("You do not have that to cover with blood.\n");
    return 0;
  }
  if(!wep->weapon_class()){
    notify_fail("That is not a weapon to cover with blood.\n");
    return 0;
  }
  if(wep->query_prevent_shadow() || wep->query_limited_shadow()){
    notify_fail("That weapon is to powerfull to cover with blood.\n");
    return 0;
  }
  if(wep->query_bloodcount()){
    write(RED+"You cover "+wep->short()+" with blood.\n"+NORM);
    present(str,this_player())->add_bloodcount();
    destruct(this_object());
    return 1;
  }
  bloodshadow = clone_object("/players/wocket/caves/OBJ/bloodshadow.c");
  bloodshadow->set_bloodshadow(wep);
  bloodshadow->add_bloodcount();
  write(RED+"You cover "+wep->short()+" with blood.\n"+NORM);
  destruct(this_object());
return 1;
}
