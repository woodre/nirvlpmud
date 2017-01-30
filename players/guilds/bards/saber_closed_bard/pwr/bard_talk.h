/*
 *  The Bardic chat channel
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


bard_talk(str)  {

  object instrument, person, *list;
  int i, c;
  string temp, color_temp;

  if(spell(-50,1,1) ==-1) return 0;

  if(!INSTR) { notify_fail(NO_INSTRUMENT); return 0; }
  
  if(!INSTR->query_on()) { 
      notify_fail("You must tune your instrument before you talk to your kin.\n"+
                  "To tune your instrumet < toggle >\n"); 
      return 0; 
      }
      
  if(!str) { notify_fail ("Don't you have anything to say?\n"); 
      return 0; 
      }
      
  color_temp = BOLD+"("+HIB+"*"+NORM+""+BOLD+")"+NORM+" "+
               HIM+""+tp+""+NORM+" sings: "+str+"\n";
  temp = "(*) "+tp+" sings: "+str+"\n"; 
   
  c = 0;
  list=users();
  for(i=0; i<sizeof(list); ++i)  {
  
    person=list[i];
    instrument=present("instrument",person);
    if(instrument && (int)instrument->query_on())  {
      if((int)instrument->query_color()) { tell_object(person,color_temp); } else
      { tell_object(person,temp); }
      ++c;
      }
    }
   
    if(c==1) write("There are no other Bards within the realms of magic.\n");
    return 1;
        }
