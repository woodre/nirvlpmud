int healval;
id(str) { return str == "steak"; }
init() {
add_action("eat","eat");
}
short() { return "A juicy steak"; }
long() { 
write("The steak looks a little on the rare side and a little processed,\n"+
"but it does look delicious.\n");
}
eat(str) {
if (!id(str)) return 0;
write("You gobble down the steak.\n");
say(this_player()->query_name()+" scarfs down a steak.\n");
if(!healval) healval = 1+random(2);
this_player()->heal_self(healval);
destruct(this_object());
return 1;
}
get() { return 1; }
drop() { return 0; }
/* The following function was added because players are abusing the steaks. */
/* Too many players are walking around with about 50 or more steaks on them.*/
/* Added by:  Omega (level 300)     Function query_weight()                 */
query_weight() { return 1; }
set_healval(arg){healval=arg;}
