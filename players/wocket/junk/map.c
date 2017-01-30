id(str){ return str == "map"; }

mixed *map;

reset(){
map = allocate(2);
map[0] = ({1,1,0,1,});
map[1] = ({ 0,0,1,1, });
}

init(){
 add_action("writemap","writemap");
  add_action("testroom","testroom");
}

writemap(){
int j,b;
  for(j=0,b=2;j<b;j++){
int i,a;
  for(i=0,a=4;i<a;i++){
    write(map[j][i]); 
  }
  write("\n");
  }

return 1;
}

testroom(str){
int a,b;
sscanf(str,"%d %d",a,b);
if(map[a][b] == 1){ write("room"); }
else
write("nope\n");
return 1;
}
