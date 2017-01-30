#include <ansi.h>


inherit "/obj/armor";

void reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("mirror shield");
    set_alias("the mirror shield");
    set_type("shield");
    set_short("The Mirror Shield");
    set_long("\
This steel shield has been polished to a mirror shine.\n\
You can see your reflection upon it.\n");
    set_ac(0);
    set_params("other|fire",     1, 3,     "mirror_bounce");
    set_params("other|ice",      1, 3,     "mirror_bounce");
    set_params("other|electric", 1, 3,     "mirror_bounce");
    set_params("other|poison",   1, 3,     "mirror_bounce");
    set_params("other|mental",   1, 3,     "mirror_bounce");
    set_params("magical",        1, 3,     "mirror_bounce");
}

void long(string arg)
{
    ::long(arg);
    if(this_player()->query_attrib("int") > random(40))
      return (write("\
You notice that something has been written upon the back.\n\
You may be able to \"read\" it.\n"));
}

string
short()
{
    string sh, x;
   if(sscanf(sh = (string)::short(), "%s(worn)", x))
      return x + (HIW + "(" + NORM + "worn" + HIW + ")" + NORM);
    else return sh;
}
   

int
mirror_bounce(object owner)
{
    if(random(6)) return random(2);
    else
    {
      object a;

      if((a = this_player()) && (a != owner))
      {
        if(environment(owner)) tell_room(environment(owner), "\n  * " + short_desc + " FLASHES!\n\n");
        tell_object(a, "You see your own reflection.\n");
        tell_object(a, "The laws of nature reverse, and energy repels!\n");
        a->hit_player(random(10), "magical");
      }
    }
}

void init() {
    ::init();
    add_action("cmd_read", "read");
}

cmd_read(arg) {
   if(!arg) { notify_fail("Read what?\n"); return 0; }
    if(!id(arg)) return (notify_fail("You may read " + short_desc + ".\n"), 0);
    write("\n\tForged by Gilmour the Seer.\n\n");
    return 1;
}
