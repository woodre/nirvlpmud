inherit "obj/container";

int c,lid;

reset(arg) {
    ::reset(arg);
    if (!arg) {
        set_long("A green stove with oven. It has 4 top burners and \n"+
                 "an oven door. One oven dial and burner controls You can\n"+
                  "set the dial. The burner knobs are missing.\n");
	set_short("A stove");
	set_name("stove");
	set_weight(300);
	set_max_weight(6);
	set_value(12);
        set_can_open(1);
        lid = 1;
    }
}
init() { 
 add_action("set","set");
 add_action("quit","quit");
 add_action("open","open");
 add_action("close","close");
 add_action("up","out");
}
open(arg) {
  if(arg != "stove" && arg != "oven" && arg != "oven door")
    return 0;
  if(!lid) { write("It's already open.\n"); return 1; }
  if(c) { write("You can't open the oven when it's on.\n"); return 1; }
  say(this_player()->query_name()+" opens the oven door.\n");
  write("You open the oven.\n");
  lid = 0;
  ::open("stove");
  return 1;
}
close(arg) {
  if(arg != "stove" && arg != "oven" && arg != "oven door")
    return 0;
  if(lid)  { write("It's already closed.\n"); return 1; }
  say(this_player()->query_name()+" closes the oven door.\n");
  write("You close the oven door.\n");
  lid = 1;
  ::close("stove");
  return 1;
}
set(arg) {
 if(arg != "stove" && arg != "dial" && arg != "oven") return 0;
  if(!lid) { write("You need to close the oven door.\n"); return 1;}
 say(this_player()->query_name()+" sets the dial for the oven.\n");
 say("There is a WOOSH as the burners ignite.\n");
 write("You set the dial.\n");
 write("The oven begins to give off heat.\n");
 c = 0;
 set_short("A Stove <HOT>\n");
 call_out("do_cycle",1);
  return 1;
}
do_cycle() {
 c += 1;
 if(c == 1) { say("You smell the burn stuff at the bottom of the oven.\n");
              tell_room(this_object(),"You're getting hot.\n"); }
 if(c == 2) { say("The stove emits some smoke.\n");
              tell_room(this_object(),"You're burning up.\n"); }
 if(c == 3) { say("The oven is giving off noticable heat.\n");
              tell_room(this_object(),"You see marks on your skin where it touches the shelf.\n"); }
 if(c == 4) { say("The oven seems to be glowing inside.\n");
            tell_room(this_object(),"You feel like a pot roast.\n"); }
 if(c == 5) { say("A smell of cooked meat comes from the oven.\n");
              tell_room(this_object(),"Is that your flesh burning?\n"); }
 if(c == 6)   say("The oven's burner kicks down a notch.\n");
 if(c == 7) { say("The oven is heating the room.\n");
              tell_room(this_object(),"It's getting smokey.\n"); }
 if(c == 8) { say("Smoke pours out through the oven's seams.\n");
              tell_room(this_object(),"You're burnt rather badly.\n"); }
 if(c == 9) { say("The oven makes a woosh sound as it enters self-cleaning mode.\n");
             tell_room(this_object(),"Just when you think it can't get hotter, it does.\n"); }
 if(c == 10) { say("The oven makes a loud a click and sound of gas flowing stops.\n");
             tell_room(this_object(), "The temp levels off and begins to drop.\n"); }
 if(c == 11) say("The oven stops glowing inside the smell of burnt meat is heavy in the air.\n");
 if(c < 11)
 call_out("do_cycle",30);
 if(c == 11) { c = 0; set_short("A Stove"); }
}
up() {
 if(environment(this_player()) != this_object()) return 0;
 if(lid) { 
   write("You find the door is closed and latched.\n");
   write("It can only be opened from the outside.\n");
   tell_room(environment(this_object()),"There is some pounding from the inside of the oven.\n");
   return 1;
  }
  move_object(this_player(),environment(this_object()));
  say(this_player()->query_name()+" pops out of the oven.\n");
  write("You pop out of the oven.\n");
  return 1;
}
realm() {
 if(lid)
 return "NT"; }
quit() {
 if(environment(this_player()) != this_object()) return 0;
 if(!lid) return 0;
 write("You're trapped here buddy.\n");
  return 1;
}
