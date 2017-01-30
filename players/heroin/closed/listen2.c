drop(){return 1;}
get(){return 1;}
long(){write("It works");return 1;}
query_value(){return 0;}
id(str){return 1;}
init(){
add_action("dest_me","999");
}
dest_me(){
destruct(this_object());
return 1;}
