#include "../../defs.h"
string chair1,chair2;

id(str){ return str == "chairs" || str == "chair"; }
short(){ return "A pair of leather high-back chairs"; }
long(str){
  write("They are a pair of high-back red leather chairs.  Worn\n"+
        "slightly by use, the cracks in the leather bring a certain\n"+
        "air of quality.  ");
  if(chair1){
    write("One of the chairs is occupied by "+capitalize(chair1));
    if(chair2){
     write(",\nwhile the other is occupied by "+capitalize(chair2)+".\n");
    } else {
     write(".\n");
    }
    return 1;
  }
  if(chair2){
    write("One of the chairs is occupied by "+capitalize(chair2)+",\nwhile "+
          "the other is left empty.\n");
    return 1;
  }
  write("\n");
  return 1;
}
    
init(){
  add_action("sit","sit");
  add_action("stand","stand");
}

sit(str){
  if(tprn == chair1 || tprn == chair2){
    write("You are already sitting.\n");
    return 1;
  }
  if(chair1 && chair2){
    write("You pull up a seat next to the two high-back chairs.\n");
    say(tpn+" sits down on the floor.\n");
    return 1;
  }
  if(chair1 && !chair2){
    write("You sit down in one of the comfy leather high-back chairs.\n");
    say(tpn+" sits down in one of the comfy leather chairs.\n");
    this_player()->set_al_title(tp->query_al_title()+") (sitting");
    chair2 = this_player()->query_real_name();
    return 1;
  }
  write("You sit down in one of the comfy leather high-back chairs.\n");
  say(tpn+" sits down in one of the comfy leather chairs.\n");
  this_player()->set_al_title(tp->query_al_title()+") (sitting");
  chair1 = this_player()->query_real_name();
  return 1;
}

stand(){
string rname;
string al;
string front,back;
int i;
   rname = tprn;
   if(rname == chair1){
     al = this_player()->query_al_title();
     sscanf(al,"%s) (sitting%s",front,back);
     if(!back) back = "";
     al = front+back;
     this_player()->set_al_title(al);
     write("You stand up out of the comfy chair.\n");
     say(tpn+" stand up out of the comfy chair.\n");
     chair1 = 0;
     return 1;
   }
   if(rname == chair2){
     al = this_player()->query_al_title();
     sscanf(al,"%s) (sitting%s",front,back);
     if(!back) back = "";
     al = front+back;
     this_player()->set_al_title(al);
     write("You stand up out of the comfy chair.\n");
     say(tpn+" stands up out of the comfy chair.\n");
     chair2 = 0;
     return 1;
   } 
   write("You stand up.\n");
   say(tpn+" stands up.\n");
   return 1;
}

query_chair1(){ return chair1; }
query_chair2(){ return chair2; }
