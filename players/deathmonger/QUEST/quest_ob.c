
id(str){ return str == "flipperty"; }

object me;

init(){
me = environment(this_object());
}
query_dude(){ return me; }

drop() { return 1;}
