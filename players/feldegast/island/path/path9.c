reset(arg) {
if(arg) return;
start();
}
start() {
object *u;
object x,y;
int i;
u=users();
for(i=0; i < sizeof(u); i++) {
x=present("vertefakirdicta",u[i]);
if(x && (x->is_bugged())==0) {
y=clone_object("/players/feldegast/island/path/path8.c");
if(y) y->start(x);
}
}
call_out("start",240);}
