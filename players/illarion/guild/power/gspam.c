/* gspam.c - toggles on or off extra messages about skills
 */

string help() {
  return "Usage: gspam [off/low/full]\n"+
         "Cost:  none\n\n"+
         "Your spam level controls how many guiled messages\n"+
         "you and others see when you're using your skills.\n"+
         "In off mode, you see no messages about skills or\n"+
         "practices.  In low mode, you see all the guild messages\n"+
         "but don't broadcast them to the room.  In full mode,\n"+
         "the room sees messages about your skills as well.\n";
}

void display_spam(int spam_status) {
    write("Your guild spam is set to "+(spam_status?(spam_status==2?"full":"low"):"off")+".\n");
}

status main(string arg) {
  object gob;
  gob=previous_object();
  if(!arg) {
    display_spam((int)gob->query_spam_level());
    return 1;
  }
  switch(arg) {
    case "off":   gob->set_spam_level(0); break;
    case "low":   gob->set_spam_level(1); break;
    case "full":  gob->set_spam_level(2); break;
    default:      write("Usage: guild_spam [off/low/full]\n"); return 1;
  }
  display_spam((int)gob->query_spam_level());
  return 1;
}