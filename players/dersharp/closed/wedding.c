inherit "obj/treasure";
/* Created by the Wizard..Merlyn. */

string spouse;
object ob,ob2;
int weight;

reset(arg)
{
  if(arg) return;
  name = "A wedding ring";
}

extra_look() { return (environment()->query_name() + " is married to " + capitalize(
spouse) + " .."); }
query_auto_load() { return("/players/dersharp/wedding.c:" + spouse + ";"); }

id(str) { return (str == "ring" || str == "wedding_ring"); }

short() { if (spouse) { return name + " (" + capitalize(spouse) + ")"; } else { return name; } }

long()
{
  write("You run your eyes along the slender golden band that covers\n"+
        "your finger ... It shines gently as you tilt your hand in the\n"+
        "sun, the diamonds set in it reflecting their own soft light,\n"+
        "sparkling as if to smile at you ... The ring is warm on your\n"+
        "finger, and you cannot help but feel loved.\n");
}

init_arg(str)
{
  sscanf(str,"%s;",spouse);
}

init()
{
  add_action("ring", "ring");
  add_action("love", "love");
  add_action("bye","toss ring");
  add_action("bring_spouse", "bring");
  add_action("goto_spouse", "visit");
  add_action("echo_spouse", "echo");
  add_action("help","help");
  if (spouse) {
    ob = find_player(spouse);
    if (ob) {
      ring(this_player()->query_name() + " has entered the game!");
    } else {
      write("Ring tells you: " + capitalize(spouse) + " is not playing now.\n");
    }
  }
}

get() { return 1; }
query_value() { return (0); }
query_weight(){ return (0); }

get_spouse()
{
  if (spouse) {
    ob = find_player(spouse);
    if (ob) return(1);
write(capitalize(spouse) + " tells you: I'm not here now *hug*\n");
  } else {
    write("You are not married!\n");
  }
  return;
}

ring(str)
{
  if (!get_spouse()) return(1);
  tell_object(ob, this_player()->query_name() + " (ring): " + str + "\n");
  write("You tell " + ob->query_name() + ": " + str + "\n");
  return(1);
}

local_set_spouse(str) { spouse = str; }

toss_ring() {
   write("Your wedding ring disintigrates on contact with the floor.\n");
   destruct(this_object());
   return 1;
}
drop(str) { if (spouse) { return(1); } else { return(0); } }

love(str)
{
  if (!get_spouse()) return(1);
  tell_object(ob,this_player()->query_name() + " loves you ...\n");
  write(this_player()->query_name() + " loves " + ob->query_name() + " ...\n");
  return(1);
}

bring_spouse(str)
{
  if (!get_spouse()) return(1);
  if (environment(ob)->realm() || environment(this_player())->realm()) {
    write("A magical barrier prevents you!\n");
    return(1);
  }
  tell_room(environment(ob),this_player()->query_name() + " grabs "
    + ob->query_name() + " and drags " + ob->query_objective()
    + " off ...\n");
  tell_object(ob,this_player()->query_name() + " reaches out and takes you in "
    + this_player()->query_possessive() + " arms lovingly ...\n");
  write("You reach out and take " + ob->query_name() + " into your arms tenderly.\n"
);
  say(this_player()->query_name() + " reaches out and pulls " + ob->query_name()
   + " to " + this_player()->query_objective() + ".\n");
  move_object(ob, environment(this_player()));
  this_player()->add_spell_point(-50);
  return(1);
}

goto_spouse(str)
{
  if (!get_spouse()) return(1);
  if (environment(ob)->realm() || environment(this_player())->realm()) {
    write("A magical barrier prevents you!\n");
    return(1);
  }
  tell_room(environment(ob),this_player()->query_name() + " runs in and "
    + "hugs " + ob->query_name() + ".\n");
  tell_object(ob,this_player()->query_name() + " appears and throws "
    + this_player()->query_possessive() + " arms around you!\n");
  write("You throw your arms around " + ob->query_name() + "!\n");
  say(this_player()->query_name() + " runs off.\n");
  move_object(this_player(),environment(ob));
  this_player()->add_spell_point(-50);
  return(1);
}

echo_spouse(str)
{
  if (!get_spouse()) return(1);
  tell_object(ob,"\n" + str + "\n");
  write("You echo: " + str + "\n");
  return(1);
}

help(str)
{
  if (str == "ring") {
cat("/players/dersharp/wedhelp");
    return 1;}
return; }
/*
    write("With this ring, you can:\n"+
          "  RING <msg> - Tell your spouse a message.\n"+
          "  LOVE - Express your feelings for your spouse.\n"+
          "  BRING - Bring your spouse to you.\n"+
          "  VISIT - Go to your spouse.\n"+
          "  ECHO - A private echo to your spouse.\n");
    return(1);
  }
  return;
}
*/
