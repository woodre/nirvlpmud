main(string str) {
  object offwep, wep, mygob;
 if(!str) {
  mygob=previous_object();
    wep = mygob->query_firstwep();
    offwep = mygob->query_offwep();
    if(offwep) {
      offwep->stop_offwield();
      mygob->set_offwep(0);
/*
    wep->un_wield();
    mygob->remove_firstwep(0);
*/
      write("You stop offwielding "+offwep->query_name()+" in your offhand.\n");
    return 1; 
  }
 else
 return 0;
}
return 0;
}
