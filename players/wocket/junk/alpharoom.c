/* room code alternative */
/*

10 by 10 room

*/
#include "/players/wocket/closed/ansi.h"

string *objnames;
string msghistory;
int *xpos,*ypos;
int rows,cols;

reset(arg){
  if(arg) return;
  rows = 10;
  cols = 40;
  objnames = xpos = ypos = ({});
  set_light(1);
  objnames = ({ "blank","wall","wall","wall","tree","portal" });
  xpos = ({ 0,3,3,3,5,2, });
  ypos = ({ 0,2,3,4,7,3, });
}

long(){
int i,j,k;
int index;
string msg;
  msg="\n+----------+\n";
  for(i=0;i<rows;i++){
    msg+="|";
    for(j=0;j<cols;j++){
      if(collision(j,i)){  
       k = collision(j,i);
       switch(objnames[k]){
        case "wall":   msg+="X";                       break;
        case "portal": msg+= HIB+"O"+OFF;              break;
        case "tree":   msg+= BGRN+YEL+"Y"+OFF;         break;
        default: msg+="*";
       }
      }
      else{
        msg+=" ";
      }
    }
    msg+="|\n";
  }
  msg+="+----------+\n";
  write(msg);
}

init(){
object ob;
  ob = this_player();
  objnames += ob->query_real_name();
  xpos += 0;
  ypos += 0;
  add_action("movement","n");
  add_action("movement","e");
  add_action("movement","w");
  add_action("movement","s");
}

movement(){
string verb;
int i,testx,testy;
  verb = query_verb();
  i = get_player_index(this_player());
  testx = xpos[i];
  testy = ypos[i];
  switch(verb){
  case "n":  testy--;          break;
  case "ne": testy--; testx++; break;
  case "e":           testx++; break;
  case "s":  testy++;          break;
  case "w":           testx--; break;
  }
  if(collision(testx,testy)){
    write("You fail.\n");
    return 1;
  }
  write("You move "+verb+".\n");
  xpos[i]=testx; ypos[i]=testy;
  say(this_player()->query_name()+" moved "+verb+".\n");
  return 1;
}

collision(x,y){
int i,a,failed;
  if(x == cols || x < 0 || y < 0 || y == rows){
    return 1;
  }
  failed = i = 0;
  while( i < sizeof(objnames) && !failed){
    if(xpos[i] == x && ypos[i] == y){
      failed = i;
    }
  i++;
  }
  return failed;
}

get_player_index(ob){
string str;
  str = ob->query_real_name();
  if(str)
    return get_index(str);
}
  
get_index(str){
int i;
  i = member_array(str,objnames);
  return i;
}
  
get_x(i){
  return xpos[i];
}

get_y(i){
  return ypos[i];
}