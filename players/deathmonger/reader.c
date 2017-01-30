
id(str){ return str == "reader"; }
short(){ return "reader"; }
long() { write("Type 'more' to read my concept.\n"); }
get(){ return 1; }
init(){
add_action("more","more");
}
more(str){
call_other("/closed/wiz_soul","more", str);
     return 1;
}
