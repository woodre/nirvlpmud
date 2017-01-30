/* An exmple for some more difficult usage of the parser.
 * The macros in the add_rules described by <living> and
 * <word> ... can be found in the do_action() as variables
 * of the args-mapping with the appropriate macros G_LIVING
 * and G_WORD ...
 */

#include <grammar.h> // parser macros
#include <message.h> // message macros

inherit "basic/parser";   // add_rules
inherit "basic/message";  // messages
inherit "complex/armour"; // we can wear it as a helmet too

int sugar;     // how many sugar is left
status spoon;  // is the spoon still in the tin?

string my_long() {
  string str1, str2;

  if (spoon)
    str1 = "There is a spoon, maybe you can grab it from the tin?\n";
  else
    str1 = "If you have a spoon, you can use the spoon to feed someone\n"
           "with sugar from the tin. Try out the correct grammar!\n";

  switch(sugar) {
  case 0: str2 = "empty"; break;
  case 1: str2 = "nearly empty"; break;
  case 2: str2 = "half full"; break;
  case 3: str2 = "nearly full"; break;
  case 4: str2 = "full"; break;
  default: str2 = "full"; break;
  }

  return "This is a tin for sugar. It is " + str2 + ".\n" +
         str1 + "If the tin is empty you can use it as a helmet.\n";
}

void create() {
  ::create();
  sugar = 4; // full
  spoon = 1; // spoon is in the tin
  set_name("tin");
  set_short("a tin");
  set_type("helmet");
  set_class(1);
  set_long(#'my_long);
  set_encumbrance(2500);
  set_value(100);

  add_rule("use <object> to feed <living> with <word> from <me>", "use");
  add_error_message("use", "Use what? to feed whom? with what? from where?\n");
  add_rule("grab <word> from <me>", "grab");
  add_error_message("grab", "grab what? from where?\n");
}

void init() {
  ::init();
  add_actions(); // activate the add_rules in the do_action()
}

mixed wear(string str) {
  if (id(str)) {          // wear this object?
    if (!sugar) {         // is it empty?
      return ::wear(str); // then wear it, but use complex/armour wear()
    }
    message(({ ({ M_WRITE, "You should empty the tin first." }) }));
    return 1;
  }
  return 0;
}

status do_action(string verb, mapping args) {
  object feeder;

  switch(verb) {
  case "use":
    if (args[G_OBJECT]->id("spoon")) {  // are we using a spoon?
      if (args[G_WORD] == "sugar") {    // are we feeding with sugar?
        if (sugar) {                    // is there sugar in the tin?
          message(({ ({ M_PLAYER, M_PL_VERB, " use", " ", M_PL_POSSESSIVE,
                        " spoon to feed ", args[G_LIVING], " with sugar from ",
                        M_PL_POSSESSIVE, " tin." }), 2, // delay of 2 seconds
                     ({ args[G_LIVING], M_VERB, " look", args[G_LIVING],
                        " somewhat sweeter at ", M_PLAYER, "." }) }));
          sugar--;                      // use a sugar
          if (!sugar)
            message(({ ({ M_WRITE, "Your tin is empty now." }) }));
          args[G_LIVING]->heal_self(3); // sugar is good for you!
          return 1;                     // successfully done
        }
        message(({ ({ M_PLAYER, M_PL_VERB, " try", " to feed ", args[G_LIVING],
                      " with sugar but ", M_PL_VERB, "fail", " because ",
                      M_PL_POSSESSIVE, " tin is empty now." }) }));
        return 1;                       // success, because of empty tin
      }
      message(({ ({ M_WRITE, "There is only sugar in the tin, but never "
                    "something like ", args[G_WORD], "."}) }));
      return 1;                         // we used something other than sugar
    }
    message(({ ({ M_WRITE, "Naah, we only accept spoons for feeding!" }) }));
    return 1;                           // Didn't use 'spoon'
    break;
  case "grab":
    if (args[G_WORD] == "spoon") {
      if (!spoon) {                     // There is no spoon
        message(({ ({ M_WRITE, "Sorry, but there isn't any spoons left." }) }));
        return 1;
      }
      message(({ ({ M_PLAYER, M_PL_VERB, " grab", " a spoon from the tin."}) }));
      feeder = clone_object("complex/item");
      feeder->set_name("spoon");
      feeder->set_short("a spoon");
      feeder->set_long("A nice metal spoon.\n");
      feeder->set_value(14);
      feeder->set_encumbrance(1000);
      if (transfer(feeder, this_player())) {  // Perhaps too heavy?
        message(({ ({ M_PLAYER, M_PL_VERB, " drop", " the spoon because "
                      "it's too heavy for ", M_PL_OBJECTIVE, "." }) }));
        move_object(feeder, environment(this_player()));
      }
      spoon = 0;  // spoon has left the tin
      return 1;   // successfully done
    }
    if (args[G_WORD] == "sugar") {
      message(({ ({ M_WRITE, "Naah, we use spoons to eat the sugar." }) }));
      return 1; // for too greedy people
    }
    message(({ ({ M_WRITE, "There aren't many things for grabbing in the tin. "
                  "Why don't you try the spoon or the sugar?" }) }));
    return 1;   // Did we try to grab air out of the tin
    break;
  }
  return ::do_action(verb, args); // for other verbs defined in the inheritd
                                  // class
}

