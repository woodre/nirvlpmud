inherit "obj/clean";


string name;
status glow;

init () { add_action("name","name"); }

id(str) { return str == "orb" || str == "blood orb" || 
                 str == name  || str == (name + "_orb"); }

get() { return 1; }
drop() { return 0; }
query_weight() { return 1; }
query_value() { return 100; }

reset() {}

short() { return "The Blood Orb"; }

long()
{
  if (glow)
    write("     You hold in your hand a small glowing orb.\n");
  else
    write("     You hold in your hand a small orb.\n");
  write("Gazing into it, you see something pulsating.\n");
  if (!name)
    write("An inner voice tells you to name the orb.\n");
  else
    write("The name of the Blood Orb is "+name+".\n");
}


set_name(string newname)
{
  name = newname;
  if (name == "heart")
  {
    if (!glow) write("\nThe orb starts glowing!!\n");
    glow = 1;
  }
  else if (glow)
  {
    glow = 0;
    write("\nThe orb no longer glows.\n");
  }
  else
  {
    glow = 0;
  }
}


int name (string str)
{
  string orbType, orbName;
  string *inputStr;

  if (!str)
  {
    write("name <orbType> orb <name>.\n");
    return 1;
  }

  str = lower_case(str);
  
  inputStr = explode(str, " ");

  if (sizeof(inputStr) != 3)
  {
    write("name <orbType> orb <name>.\n"+
          "For example: name black orb jennifer.\n");
    return 1;
  }

  if (inputStr[1] != "orb")
  {
    write("name <orbType> orb <name>.\n"+
          "For example: name black orb jennifer.\n");
    return 1;
  }

  orbType = inputStr[0];
  orbName = inputStr[2];

  if (orbType == "blood")
  {
    write("You name the Blood Orb "+orbName+".\n");
    set_name(orbName);
    return 1;
  }
}

