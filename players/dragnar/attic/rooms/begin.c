short() { return 0; }
long() { return 0; }
id(str) { return 0; }
int s;
reset(arg) {
if(!arg) s=0;
}

init() {
	add_action("begin","begin");
	}
begin() {
   write("The temple is temporarily closed. - Dragnar 6/1/99.\n");
   return 1;
	if(s==1) {
	write("Someone is already in Mortal Kombat.\n");
	return 1;
	}
/* Putting new MK here - Snow 9/98 */
this_player()->move_player("via secret exit#players/beck/MortalKombat/Temple.c");
s=1;
return 1;
}
