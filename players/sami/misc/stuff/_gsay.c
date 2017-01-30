main(string str)
{
string mess;

if(this_player()->query_gender() == "male")
mess = "\n    |||||||  <-"+this_player()->query_name()+"\n"+
          "    (.)I(.)\n"+
          "     < o >\n"+
          "       0  .oO("+str+")\n"+
          "      /|)\n"+
          "       |\n"+
          "       LL\n";

if(this_player()->query_gender() != "male")
mess = "\n    @@@@@@@  <-"+this_player()->query_name()+"\n"+
      "    (.)I(.)\n"+
      "     < o >\n"+
      "       0  .oO("+str+")\n"+
      "      /Y)\n"+
      "       ^\n"+
      "       LL\n";

tell_room(environment(this_player()),mess);
return 1;
}
