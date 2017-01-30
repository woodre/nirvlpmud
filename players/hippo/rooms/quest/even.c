int y,z,x;
int a;
int *b;
reset(arg){
y = 7, z = 10;
b=allocate(y);
for(x=0;x<y;x++)
{  a=random(z);
   b[x]=a;
}
}
init(){
add_action("show","show"); }
show(){
for(x=0;x<y;x++)
{  write("nr: "+b[x]+".\n");
}
   return 1;
}
