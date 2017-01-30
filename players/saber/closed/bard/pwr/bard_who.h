/*
 *  A new who for the Bardic Guild or Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


bard_who()  {

int NUMBER, X;
string WHO, LEVELS;
object USERS, MINI;

  USERS = users();
  
write("\n");
write(">-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-<\n");
write(">-<                                                                         >-<\n");
write(">-<    Name     >-<  Level  >-<  Gender >-<    Guild    >-<    Mini Guild   >-<\n");
write(">-<                                                                         >-<\n");
write(">-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-<\n");
write(">-<                                                                         >-<\n");

  for(X = 0; X < sizeof(USERS); X+=1)  {
    if(USERS[X]->query_level() < 50)  {
  
   write(">-<  ");
 if(USERS[X]->query_guild_name() == "bard")  write(BOLD);
   write(pad(USERS[X]->query_name(),   16));
   write(NORM);
 if(USERS[X]->query_level() > 20)  write(BOLD); 
   write(pad(USERS[X]->query_level(),  12));
   write(NORM);
 if(COLOR)  {
  if(USERS[X]->query_gender() == "male")    write(HIB);
  if(USERS[X]->query_gender() == "female")   write(HIR);
  if(USERS[X]->query_gender() == "creature") write(HIG);
        }
   write(pad(USERS[X]->query_gender(), 14));
   write(NORM);
 if(USERS[X]->query_guild_name() == 0 || USERS[X]->query_guild_name() == "none")  {
   write(".......         ");
         }  else  {
 if(USERS[X]->query_guild_name() == "bard")  write(BOLD);
   write(pad(USERS[X]->query_guild_name(), 16));
         }
   write(NORM);
 if(present("base_obj", USERS[X]))  {
   MINI = present("base_obj", USERS[X]);
   write(pad(MINI->query_newguild(), 13));
         }  else  {
   write("             ");
         }
   write(">-<\n");
         }
         }
write(">-<                                                                         >-<\n");
write(">-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-< >-<\n");
write("\n");
  return 1;
        }       
