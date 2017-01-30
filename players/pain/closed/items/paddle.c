inherit "obj/treasure";
object ob;
string obn, obg;

reset(arg) {
   if(arg) return;
set_short("Pain's 'Fuh Q' Paddle");
set_alias("paddle");
   set_id("paddle");
set_long("Pain's BIG ASS 'Fuh Q' Paddle\n");
   set_weight(0);
   set_value(0);
}
drop() { return 1; }
init() {
   add_action("paddle","paddle");
   add_action("whack","whack");
   add_action("pdl","pdl");
}
paddle(str) {
ob = present(str, environment(this_player()));
obn = ob->query_name();
obg = ob->query_gender();
 if(!str){
write("You take your paddle out and eye those in the room.\n");
say("Pain takes his BIG ASS paddle out and eyes those in the room.\n");
return 1;
}
if(!ob){write("OOOOPs... they aren't here\n"); return 1;}
if(obg == "male"){
say("Pain grabs "+obn+" and forces him to grab his ankles.\n");
tell_object(ob,"You grab your ankles and brace yourself for what you know is next.\n");
say("Pain raises his paddle and prepares to thouroughly paddle "+obn+".\n");
call_out("whack",10);
call_out("whack",10);
call_out("whack",10);
call_out("whack",10);
call_out("pdl",20);
say("Pain puts his paddle away with a gleem in his eye!\n");
tell_object(ob, "You stifle a tear and hold your butt in pain.\n");
write(obn+" holds his ass in extreme pain.\n");
return 1;
}
say("Pain grabs his paddle and looks "+obn+" over playfully.\n");
tell_object(ob, "You feel a tingle run through you as Pain eyes you.\n");
say("Pain playfully paddles "+obn+"'s cute little ass.\n");
tell_object(ob, "You giggle in delight as Pain paddles you.\n");
say("Pain puts his paddle away and invites "+obn+" up to his workroom.\n");
return 1;
}
whack(){
write("You cringe as Pain brings his paddle back and whacks the shit outta "+obn+"!\n");
return 1;
}
pdl(){
say("Pain pulls his paddle back and winds up for one final whack!\n");
say("Pain slams his paddle into "+obn+"'s ass with all his might.\n");
say(obn+" falls over from the impact and grab's his ass.\n");
return 1;
}

