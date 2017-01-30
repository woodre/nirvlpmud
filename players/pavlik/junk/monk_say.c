monk_say(str)
{
 say(capitalize(this_player()->query_name())+" says: "+msay(str)+"\n");
write("You monk_say: "+str+"\n");
   return 1;
}

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
         else temp="";
       msg=msg+temp;
   }
   return msg;
}
