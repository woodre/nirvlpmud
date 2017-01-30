inherit "/obj/armor";

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("galoshes");
    set_alias("rubbery galoshes");
    set_short("Thick, rubbery galoshes");
    set_long("\
A thick, rubbery pair of galoshes that you can wear\n\
upon your feet.  Mud cakes the soles from constant\n\
wear.  They should do well to protect you.\n");
    set_type("boots");
    set_weight(1);
    set_ac(2);
    set_silently(1);
    set_value(555 + random(111));
}

status
wear(string str)
{
    int flag, x;
    flag = worn;

    x = (status)::wear(str);
    if(!flag && worn)
    {
      write("You pull the galoshes over your feet.\n");
      say((string)this_player()->query_name() + " \
pulls the galoshes over " + possessive(this_player()) + " feet.\n");
      return 1;
    }
    else
      return x;
}

status
remove(string str)
{
    int flag, x;
    flag = worn;

    x = (status)::remove(str);
    if(flag && !worn)
    {
      write("You pull off the rubbery galoshes from your feet.\n");
      say((string)this_player()->query_name() + " \
removes the rubbery galoshes from " + possessive(this_player()) + " \
feet.\n");
      return 1;
    }
    else
      return x;
}
