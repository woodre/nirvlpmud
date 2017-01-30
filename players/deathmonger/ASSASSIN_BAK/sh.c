inherit "obj/living";
object target;
string name,heh,boggle;

set_boggle(arg) {
name=arg;
}
id(arg)
{
   if (target)
    /* return target->id(arg) || arg == boggle; */
     return arg == name;
}
target_shadow(ob)
{
   target = ob;
   shadow(ob, 1);
}

query_short(){ return name; }
short()
{
        return name;
}

query_cap_name(){ return capitalize(name); }
query_real_name(){ return name; }
remove_target()
{
   destruct(shadow(target, 0));
   target = 0;
}
query_name() {
        if(target->query_invis())
        return "Someone";
return name;
}
