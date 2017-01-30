inherit "/obj/weapon.c";

string c;

void
reset(status arg) 
{
    if(arg) return;
    ::reset();
    if(!c) c = "An extremely sharp";
    set_name("knife");
    set_alias("hunting knife");
    set_short(c + " hunting knife");
    set_long(
c + " hunting knife with a bone handle, and a razor-like\n\
blade.  There are a few notches on the underside of the\n\
weapon, and a small, jagged hilt.\n");
    set_value(666 + random(222));
    set_weight(1);
    set_class(16);
    set_type("knife");
    set_hit_func(this_object());
}

string
short()
{
    switch(query_wear())
    {
      case 0..40: c = "An extremely sharp";
        break;
      case 41..101: c = "A quite sharp";
        break;
      case 102..202: c = "A sharp";
        break;
      case 203..401: c = "A dull";
        break;
      default: c = "A worn out";
        break;
    }

    short_desc = (c + " hunting knife");

    return ((string)::short());
}

int 
weapon_hit(object target)
{
    string x, n;

    if(random(100) <= 10) 
    {
      write("You slash deeply into " + 
        (x = (string)target->query_name()) + "...\n");
      say((n = (string)this_player()->query_name()) + " \
slashes deeply into " + x + "...\n", target);
      tell_object(target, n + " slashes deeply into you...\n");
      return 4;
    }
}

void
long(string str)
{
    if(str == "notches" || str == "underside" ||
       str == "the notches" || str == "scores")
    {
      write("\
Several scores of notches upon the underside of the beast.\n");
      return;
    }

    ::long(str);
}

status
id(string str)
{
    return (::id(str) || str == "notches" || str == "underside" || str == "the notches" || str == "scores");
}
