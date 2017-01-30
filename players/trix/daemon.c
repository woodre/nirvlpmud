
/*
 * DO NOT clone this thing!!!
 * Sample daemon object. Learn how this works and life will begin.
 */

#define HOME "/players/mizan/workroom"

id(str) { return str == "object"; }
short() { return "A sample master daemon object"; }
long() {
  write("Do NOT clone this thing!\n");
}

reset() {
  move_object(this_object(), HOME);
}

/* Notice that there is NO init() */

bgrin() {
  write("You grin biggly.\n");
  tell_room(environment(this_player()), (this_player()->query_name()) + " grins biggly.\n");
  return 1;
}

girn() {
  write("Doh! You misspell and GIRN like an idiot!\n");
  tell_room(environment(this_player()), (this_player()->query_name()) + " girns like and idiot!\n");
  return 1;
}

/* Ok.. notice the difference between the above two functions, and
 * the rest from here...
 */

rtell(str) {
  tell_room(environment(this_player()), (this_player()->query_name()) + " " + str + "\n");
  return 1;
}

doh() {
  write("You go 'Doh!'\n");
  rtell("goes 'Doh!'");
  return 1;
}

bog() {
  write("You are left in a steep bogglement.\n");
  rtell("is left in a steep bogglement.\n");
  return 1;
}

/* Now they get a bit fancier. */

bah(str) {
  if(!str) {
    write("You go 'BAH!'\n");
    rtell("goes 'BAH!'");
    return 1;
  }
  write("You go 'BAH!' at the concept of " + str + ".\n");
  rtell("goes 'BAH!' at the concept of " + str + ".");
  return 1;
}

gribble(str) {
  if(!str) {
    write("You gribble uncontrollably.\n");
    rtell("gribbles uncontrollably.\n");
    return 1;
  }
  write("You gribble at the concept of " + str + ".\n");
  rtell("gribbles at the concept of " + str + ".\n");
  return 1;
}

fucknut(arg) {
  object ob;
  if(!arg) return 0;
  ob=present(arg, environment(this_player()));
  if(!ob || !living(ob)) return 0;
  write("You feel that " + (ob->query_name()) + " is a fucknut.\n");
  rtell("feels that " + (ob->query_name()) + " is a fucknut.\n");
  return 1;
}  

squish(arg) {
  object ob;
  if(!arg) {
    write("You squish sloppily about the room.\n");
    rtell("squishes sloppily around the room.");
    return 1;
  }
  ob=present(arg, environment(this_player()));
  if(!ob || !living(ob)) return 0;
    write("You squish " + (ob->query_name()) + "'s head from afar with your fingers.\n");
    rtell("squishes the head of " + (ob->query_name()) + " from afar.");
    return 1;
  }

moo(arg) {
  object ob;
  if(!arg) {
    write("You moo contentedly.\n");
    rtell("moos contentedly.");
    return 1;
  }
  ob=present(arg, environment(this_player()));
  if(!ob || !living(ob)) return 0;
    write("You moo contentedly at " + (ob->query_name()) + ".\n");
    rtell("moos contentedly at " + (ob->query_name()) + ".\n");
    return 1;
  }

boink(arg) {
  object ob;
  if(!arg) {
    write("You go 'Boink!'\n");
    rtell("goes: 'Boink!'");
    return 1;
  }
  ob=present(arg, environment(this_player()));
  if(!ob || !living(ob)) return 0;
    write("go 'Boink!' at " + (ob->query_name()) + ".\n");
    rtell("looks at " + (ob->query_name()) + " and goes 'Boink!'\n");
    return 1;
  }

commands() {
  write("COMMANDS:\n\n");
  write("bgrin\n"+
  "girn\n"+
  "doh\n"+
  "bog\n"+
  "bah <at anything>\n"+
  "gribble <at anything>\n"+
  "fucknut <at someone>\n"+
  "moo <at someone>\n"+
  "squish <at someone>\n"+
  "boink <at someone>\n");
}

