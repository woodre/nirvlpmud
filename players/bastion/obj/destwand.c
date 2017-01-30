
id(str) { return str=="wand" || str=="wand of negation"; }
short() { return "A small, black wand"; }
long() { write("You see nothing special.\n"); return 1; }
query_info() { return "Wand of negation"; }
query_value() { return 500; }
get() { return 1; }
query_save_flag() { return 1; }

init() {
     add_action("use", "use");
     add_action("use", "wave");
}

use(str) {
     object field;
     object staff, wand, armor, money;  /* Rumplemintz */
     if(!id(str)) return 0;
     field=present("force field", environment(this_player()));
     if(!field) {
          write("This has no effect.\n");
          return 1; }
     /* Added to force inventory to move to the vault instead of desting
      * -- Rumplemintz   Dec-14-2009  */
     staff = present ("staff", field);
     money = present ("money", field);
     wand = present ("wand", field);
     armor = present ("armor", field);
     if (staff) move_object(staff, environment(field));
     if (money) move_object(money, environment(field));
     if (wand) move_object(wand, environment(field));
     if (armor) move_object(armor, environment(field));
     destruct(field);
     write("The force field disappears.\n");
     say(this_player()->query_name() + " waves a small wand, and the "+
          "field disappears.\n");
     call_out("self_destruct", 3);
     return 1;
}

self_destruct() {
     say("The wand grows warm and disappears in a spark\n"+
           "of electricity. It must've shorted.\n");
     destruct(this_object());
}
