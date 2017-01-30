short() {
  return "Sigil guild object (ver 0.2)";
}

long() { 
  write(major_map["header"]+"\n");
  write(
    "   Imprinted on your "+location+" is the symbol of\n"+
    "   "+major_type+". It glows with a soft "+major_map["color"]+"light"+NORM+".\n"+
    "   You can do any of the following to use its power:\n\n"+
    "      "+major_map["color"]+"set_power"+NORM+"............Sets the power you wish to\n"+ 
    "                           pour into invoking the sigil.\n"+
    "      "+major_map["color"]+major_type+NORM+"("+major_map["color"]+
      extract(major_type,0,1)+NORM+")......Invokes the power of the\n"+
    "                           sigil into a killing spell.\n");
  if(extralevel > 14)
    write("      "+major_map["color"]+"cone"+NORM+"("+major_map["color"]+"co"+NORM+
          ").............Fires a deadly cone of "+major_type+"\n"+
          "                           at two attackers.\n\n");
  write("Use "+major_map["color"]+"set_power"+NORM+" alone to see a listing of possible\n"+
        "settings.\n");
  write("Power is currently set at "+major_map["color"]+
         capitalize(DAEMON->query_pmess())+NORM+".\n\n");
  write("Type "+BOLD+"shelp"+NORM+" to learn more about the guild.\n");
  write(major_map["header"]+"\n");
}

extra_look(){
string msg;
  msg = USER->query_name()+" has a glowing "+major_map["color"]+"sigil"+NORM+
         " on "+USER->query_possessive()+" "+location+"";
  return msg;
}
