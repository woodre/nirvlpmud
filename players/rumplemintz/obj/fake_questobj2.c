inherit "obj/treasure";
reset(arg){
  if(arg){
    return ;
  }
  set_value(1);
}
id(str) { return str == "orb" ||
                str == "dragon orb" ||
                str == "dragonorb"; }
short() { return "A Dragon orb";}
long() { write("This is an orb of Dragonkind.\n"+
       "It looks broken, and cannot be used anymore.\n");
}
get(){return 1;}
drop(){return 1;}
