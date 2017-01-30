 string LONG,SHORT,READ,ID;
 
id(str){
  if(ID && SHORT && LONG)
    return str==ID || str==SHORT || str==LONG;
  return str=="sign";
}
 
get(){ return 0; }
 
long(){
  if(!LONG){

    write("A SEXY sign.  (Try and read it!)\n");
    return 1;
  }
  write(LONG);
  return 1;
}
 
short(){
  if(!SHORT)
     return "A large sign";
  return SHORT;
}
 
reset(){}
 
init(){
  add_action("read_sign", "read");
}
 
read_sign(){
  if(!READ){write("Looking for SEX?  GO THAT WAY ----> EAST \n");
    return 1;
  }
  write(READ);
  return 1;
}
 
set_long(s){ LONG = s; }
set_short(s){ SHORT = s; }
set_read(s){ READ = s;}
set_id(s){ ID = s; }


