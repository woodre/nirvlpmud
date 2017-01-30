
string LONG,SHORT,READ,ID;

id(str){
  if(ID && SHORT && LONG)
    return str==ID || str==SHORT || str==LONG;
  return str=="sign";
}

get(){ return 0; }

long(){
  if(!LONG){
    write("A large sign. (Try reading it)\n");
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
  add_action("read_sign","read");
}

read_sign(){
  if(!READ){
    write("There have been problems with the Shadow Blade and so I asked\n"+
          "Sassman to try it fix it.  Well, as it turns out, the blade is now\n"+
          "totally dead and until I get around to fixing the NEW errors (as\n"+
          "well as the old ones) Mr. Shadow Blade is taken out of the game.\n"+
          "\n\nI'm terribly sorry for the problems, but...\n\n\nGrimm\n");
    return 1;
  }
  write(READ);
  return 1;
}

set_long(s){ LONG = s; }
set_short(s){ SHORT = s; }
set_read(s){ READ = s;}
set_id(s){ ID = s; }
