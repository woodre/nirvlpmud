inherit "/obj/monster";

void
reset(int arg)
{
    if(arg) return;
    ::reset();
    set_name("man");
    set_short("A man who heals in combat");
    set_long("\
This is a man who heals in combat\n");
}

void
heart_beat()
{
    ::heart_beat();
    if(!environment()) return;
    if(!random(5) && attacker_ob) /* 1 in 5 chance in combat of heal */
    {
      tell_room(environment(),
"The man heals.... GRAAAAAH\n");
      heal_self(5 + random(5));
    }
}
