int val;
query_val() { return val;}
query_save_flag() {return 1;}
set_val(x) {
   val = x;
   }
id(str) {
    if (str == "check" ) return 1;
    return 0;
   }
short() {
   return "A welfare check";
  }
long() {
   write("A welfare check for ");
   write(val);
    write(" dollars funded by taxpayer money.\n");
   write("To cash this check, you need to go to the welfare offices,\n");
   write("located in New York,Washington D.C., Texas, and the Naval base.\n");
}
query_weight() {
return 1;
}
get() {
return 1;
}
init() {
object this,that;
int y1,x1,z1;
     this=first_inventory(environment(this_object()));
    write(this);
       write("\n");
      while(this=this_object()) {
    this=next_inventory(environment(this_object()));
    write(this);
    write("\n");
    write(this_object());
   }
      if(this!=0) {
      y1=call_other(this,"query_val",0);
      z1=query_val();
      x1=z1+y1;
      set_val(x1);
     move_object(this,"room/south/sshore10");
}
}
reset(arg){
    if (arg)
       return;
    val = 1;
}
