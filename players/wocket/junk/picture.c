#include "/players/wocket/closed/ansi.h"
int line;
int space;


id(str){ return str == "picture"; }

reset(){
space = 1;
}
init(){
    add_action("move_left","left");
    add_action("move_right","right");
    add_action("move_up","up");
    add_action("move_down","down");
#ifndef __LDMUD__
  add_action("catch_all"); add_xverb("");
#else
  add_action("catch_all", "", 3);
#endif
}

catch_all(){
  call_out("drawpic",0,this_player());
  return 0;
}

move_up(){
    line--;
if(line < 1)
    line = line + 10;
    return 1;
}

move_down(){
    line++;
if(line > 10)
    line = line - 10;
    return 1;
}

move_left(){
    space+=1;
if(space > 10)
    space = space - 10;
  return 1;
}

move_right(){
    space-= 1;
if(space < 0)
    space = space + 10;
  return 1;
}

drawpic(player){
int x;
int i;
int temp_line, temp_space;
if(!player) player = this_player();
tell_object(player,HOME);
tell_object(player,"+\n");
temp_line = temp_space = 0;
for(x = 0;x < 10;x++){
  for(i = 0;i<10;i++){
    if((temp_line == line) && (temp_space == space)){
     tell_object(player,HIR+"I"+OFF);
    }
    else
     tell_object(player," ");
    temp_space++;
  }
  tell_object(player,"\n"+EAOL);
  temp_line++;
  temp_space = 0;
}
tell_object(player,"map drawn\n"+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+DS+EAOL);
}
