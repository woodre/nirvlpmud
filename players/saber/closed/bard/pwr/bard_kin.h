/*
 *  A spell to tell who is a Bard for the Bards of Ryllian.
 *  v3.0 by Saber / Geoffrey Z.
 *
 */

bard_kin()  {
int b, WIZ;
object ob, ob2, INSTRUM;
string spon;

ob = users();

write("\n");
write(" _______________________________________________________________________\n");
write("\n");
write("  "+BOLD+"Name"+NORM+"           "+BOLD+"Level"+NORM+"         "+BOLD+"Rank"+NORM+
      "              "+BOLD+"Sponsor"+NORM+"      "+BOLD+"Gender"+NORM+"\n");
write(" _______________________________________________________________________\n");
write("\n");

for(b=0;b<sizeof(ob);b+=1)  {
  if(present("bard_obj", ob[b]))  {
   if(ob[b]->query_level() < 20)  {
   write("  ");

   INSTRUM = present("bard_obj", ob[b]);
   
 if(!INSTRUM->query_on()) { 
   
   if(ob[b]->query_invis() == 0)  {
     write(pad(ob[b]->query_name(),15));  }
   else  {  write(pad("*"+ob[b]->query_name()+"*",15));  }
   
   }  else  {

   if(ob[b]->query_invis() == 0)  {
     write(BOLD+pad(ob[b]->query_name(),15)+NORM);  }
   else  {  write(BOLD+pad("*"+ob[b]->query_name()+"*",15)+NORM);  }
   
   }

  write(pad(ob[b]->query_level(),14));
  
  ob2 = present("bard_obj", ob[b]);
  
       if(ob[b]->query_level() > 20 && ob[b]->query_real_name() == "saber")  
          write("Bardic Wizard     ");
  else if(ob[b]->query_level() > 20)  
          write("Wizard            ");  
  else if(ob2->query_bard_level() < 4)  
          write("Apprentice        ");
  else if(ob2->query_bard_level() > 3  && ob2->query_bard_level() < 7)   
          write("Journeyman        ");
  else if(ob2->query_bard_level() > 6  && ob2->query_bard_level() < 10)   
          write("Minstrel          ");
  else if(ob2->query_bard_level() > 9  && ob2->query_bard_level() < 13)   
          write("Bard              ");
  else if(ob2->query_bard_level() > 12 && ob2->query_bard_level() < 15)   
          write("Bard [High]       ");
  else if(ob2->query_bard_level() > 15 && ob2->query_bard_level() < 22)   
          write("Bard [Master]     ");
  else if(ob2->query_bard_level() > 21 && ob2->query_bard_level() < 29)   
          write("Bard [Guardian]   ");
  else if(ob2->query_bard_level() > 28 && ob2->query_bard_level() < 36)   
          write("Bard [Guardian]   ");
  else if(ob2->query_bard_level() > 35 && ob2->query_bard_level() < 43)   
          write("Bard [Guardian]   ");
  else if(ob2->query_bard_level() > 42)   
          write("Bard [Avatar]     ");
  else    write("Guest             ");

  if(ob2->query_bard_level() < 8)  {
    spon = this_object()->query_sponsor();
    ob2 = present("bard_obj", ob[b]);
    spon = ob2->query_sponsor();
    write(pad(spon,13));
  }  else  { write("             ");  }

  if(ob[b]->query_gender() == "male")    write(HIB);
  if(ob[b]->query_gender() == "female")   write(HIR);
  if(ob[b]->query_gender() == "creature") write(HIG);

   write(pad(ob[b]->query_gender(),9));
   write(NORM);

write("\n");

         } } }

write("\n");
write(" _______________________________________________________________________\n");
write("\n");

for(b=0;b<sizeof(ob);b+=1)  {
  if(present("bard_obj", ob[b]))  {
   if(ob[b]->query_level() > 19)  {
   if(ob[b]->query_invis() == 0)  {

   write("  ");

   INSTRUM = present("bard_obj", ob[b]);
   
 if(!INSTRUM->query_on()) { 

  write(pad(ob[b]->query_name(),15));  }  else  {
  write(BOLD+pad(ob[b]->query_name(),15)+NORM);  } 

       if(ob[b]->query_level() > 19  && ob[b]->query_level() < 100)   
          write("Wizard        ");
  else if(ob[b]->query_level() > 99  && ob[b]->query_level() < 1000)   
          write("Sr Wizard     ");
  else    write("God           ");
    
 if(ob[b]->query_real_name() == "saber")  write("Bardic Wizard     ");
                                  else    write("Wizard            ");  

   write("             ");

  if(ob[b]->query_gender() == "male")    write(HIB);
  if(ob[b]->query_gender() == "female")   write(HIR);
  if(ob[b]->query_gender() == "creature") write(HIG);

   write(pad(ob[b]->query_gender(),9));
   write(NORM);
   
write("\n");
        }
        }
        }
        }
        
write("\n");
write(" _______________________________________________________________________\n");
  write("\n");
  return 1;
        }
