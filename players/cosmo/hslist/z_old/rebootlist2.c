#include "/obj/user/channel.c"

/*-------------------------------------------------------------------*/
short() {
    return "A list of the top players since reboot" ;
}

long() {
    write("blah\n");
}

/*-------------------------------------------------------------------*/
id(str) {
    return str == "list" || str == "top" || str == "top players" ||
        str == "list of top players" || str == "top list";
}

/*-------------------------------------------------------------------*/
reset(arg) {
  if(arg) return;
}

/*-------------------------------------------------------------------*/
/* Used in /obj/user/channel.c - must return > 20 */
query_level() { return 22; }

query_weight() { return 1; }

query_value() { return 5; }

get() { return 1; }

/*-------------------------------------------------------------------*/
init() {
  channel_names = ({ });
  add_channel("msg");
  add_action("read"); add_verb("read");
  write("Test1\n");
}

/*-------------------------------------------------------------------*/
read(str) {
  if (!id(str))
    return 0;
  say(call_other(this_player(), "query_name") + " reads the top list.\n");
  return 1;
}

/*-------------------------------------------------------------------*/
catch_tell(str) {
string pname, in_out, junk1, junk2;
int pexp;               /* Player's exp */
object who;

  write("Test2\n");
  write(str);

  /* Make sure it is a valid msg str; don't include the guest */
  if ((sscanf(str, "%s (%s) has %s %s", pname, junk1, in_out, junk2) == 4)
     && (pname!="Guest")) {

    if (in_out=="entered") {
      /* Convert the player's name to an object, get the exp, and store it */
      who = present(pname, this_player());
      pexp = who->query_exp();
    }
    write(pname+" "+in_out+" with "+pexp+" experience.\n");
  }
  else write("Invalid msg string.\n");
}

/*-------------------------------------------------------------------*/
