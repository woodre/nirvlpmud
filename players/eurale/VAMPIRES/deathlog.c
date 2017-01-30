deathlog() {
  
int size,Hacksize;
string YEAR;
size = file_size("/log/DEATHS");

if(size > 0) {
string jnk1;
string deathlog,worktext;
if(size > 3000) Hacksize=3000;
else Hacksize = size;

sscanf(ctime(time()),"%s200%s",jnk1,YEAR);
deathlog = read_bytes("/log/DEATHS",size-Hacksize,Hacksize);
rm("/players/eurale/VAMPIRES/deathlog");
while(sscanf(deathlog,"%s\n%s",worktext,deathlog) == 2) {
   string deathtime,playname,playkill,playgold;
   int playexp;

   if(sscanf(worktext,"%s 200"+YEAR+" %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5) {
            if(playname != "guest") {
               playname=capitalize(playname)+pad("",3+(11-strlen(playname)),' ');
               sscanf(deathtime,"%s %s",jnk1,deathtime);
write_file("/players/eurale/VAMPIRES/deathlog","   "+playname+
  deathtime+"     "+capitalize(playkill)+"\n");
            }
         }
      }
   }   
   return 1;
}
