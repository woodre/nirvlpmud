#include "/players/maledicta/ansi.h"
inherit "/obj/treasure.c";
string testwho;

reset(arg){
  if(arg) return;
set_id("tester");
set_short(0);
set_long("test.\n");
}

init(){
add_action("testwep","testwep");
add_action("setwho","setwho");
}

setwho(str){
testwho = str;
}

testwep(string str){
object wep;
object testshadow;

wep = present(str,this_player());
  if(!wep){
    write("That is not here.\n");
    return 0;
  }
  if(!wep->weapon_class()){
    write("Not a wep.\n");
    return 0;
  }
  testshadow = clone_object("/players/maledicta/closed/blessshadow.c");
  if(testwho){
  testshadow->set_attack_who(testwho);
  }
  testshadow->set_bless_shadow(wep);
  write("done.\n");
  destruct(this_object());
  return 1;
  }
