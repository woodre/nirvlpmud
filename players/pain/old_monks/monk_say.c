msay(str)
{
   string msg,temp,letter;
   int i;
   msg="";
   for(i=0;i<strlen(str);i++)
   {
      letter=extract(str,i,i);
if(lower_case(letter)=="a") temp="u";
else if(lower_case(letter)=="b") temp="f";
else if(lower_case(letter)=="c") temp="t";
else if(lower_case(letter)=="d") temp="m";
else if(lower_case(letter)=="e") temp="a";
else if(lower_case(letter)=="f") temp="Q";
else if(lower_case(letter)=="g") temp="a";
else if(lower_case(letter)=="h") temp="B";
else if(lower_case(letter)=="i") temp="y";
else if(lower_case(letter)=="j") temp="k";
else if(lower_case(letter)=="k") temp="j";
else if(lower_case(letter)=="m") temp="o";
else if(lower_case(letter)=="n") temp="d";
else if(lower_case(letter)=="o") temp="i";
else if(lower_case(letter)=="p") temp="q";
else if(lower_case(letter)=="q") temp="p";
else if(lower_case(letter)=="r") temp="h";
else if(lower_case(letter)=="s") temp="z";
else if(lower_case(letter)=="t") temp="h";
else if(lower_case(letter)=="u") temp="a";
else if(letter==" ") temp=" ";
else if(letter=="A") temp = "e";
else if(letter=="B") temp = "f";
else if(letter=="C") temp = "Y";
else if(letter=="D") temp = "m";
else if(letter=="E") temp = "U";
else if(letter=="F") temp = "h";
else if(letter=="G") temp = "q";
else if(letter=="H") temp = "f";
else if(letter=="I") temp = "O";
else if(letter=="J") temp = "S";
else if(letter=="L") temp = "D";
else if(letter=="M") temp = "N";
else if(letter=="N") temp = "m";
else if(letter=="O") temp = "a";
else if(letter=="P") temp = "c";
else if(letter=="R") temp = "f";
else if(letter=="S") temp = "h";
else if(letter=="T") temp = "z";
else if(letter=="U") temp = "a";
  else temp=letter;
       msg=msg+temp;
   }
   return msg;
}
