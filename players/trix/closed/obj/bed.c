reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="bed"||str=="u2numb") return 1;
        return 0;
}

long() {
        write( "This is a comfortable and wide fluffy bed, it makes you think of candid soft\n"+
               "clouds. Many pillows lay here and there upon it.\n"+
               "Why don't you 'lay down on it(bed)'?\n");
       }

short()
    { return "A large and fluffy bed"; }



query_weight() {
        return 50;
}

query_value() {
        return 50;
}
init()
{
   add_action("lay","lay");
}

lay(str)
 {
  string st1,st2,st3;
  object bedd;
  if((!str) || ((sscanf(str,"%s %s %s",st1,st2,st3) !=3))) { return 0; }
  if(st1!="down") { return 0; }
  if(st2!="on") { return 0; }
  if(st3!="bed") { write("Lay down on what?\n"); return 1; }
  write("You climb the bed and lay down upon it.\n");
  say(call_other(this_player(),"query_name",)+" climbs the bed and lays down upon it.\n",this_player());     
tell_room("/players/trix/closed/room/oroom",
          capitalize(this_player()->query_real_name())+" jumps on here and lays down next to you.\n");
move_object(this_player(),"/players/trix/closed/room/oroom");
  command("look",this_player());
return 1;
 }
get() {
        return 0;
}
