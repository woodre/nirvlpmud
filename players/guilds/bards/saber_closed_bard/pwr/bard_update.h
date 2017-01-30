/*
 *  Updating the Bardic Instrument
 *  v3.0 by Saber / Geoffrey Z.
 *
 */


bard_update()  {

  string TEMP_NAME;
  object NEW_INSTR;

  save_me();

  TEMP_NAME = INSTR->query_pet_name();
    NEW_INSTR = clone_object("/players/saber/closed/bard/instrument.c");
    destruct(INSTR);
  move_object(NEW_INSTR,TP);
  NEW_INSTR->set_pet_name(TEMP_NAME);

  if(INSTR->COLOR)  {
    write("Your "+INST+" "+HIY+"shines"+HIY+" like new.\n");
       }  else  {
    write("Your "+INST+" shines like new.\n");
       } 

  return 1;
        }
