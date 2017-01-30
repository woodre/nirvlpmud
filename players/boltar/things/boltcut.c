int verif;
short() { return "Bolt cutters"; }
long() { 
  write("A strong pair of bolt cutters, they could cut even magical things.\n");
     write("You can use them on chains, cables, etc\n");
  return 1;
}
init() {
add_action("use","use");
}
id(str) {
return str=="bolt cutters" || str == "cutters";
}
use(str) {
string arg,what;
object inv1,inv2;
if(!str) return 0;
if(sscanf(str,"%s on %s",arg,what)!= 2) return 0;
   if(!id(arg)) return 0;
   if(environment() !=this_player()) {
     write("You must get it first!\n");
     return 1;
   }
inv1=present(what,this_player());
inv2=present(what,environment(this_player()));
if(!inv1 && !inv2) {
write("There is no "+what+" here.\n");
return 1;
}
if(!inv1->id("fertility") || inv2) {
write("The bolt cutters are too dull cut that.\n");
return 1;
}
if(inv1->id("fertility")) {
if(inv1->id("amulet")) {
  write("The bolt cutters break the chain of the amulet.\n");
  write("The figurine glows brightly and vanishes.\n");
  say(this_player()->query_name()+" cuts an amulet off with bolt cutters, then both glow and vanish.\n");
} if(inv1->id("ring")) {
    write("The bolt cutters cut through the ring.\n");
    write("The ring glows brightly and vanishes.\n");
     say(this_player()->query_name()+" cuts a ring off with bolt cutters, then both glow and vanish.\n"); 
}
  destruct(inv1);
  log_file("b_amulet",verif+" boltcut amulet "+this_player()->query_real_name()+"\n");
  write("The bolt cutters glow brightly and vanish.\n");
  destruct(this_object());
  return 1;
}
return 1;
}
get() { return 1; }
query_value() { return 2; }
set_verif(arg) { verif=arg;}
set_misses(arg) { verif=arg;}
query_misses(arg) { return verif;}
reset() {
if(this_player()) 
if(this_player()->query_level()>20) {
log_file("b_amulet",this_player()->query_name()+" cloned cutters.\n");
}
}
