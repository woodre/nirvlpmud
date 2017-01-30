inherit "obj/treasure";
reset(arg){
  if(arg){
    return ;
  }
  set_value(1);
}
id(str) { return str == "hilt" ||
                str == "sword hilt" ||
                str == "swordhilt"; }
short() { return "A Sword hilt";}
long() { write("This is the hilt of a sword.\n"+
       "It looks as though it was a rather large and powerful sword.\n");
}
get(){return 1;}
drop(){return 1;}
