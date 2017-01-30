info_database(string str) {
  if(!str) {
    write("Your guild commands...\n");
    write("_________________________________________\n");
    write("advance\n"+
          "addxp\n"+
          "enhance\n"+
          "bodyscan\n"+
          "cyberlevels\n"+
          "users\n"+
          "net\n"+
          "nem\n"+
          "line\n"+
          "newlink\n"+
          "download\n"+
          "internal_clock\n"+
          "set_title\n"+
          "exchange\n"+
          "leave_ninjas\n"+
          "recruit\n"+
          "join\n"+
          "cyber <topic> , for help on topics listed\n");
    write("_________________________________________\n");
    return;}
  if(str == "advance") {
     write("This is the function to raise the ninja when"+
           " he/she gets enough xp for the next level.\n");
     return;}
  if(str == "enhance") {
     write("This is a guildmaster command to promote/"+
           "demote a ninja.\n");
     return;}
  if(str == "addxp") {
     write("This is a guildmaster command to raise/lower"+
           "a ninja's xp.\n");
     return;}
  if(str == "bodyscan") {
     write("This shows info on the ninja's guild file.\n");
     return;}
  if(str == "cyberlevels") {
     write("Shows levels, xp, and titles for CyberNinja guild.\n");
     return;}
  if(str == "download") {
     write("Saves your guild file.\n");
     return;}
  if(str == "new_link") {
     write("Updates your guild object.\n");
     return;}
  if((str == "nem") || (str == "net")) {
     write("Guild channel emote (nem) or tell (net).\n");
     return;}
  if(str == "line") {
     write("Muffles guild channel <on/off>\n");
     return;}
  if(str == "users") {
     write("Who list of all guild members.\n");
     return;}
  if(str == "internal_clock") {
     write("Look at church clock.\n");
     return;}
  if(str == "set_title") {
     write("Sets your title to your current guild title.\n");
     return;}
  if(str == "exchange") {
     write("Exchange normal experience to guild experience.\n");
     return;}
  if(str == "leave_ninjas") {
     write("Leave the ninja guild.\n");
     return;}
  if(str == "join") {
     write("*To be called by guild room* Way to join guild.\n");
     return;}
  if(str == "recruit") {
     write("Recruit a member into guild.\n");
     return;}
}
