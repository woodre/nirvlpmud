#include "/players/fred/ansi.h"
inherit "/obj/treasure";

reset (arg){
  set_id("book");
  set_short("The great "+BOLD+"Book"+NORM+" of "+BOLD+"Knowledge"+NORM);
  set_long(
     "  A book used throughout the centuries to judge the \n"+
     "vast assortment of weapons and armors in the realm.\n"+
     "One must use the book wisely or it's powers will be wasted.\n"+
     "To understand how the book works use "+BOLD+HIY+"< book_help >"+NORM+".\n");
  set_weight(1);
  set_value(1500);
}

init(){
  ::init();
    add_action("conem","con");
    add_action("bookem","book_help");
  } 

bookem(){
  write("To use the book just "+HIB+"'con <name>'"+NORM+" of a piece of armor"+
        " or weapon in your inventory.\n");
  return 1; }
 
conem(str){
object it;
int Wep;
int Arm;
int WeighIt;
string Atype;
string hownice;
string itsweight;
it = present(str, this_player());
if(!it){
  write("You don't see that here.\n");
  return 1; }
Wep = it->weapon_class();
Arm = it->armor_class();
Atype = it->query_type();
WeighIt = it->query_weight();
if(!Arm && !Wep){
  write("This doesn't seem to be a piece of armor or a weapon.\n");
  return 1; }
if(Wep){
  if(Wep > 21){
    hownice = "GrandMaster";
  }
  else if(Wep > 19){
    hownice = "Superior";
  }
  else if(Wep > 17){
    hownice = "High";
  }
  else if(Wep > 15){
    hownice = "Above Average";
  }
  else if(Wep > 12){
    hownice = "Average";
  }
  else if(Wep > 7){
    hownice = "Below Average";
  }
  else{
    hownice = "Inferior";
  }
}
if(Arm){
  if(Arm > 2){
    hownice = "GrandMaster";
  }
  else if(Arm > 1){
    hownice = "High";
  }
  else{
    hownice = "Average";
  }
if(Atype == "armor"){
  if(Arm > 5){
    hownice = "GrandMaster";
  }
  else if(Arm > 4){
    hownice = "Superior";
  }
  else if(Arm > 3){
    hownice = "High";
  }
  else if(Arm > 2){
    hownice = "Average";
  }
  else if(Arm > 1){
    hownice = "Below Average";
  }
  else{
    hownice = "Inferior";
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

write("You flip through the book to find the "+GRN+capitalize(str)+NORM+" and see that...\n"+
      "It appears to be of "+GRN+hownice+" quality"+NORM+", and is "+GRN+itsweight+NORM+".\n");
if(it->query_hit_func()){
        write("It seems to possess some Other power. Although you cannot\n"+
                  "judge what without using it.\n");
}
if(it->query_type()){
  write("It seems to be of '"+BOLD+it->query_type()+NORM+"' type.\n");
}
if(it->query_save_flag()){
  write("The "+GRN+capitalize(str)+NORM+" is not saveable.\n");
}
else{
  write("The "+GRN+capitalize(str)+NORM+" is saveable.\n");
}
return 1;
}