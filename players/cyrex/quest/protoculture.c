
id(str) {return str == "protoculture" || str == "quest";}

short() {
  return "protoculture";
}

long() {
    write("This is the quest of Protoculture:\n");
    write(hint());
}

hint()
{
return("You must find Regis in her hive and destroy the Protocultural Orb.\n");
}
quest_name() {return("protoculture");}
