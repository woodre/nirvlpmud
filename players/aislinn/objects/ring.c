int worn,i;
object worn_by;

id(str) {
       return str == "ring";
        }

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("wear"); add_verb("wear");
    add_action("heal"); add_verb("heal");
#else
  add_action("wear", "wear");
  add_action("heal", "heal");
#endif
}

long() {
  write("A platinum ring, with a HUGE diamond.  If you look inside\n");
  write("the band, you notice the words:  Healing is believing.\n");
    }

short() {
    if (worn)
        return "A diamond ring"  + " (worn)";
    return "A diamond ring";
}

query_value()
{
    return 1000/(i+1);
}

wear(str)
{
    if (!id(str))
        return 0;
    if (environment() != this_player()) {
       write("You must get it first!\n");
       return 1;
    }
    if (worn) {
        write("You alread wear it!\n");
        return 1;
    }
   worn_by = this_player();
    call_other(this_player(), "wear", this_object());
  worn = 1;
    return 1;
}

drop(silently) {
    if (worn) {
        call_other(worn_by, "stop_wearing", 0);
        worn = 0;
        worn_by = 0;
        if (!silently)
            write("You drop the ring.\n");
    }
    return 0;
}
get() {
    return 1;
}

query_weight() {
    return 1;
}
un_wear() {
    if (worn)
        worn = 0;
    worn_by = 0;
}

query_name() {
   return "ring";
   }
heal() {
if (i < 6) {
write("You feel alot better.\n");
i = i+1;
call_other(this_player(), "heal_self", 60);
if (i == 5) {
write("The ring turns green, the diamond cracks, and it vanishes.\n");
    move_object(this_object(), "players/aislinn/store");
    return 1;
}
}
return 1;
}
query_hits() { return i;}
set_hits(arg) { i = arg;}
