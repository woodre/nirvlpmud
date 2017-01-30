object shadowee;

void
start_shadow(object ob)
{
    shadowee = ob;
    shadow(ob, 1);
}

void
end_shadow()
{
    shadow(shadowee, 0);
    destruct(this_object());
}

string
short()
{
    if((object)environment(shadowee)->query_offwielding() == shadowee)
      return (string)shadowee->short() + " (Offwielded)";
    else return (string)shadowee->short();
}
