#define CAP         capitalize
#define LETTERS "/players/dragnar/daemons/ascii/"

string ascii_string(string font, string str)
{
   int x, a, i;
   string line, letter, block, FONT, *words;
   
   block = "";
   words = explode(str," ");
   FONT = LETTERS + font + "/";
   for(i = 0; i < sizeof(words); i++)
   {
      str = words[i];
      for(x = 0; x < 6; x++)
      {
         line = "";
         for(a = 0; a < strlen(str); a++)
         {
            letter = CAP(extract(str,a,a));
            if(letter == ".") letter = "period";
            if(letter == "/") letter = "slash";
            if(letter != " " && file_size(FONT+letter) > 3)
               {
               letter = read_file(FONT+letter,(x+1),1);
               if(sscanf(letter,"%s\n",letter));
               letter += "";
               
             }
            line += letter;
          }
         block = block + line + "\n";
       }
      block += "\n";
   }
   return block;
}
