
/*
 * TIMEPIECE (4/23/94)
 * Keeps track of time.
 * 6 days in a week
 * 4 weeks in a month
 * 10 months in a year
 * 4 seasons a year
 */

#define SAVE_FILE "players/molasar/rowan/obj/time"

static string *days;
static string *months;
static string *weeks;
static string *seasons;
string curr_day;
string curr_month;
string curr_week;
string curr_season;
int curr_time;
int year;


reset(arg) {
   if(!arg) {
     init_time();
     restore_time();
   }
   save_object(SAVE_FILE);
}

init_time() {
   days = allocate(6);
   days[0] = "Meundai";
   days[1] = "Frendai";
   days[2] = "Veduidai";
   days[3] = "Kerindai";
   days[4] = "Wialtdai";
   days[5] = "Suremdai";
   months = allocate(10);
   months[0] = "FiLauren";
   months[1] = "BrenMorn";
   months[2] = "ShawZen";
   months[3] = "Turenloa";
   months[4] = "neCronim";
   months[5] = "sheBornim";
   months[6] = "Krinsand";
   months[7] = "Densaigen";
   months[8] = "Heptmore";
   months[9] = "Estelian";
   weeks = allocate(4);
   weeks[0] = "First Dawn";
   weeks[1] = "Mid Moon";
   weeks[2] = "Latter Moon";
   weeks[3] = "Last Dawn";
   seasons = allocate(4);
   seasons[0] = "Winter's Morning";
   seasons[1] = "Winter's Night";
   seasons[2] = "Summer's Morning";
   seasons[3] = "Summer's Night";
   return 1;
}   

/*
 * 6 RL hours == 1 week
 */

get_current_time() {
   
   curr_day = (time() - curr_time)/3600;
   if(curr_day >= 6) {
     curr_day = 0;
     curr_time = time();
     curr_week += 1;
     if(curr_week >= 4) {
       curr_week = 0;
       curr_month += 1;
       if(curr_month >= 10) {
         curr_month = 0;
         year += 1;
       }
     }
   }
   if(curr_month <= 2)
     curr_season = 0;
   else
     if(curr_month <= 4)
       curr_season = 1;
   else
     if(curr_month <= 7)
       curr_season = 2;
   else
       curr_season = 3;
   write(days[curr_day]+" in the week of the "+weeks[curr_week]+", "+ 
         months[curr_month]+" "+year+"\n");
   write("It is the season of "+seasons[curr_season]+".\n");
   return 1;
}

justify(str, len) { return extract(str+"                        ",0,len-1); }

calendar_list() {
   int i;

write("[================================================================]\n");
   write("Days:\n");
   write("-----\n");
   for(i=0; i < sizeof(days); i++)
      write(justify(days[i],10));
   write("\n\n");
   write("Weeks:\n");
   write("------\n");
   for(i=0; i < sizeof(weeks); i++)
      write(justify(weeks[i],15));   
   write("\n\n");
   write("Months:\n");
   write("-------\n");
   for(i=0; i < sizeof(months); i++) {
      write(justify(months[i],12));
      if(i == (sizeof(months)/2 - 1))
        write("\n");
   }
   write("\n\n");
   write("Seasons:\n");
   write("--------\n");
   for(i=0; i < sizeof(seasons); i++) {
      write(justify(seasons[i],20));
      if(i == (sizeof(seasons)/2 - 1))
        write("\n");
   }
   write("\n");
write("[================================================================]\n");
   return 1;
}

calendar_help() {
write("[================================================================]\n");
write("                CALENDAR SYSTEM FOR ROWAN\n");
write("\n");
write("calendar                - Get current date\n");
write("calendar_list           - Lists all days, weeks, months, seasons\n");
write("\n");
write("All days, weeks, months, seasons progress from left to right\n");
write("in the <calendar_list>\n");
write("One hour of real time is equal to 1 day.\n");
write("Six hours equal one week, and so on.\n");
write("The time is saved and will progress even if the mud crashes.\n");
write("If the mud is crashed for more than 6 hours the Calendar system\n");
write("will only advance 1 week.\n");
write("[================================================================]\n");
return 1;
}

save_time() {
   save_object(SAVE_FILE);
   return 1;
}

restore_time() {
   restore_object(SAVE_FILE);
   return 1;
}

