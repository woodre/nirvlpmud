int wait;
id(str){  return str == "patron"; }

init(){
  add_action("listen","listen");
  set_heart_beat(1);
}

heart_beat(){
  wait--;
  if(wait == 0){ do_chat(); wait = 30; }
}

do_chat(){
string person,msg;
switch(random(3)){
case 0:  person = "man"; break;
case 1:  person = "woman"; break;
case 2: person = "patron"; break;
}
switch(random(3)){
case 0: msg = "Something strange is happening in the Euka forest."; break;
case 1: msg = "Those poor lemars.  That is such an evil wizard."; break;
case 2:  msg = "Somebody should go help them."; break;
}
tell_room(environment(this_object()),"You hear a "+person+" in the back say, \""+msg+"\"\n");
}

listen(){
  do_chat();
  wait = 0;
return 1;
}
