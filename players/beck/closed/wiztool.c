string preload;
#include "/players/beck/esc.h"
preload(arg){ preload = arg; return 1; }
id(str){
return str == "wiztool";
}
init(){
add_action("star2","star2");
add_action("preload","preload");
}
star2(arg){
object list;
int i;
list = users();
for(i=0; i<sizeof(list); i++){
if(present("star_tattoo", list[i])){
tell_object(list[i], BROWN+"~*~ "+OFF+preload+BROWN+"~*~: "+OFF+arg+"\n");
}
}
return 1;
}
