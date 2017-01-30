reset(arg) {
        if(arg) return;
}
    query_auto_load() {
    return "/players/trix/obj/emote.c:";
}

 long() {
           write("An emoter, just type em <emotion.\n");
           return 1;
        }
 short() {
        return "An emoter";
        }
id(str) {
        if( str == "emoter" ) return 1;
        return 0;
}
init() {
        add_action("emote","em");
        return 1;
       }
emote(arg)
{  if(!arg) { write("Emote what?\n"); return 1; }
   write( "You "+arg+".\n" );
   say(this_player()->query_name()+" "+arg+".\n" );
   return 1;
}  
get() {
        return 1;
}
drop() {
        return 1;
}
