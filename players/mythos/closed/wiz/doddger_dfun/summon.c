do_summon(str) {
   object ob;
   string bye, there;

if(!str) return 0;
    ob = find_player(str);
   if(!ob) ob=find_living(str);
   if(!ob) {
   write (capitalize(str) + "is not online at this time.\n");
       return 1;
      }
    there = environment(ob);
tell_object(ob, "A giant eagle dives into the room, grabbing you s\nsharply with its talons!\n");
   move_object(ob, environment(this_player()));
    tell_room(there, capitalize(str) +
   " is suddenly carried off by a gigantic eagle!\n");
say (capitalize(str) + " plops down in front of you.\n");
write (capitalize(str) + " arrives as commanded.\n");
    return 1;
}
