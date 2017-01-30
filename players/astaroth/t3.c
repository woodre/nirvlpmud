inherit        "room/room";
 
string cap_name;
reset(arg)
        {
/*
        if (!present("shirt")) {
           move_object(clone_object("players/astaroth/shirt"), this_object());
           }
*/
        if (!arg)
                {
                set_light(1);
                short_desc = "Astaroth's Hottub";
                long_desc = "The Hottub, made of wood and ceramic.\n" +
                            "sits in the middle of a big marble room.\n" +
                            "Bay windows light the area all the time, for\n"+
                            "the sun never goes down here. Plants hang in the\n"+
                            "Bay windows, giving it a homey look.\n"+
                            "\n";
                dest_dir = ({"players/astaroth/stu", "west"});
                }
        }
init() {
        ::init();
                add_action("splash"); add_verb("splash");
               add_action("emote"); add_verb("emote");
               add_action("emote"); add_xverb(":");
                add_action("dunk"); add_verb("dunk");
                add_action("feel"); add_verb("feel");
                add_action("snorkel"); add_verb("snorkel");
        }
 
static general(self, others) {
    write(self + "\n");
    cap_name = call_other(this_player(), "query_name");
    say(cap_name + " " + others + "\n");
    return 1;
}
 
static specific(self, others, who, target) {
    who = present(lower_case(who), environment(this_player()));
    cap_name = call_other(this_player(), "query_name");
    if (!who || !living(who) || who == this_player())
        return 0;
    write(self + "\n");
    tell_object(who, cap_name + " " + target + "\n");
    say(cap_name + " " + others + "\n", who);
    return 1;
}
 
splash(str) {
     if(!str) {
       write("Splash someone?\n");
      return 1;
     }
     str = capitalize(str);
     return specific("You splash "+str+".","splashes "+str+".",str,"splashes you.");
}
dunk(str)  {
    if (!str) {
        write("Dunk who?\n");
        return 1;
    }
    str = capitalize(str);
    return specific("You push "+str+" under the water.","dunks "+str+".",
                    str, "gives you a head full of water.");
}
emote(str) {
 
   if (!str) {
      write(" emote or : needs a string to emote!\n");
      return 1;
   }
   say(call_other(this_player(), "query_name")+" "+str+"\n");
   write("You emote: "+str+"\n");
   return 1;
}
