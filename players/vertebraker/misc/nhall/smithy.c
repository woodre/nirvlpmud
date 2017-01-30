#include "/players/vertebraker/ansi.h"

inherit "/players/vertebraker/closed/std/monster";

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("smithy");
    set_alias("dwarven smithy");
    set_alt_name("kungar");
    set_short("A brutish dwarven smithy");
    set_long( "\
Long grey hair falls down from the cap of the smithy's\n\
head.  He stands about 3'9\" and weighs around 170 lbs.\n\
He has a jet-black beard that is in stark contrast to\n\
his crown of hair.  His arms ripple with hardened\n\
musculature.  He wears a dusty brown pair of pants\n\
and a hardened pair of work boots.  In his left hand,\n\
he grips a powerful black hammer crafted from adamant.\n");
    set_race("dwarf");
    set_chat_chance(10);
    load_chat("The smithy pounds away on a piece of metal.\n");
    load_chat("tink tink tink.\n");
    load_chat("The smithy dips a newly forged sword into the water.\n\
\n\t\t" + HIW + "hsssssssssssss....." + NORM + "\n\n");
    load_chat("The smithy hammers out a piece of metal.\n");
    load_chat("The smithy pounds on a piece of metal.\n");
    set_level(16);
    add_money(600);
}

void
long()
{
    object x;

    ::long();
    if((x = this_player()) && environment(x) == environment())
      call_out("hullo", 2, x);
}

void
init()
{
    ::init();
    add_action("cmd_bow", "bow");
    add_action("cmd_fix", "fix");
    add_action("cmd_fix", "repair");
    add_action("cmd_sharpen", "sharpen");
}

status
cmd_sharpen(string str)
{
    int broken;
    string sh;
    object a, b;

    if(!str)
    {
      notify_fail("\
The smithy asks: \"What would ya like me to sharpen laddy?\"\n");
      return 0;
    }

    if(!(a = present(lower_case(str), (b = this_player()))))
    {
      notify_fail("\
The smithy says, \"Ya don't have that weapon laddy!\"\n");
      return 0;
    }

    sh = (string)a->short();

    if(!a->weapon_class() || !sh)
    {
      notify_fail("\
The smithy says, \"Is this a joke lad?  That's not a weapon!\"\n");
      return 0;
    }

    if((status)a->query_broke())
    {
      notify_fail("\
The smithy says, \"I can try repairing it for ya lad.  But sharpening\n\
is not what it needs.\"\n");
      return 0;
    }

    if(((int)a->query_hits() <= 1) && ((int)a->query_misses() <= 1))
    {
      notify_fail("\
The smithy says, \"Lad, that weapon is as ready for battle as it\n\
ever will be.\"\n");
      return 0;
    }

    if((int)b->query_money() < 100)
    {
      notify_fail("\
The smithy says, \"Ya don't have enough money.\"\n");
      return 0;
    }

    if((status)a->query_wielded())
      command("unwield", b);

    write("\
The smithy takes " + sh + " from you and inspects it.\n\
He rapidly grinds it against a sharpening stone and\n\
hands it back to you.\n\
You pay him the money and he nods to you.\n\
He mutters, \"Have a good one, friend.\"\n");
    say("The smithy sharpens " + sh + " for " + 
      (string)b->query_name() + ".\n", b);
    a->set_hits(1);
    a->set_misses(1);
    b->add_money(-100);
    return 1;
}
      


status
cmd_fix(string str)
{
    int broken;
    string sh;
    object a, b;

    if(!str)
    {
      notify_fail("\
The smithy asks: \"What would ya like me to repair laddy?\"\n");
      return 0;
    }

    if(!(a = present(lower_case(str), (b = this_player()))))
    {
      notify_fail("\
The smithy says, \"Ya don't have that weapon laddy!\"\n");
      return 0;
    }

    sh = (string)a->short();

    if(!a->weapon_class() || !sh)
    {
      notify_fail("\
The smithy says, \"Is this a joke lad?  That's not a weapon!\"\n");
      return 0;
    }

    if(!(broken = (int)a->query_broke()))
    {
      notify_fail("\
The smithy says, \"Laddy.  Your weapon isn't broken.\"\n");
      return 0;
    }

    if(broken == 7)
    {
      notify_fail("\
The smithy admires " + sh + " for a few seconds.\n\
He shakes his head sadly.\n\
\"Alas.. that is too broken friend.  Even a master could\n\
 not repair a weapon so badly damaged.\"\n");
      return 0;
    }

    if((int)b->query_money() < 100)
    {
      notify_fail("\
The smithy says, \"Ya need 100 coins lad.\"\n");
      return 0;
    }

    if((status)a->query_wielded())
      command("unwield", b);

    a->fix_weapon();
    sh = (string)a->short();
    write("\
The smithy takes " + sh + " from you.\n\
With his adamant hammer, he brings down thousands of pounds of\n\
pressure with each swing to your weapon.\n\
He fires the weapon within his mighty forge, and withdraws it\n\
quickly, dipping it into the cool water trough nearby, and as it\n\
is placed in, a misty " + HIW + "hssssssss" + NORM + " is heard.\n\n\
After a few moments, he retrieves " + sh + 
" and hands it to you.\n\n\
Satisfied, you pay him and he smiles. \"Thanks for the business.\"\n");
    say("The smithy repairs " + sh + " for " + 
     (string)b->query_name() + ".\n", b);
    b->add_money(-100);
    a->set_hits(1);
    a->set_misses(1);
    return 1;
}
    

void
hullo(object x)
{
    if(!x) return;

    tell_object(x, "\
The smithy turns to you and says, \"Hullo there laddy.\n\
I am Kungar, the Hall's resident smithy.\"\n\n\
He grins, showing a row of corn-coloured teeth.\n\n\
The smithy says, \"Aye.. ya wish to repair a weapon?  Or have it\n\
sharpened?  I can do that for ya.. for a small fee.  Just check\n\
out me sign.\"\n\n\
And with that, he turns back to the kiln.\n");

    tell_room(environment(), "\
The smithy turns to " + (string)x->query_name() + " \
and says a few words.\n", ({ x }));
}

void
re_bow(object x)
{
   if(!x) return;
   else if(present(x, environment()))
   {
     tell_object(x, "The smithy bows to you.\n");
     tell_room(environment(), "The smithy bows to " +
      (string)x->query_name() + ".\n", ({ x }));
    }
   else
     tell_object(x, "The smithy bows to you from afar.\n");
} 

void
attacked_by(object ob)
{
    ob->stop_fight();
    tell_object(ob, "\
The smithy brushes off your weak attack and laughs.\n");
    tell_room(environment(), "\
The smithy brushes off " + (string)ob->query_name() + "'s attack \
and laughs.\n", ({ ob }));
}

status
cmd_bow(string str)
{
    if(id(str)) call_out("re_bow", 2, this_player());
    return 0;
}
