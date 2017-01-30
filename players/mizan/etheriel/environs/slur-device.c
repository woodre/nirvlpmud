/* Code for the slur-generator courtesy of Sado@Nirvana
 */

id(str) { return str == "distortion"; }

long() {
  write("A distortion in the ether-muck\n");
}

init() {
  add_action("dsay","say");
  add_action("dsay","'");
}

dsay(str) {
   say(this_player()->query_name()+" says: "+distort(str)+"\n");
   write("You say: "+distort(str)+"\n");
   return 1;
}

distort(str) {
   string msg,temp,letter;
   int i;
   msg="";
   for(i=0;i<strlen(str);i++)
   {
      letter=extract(str,i,i);
         if(lower_case(letter)=="u") temp="urble";
         else if(lower_case(letter)=="r") temp="rum";
         else if(letter=="l" && extract(str,i-1,i-1)=="l") temp="l";
         else if(letter==" " && random(9)==1) temp="(glug) ";
         else if(letter==" " && random(9)==1) temp="(bloop) ";
         else if(letter==" " && random(9)==1) temp="(nog) ";
         else if(letter==" " && random(9)==1) temp="(ploof) ";
         else if(letter==" " && random(9)==1) temp="(glop) ";
         else if(letter==" " && random(4)==1) temp="(moo) ";
         else temp="";
         if((letter=="'" && str[i+1]=='t') ||
               (letter=="s" && str[i+1]=='s')) i++;
         msg=msg+letter+temp;
      }
    msg=msg+letter;
   return msg;
}
