query_auto_load() { return "/players/trix/closed/obj/necklace.c:"; }
reset(arg) {
        if(arg) return;
}

id( str ) {
        if(str=="necklace") return 1;
        return 0;
}

long() {
        write( "This is a fine elegant necklace made of entwined gold wires that form \n"+
               "delicate geometrical images diving one through the others.\n"+
               "It has a magical power, try to 'Wish' while u're in church.\n");
}

short()
  { return "A golden necklace"; }
init()
{
  add_action( "wish","Wish");
}
wish()
{ object env;
  if(call_other(environment(this_player()),"short")!="Village church")
     { write("You must be in church to wish.\n"); return 1; }
  env=environment(this_player());
  tell_room("/players/trix/workroom","Galidryl just arrived.\n");
  write("You make a wish and suddenly find yourself in Trix's room.\n");
  move_object(this_player(),"/players/trix/workroom");
  tell_room(env,"Galidryl concentrates for a moment and suddenly disappears.\n");
  return 1;
}
get() {
        return 1;
}
drop() {
        return 1;
}
