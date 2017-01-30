/*
 * This is a curse that the player can't get rid of.
 * It prevents you from shouting.
 */
 
int start_time;
 
query_auto_load() {
    return "players/astaroth/back_curse:"+start_time;
}
 
start(ob) {
    move_object(this_object(), ob);
    start_time = time();
    tell_object(ob, "You suddenly get very confused!\n");
}
 
id(str) {
    return str == "back_curse";
}
 
long() {
    write("How can you look at a curse ?\n");
}
 
drop() { return 1; }
 
init() {
    add_action("do_shout", "shout");
    add_action("do_tell","tell");
    add_action("do_say","say");
    add_action("do_say","'",1);
}
 
do_shout(str) {
    if (time() < start_time + 3600) {
        write("Ok.\n");
        shout(capitalize(reverse(this_player()->query_real_name()))+
            " shouts: "+reverse(str)+"\n");
        return 1;
    } else {
        destruct(this_object());
        return 0;
    }
}
 
init_arg(str) {
    sscanf(str, "%d", start_time);
}
 
extra_look() {
    return "This player looks confused";
}
do_say(str) {
   string verb;
    if (time() < start_time + 3600) {
        verb=query_verb();
        if (str==0) str = "";
        if (verb[0]=="'"[0]) str = extract(verb,1)+" "+str;
        write("You say: "+str+"\n");
        say(capitalize(reverse(this_player()->query_real_name()))+
            " says: "+reverse(str)+"\n");
        return 1;
    } else {
        destruct(this_object());
        return 0;
    }
}
reverse(str) {
   string drawkcab;
   int i;
   drawkcab="";
   for (i=strlen(str); i>-1; i--) {
     drawkcab=drawkcab+extract(str,i,i);
   }
   return drawkcab;
}
do_tell(str) {
   string who,mess;
   object player;
    if (time() < start_time + 3600) {
   sscanf(str,"%s %s",who,mess);
   if (!who || !mess || who=="") return 0;
   player=find_player(who);
   if (!player) return 0;
   write ("You tell "+capitalize(who)+": "+mess+"\n");
   tell_object(player,capitalize(reverse(this_player()->query_real_name()))+
      " tells you: "+reverse(mess)+"\n");
        return 1;
    } else {
        destruct(this_object());
        return 0;
    }
}
