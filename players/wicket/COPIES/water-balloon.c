inherit "/players/mizan/core/object.c";
#include "/obj/ansi.h"

string my_color;

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   my_color = get_random_color();

   set_get(1);
   set_weight(1);

   set_short("A " + my_color + " water balloon");
   set_name("balloon");
   set_weight(1);

   set_read("The balloons seem to have the writing 'Happy Birthday!' faintly\n"+
            "printed on them.\n");
   set_smell("The water balloon smells kind of stinky, like cheap rubber would.\n");
   set_taste("The water balloon tastes like... rubber!\n");
   set_info("You can hit other wizzes with this");
}

query_weight() { return 1; }

long()
{
    write("This is an ordinary looking water balloon.\n");
    write("It appears you can 'pelt' someone with it, or load it on\n"+
          "a suitable catapult to hit someone with.\n");
}

drop(arg)
{
    if(arg) return 0;
    if(environment(this_object()) != this_player()) return 0;
    
    if(1 == random(5))
    {
        write("The water balloon breaks apart!\n");
        say(this_player()->query_name() + " drops a water balloon and it breaks apart!\n");
        this_player()->add_weight(-this_object()->query_weight());
        destruct(this_object());
        return 0;
    }
}

init()
{
    ::init();

    add_action("pelt", "pelt"); 
}

pelt(arg)
{
    object target;
    if(environment(this_object()) != this_player()) return 0;
    if(!arg) return 0;

    target = present(arg, environment(this_player()));
    if(!target)
    {
        write("Pelt who?\n");
        return 1;
    }

    if(!living(target))
    {
        write("Well, '" + arg + "' is not a living thing.\n");
        return 1;
    }

/* wizzes should not be immune :)
    if(this_player()->query_level() <= 20 && target->query_level() >= 20)
    {
        write("That would not be a good idea.\n");
        return 1;
    }
*/

    write("You pelt " + target->query_name() + " with the water balloon!\n");
/* not needed
    say(this_player()->query_name() + " pelts " + target->query_name() + " with a " + my_color + " water balloon!\n");
 */
    move_object(this_object(), environment(target));
    this_player()->add_weight(-this_object()->query_weight());
    on_explode(target);
    return 1;
}

on_explode(arg)
{
    if(!environment(this_object()))
    {
        return 0;
    }

    tell_room(environment(), HIB);
    tell_room(environment(), splash());
    tell_room(environment(), ESC + "[0m"+ ESC + "[0m");


    if(arg)
        tell_room(environment(), arg->query_name() + " is pelted with a water balloon!\n");

    tell_room(environment(), "Water goes splashing all over the place.\n");

    if(arg)
        move_object(clone_object("/players/mizan/etheriel/items/water-balloon-residue.c"), arg);

    if(environment(this_object()) && environment(environment(this_object())))
        call_other(environment(this_object()), "on_explode");

    destruct(this_object());
    return 1;
}

/* for the vehicles */
detonate(arg)
{
    return on_explode(arg);
}

splash()
{
    string my_result;

    my_result =
      "\t SSSS   PPPPP   LL       AAA     SSSS   HH  HH\n"+
      "\tSS      PP  PP  LL      AA AA   SS      HH  HH\n"+
      "\t SSSS   PPPPP   LL     AA   AA   SSSS   HHHHHH\n"+
      "\t    SS  PP      LL     AAAAAAA      SS  HH  HH\n"+
      "\t SSSS   PP      LLLLL  AA   AA   SSSS   HH  HH\n\n";

    return my_result;

}

get_random_color()
{
    int a;
    a = random(6);

    switch(a)
    {
    case 1:
        return HIR + "red" + ESC + "[0m"+ ESC + "[0m";
    case 2:
        return HIG + "green" + ESC + "[0m"+ ESC + "[0m";
    case 3:
        return HIB + "blue" + ESC + "[0m"+ ESC + "[0m";
    case 4:
        return HIY + "yellow" + ESC + "[0m"+ ESC + "[0m";
    case 5:
        return HIBLK + "black" + ESC + "[0m"+ ESC + "[0m";
    default:
        return HIW + "white" + ESC + "[0m"+ ESC + "[0m";
    }
}
