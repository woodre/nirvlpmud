#include "/players/catacomb/saiyan/def.h"

check_baby_check(str){
  object nerf;
  int Wep, Arm, WeighIt;
  string Atype, pretty, itsweight;
  nerf = present(str, this_player());
    if(!nerf){
    write("You don't see that here.\n");
    return 1; }
  Wep = nerf->weapon_class();
  Arm = nerf->armor_class();
  Atype = nerf->query_type();
  WeighIt = nerf->query_weight();
    if(!Arm && !Wep){
      write("This doesn't seem to be a piece of armor or a weapon.\n");
      return 1; }
    if(Wep){
      if(Wep > 21){
        pretty = "God Like";
      }
      else if(Wep > 19){
        pretty = "Superior";
      }
      else if(Wep > 17){
        pretty = "Great";
      }
      else if(Wep > 15){
        pretty = "Good";
      }
      else if(Wep > 12){
        pretty = "Average";
      }
      else if(Wep > 7){
        pretty = "Poor";
      }
      else{
        pretty = "Junk";
      }
    } 
    if(Arm){
      if(Arm > 2){
        pretty = "God Like";
      }
      else if(Arm > 1){
        pretty = "Great";
      }
      else{
        pretty = "Average";
    }
    if(Atype == "armor"){
      if(Arm > 5){
        pretty = "God Like";
      }
      else if(Arm > 4){
        pretty = "Superior";
      }
      else if(Arm > 3){
        pretty = "Great";
      }
      else if(Arm > 2){
        pretty = "Average";
      }
      else if(Arm > 1){
        pretty = "Poor";
      }
      else{
        pretty = "Junk";
      }
    }
  }
    if(WeighIt > 6){
      itsweight = "a Lead weight";
    }
    else if(WeighIt > 4){
      itsweight = "Very Heavy";
    }
    else if(WeighIt > 2){
      itsweight = "Heavy";
    }
    else if(WeighIt > 1){
      itsweight = "of Average Weight";
    }
    else{
      itsweight = "Very Light";
    }

    write("You quickly study the "+BOLD+GRN+capitalize(str)+NORM+" with your Saiyan abilities and realize...\n"+
      "The "+BOLD+GRN+str+NORM+" appears to be of "+BOLD+pretty+" quality"+NORM+", and is "+BOLD+itsweight+NORM+".\n");
    if(nerf->query_hit_func()){
        write("It seems to possess some Other power. Although you cannot tell what.\n");
      }
  if(nerf->query_type()){
  write("It seems to be of '"+BOLD+nerf->query_type()+NORM+"' type.\n");
  }
  if(nerf->query_save_flag()){
    write("The "+BOLD+GRN+capitalize(str)+NORM+" is not saveable.\n");
  }
  else{
    write("The "+BOLD+GRN+capitalize(str)+NORM+" is saveable.\n");
  }
  return 1;
}
