int inflated,co;

reset(arg) {
 if(!arg)
  set_light(1);
  co = 3;
}

init() {
    rem_agg();
    add_action("out", "out");
    add_action("inflate","inflate");
    add_action("deflate","deflate");
}

inflate(str) {
 if(!str) return 0;
 if(str!="church" && str!="inflatable church") return 0;
 if(inflated) {
   write("It is already inflated.\n");
   return 1;
 }
 if(co < 1) {
   write("The CO2 cartridges are all used up.\n");
   return 1;
 }
 if(environment(this_object())->is_player()) {
   write("You should drop it first.\n");
   return 1;
 }
 say(this_player()->query_name()+" pulls the cord on the inflatable\n"+
     "church. There is a hissing noise as it inflates and grows into\n"+
     "a minature, vinyl balloon walled church.\n");
 write("You pull the cord and the church inflates, growing into\n"+
       "a minature, vinyl balloon walled church.\n");
 inflated = 1;
 co -= 1;
 return 1;
}

deflate(str) {
 if(!str) return 0;
 if(str!="church" && str!="inflatable church") return 0;
 if(!inflated) {
   write("It is already deflated.\n");
   return 1;
 }
 if(first_inventory(this_object())) {
   write("There's something in the inflatable church still.\n");
   return 1;
 }
 say(this_player()->query_name()+" pulls the plug on the inflatable\n"+
     "church. There is a hissing noise as it deflates falling into\n"+
     "a ruffled pile of vinyl sheet.\n");
 write("You pull the plug and the church deflates, falling into\n"+
     "a ruffled pile of vinyl sheet.\n");
 inflated = 0;
 return 1;
}

query_weight() { 
  if(inflated) return 100;
  else return 5;
}

query_value() { return 2500; }

short() {
 if(inflated)
    return "An inflatable church";
 else
    return "An inflatable church (deflated)";
}

long(str) {
  if (str == "pit") {
	write("In the middle of the church is a deep pit.\n"+
	      "It was used for sacrifice in the old times, but nowadays\n" +
	      "it is only left for tourists to look at.\n");
	return;
    }
        write("The lamp beside the elevator is lit.\n");
}

id(str) {
    return str == "church" || str == "inflatable church" || 
    str == "clock";
}


out() {
 say(this_player()->query_name()+" leaves the church.\n");
 call_other(this_player(), "move_player", "west#room/elevator");
    return 1;
}

pray() {
  if(this_player()->query_guild_name() == "shardak") {
    object mark;
    if(mark = present("shardak_mark", this_player())) {
      write("You may not pray at this most holiest of places.\n");
      return 1;
      }
    }
    return call_other(this_player(), "remove_ghost", 0);
}

query_drop_castle() { return 1; }

rem_agg() {
   object what;
   object ob;
   what = this_object();
   ob = first_inventory(what);
   if (ob) {
      
      while(ob) {
          if(ob->query_aggressive()) { 
            write(ob->short()+" vanishes in a puff of smoke.\n");
            move_object(ob,"room/south/sforst29");
          }
         ob = next_inventory(ob);
       }
   }
   return 1;
}

query_no_fight() {return 1;}
