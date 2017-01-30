id(str){ return str == "nopoke"; }

init(){
  add_action("nopoke","poke");
}

nopoke(str){
  if(str == "wocket"){
    write("You may not poke wocket at this time.\n");
  return 1;
}
return 0;
}
