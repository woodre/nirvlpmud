main(string str)
{
string mess;

if(this_player()->query_gender() == "male")
mess = "\n    |||||||\n"+
          "    (.)I(.)\n"+
          "     < o >\n"+
          "       0  .oO("+str+")\n"+
          "      /|)\n"+
          "       |\n"+
          "       LL\n";

if(this_player()->query_gender() != "male")
mess = "\n    @@@@@@@\n"+
      "    (.)I(.)\n"+
      "     < o >\n"+
      "       0  .oO("+str+")\n"+
      "      /Y)\n"+
      "       ^\n"+
      "       LL\n";

command("wiz " + mess,this_player());
return 1;
}
