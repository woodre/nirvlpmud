#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()

inherit "obj/treasure";
  int x;

reset(arg) {
  if(arg) return;
  set_id("egg");
  set_short("A fiery red egg");
  set_long("You gaze at the egg.  You see images of\n"+
    "flames work across the egg's surface.\n"+
    "Perhaps in time something will hatch.\n"+
    "Maybe you should wait.\n");
  set_weight(5);
  set_value(0);
  call_out("birth",20);
}

birth() {
  if(!environment(this_object())) { destruct(this_object()); return 1; }
    check_hatch();
    say("Something is wrong......The egg found in the sand\n"+
      "pulsates with an unatural light...the world seems to stop....\n");
   if(environment(this_object()))
      if(living(environment(this_object()))) {
        tell_object(environment(this_object()),"The heat is intense and painful!\n");
        environment(this_object())->heal_self(-random(50));
        move_object(this_object(),environment(environment(this_object())));
        }
    say(CLR+HOME);
    say("\n\n\n\n\n\n\n");
    say("\n"+HIR+
          "                                        *     *    *\n"+
          "                                 *        *          *    *\n"+
          "                                       *             *        *\n"+NORM);   
  say(HIR+"                        *        *               *               *\n"+
          "                      *       *        *                  *         *\n"+
          "                             *                    *               *        \n"+NORM);
  say(HIR+"                  *           *             *              *            *\n"+
          "                *        *     *         *       *            *           *\n"+
          "                            *      *                  *               *     *\n"+NORM);
  say(HIR+"              *         *               *                  *        *        *\n"+
          "                     *                       *         *       *         *\n"+NORM);
  say(HIR+"             *          *      *                *           *           *      *\n"+
          "            *         "+NORM+HIB+"^^^^^     ^        ^^^^       ^^^^^       ^^^^^"+HIR+"          *\n"+NORM);
  say(HIR+"            *         "+NORM+HIB+"^         ^       ^    ^      ^   ^       ^"+HIR+"               *\n"+NORM);
  say(HIR+"                      "+NORM+HIB+"^^^^^     ^       ^^^^^^      ^^^^^       ^^^^^"+HIR+"          *\n"+
          "             *        "+NORM+HIB+"^         ^       ^    ^      ^    ^      ^"+HIR+"         *\n"+NORM);
  say(HIR+"           *     *    "+NORM+HIB+"^         ^^^^^   ^    ^      ^     ^     ^^^^^"+HIR+"         *\n"+
          "             *     *            *         *                  *                   *\n"+NORM);
  say(HIR+"            *          *                        *                  *          *\n"+NORM);
  say(HIR+"                     *        *        *                 *                   *\n"+
          "              *       *                              *                        *\n"+NORM);
  say(HIR+"                   *        *              *                  *         *    *\n"+
          "                     *             *                               *       *\n"+NORM);
  say(HIR+"                         *            *         **          *         *\n"+
          "                              *           *          *            *\n"+
          "                                   *       *            *      *\n"+NORM);
  say(HIR+"                                         *       *         *\n\n"+NORM);
move_object(clone_object("/players/mythos/amon/forest/hinotori.c"),environment(this_object()));
say(MAG+"A FIREBIRD IS BORN!\n\n\n"+NORM);
say("->>");
    destruct(this_object());
return 1;}

query_auto_load() { return ""; }
drop() {
     string where,a,b;
   if(this_player())
   if(environment(this_player()))
     where=object_name(environment(this_player()));
     if(sscanf(where,"%smythos%s",a,b) !=2) {
       write("You cannot drop the egg here.\n");
       return 1;
     }
    return 0;
}
check_hatch() {
object holder;
     holder = environment(this_object());
     if(!holder) { destruct(this_object()); return 1; }
     if(!living(environment(this_object()))) return 1;
     tell_room(environment(holder),holder->query_name()+" vanishes!\n");
     tell_object(holder,"You find yourself elsewhere.\n");
     move_object(holder,"/players/mythos/aroom/forest/clear.c");
     tell_room(environment(holder),holder->query_name()+" appears suddenly.\n");
     tell_object(holder,"The egg begins to shake, you cannot hold it any longer, it\n"+
      "falls out of your hands to the ground.\n\n");
     tell_room(environment(holder),holder->query_name()+" quickly drops an egg.\n");
     move_object(this_object(),environment(holder)); 
     holder->add_weight(-5);
     return 1;
}
