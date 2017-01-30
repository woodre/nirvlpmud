inherit "obj/treasure";
reset(arg){
  if(arg){
    return ;
  }
  set_value(1);
}
id(str) { return str == "ring" ||
                str == "dwarf ring" ||
                str == "dwarfring"; }
short() { return "Dwarf ring";}
long() { write("This is the Dwarf ring.\n"+
        "It looks as though it is very important, however, it's not armor.\n");
}
get(){return 1;}
drop(){return 1;}
