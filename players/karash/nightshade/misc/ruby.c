inherit "obj/treasure";
int charges, last_use;
reset(arg) {
if(arg) return;
charges = 10 + random(6);
last_use = 0;
}
id(str) { return str == "gem"; }
init() {
::init();
if (environment() == this_player()) add_action("use","use");
}
short() { return "Red Ruby"; }
long() {
write("A blood red ruby that seems to pulsate with life. Evil life.\n"+
"Small fireballs swirl around inside the gem as if waiting to get\n"+
"out.\n");
}
use(str) {
string target, what;
object ob;

if (!str) return 0;
if (sscanf(str,"%s on %s",what,target) != 2) what = str;
if (what != "ruby") return 0;
if (!target) ob = this_player()->query_attack();
else
ob = present(target,environment(this_player()));
if (!ob || !living(ob)) {
write ("At whom?\n");
return 1;
}
if (time() < (last_use + 3)) {
write ("The gem is low on power at the moment.\n");
return 1;
}
this_player()->attack_object(ob);
write("You summon the power of the ruby to your aid and a fireball rushes toward "+ob->query_name()+"!\n");
say(this_player()->query_name()+" glows with the power of the ruby and hurls a fireball towards you!\n");
ob->hit_player(10);
last_use = time();
charges --;
if (charges < 1) {
write ("The ruby slowly fades from existence with the loss of its evil energy.\n");
destruct(this_object());
}
return 1;
}
