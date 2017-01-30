#define CHUNK_SIZE 300
#include <ansi.h>
string called_from_ip, startdate, enddate, *names, *dates;
int next_line;

string build_date(string lineToCheck)
{
   string datereturn, *stringWords;
   
   stringWords = explode(lineToCheck," ");
   stringWords -= ({ " " });
   stringWords -= ({ "" });
   datereturn = "UNKNOWN";
   
   if(sizeof(stringWords) > 6)
      datereturn = stringWords[0] + " " + stringWords[1] + " " + stringWords[2];
   
   return datereturn;
}

void check_ip(string searcher, string filename, int start_line)
{
   int a, b, c;
   string filetext, tmpdate,*lines, *matches, *tmp;
   
   filetext = read_file(filename, start_line, CHUNK_SIZE);
   if(!filetext)
      return;
   
   lines = explode(filetext, "\n");
   
   if((!startdate || !strlen(startdate)) && sizeof(lines))
      {
      a = 0;
      startdate = build_date(lines[a]);
      while(startdate == "UNKNOWN" && a < sizeof(lines))
      {
         a++;
         startdate = build_date(lines[a]);
      }
   }
   if(!startdate || !strlen(startdate))
      startdate = "UNKNOWN";
   
   enddate = "UNKNOWN";
   
   if(sizeof(lines))
      {
      a = sizeof(lines) - 1;
      while(enddate == "UNKNOWN" && a != 0)
      {
         enddate = build_date(lines[a]);
         a--;
      }
   }
   
   matches = regexp(lines, searcher);
   for(a = 0; a < sizeof(matches); a++)
   {
      tmp = explode(matches[a]," exit ");
      if(sizeof(tmp))
         {
         tmp = explode(tmp[0]," ");
         if(sizeof(tmp))
            {
            c = member(names,tmp[sizeof(tmp)-1]);
            if(find_player(tmp[sizeof(tmp)-1]))
               tmpdate = "LOGGED ON";
            else
               {
               tmpdate = "";
               for(b = 0; (b+1) < sizeof(tmp); b++)
               tmpdate += tmp[b] + " ";
            }
            
            if(c == -1)
               {
               names += ({ tmp[sizeof(tmp)-1] });
               dates += ({ tmpdate });
            }
            else
               dates[c] = tmpdate;
         }
       }
   }
   
   check_ip(searcher,filename,start_line+CHUNK_SIZE);
   return;
}

main(string str)
{
   string this_ip, first, *file_list, *colors;
   object whom;
   int x;
   
   file_list = ({ "/log/ENTER.old","/log/ENTER" });
   if(!str)
      {
      write("Find who's IP?\n");
      return 1;
   }
   
   first = extract(str,0,0);
   called_from_ip = "";
   whom = find_player(str);
   if(whom)
      called_from_ip = query_ip_number(whom);
   
   if(strlen(called_from_ip) < 1 && !restore_object("pfiles/" + first + "/" + str))
      called_from_ip = str;
   
   names = ({ });
   dates = ({ });
   next_line = 1;
   colors = ({ HIC,"" });
   
   for(x = 0; x < sizeof(file_list); x++)
   check_ip(called_from_ip,file_list[x],next_line);
   write("Matches for: " + called_from_ip + " (" + startdate + " - " + enddate + ")\n");
   for(x = 0; x < sizeof(names); x++)
   write("  " + colors[x % 2] + pad(capitalize(names[x]),12)+ dates[x] + NORM+"\n");
   if(!sizeof(names))
      write("  No matches.\n");
   return 1;
}
