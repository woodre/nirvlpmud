
#include "../all.h"

object bweapon, USER;

set_illusion_shadow(object obj){
  bweapon = obj;
  USER = environment(obj);
  shadow(bweapon,1);
}

rm_illusion_shadow(){
  shadow(bweapon,0);
  destruct(this_object());
  return 1;
}

query_illusion_shadow(){ return 1; }


wield(str){
  write("As you try to wield the "+str+
    " you realize it is only an illusion.\n");
  return 1;
}

short(){ 
  if(this_player()->query_guild_name() == "fallen")
    return bweapon->short()+BOLD+BLK+" [illusion]"+NORM;
  else
    return bweapon->short();
}

long(){ 
  bweapon->long(); 
  write(BOLD+BLK+"The "+bweapon->query_name()+
    " is cloaked in a very soft shadow.\n"+NORM);
}

query_weight(){  return 1; }    /* shadows make it lighter */

query_save_flag(){ return 1; }  /* does not save */

hit(nmy){         /* in case they somehow wielded it despite block */
  if(!random(10))
  {
    write("The illusion fades away...\n");
    destruct(bweapon);
    rm_illusion_shadow();
  }
}

