id(str) { return str == "speaker" || str == "loudspeaker"; }

short() {
  return "A Loudspeaker";
  }

long() {
  write("If you see this loudspeaker you are wrong.\n");
  }

init() {
  call_out("rand_mes",10);
}

rand_mes() {
  object tp;
  string rm1,rm2,rm3,rm4,rm5,rm6;
  int num;
  string msg;
  tp=this_player();
  rm1="players/pathfinder/detroit/rooms/hood1";
  rm2="players/pathfinder/detroit/rooms/hood2";
  rm3="players/pathfinder/detroit/rooms/hood3";
  rm4="players/pathfinder/detroit/rooms/hood4";
  rm5="players/pathfinder/detroit/rooms/hood5";
  rm6="players/pathfinder/detroit/rooms/hood4";
  num=(random(3)+1);
  if(num==1) {
    msg="You are scared shitless by the little old lady who almost ran\nover you with her car.\n";
  }
  if(num==2) {
    msg="You leave hershey squirts in your underwear as you hear\nbullets fly by your head.\n";
  }
  if(num==3) {
    msg="You can hear the sound of a police car's siren rapidly approaching.\nYou finally see it headed straight for you in pursuit of someone.\n";
  }
  tell_room(rm1,msg);
  tell_room(rm2,msg);
  tell_room(rm3,msg);
  tell_room(rm4,msg);
  tell_room(rm5,msg);
  tell_room(rm6,msg);
  call_out("rand_mes",10);
}
