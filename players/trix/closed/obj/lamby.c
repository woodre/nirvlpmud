query_auto_load()
{ return "/players/trix/closed/obj/lamby.c:"; }

reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="lamby") return 1;
        return 0;
}

long() {
        write( "A lamby you can suck on. Why is it called a lamby?\n"+
               "Cause it makes you look like the guy in SILENCE OF THE LAMBS!\n");
}

short()
  { return "a lamby"; }
init()
{
  add_action( "suck","suck");
  add_action( "do_emote",";");
}
suck(arg)
{  if(arg!="lamby") return;
   write("You suck on the lamby.\n");
   say("Baby puts the sucker in his mouth. He looks like the guy from Silence of the Lambs.\n");
   return 1;
}

do_emote( str ) {
        if(!str) { write("Emote what?!?\n"); return 1;}
        write("You emote: "+call_other(this_player(),"query_name")+" "+str+"\n" );
        say(call_other(this_player(),"query_name")+" "+str+"\n" );
        return 1;
}
get() {
        return 1;
}
drop() {
        return 1;
}
