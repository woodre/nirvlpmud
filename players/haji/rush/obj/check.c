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
      if(this_object()) {
       object this,that;
       int x1,y1,z1;
             move_object(this_object(),environment(this_player()));
       this=present("check",this_player());
       if(!this) {
         move_object(this_object(),this_player());
         return 1;
      }
         x1=query_val();
        y1=call_other(this,"query_val",0);
        z1=x1+y1;
        set_val(z1);
        destruct(this);
        move_object(this_object(),this_player());
        return 1;
        } else {
return 1;
 }
}
init() {
}
reset(arg){
    if (arg)
       return;
    val = 1;
}
