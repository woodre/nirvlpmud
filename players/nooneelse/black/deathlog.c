/*  This whole thing is inefficient, but /log/DEATHS sucks. */

deathlog() {
  
int size,Hacksize;
string YEAR;
size=file_size("/log/DEATHS");

if(size > 0) {
string jnk1;
string deathlog,worktext;
if(size > 3000) Hacksize=3000;
else Hacksize=size;

  /*  This will need to be updated in 2000  */
sscanf(ctime(time()),"%s199%s",jnk1,YEAR);
deathlog=read_bytes("/log/DEATHS",size-Hacksize,Hacksize);
rm("/players/nooneelse/black/deathlog");
while(sscanf(deathlog,"%s\n%s",worktext,deathlog)==2) {
   string deathtime,playname,playkill,playgold;
   int playexp;

   if(sscanf(worktext,"%s 199"+YEAR+" %s %d exp %s gold killed by %s.",deathtime,playname,playexp,playgold,playkill)==5) {
            if(playname != "guest") {
               playname=capitalize(playname)+pad("",3+(11-strlen(playname)),' ');
               sscanf(deathtime,"%s %s",jnk1,deathtime);
write_file("/players/nooneelse/black/deathlog.txt","   "+playname+
  deathtime+"     "+capitalize(playkill)+"\n");
            }
         }
      }
   }   
   return 1;
}
