inherit "obj/treasure";
int charges, last_use;
reset(arg) {
if(arg) return;
charges = 1 + random(6);
last_use = 0;
}
id(str) { return str == "wand"; }
init() {
::init();
if (environment() == this_player()) add_action("use","use");
}
short() { return "Wand of Icestorm ["+charges+"]"; }
long() {
write ("A long piece of enchanted amber. You can feel the magical\n"
+ "energies swirling around it. Type 'use wand [on <target>]' to\n"
+ "use this powerful item.\n");
}
use(str) {
string target, what;
object ob;

if (!str) return 0;
if (sscanf(str,"%s on %s",what,target) != 2) what = str;
if (what != "wand") return 0;
if (!target) ob = this_player()->query_attack();
else
ob = present(target,environment(this_player()));
if (!ob || !living(ob)) {
write ("At whom?\n");
return 1;
}
if (time() < (last_use + 3)) {
write ("The wand is still recharging.\n");
return 1;
}
this_player()->attack_object(ob);
write ("You conjure up an ice storm and it engulfs "+ob->query_name()+"!\n");
say(this_player()->query_name()+" conjures up an ice storm.\n");
ob->hit_player(random(10));
last_use = time();
charges --;
if (charges < 1) {
write ("The wand crumbles to dust.\n");
destruct(this_object());
}
return 1;
}
query_save_flag() { return 1; }
