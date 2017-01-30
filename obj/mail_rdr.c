/* Mailer 2 */

/*
 * This mailer has three parts, an editor, and a pager (which are used by the
 * bulletin board).  The mailer allows text copy/paste, forwarding, replying.
 * Allows the mailer to mark mail as private. Private mail cannot be forwarded
 * or pasted to the clipboard. I have also added the route string on the
 * basis that if intermud ever gains a mail system, then this can easily be
 * adapted
 */

#if 0 /* Until include_dirs is fixed */
#include <mudlib.h>
#include <player.cfg>
#include <ansi.h>
#else
#include "/include/mudlib.h"
#include "/include/cfg/player.cfg"
#include "/include/ansi.h"
#endif

#define REAL      (string)this_player()->query_name(1)
#define TIME      ctime(time())[4..15]
#undef PASTE
#define PASTE     "/" + PASTE_DIR + "/" + REAL

#define SENDER    0
#define HEADER    1
#define ROUTE     2
#define MESSAGE   3
#define NEW       4
#define PRIVATE   5
#define DATE_TIME 6

#ifdef INTERMUD   /* no such thing yet, just in case */
#define MUDNAME   INTERMUD_NAME
#define UDP_MAIL  UDP_CMD_DIR + "mail"
#endif


/* stored mail */

mixed *mail; /* ({ ({ sender,header,route,message,new,private}),}) */


/* default mailing fields */

static string *aspirant;
static string *apprentice;
static string *creator;
static string *sage;
static string *lord;
static string *senior;
static string *elder;
static string *arch;
static string *admin;


/* new send mail stuff */

static string recipient;
static string title;
static string route;
static string *cc;
static string message;
static int reply;
static status private_mail;  /* Not clippable or forwardable */


/* read mail stuff */

static int current_message;


/* fn prototypes */

void reset(status arg);                /* set some variables */
void init();
static status test_player(string who); /* test if player exists */
static status headers();               /* writes list of mail */
int new_mail(string who);              /* used by finger */
static status pmail(string str);       /* private mail */
static status mail(string str);        /* mail someone */
static status reply(int i);            /* reply to existing mail */
static status forward(string str);     /* forward existing mail */
static void mail_editor(string str);   /* clone mail editor */
void end_editor(string str);           /* editor calls on save quit */
static void get_cc(string str);        /* get list of other recipients */
static send_mail();                    /* prepare to send mail */
static send_mail_to(string who);       /* send mail to recipient */
static status delete(string str);      /* delete existing mail */
void load_mail();          /* load new mail in recipients' mailer */
void refresh_mail();       /* refresh recipients mailer before send new mail */
static status read(string str);        /* read mail|start controller */
static void prompt();                  /* prompt for mail controller */
static void mail_control(string str);  /* main mail controls */
static void do_read(int i);            /* clone mail reader (pager) */
void editor_quit(string arg);          /* editor calls on quit */
void pager_quit(string arg);           /* pager calls this on quit */
static status valid_name(string arg);

void reset_field();        /* resets|loads default mailing fields */
string *set_field(string field_name, string *field);
string *get_field(string field_name);
static void parse_cc(string str);


/****************************************************************************/

void reset(status arg) {
  if (arg) return;

  title = "";
  cc = ({});
  mail = ({});
  current_message = 1;
  reset_field();
}

status drop(status quit) {
  if (quit) destruct(this_object());
  return 1;
}

void init() {
  if (this_player()->query_npc()) {
    destruct(this_object());
    return;
  }
  if (environment() != this_player()) return;
  restore_object(MAIL_DIR + REAL);
  add_action("mail",    "mail");
  add_action("pmail",   "pmail");
  add_action("headers", "from");
  add_action("reply",   "reply");
  add_action("forward", "forward");
  add_action("delete",  "delete");
  add_action("read",    "read");
}

status id(string str) { return str == "mailer"; }

status get() { return 1; }


/****************************************************************************
 * cc parser
 */

void reset_field() {
  aspirant = ({});
  apprentice = ({});
  creator = ({});
  sage = ({});
  lord = ({});
  senior = ({});
  elder = ({});
  arch = ({});
  admin = ({});
#ifdef MAIL_FIELD_LOADER
  MAIL_FIELD_LOADER->load_fields(this_object());
#endif
}

string *set_field(string field_name, string *field) {
  switch(field_name) {
    case "aspirant":
      aspirant = (field) ? field : ({});
    break;
    case "apprentice":
      return apprentice = (field) ? field : ({});
    break;
    case "creator":
      return creator = (field) ? field : ({});
    break;
    case "sage":
      return sage = (field) ? field : ({});
    break;
    case "lord":
      return lord = (field) ? field : ({});
    break;
    case "senior":
      return senior = (field) ? field : ({});
    break;
    case "elder":
      return elder = (field) ? field : ({});
    break;
    case "arch":
      return arch = (field) ? field : ({});
    break;
    case "admin":
      return admin = (field) ? field : ({});
    break;
  }
  return ({});
}


string *get_field(string field_name) {
  switch(field_name) {
    case "aspirant":
      return aspirant;
    break;
    case "apprentice":
      return apprentice;
    break;
    case "creator":
      return creator;
    break;
    case "sage":
      return sage;
    break;
    case "lord":
      return lord;
    break;
    case "senior":
      return senior;
    break;
    case "elder":
      return elder;
    break;
    case "arch":
      return arch;
    break;
    case "admin":
      return admin;
    break;
  }
  return ({});
}

static void parse_cc(string str) {
  string next_word, rest;
  string *operators, *fields; 
  string next_operator, current_operator;
  int i;
  status stop_flag;

  if (!str) return;
  while(sscanf(str,"%s %s", str, rest)) str += rest;
  operators = ({ ">", "<", "+", ",", "-", });
  fields = ({ "aspirant", "apprentice", "creator",
              "sage", "lord", "senior", "elder",
              "arch", "admin",
  });
  
  for (next_operator = "+"; !stop_flag; ) {
    stop_flag = 1;
    current_operator = next_operator;
    for (i = 0, next_word = str; i < sizeof(operators); i++) {
      if (sscanf(next_word,"%s"+ operators[i] +"%s", next_word, rest)) {
        next_operator = operators[i];
        stop_flag = 0;
      }
    }
    sscanf(str,next_word + next_operator +"%s", str);
    if(next_word == "") continue;

    if ((i = member_array(next_word, fields)) != -1) {
      switch(current_operator) {
        case "<":
          for(i += 1; i--; ) {
            if (!sizeof(get_field(fields[i]))) continue;
            cc += get_field(fields[i]);
            if (sizeof(cc) && sizeof(cc) != sizeof(get_field(fields[i]))) {
              route += ", ";
            }
            route += fields[i];
          }
        break;

        case ">":
          for ( ; i < sizeof(fields); i++) {
            if (!sizeof(get_field(fields[i]))) continue;
            cc += get_field(fields[i]);
            if (sizeof(cc) && sizeof(cc) != sizeof(get_field(fields[i]))) {
              route += ", ";
            }
            route += fields[i];
          }
        break;

        case "+": case ",":
          if (!sizeof(get_field(fields[i]))) break;
          cc += get_field(fields[i]);
          if (sizeof(cc) && sizeof(cc) != sizeof(get_field(fields[i]))) {
            route += ", ";
          }
          route += fields[i];
        break;

        case "-":
#ifndef __LDMUD__
          write("Cannot subtract a field.\n");
#else
          if (!sizeof(get_field(fields[i]))) break;
          if (sizeof(cc)) route += ", ";
          cc -= get_field(fields[i]);
          route += "!"+ fields[i];
#endif
        break;
      }
    }  
    else {
      switch(current_operator) {
        case "<": case "-":
          next_word = capitalize(next_word);
          if ((i = member_array(next_word, cc)) == -1) {
            write("Mail is not routed to '"+ next_word +"'.\n");
          }
          else {
            if (sizeof(cc)) route += ", ";
            route += "!"+ next_word;
            cc = cc[0..(i-1)] + cc[(i+1)..(sizeof(cc)-1)];
          }
        break;

        case ">": case "+": case ",":
          next_word = capitalize(next_word);
          if (!valid_name(next_word)) {
            write("Invalid name, '"+ next_word +"'.\n");
          }
          else if (test_player(next_word)) {
            if (sizeof(cc)) route += ", ";
            route += next_word;
            cc += ({ next_word, });
          }
          else {
            write("No such player, "+ next_word +".\n");
          }
        break;
      }
    }
  }
}


/*********************************************************************/
/* test for existing player character */

static status test_player(string who) {
#ifdef INTERMUD
  string mud;

  if(sscanf(who,"%s@%s", who, mud)) return 1; /* let receiver do it */
#endif
  who = lower_case(who);
  return restore_object(SAVE_NO_BANISH+who)
      || restore_object(SAVE_WIZARD+who)
      || restore_object(SAVE_PLAYER+who)
      || restore_object(SAVE_FIRST +who);
}


/****************************************************************/
/* headers - indicate new mail */

static status headers() {
  int i;

  if (!sizeof(mail)) {
    notify_fail("No Mail.\n");
    return 0;
  }
  for (i = 0; i < sizeof(mail); i++) {
    if (i < 9) write(" ");
    write((i+1)+". Subject: "+ mail[i][HEADER]);
    if (mail[i][NEW])
      write(" (NEW"+ ((mail[i][PRIVATE]) ? " -CONFIDENTIAL-" : "") +")\n");
    else
      write(" (READ"+ ((mail[i][PRIVATE]) ? " -CONFIDENTIAL-" : "") +")\n");
  }
  if (query_verb() != "from") prompt();
  return 1;
}   

/*****************************************************************/
/* new mail - used by finger */

int new_mail(string who) {
  int i;
  int size;

  if (!who) return 0;
  who = capitalize(who);
  if (!test_player(who)) return 0;
  if (!restore_object(MAIL_DIR+lower_case(who))) return 0;
  size = sizeof(mail);
  for (i = size; i-- ; ) {
    if (mail[i][NEW]) {
      restore_object(MAIL_DIR + REAL);
      return (i == size -1 ? 1 : -1); /* -1 for unread */
    }
  }
  return 0;
}


/*****************************************************************/
/* private mail */

static status pmail(string str) {
  private_mail = 1;
  mail(str);
  return 1;
}


/*****************************************************************/
/* mail */

static status mail(string str) {
  if (!str) {
    notify_fail("mail who?\n");
    private_mail = 0;
    return 0;
  }
  str = capitalize(str);
  if (!test_player(str)) {
    notify_fail("No such player, "+ str +".\n");
    private_mail = 0;
    return 0;
  }
  recipient = str;
  if (reply) write("Press <return> for reply.\n");
  write("Subject: ");
  input_to("mail_editor");
  return 1;
}

/********************************************************************/
/* reply */

static status reply(string str) {
  int i;

  if (!sizeof(mail)) {
    notify_fail("No Mail.\n");
    return 0;
  }
  if (!str || sscanf(str,"%d",i) != 1) {
    notify_fail("reply #num\n");
    return 0;
  }
  if (i < 1 || i > sizeof(mail)) {
    notify_fail("You have only "+ sizeof(mail) +
          " message"+((sizeof(mail)==1)?"":"s")+".\n");
    return 0;
  }
  reply = i;
  mail(mail[i-1][SENDER]);
  return 1;
}


/**********************************************************************/
/* forward */

static status forward(string str) {
  int i;
  string *mark;
  string tmp;

  if (!sizeof(mail)) {
    notify_fail("No Mail.\n");
    return 0;
  }
  if (!str || sscanf(str,"%d %s", i, str) != 2) {
    notify_fail("forward #num who?\n");
    return 0;
  }
  if (i < 1 || i > sizeof(mail)) {
    notify_fail("You have only "+ sizeof(mail) +
          " message"+((sizeof(mail)==1)?"":"s")+".\n");
    return 0;
  }
  if (mail[i-1][PRIVATE]) {
    write("Sorry, you cannot forward mail marked as Confidential.\n");
    return 1;
  }
  str = capitalize(str);
  if (!test_player(str)) {
    notify_fail("No such player, "+ str +".\n");
    return 0;
  }
  i -= 1; 
  recipient = str;
  title = mail[i][HEADER];
  sscanf(title,"%sFwd: %s",tmp, title);
  title = "Fwd: "+ title;
  route = mail[i][ROUTE];
  route += "Forwarded by: "+ capitalize(REAL) 
#ifdef INTERMUD
          +"@"+ MUDNAME
#endif
          +", Sent to: "+ recipient +"\n";
  message = mail[i][MESSAGE];
  mark = explode(message,"\n");
  message = ">"+ implode(mark,"\n>");
  write("CC: ");
  input_to("get_cc");
  return 1;
}

/**********************************************************************/
/* invoke editor */

static void mail_editor(string str) {
  string tmp, reply_msg, *mark;

  if (!str || str == "") {
    if (reply) {
      title = mail[reply-1][HEADER];
      sscanf(title,"%sRE: %s",tmp, title);
      title = "RE: "+ title;
      write("Reply: "+ title +"\n");
      route = mail[reply-1][ROUTE];
      route += "Reply by: "+ capitalize(REAL)
#ifdef INTERMUD
              +"@"+ MUDNAME
#endif
              +", Sent to: "+ recipient +"\n";
      reply_msg = mail[reply-1][MESSAGE];
      mark = explode(reply_msg,"\n");
      reply_msg = ">"+ implode(mark,"\n>");
      private_mail = mail[reply-1][PRIVATE];
      reply = 0;  /* reset reply flag */
    }
    else {
      title = "("+ capitalize(REAL) +")";
      route = "Author: "+ capitalize(REAL)
#ifdef INTERMUD
             +"@"+ MUDNAME
#endif
             +", Sent to: "+ recipient +"\n";
    }
  }
  else {
    str = (string)this_player()->filter_ansi(str);
    title = str +" ("+ capitalize(REAL) +")";
    route = "Author: "+ capitalize(REAL)
#ifdef INTERMUD
           +"@"+ MUDNAME
#endif
           +", Sent to: "+ recipient +"\n";
  } 
  clone_object(EDITOR)->edit("end_editor", reply_msg, 1);
}


/* end of using editor */

void end_editor(string str) {
  int i;

  if (!sscanf(file_name(previous_object()),EDITOR+"#%d",i)) return;  
  message = str;
  route += "CC: ";
#ifdef MAIL_FIELD_LOADER
  write("Valid CC fields: admin, arch, elder, senior, lord, sage,\n"+
        "                 creator, apprentice, aspirant.\n"+
        "Valid CC operators: +, -, >, <\n"+
        "CC Example: >arch+lord will send mail to arches and above,"+
        "  and lords.\n");
#endif /* MAIL_FIELD_LOADER */
  write("CC: ");
  input_to("get_cc");
}

/* get other recipients */

static status valid_name(string str) {
  int i;

  str = lower_case(str);
  for (i = 0; i < strlen(str); i++) {
    if ((str[i] < 'a' || str[i] > 'z') && str[i] != '@') return 0;
  }
  return 1;
}


static void get_cc(string str) {
  if (!str || str == "") {
    if (!sizeof(cc)) route += "none";
    route += ".\n";
    send_mail();
    return;
  }
  parse_cc(str);
  write("CC: ");
  input_to("get_cc");
}

/* prepare to send all mail */

static send_mail() {
  int i;

  save_object(MAIL_DIR+REAL);
  send_mail_to(recipient);
  for (i = 0; i < sizeof(cc); i++) {
    if (member_array(cc[i], cc) == i
     && lower_case(cc[i]) != lower_case(recipient)
     && lower_case(cc[i]) != (string)this_player()->query_name(1)) {
      send_mail_to(cc[i]);
    }
  }
  recipient = 0;
  title = 0;
  route = 0;
  cc = ({});
  message = 0;
  reply = 0;
  private_mail = 0;
  if (sizeof(mail)) prompt();
}

/* send mail to recipient */

static send_mail_to(string who) {
  object ob;
  string mud;

  who = lower_case(who);
#ifdef INTERMUD /* the object UDP_MAIL is not code yet, just an idea */
  if (sscanf(who,"%s@%s", who, mud)) {
    call_other(UDP_MAIL,"mail",who,  /* who are we mailing */
                               mud,  /* at which mud       */
                             title,  /* mail header        */
                             route,  /* route of mail      */
                           message); /* mail message       */
    return;
  }
#endif
  if (ob = find_player(who)) {
    tell_object(ob,"You have New mail from "+capitalize(REAL)+".\n");
    ob = present("mailer", ob);              
    if (ob) ob->refresh_mail();
  }
  mail = ({});
  restore_object(MAIL_DIR+who);
  mail += ({
            ({
                REAL,
               title,
               route,
             message,
                   1,
        private_mail,
                TIME,
            }),
          });
  save_object(MAIL_DIR+who);
  if (ob) ob->load_mail();
  restore_object(MAIL_DIR+REAL);
  write("Mail sent to "+ capitalize(who) +".\n");
}

/**********************************************************************/
/* delete */

static status delete(string str) {
  int from, to;

  if (!str || !sscanf(str,"%d,%d", from,to) || !sscanf(str,"%d",from)) {
    write("delete #1,#2?\n");
    return 1;
  }
  if (!to) to = from;
  if (from < 1 || to < from || to > sizeof(mail)) {
    write("You have only "+ sizeof(mail) +" message");
    write(((sizeof(mail) == 1) ? "" : "s") +".\n");
    return 1;
  }
  write("You delete message ");
  write(((from == to) ? from +"" : from +" to "+ to) +".\n");
  mail = mail[0..(from-2)]+mail[to..(sizeof(mail)-1)];
  if (current_message > sizeof(mail)) current_message = sizeof(mail);
  if (current_message < 1) current_message = 1;
  if (sizeof(mail)) { 
    prompt();
  }
  else {
    save_object(MAIL_DIR+REAL);
  }
  return 1;
}

/**********************************************************************/
/* reload mail object of recipient with new mail */

void load_mail() {
  int i;

  if (previous_object()) {
    if (!(sscanf(file_name(previous_object()), MAILER+"#%d",i)
#ifdef INTERMUD
       || file_name(previous_object()) == UDP_MAIL
#endif
    )) {
      return;
    }
  }
  restore_object(MAIL_DIR+(string)environment()->query_name(1));
}


/***********************************************************************/
/* refresh mail object of recipient before sending new mail */


void refresh_mail() {
  int i;

  if (previous_object()) {
    if (!(sscanf(file_name(previous_object()), MAILER+"#%d", i)
#ifdef INTERMUD
      || file_name(previous_object()) == UDP_MAIL
#endif
     )) {
       return;
     }
  }
  save_object(MAIL_DIR+(string)environment()->query_name(1));
  restore_object(MAIL_DIR+(string)environment()->query_name(1));
}


/*************************************************************************/
/*************************************************************************/
/* read mail */


static status read(string str) {
  int i;

  if (!sizeof(mail)) {
    notify_fail("No Mail.\n");
    return 0;
  }
  if (str && sscanf(str,"%d",i) == 1) {
    if (i < 1 || i > sizeof(mail)) {
      notify_fail("You only have "+ sizeof(mail) +
                  " message"+((sizeof(mail)==1)?"":"s")+".\n");
      return 0;
    }
    current_message = i - 1;
    do_read(current_message);
    return 1;
  }
  prompt();
  return 1;
}


static void prompt() {
  write("\nNext Subject: "+mail[current_message-1][HEADER]);
  write(" ("+ ((mail[current_message-1][NEW]) ? "NEW" : "READ"));
  if (mail[current_message-1][PRIVATE]) write(", -CONFIDENTIAL-");
  write(")\n(" + current_message +"/"+ sizeof(mail) +") [? - help]: ");
  input_to("mail_control");
}


static void mail_control(string str) {
  string who;
  int num;
  int from, to;

  if (!str || str == "") { /* read current message */
    do_read(current_message-1);
    return;
  }
  else if (str[0] == '?') {  /* help */
    write("      -=[ Mail Help ]=-\n\n"+
          "     ?   this help\n"+
          "     f   forward mail\n"+
          "     r   reply mail\n"+
          "     h   headers\n"+
          "     m   mail\n"+
          "     p   mail, and mark it as confidential (private)\n"+
          "     d   delete\n"+
          "     #1  read mail number #1\n"+
          "    +/-  move current message number up or down\n"+
          "    <cr> read current message\n"+
          "     c   clip mail to clipboard\n"+
          "    x,q  quit\n"+
          "    oops restore a mail deletion (maybe)\n");
    if (this_player()->query_security_level()) {
      write("   l   log mail to mailbox\n");
    }
  }
  else if (str[0] == 'l') {
    write_file("/log/mailbox/"+ REAL +".mbox",
      "\n"+ mail[current_message-1][HEADER] +"\n"+
            mail[current_message-1][ROUTE]  +
      "Message:\n"+ mail[current_message-1][MESSAGE]);
    write("Message "+ current_message +" has been put into mailbox.\n");
  }
  else if (str[0] == 'h') {
    headers();
    return;
  }
  else if (str[0] == 'f') { /* forward */
    if (sscanf(str,"f %d %s",num,who) || sscanf(str,"f %s",who)) {
      if (!num) num = current_message;
      forward(num +" "+ who);
      return;
    }
    else {
      write("f who? or f #num who?\n");
    }
  }
  else if (str[0] == 'r') { /* reply */
    if (str == "r") str = "r "+ current_message;
    if (sscanf(str,"r %d", num)) {
      if (!num) num = current_message;
      if (num < 1 || num > sizeof(mail)) {
        write("You have only "+ sizeof(mail) +" message");
        write(((sizeof(mail) == 1) ? "" : "s") +".\n");
      }
      else {
        reply(num +"");
        return;
      }
    }
    else {
      write("r #num?\n");
    }
  }
  else if (str[0] == 'm') { /* mail */
    if (sscanf(str,"m %s",who)) {
      mail(who);
      return;
    }
    else {
      write("m who?\n");
    }
  }
  else if (str[0] == 'p') { /* private mail */
    if (sscanf(str,"p %s",who)) {
      pmail(who);
      return;
    }
    else {
      write("p who?\n");
    }
  }
  else if (str[0] == 'd') {
    if (sscanf(str,"d %s",str)) str = "d"+ str;
    if (str == "d") str = "d"+ current_message;
    if (sscanf(str,"d%d,%d",from,to) || sscanf(str,"d%d",from)) {
      if (!to) to = from;
      if (from < 1 || to < from || to > sizeof(mail)) {
        write("You have only "+ sizeof(mail) +
              " message"+((sizeof(mail)==1)?"":"s")+".\n");
      }
      delete(from +","+ to);
      return;
    }
    else {
      write("d #1? or d #1,#2?\n");
    }
  }   
  else if (str[0] == '+') {  /* move current message up */
    sscanf(str,"+%d",num);
    current_message += (num) ? num : 1;
    if (current_message > sizeof(mail)) current_message = sizeof(mail);
  }
  else if (str[0] == '-') { /* move current message down */
    sscanf(str,"-%d",num);
    current_message -= (num) ? num : 1;
    if (current_message < 1) current_message = 1;
  }
  else if (sscanf(str,"%d",num)) { /* read num */
    if (num < 1 || num > sizeof(mail)) {
      write("You have only "+ sizeof(mail) +
            " message"+((sizeof(mail)==1)?"":"s")+".\n");
    }
    else {
      current_message = num - 1;
      do_read(num-1);
      return;
    }
  }
  else if (str[0] == 'c') { /* clip to clipboard */
    if (!sscanf(str,"c %d",num)) num = current_message;
    if (num < 1 || num > sizeof(mail)) {
      write("You have only "+ sizeof(mail) +
            " message"+((sizeof(mail)==1)?"":"s")+".\n");
    }
    else {
      if (mail[num-1][PRIVATE]) {
        rm(PASTE);
        write_file(PASTE,mail[num-1][MESSAGE]);
        write("Copied message to clipboard.\n");
      }
      else {
        write("sorry, you cannot 'clip' Confidential mail.\n");
      }
    }
  }
  else if (str[0] == 'x' || str[0] == 'q') {
    write("Ok.\n");
    save_object(MAIL_DIR+REAL);
    return;
  }
  else if (str == "oops") {
    write("Restoring...\n");
    restore_object(MAIL_DIR+REAL);
  }
  prompt();
}

static void do_read(int i) {
  object reader;
  string str;

  write("\nMessage Number "+ (i+1) +".\n");
  write("Title: "+ mail[i][HEADER] +"\n");
  write(mail[i][ROUTE]);
  write("Date: "+ mail[i][DATE_TIME] +"\n");
  if (mail[i][PRIVATE]) write("\t\t-CONFIDENTIAL-\n");
  write("\nMessage:\n");
  reader = clone_object(PAGER);
  move_object(reader, this_player());
  mail[i][NEW] = 0;
  str = mail[i][MESSAGE];
  if (this_player()->ansi_on()) {
    str += OFF;
  }
  else {
    str = (string)this_player()->filter_ansi(str);
  }
  reader->page(str);
}

void editor_quit(string arg) {
  int i;

  if (!sscanf(file_name(previous_object()),EDITOR +"#%d",i)) return;
  recipient = 0;
  title = 0;
  route = 0;
  cc = ({});
  message = 0;
  reply = 0;
  private_mail = 0;
  if (sizeof(mail)) prompt();
}

/********************************************************************/
/* pager quit */

void pager_quit(string arg) {
  int i;

  if (!sscanf(file_name(previous_object()),PAGER +"#%d",i)) return;
  current_message += (current_message == sizeof(mail)) ? 0 : 1;
  prompt();
}

