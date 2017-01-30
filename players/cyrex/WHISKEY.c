
inherit "obj/treasure";
int shots_drank;

id(str) { return (str == "whiskey" || str == "bottle"); }

reset() {
    set_save_flag(1);
}

long()
{
  write("A tall bottle of Scotch whiskey.\n");
  write("There are " + (11-shots_drank) + " shots left.\n");
}

short() { return "A bottle of whiskey"; }
drop() {
        write("What are you...a Fool???\n");
        return 0;
        }

init()

{
  add_action("drink","drink");
}

drink(arg)
{
  if (id(arg)) {
    if (!call_other(this_player(), "drink_alcohol", 14)) {
        write("You might want to wait a bit...you feel a little doozy.\n");
        return 1;
        }
   if (call_other(this_player(), "drink_alcohol", 15))
   say(call_other(this_player(),"query_name") + " takes a shot of whiskey.\n");
   write("You take a shot of whiskey\nYou feel the warm soothing sensation!\n");
   if (shots_drank == 10) { write(
        "You suck the last shot out and break the bottle.\n"); }
      else { write("There are " + (10 - shots_drank) + " shots left.\n"); }
      call_other(this_player(),"heal_self",20);
      shots_drank++;
      if (shots_drank > 10) {
        this_player()->add_weight(-1);
        destruct(this_object());
      }
      return 1;
    }
    return 1;
}

get() { return 1; }

query_weight() { return 2; }

query_value() { return 1000; }

