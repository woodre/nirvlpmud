id(str) {return str == "hallucinations";}
init() {
call_out("hallucinate",10,this_player());
}
hallucinate(ob) {
int i;
i = random(4);
if(i == 0) tell_object(ob,"You see all different colors before your eyes.\n");
else if(i == 1) tell_object(ob,"You feel as if you are floating.\n");

else if(i == 2) tell_object(ob,"Everything you look at seems to have a colorful trail behind it.\n");
else if(i == 3) tell_object(ob,"It appears that heads are poping out of the walls and talking to you.\n");
ob->remove_say(ob->query_name() + "looks a little dazed.\n");
call_out("wait",110,ob);
}
wait(ob) {
if(random(100) < 10) {
tell_object(ob,"Suddenly, everything becomes clear again.\n");
destruct(this_object());
return; }
call_out("hallucinate",1,ob);
}
get() {return 1;}
drop() {return 1;}
