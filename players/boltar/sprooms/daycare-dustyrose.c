
short() {return "Dustyrose's Nursery"; }
id(str) {
    return str=="window" || str == "unbreakable window" || str=="box" ||
           str=="command box" || str == "instructions";
}
long(str) {
   if(str=="box" || str=="command box" || str == "instructions") 
     write("The stylish modern looking command box has a variety of \n"+
     "options on it. The instructions list the following:\n"+
     "leave <childname>		Leave your child in the daycare center\n"+
     "pickup <childname>      	Pickup your child from the daycare center\n"+
     "other <kidname> <parent> 	Set the name of the second parent\n"+
     "list                      Lists your kids\n"+
     "check                     Check on your kids.\n"+
     "buy             		Purchase fortified munchies for the child\n"+
     "         			Only 50 coins a bag!\n");
   if(str=="window" || str == "unbreakable window") 
     write("Through the window you see the children at play and the staff\n"+
     "caring for them well.\n");
   if(str) return 0;
   write("Dustyrose's daycare #1. This room acts as an interface to\n"+
         "her children in the main dc system. There are exits to the\n"+
         "north and south. There is small command box with instructions.\n");
  return 1;
 }
init() {
  add_action("pickup","pickup");
  add_action("list_kids","list");
  add_action("check_on","check");
  add_action("set_parent_too", "other");
  add_action("leave","leave");
  add_action("south","south");
  add_action("north","north");
  add_action("buy_munchies","buy");
}

reset(arg) {
  if(arg) return;
  set_light(1);
}

pickup(str) {
 int flag,x;
 string nom;
 nom = this_player()->query_real_name();
 flag = call_other("players/boltar/sprooms/daycare","checkiflisted",nom+" "+str);
 if (flag == 99) {
   call_other("players/boltar/sprooms/daycare","pickup",str);
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare2","checkiflisted",nom+" "+str);
 if (flag == 99) { 
   call_other("players/boltar/sprooms/daycare2","pickup",str);
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare3","checkiflisted",nom+" "+str);
 if (flag == 99) {
   call_other("players/boltar/sprooms/daycare3","pickup",str);
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare4","checkiflisted",nom+" "+str);
 if (flag == 99) { 
   call_other("players/boltar/sprooms/daycare4","pickup",str);
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare5","checkiflisted",nom+" "+str);
 if (flag == 99) {
   call_other("players/boltar/sprooms/daycare5","pickup",str);
   x = 2;
 }
 if(!x) write("Cannot find your child.\n");
 return 1;
}


leave(str) {
 int flag,x;
 string nom;
 object kidob;
 nom = this_player()->query_real_name();
 if(str=="baby") { write("You must name your child.\n"); return 1; }
 if(!str) {
   write("Who do you wish to leave here?\n");
   return 1;
 }
 kidob=present(str,this_object());
 if(!kidob) { write("Cannot find any children named "+str+"\n"); return 1; }
 if(kidob->is_player()) kidob=present(str);
 if(!kidob) return 0;
 if(!present(kidob)) {
   write("please place your child in the room.\n");
   return 1;
 }
 if(!kidob->is_kid()) {
   write("We don't take that kind here.\n");
   return 1;
 }
 flag = call_other("players/boltar/sprooms/daycare","checkiflisted",nom+" "+str);
 if (flag == 99) {
    move_object(kidob,"players/boltar/sprooms/daycare");
    call_other("players/boltar/sprooms/daycare","leave",str);
    x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare2","checkiflisted",nom+" "+str);
 if (flag == 99) {
   move_object(kidob,"players/boltar/sprooms/daycare2");
   call_other("players/boltar/sprooms/daycare2","leave",str); 
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare3","checkiflisted",nom+" "+str);
 if (flag == 99) {
    move_object(kidob,"players/boltar/sprooms/daycare3");
    call_other("players/boltar/sprooms/daycare3","leave",str); 
    x =2;
 }
 flag = call_other("players/boltar/sprooms/daycare4","checkiflisted",nom+" "+str);
 if (flag == 99) {
   move_object(kidob,"players/boltar/sprooms/daycare4");
   call_other("players/boltar/sprooms/daycare4","leave",str); 
   x = 2;
 }
 flag = call_other("players/boltar/sprooms/daycare5","checkiflisted",nom+" "+str);
 if (flag == 99) {
   move_object(kidob,"players/boltar/sprooms/daycare5");
   call_other("players/boltar/sprooms/daycare5","leave",str); 
   x = 2;
 }
 if(!x) {
   write("New children must be left in the regular daycare rooms.\n");
   return 1;
 }
 return 1;
}


south() {
  object room;
  string roomf;
  room = call_other("players/boltar/hotel/hotel","query_box",this_player()->query_real_name());
  roomf = file_name(room);
  call_other(this_player(),"move_player","south#"+roomf);
  return 1;
}

north() {
    call_other(this_player(), "move_player", "north#players/boltar/sprooms/daycare-dustyrose2");
    return 1;
  }
set_parent_too(str){
 write("This must be set in the regular daycare rooms.\n");
 return 1;
}


list_kids(){
 string arg,arg2;
 arg2 = this_player()->query_real_name();
 arg = "500 "+arg2;
 call_other("/players/boltar/sprooms/daycare","list_kids",arg);
 call_other("/players/boltar/sprooms/daycare2","list_kids",arg);
 call_other("/players/boltar/sprooms/daycare3","list_kids",arg);
 call_other("/players/boltar/sprooms/daycare4","list_kids",arg);
 call_other("/players/boltar/sprooms/daycare5","list_kids",arg);
 write("TOTAL: "+call_other("/players/boltar/sprooms/daycare","count_total_kids",arg2)+"\n");
 return 1;
}

check_on() {
 call_other("/players/boltar/sprooms/daycare","check_on");
 call_other("/players/boltar/sprooms/daycare2","check_on");
 call_other("/players/boltar/sprooms/daycare3","check_on");
 call_other("/players/boltar/sprooms/daycare4","check_on");
 call_other("/players/boltar/sprooms/daycare5","check_on");
 return 1;
}


buy_munchies(str) {
  if(this_player()->query_money() < 50) {
  write("You do not have enough money.\n");
  return 1;
  }
   if(!this_player()->add_weight(1)) {
     write("You can't carry any more.\n");
     return 1;
     }
   write("You buy some munchies.\n");
  move_object(clone_object("players/boltar/things/munchies.c"),this_player());
  this_player()->add_money(-50);
  return 1;
}
