/*
  guild_voting.c - new version of bull_board that allows setting the
                   file name and directory of the saved file
                   and new commands for the guild lieutenants to vote
*/

#include "/players/nooneelse/black/lib/defs.h"

static string board_message_file;
static string new_note;
static string *headers, *notes, *votes;
int nbr_notes;
string header;
string note;
string vote;

reset(arg) {
  if (arg) return 0;

  board_message_file = "players/nooneelse/black/guild_voting";
  nbr_notes = 0;
  headers = allocate(30);
  notes = allocate(30);
  votes = allocate(30);
  restore_me();
}

id(str) {
  return str=="bulletin board" ||
         str=="board" ||
         str=="bulletinboard" ||
         str=="vampbulletinboard";
}

short() { return ("A bulletin board"); }

long() {
  int i;
  string my_name;
  my_name = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_LIEUTENANT) {
    write("Only the Vampire Guild Master, Assistant(s) and Lieutenant(s)\n"+
          "can read the information on this board.\n");
    return 1;
  }
  write("You can set up new notes with the command 'note <headline>'\n"+
        "Read a note with 'read <number>'\n"+
        "Remove an old note with 'remove <number>'\n"+
        "Vote on an issue with: 'vote <num> <vote> <comment>'\n"+
        "                       (<num> is the number of the note on "+
        "the board,\n"+
        "                        <vote> is 'yes' or 'no'\n"+
        "                        '<comment>' is optional\n");
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)==GUILD_MASTER)
    write("As the guild master, you can 'clear board'\n");

  if (nbr_notes==0) {
    write("It is empty.\n");
    return;
  }
  write("The bulletin board contains "+nbr_notes);
  if (nbr_notes==1)
      write(" note:\n\n");
  else
      write(" notes:\n\n");
  say(this_player()->query_name()+" studies the bulletin board.\n");
  for(i = 1; i <= nbr_notes; i++)
    write(i+": "+headers[i-1]+"\n");
  return 1;
}

init() {
  save_me();
  restore_me();

  add_action("new",    "note");
  add_action("read",   "read");
  add_action("remove", "remove");
  add_action("vote",   "vote");
  add_action("clear",  "clear");
}

new(str) {
  string tmp, my_name;
  my_name = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_LIEUTENANT) {
    write("Only the Vampire Guild Master, Assistant(s) and Lieutenant(s)\n"+
          "can write on this board.\n");
    return 1;
  }
  if (!str) {
    write("You must choose a header for this note.\n");
    return 1;
  }
  if (strlen(str) > 40) {
    write("Header too long (max 40 characters)\n");
    return 1;
  }
  tmp = extract(ctime(time()),0,9);  /*>>> 4,9 on orig board*/
  headers[nbr_notes] = str+" ("+this_player()->query_real_name()+", "+tmp+")";
  new_note = "";
  input_to("get_body");
  write("Enter message text.  On a blank line: '**' will save, "+
        "'~q' will abort.\n");
  write("]");
  return 1;
}

get_body(str) {
  if (str=="**") {
    notes[nbr_notes] = new_note;
    votes[nbr_notes] = "";
    new_note = 0;
    nbr_notes++;
    save_me();
    write("Ok.\n");
    return 1;
  }
  else if (str=="~q") {
    write("Ok.\n");
    new_note = 0;
    headers[nbr_notes] = 0;
    return 1;
  }
  else {
    new_note = new_note+str+"\n";
    write("]");
    input_to("get_body");
    return 1;
  }
}

read(str) {
  int note_nbr;
  string my_name;
  my_name = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_LIEUTENANT) {
    write("Only the Vampire Guild Master, Assistant(s) and Lieutenant(s)\n"+
          "can read this board.\n");
    return 1;
  }
  if (!str) {
    write("Read what?\n");
    return 1;
  }
  if (sscanf(str, "%d", note_nbr) != 1 && sscanf(str, "note %d", note_nbr) != 1)
    return 0;
  note_nbr--;
  if (!nbr_notes || note_nbr>=nbr_notes || !headers[note_nbr]) {
    write("Not that many notes.\n");
    return 1;
  }
  write("Note is titled: "+headers[note_nbr]+"\n\n");
  write(notes[note_nbr]+"\n");
  if (votes[note_nbr]=="" || votes[note_nbr]==0)
    write("\n");
  else
    write("\nVotes: "+votes[note_nbr]+"\n\n");
  return 1;
}

remove(str) {
  int note_nbr, i;
  string my_name;
  my_name = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_LIEUTENANT) {
    write("Only the Vampire Guild Master, Assistant(s) and Lieutenant(s)\n"+
          "can remove items from this board.\n");
    return 1;
  }
  if (sscanf(str, "%d", note_nbr) != 1 && sscanf(str, "note %d", note_nbr) != 1)
    return 0;
  note_nbr--;
  if (!nbr_notes || note_nbr > nbr_notes) {
    write("Not that many notes.\n");
    return 1;
  }
  headers[note_nbr] = 0;
  notes[note_nbr] = 0;
  votes[note_nbr] = "";
  for(i = note_nbr; i < nbr_notes; i++) {
    if (headers[i+1]) {
      headers[i] = headers[i+1];
      notes[i] = notes[i+1];
      votes[i] = votes[i+1];
    }
  }
  nbr_notes--;
  save_me();
  write("Removed.\n");
  return 1;
}

vote(str) {
  string my_name, player_who, vote, comments, tmp_votes, s1, s2, s3, s4, s9;
  string hd, body, rest;
  int issue, tmp, tmp2, i, vote_count, yes_votes, no_votes, nbr_lieutenants;
  my_name = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)==GUILD_MASTER ||
      GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)==GUILD_ASSISTANT) {
    write("The Vampire Guild Master, Assistant(s) cannot vote on issues\n"+
          "on this board.\n");
    return 1;
  }
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_LIEUTENANT) {
    write("Only the Vampire Guild Lieutenant(s) "+
          "can vote on the information on this board.\n");
    return 1;
  }
  if (!str) {
    write("You need to actually make some sort of vote!  The format is:\n"+
          "   vote <num> <vote> <comment>\n"+
          "   (<num> is the number of the note on the board,\n"+
          "    <vote> is 'yes' or 'no',\n"+
          "    <comments> are optional)\n");
    return 1;
  }
  tmp = sscanf(str, "%d %s %s", issue, vote, comments);
  if (tmp==1) tmp = sscanf(str, "%d %s", issue, vote);
  issue--;
  if (issue > nbr_notes) {
    write("Invalid note number.\n");
    return 1;
  }
  if (tmp!=2 && tmp!=3) {
    write("Bad vote format.\nNo vote recorded.\n"+
          "   vote <num> <vote> <comments>\n");
    return 1;
  }
  if (tmp==2) comments="no comment";
  if (votes[issue]) tmp2 = sscanf(votes[issue], "%s"+my_name+"%s", s1, s2);
  if (tmp2==2) {
   write("You have already voted on this.  Vote rejected.\n");
   return 1;
  }
  if (votes[issue]=="")
    votes[issue] = "."+my_name+" - "+vote+" -- "+comments+".";
  else
    votes[issue] = votes[issue]+"."+my_name+" - "+vote+" -- "+comments+".";

  /* now count the votes & decide on expelling */
  call_other(GUILD_OFFICE_FLOOR_TOP, "???");
  nbr_lieutenants = GUILD_OFFICE_FLOOR_TOP->query_nbr_lieutenants();
  tmp_votes = votes[issue];
  while(tmp_votes!=0 && tmp_votes!="" && tmp_votes!=".") {
    i = sscanf(tmp_votes, ".%s - %s -- %s.%s", s1, s2, s3, s4);
    if (s1=="yes") yes_votes++;
    if (s1=="no") no_votes++;
    vote_count++;
    if (i==3) tmp_votes=0;
    if (i==4) tmp_votes = "."+s4;
  }
  if (vote_count > nbr_lieutenants) {
    write("Record what you just did and mail the guild master.\n"+
          "Something is wrong with the vote counter.\n");
    return 1;
  }
  write("Vote recorded. ("+vote_count+" of "+nbr_lieutenants+
        " votes are in on this issue.)\n");
  /* expell the bugger */
  if (vote_count==nbr_lieutenants && yes_votes==vote_count) {
    /* take them off the member list */
    call_other(GUILD_MEMBER, "???");
    call_other(GUILD_MEMBER, "delete_player", player_who);
    /* add them to the traitor list & indicate it was a Council Expell */
    call_other(GUILD_PROHIBIT, "???");
    call_other(GUILD_PROHIBIT, "add_player", player_who, "CE");
    write(capitalize(str)+" is now on the guild prohibited list.\n");
    votes[issue] = votes[issue]+"."+capitalize(player_who)+" - is expelled.";
    save_me();
    return 1;
  }
  /* don't expell the bugger */
  if (vote_count==nbr_lieutenants && yes_votes!=vote_count) {
    write(capitalize(str)+" is not expelled from the guild.\n");
    votes[issue] = votes[issue]+"."+capitalize(player_who)+
                   " - is NOT expelled.";
    save_me();
    return 1;
  }
  return 1;
}

clear(str) {
  int i;
  string my_name;
  my_name = this_player()->query_real_name();
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(my_name)!=GUILD_MASTER) {
    write("Only the Vampire Guild Master can clear the board.\n");
    return 1;
  }
  if (!str || str!="board") return 0;
  for(i=0; i<29; i++) {
    headers[i] = 0;
    notes[i] = 0;
    votes[i] = "";
  }
  nbr_notes = 0;
  save_me();
  write("Board cleared\n");
  return 1;
}

save_me() {
  header = implode(headers, "\n**\n");
  note = implode(notes, "\n**\n");
  vote = implode(votes, "\n**\n");
  save_object(board_message_file);
  return 1;
}

restore_me() {
  restore_object(board_message_file);
  if (!header) return 1;
  headers = explode(header,"\n**\n");
  notes = explode(note,"\n**\n");
  votes = explode(vote,"\n**\n");
  return 1;
}
