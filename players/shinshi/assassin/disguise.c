
inherit "obj/living";
object target;
string name, short, title;

set_name(arg) {
short=arg;
}

id(arg)
{
   if (target)
    /* return target->id(arg) || arg == boggle; */
     return target->id(arg);
}
target_shadow(ob)
{
   target = ob;
   shadow(ob, 1);
}

query_short(){ return short; }
short()
{
        return short;
}
query_name(){ return target->query_name(); }

seeya()
{
   destruct(shadow(target, 0));
       return 1;
}
