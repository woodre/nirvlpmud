#define CAP         capitalize
#define LETTERS "/players/sami/misc/ascii/"

string block_string(string str)
{
   int x, a, i;
   string line, letter, block, *words;
   
   block = "";
   words = explode(str," ");
   for(i = 0; i < sizeof(words); i++)
   {
      str = words[i];
      for(x = 0; x < 5; x++)
      {
         line = "";
         for(a = 0; a < strlen(str); a++)
         {
            letter = CAP(extract(str,a,a));
            if(letter == ".") letter = "period";
            if(letter == "/") letter = "slash";
            if(letter != " " && file_size(LETTERS+letter) > 3)
               {
               letter = read_file(LETTERS+letter,(x+1),1);
               if(sscanf(letter,"%s\n",letter));
               letter += "  ";
               
             }
            line += letter;
          }
         block = block + line + "\n";
       }
      block += "\n";
   }
   return block;
}
