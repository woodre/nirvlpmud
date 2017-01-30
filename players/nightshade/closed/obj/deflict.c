object target;
startup(arg) {
target = arg;
shadow(arg,1);
}

hit_player(arg) {
int x;
x=arg*3/2;
target->hit_player(arg);
if (this_object()) 
destruct(this_object());
return x;
}
