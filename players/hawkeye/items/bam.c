inherit "obj/treasure";
object ob;
reset(arg) {
   if(arg) return;
   set_short("Hair's Bam Stick(bang bang)");
set_alias("stick");
   set_id("stick");
set_long("Hair's Bam stick made by Hawkeye, M.P\n");
   set_weight(0);
   set_value(0);
}
drop(){return 1;}
get(){return 1;}
query_auto_load(){return "players/hawkeye/items/bam.c:";}
init() {
   add_action("bam","bam");
}
bam(str) {
ob = present(str, environment(this_player()));
 if(!str){write("who are you bamming Todd?\n");return 1;}
say("Hair takes out his HUGE bam stick and BAM'S "+str+"\n");
write("You whip out your HUGE bam stick and BAM "+str+"\n");
command("applaud",ob);
command("worship hair",ob);
return 1;
}
