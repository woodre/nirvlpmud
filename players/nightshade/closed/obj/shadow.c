object target;
string name,heh,boggle;

set_boggle(arg) {
name=arg;
}
id(arg)
{
   if (target)
      return target->id(arg) || arg == boggle;
}
target_shadow(ob)
{
   target = ob;
   shadow(ob, 1);
}
short()
{
        return name;
}

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
