reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="emoter") return 1;
        return 0;
}

long() {
        write( "An emoter, type ; <msg> to emote whatever u want.\n");
}

short()
  { return "An emoter"; }
init()
{
  add_action( "do_emote",";");
}


do_emote( str ) {
        if(!str) { write("Emote what?!?\n"); return 1;}
        write("You emote: "+call_other(this_player(),"query_name")+" "+format(str,60)+"\n" );
        say(call_other(this_player(),"query_name")+" "+format(str,70)+"\n" );
        return 1;
}
get() {
        return 1;
}
drop() {
        return 0;
}
