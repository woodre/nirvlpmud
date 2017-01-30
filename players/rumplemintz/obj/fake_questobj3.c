inherit "obj/treasure";
reset(arg){
  if(arg){
    return ;
  }
  set_value(1);
}
id(str) { return str == "bane" ||
                str == "lords bane" ||
                str == "lordsbane"; }
short() { return "Lords bane";}
long() { write("This is the ever powerful Lordsbane.\n"+
        "However, it looks as though the Dwarven Lord made it useless.\n");
}
get(){return 1;}
drop(){return 1;}
