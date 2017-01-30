inherit "obj/treasure";
object ob;
reset(arg) {
   if(arg) return;
set_short("Pain's Whapper");
set_alias("whapper");
   set_id("whapper");
set_long("Pain's Whapper made by Hawkeye, M.P\n");
   set_weight(0);
   set_value(0);
}
drop() { return 1; }
query_auto_load(){return "players/hawkeye/items/whap.c";}
init() {
   add_action("whap","whap");
    add_action("qit","qit");
}
whap(str) {
ob = present(str, environment(this_player()));
 if(!str){write("Who are you bamming Ted?\n");return 1;}
say("Pain takes out his whapper and WHAP'S "+str+"\n");
say("Whap Whap.........The WHAPPER(fear it).\n");
write("You whip out your HUGE whapper and WHAP "+str+"\n");
command("bow pain",ob);
command("worship pain",ob);
command("applaud",ob);
return 1;
}
qit(str) {
ob = present(str, environment(this_player()));
if(!ob){write("Its qit Calandryll Ted, shitboy!\n");return 1;}
if(ob) {
call_other(ob,"quit",0);
write("\n\n"+str+" has quit.\n");
return 1;
}
return 1;
}
