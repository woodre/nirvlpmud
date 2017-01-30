id(str) { return str=="timer"; }
short() { return 0; }
long() { return 0; }
int x;
reset(arg) {
        if(!arg) x=0;
}
init() {
        call_out("leave",1);
}
leave() {
        object user;
        user=environment(this_object());
  if(x > 59 && user) {
        move_object(user,"room/church");
   command("look",user);
        tell_object(user, "You have been released from jail.  You are escorted to the church.\n");
        tell_object(user,"\n\n");
        destruct(this_object());
return 1;
        }
        x=x+1;
  if(user)
        call_out("leave",1);
return 1;
}        
 
get() { return 1; }
drop() { return 1; }

