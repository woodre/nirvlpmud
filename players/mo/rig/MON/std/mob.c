inherit "/obj/monster";

reset(arg)
{
  string *myNames;

  ::reset(arg);
  if(arg) return;

  if(random(2)) /* male */
  {
    set_gender("male");
    myNames = ({ "bob", "bill", "george", "steve" });
  }
  else
  {
    set_gender("female");
    myNames = ({ "karen", "bobbi sue", "karen", "tonya", "tomasina" });
  }

  set_name(myNames[random(sizeof(myNames))]);
}

