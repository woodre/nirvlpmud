int position; 
/* 
0 = standing
1 = kneeling
2 = sitting
3 = meditating
4 = flying
*/

clericEnsoul(){
  object obj;
  obj =  clone_object("/players/wocket/clerics/cleric_soul.c");
  move_object(obj,this_player());
  destruct(this_object());
  return 1;
}

positionCheck(){
string msg;
  switch(position){
    case 0: return 0; break;
    case 1: msg = "kneeling"; break;
    case 2: msg = "sitting"; break;
    case 3: msg = "meditating"; break;
    case 4: return 0; break;
    default: return 0;
  }	
  write("You can not do that while you are "+msg+".\n");
  return 1;

}

query_standing(){ return position == 0; }
query_kneeling(){ return position == 1; }
query_sitting(){ return position == 2; }
query_meditating(){ return position == 3; }
query_flying(){ return position == 4; }
query_position(){ return position; }

startSitting(){
  if(position == 2){
    notify_fail("You are already sitting.\n");
    return 0;
  }
  write("You sit down.\n");
  say(this_player()->query_name()+" sits down.\n");
  position = 2;
  return 1;
}

startStanding(){
  if(position == 0){
    notify_fail("You are already standing.\n");
    return 0;
  }
  write("You stand up.\n");
  say(this_player()->query_name()+" stands up.\n");
  position = 0;
  return 1;
}

startKneeling(){
  if(position == 1){
    notify_fail("You are already kneeling.\n");
    return 0;
  }
  write("You start kneeling.\n");
  say(this_player()->query_name()+" starts kneeling.\n");
  position = 1;
  return 1;
}