lead_toggle(string str){
  object gob;
  if(str) return 0;
gob = present(GID, TP);
  if(!gob) return;
  if(gob->query_brave()) {
    write("You will now lead all fights.\n");
    gob->toggle_brave(); gob->save_me(); return 1; }
  write("You will no longer lead all fights.\n");
  gob->toggle_brave(); gob->save_me(); return 1; }
