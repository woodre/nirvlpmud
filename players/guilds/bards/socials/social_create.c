/* social_create.c
 * used to create new Bard socials
 * based on Vertebraker's code
 */
 
string *allowed;
string social_name;
string *social_info;
object target;
object me;
string creator;
int editing_message;
status approved;

#define DUMMY "/players/guilds/bards/star.c"
#define CODE(x,y,z) (string)"/players/guilds/bards/socials/bard_social"->process_codes(x,y,z)
#define COLOR(x) (string)"/players/guilds/bards/lib/addcolor"->addcolor(x)
#define FORMAT(x) (string)"/players/guilds/bards/lib/ansi_pad"->ansi_format(x)
#define APPROVED_OB "/players/guilds/bards/socials/bard_social"
#define UNAPPROVED_OB "/players/guilds/bards/socials/bard_social_un"

id(str) { return str=="bard_social_creator"; }

void start_create() {
  if(!allowed)
    allowed=explode("1234567890qwertyuiopasdfghjklzxcvbnm","");
  if(!target) {
    DUMMY->wake_up_darlin();
    target=find_object(DUMMY);
  }
  me=this_player();
  approved=0;
  social_info=0;
  social_name=0;
  write("\n --- Bard Social Creation --- \n");
  write("Warning: Abuse will not be tolerated.  If you encounter any\n");
  write("bugs cease use until they are fixed.\n");
  write("[1] - Create a new social\n");
  write("[2] - Edit an unapproved social\n");
  write("[3] - Withdraw an unapproved social\n");
  if((int)this_player()->query_level()>19) {
    write("[4] - (wiz)Approve a social\n");
    write("[5] - (wiz)Edit an approved social\n");
    write("[6] - (wiz)Delete an approved social\n");
  }
  write("[q] - quit\n");
  write("[h] - help\n");
  write("Enter your selection: ");
  input_to("main_menu_select");
}

void end_create() {
  destruct(this_object());
}

status return_to_main(string arg) {
  start_create();
  return 1;
}

void new_social_prompt() {
  write("Enter the name of the social: ");
  input_to("new_social_name");
  return;
}

status simple_sort(string x,string y) {
  return x<y;
}

varargs status list_socials(status is_appr,string chk_creator) {
  string *verbs;
  string output;
  int s;
  verbs=(string*)(is_appr?APPROVED_OB:UNAPPROVED_OB)->get_verbs();
  output="";
  s=sizeof(verbs);
  if(verbs)
    verbs=sort_array(verbs,"simple_sort");
  while(s--)
    if(!chk_creator || (string)(is_appr?APPROVED_OB:UNAPPROVED_OB)->get_creator(verbs[s])==chk_creator) {
      output+=verbs[s];
      if(!chk_creator)
        output+=" ("+(string)(is_appr?APPROVED_OB:UNAPPROVED_OB)->get_creator(verbs[s])+")";
      output+=", ";
      }
  if(output=="") {
    write("No available socials.\n");
    return 0;
  }
  write(format(output[0..strlen(output)-3],60));
  return 1;
}

void edit_social_prompt() {
  if(!list_socials(approved,((int)me->query_level()<20?(string)me->query_real_name():0)))
    return start_create();
  write("Enter the name of the social to edit: ");
  input_to("edit_social_name");
}

void remove_social_prompt() {
  if(!list_socials(approved,((int)me->query_level()<20?(string)me->query_real_name():0)))
    return start_create();
  write("Enter the social you wish to remove: ");
  input_to("remove_social_name");
}

void approve_social_prompt() {
  if(!list_socials(0,0)) {
    start_create();
    return;
  }
  write("Which social do you want to review? ");
  input_to("choose_approve");
}

status main_menu_select(string arg) {
  switch(arg) {
    case "q": end_create();
      return 1;
    case "h":
      write("Socials are \"canned\" emotes, like smile and hug.\n");
      write("High level bards can create new ones- but they must\n");
      write("be creative, original, clean, free of spelling and\n");
      write("grammar errors (unless themeatic), and they must be\n");
      write("approved by a guild wizard.\n");
      write("<Hit enter to return to the main menu>");
      input_to("return_to_main");
      return 1;
    case "1":
      creator=(string)me->query_real_name();
      new_social_prompt();
      break;
    case "2":
      edit_social_prompt();
      return 1;
    case "3":
      remove_social_prompt();
      return 1;
    case "4":
      if((int)me->query_level()>19)
        approve_social_prompt();
      else
        start_create();
      return 1;
    case "5":
      if((int)me->query_level()>19) {
        approved=1;
        edit_social_prompt();
      } else
        start_create();
      return 1;
    case "6":
      if((int)me->query_level()>19) {
        approved=1;
        remove_social_prompt();
      } else
        start_create();
      return 1;
    default:
      start_create();
      return 1;
  }
}

void save_social() {
  if(approved)
    APPROVED_OB->set_social(social_name,social_info,creator);
  else
    UNAPPROVED_OB->set_social(social_name,social_info,creator);
  write("The social "+social_name+" has been saved as "+(approved?"approved":"unaproved")+".\n");
  start_create();
}

void edit_social_menu() {
  if(!social_info || sizeof(social_info)<7) {
    write("Incorrect initialization.  Aborting.");
    end_create();
    return;
  }
  write("   Emotion Editor: "+social_name+"\n\n");
  write("Non-targeted Messages:\n");
  write("     [1] User:     "+FORMAT(CODE(social_info[0],me,target)));
  write("     [2] Room:     "+FORMAT(CODE(social_info[1],me,target)));
  write("Targeted Messages:\n");
  write("     [3] User:     "+FORMAT(CODE(social_info[2],me,target)));
  write("     [4] Room:     "+FORMAT(CODE(social_info[3],me,target)));
  write("     [5] Target:   "+FORMAT(CODE(social_info[4],me,target)));
  write("Afar Messages:\n");
  write("     [6] User:     "+FORMAT(CODE(social_info[5],me,target)));
  write("     [7] Target:   "+FORMAT(CODE(social_info[6],me,target)));
  write("\n");
  write("     [s] Save the social\n");
  write("     [h] Show help on what to enter\n");
  write("     [c] List the codes you can use\n");
  write("     [q] Quit to main menu\n");
  write("Enter your selection: ");
  input_to("edit_social_choice");
}

status check_name(string arg) {
  string *letters;
  int s;
  letters=explode(arg,"");
  s=sizeof(letters);
  while(s--)
    if(member_array(letters[s],allowed)==-1)
      return 0;
  return 1;
}

int check_existing(string arg) {
  if(file_size("/bin/soul/_"+arg+".c")>0)
    return 1;
  if(APPROVED_OB->get_social(arg))
    return 2;
  if(UNAPPROVED_OB->get_social(arg))
    return 3;
  return 0;
}

status new_social_name(string arg) {
  string tmp1,tmp2;
  int x;

  if(!arg || arg=="") {
    write("You must enter a name (q to quit).\n");
    new_social_prompt();
    return 1;
  } else if(arg=="q") {
    start_create();
    return 1;
  }
  arg=lower_case(arg);
  if(!check_name(arg)) {
    write("Letters and numbers only.\n");
    new_social_prompt();
    return 1;
  }
  x=check_existing(arg);
  if(x) {
    if(x==1)
      write("You cannot override Nirvana socials.\n");
    else if(x==2)
      write("That is already a Bard social.\n");
    else if(x==3)
      write("That social is already pending approval.\n");
    new_social_prompt();
    return 1;
  }
  social_name=arg;
  social_info=({"none","none","none","none","none","none","none"});
  edit_social_menu();
  return 1;
}

void edit_social_help() {
  write("In the social creator, you get to write exactly what a social\n");
  write("looks like from all the possible angles: You, the target, if there\n");
  write("is one, and the room, if there is one.\n");
  write("Since the person using the social and the target will change, there\n");
  write("are codes that replace the parts of the social that can change.\n");
  write("For a list of the codes, press h after you select a message to edit.\n");
  write("[Press Enter to continue]");
  input_to("edit_social_help2"); 
}

void edit_social_help2(string arg) {
  write("You can't create socials that already exists for all of Nirvana,\n");
  write("But the smile social is a good example of what each message is for,\n");
  write("and how to use the codes:\n");
  write("Non-targeted Room Messages:\n");
  write("  User:   You smile.\n");
 write("  Becomes:  You smile.\n");
  write("  Room:   #MN# smiles.\n");
  write("  Becomes:  "+FORMAT(CODE("#MN# smiles.",me,target)));
  write("Targeted Room Messages:\n");
  write("  User:   You smile at #TN#.\n");
  write("  Becomes:  "+FORMAT(CODE("You smile at #TN#.",me,target)));
  write("  Room:   #MN# smiles at #TN#.\n");
  write("  Becomes:  "+FORMAT(CODE("#MN# smiles at #TN#.",me,target)));
  write("  Target: #MN# smiles at you.\n");
  write("  Becomes:  "+FORMAT(CODE("#MN# smiles at you.",me,target)));
  write("Afar Messages:\n");
  write("  User:   From afar, you smile at #TN#.\n");
  write("  Becomes:  "+FORMAT(CODE("From afar, you smile at #TN#.",me,target)));
  write("  Target: From afar, #MN# smiles at you.\n");
  write("  Becomes:  "+FORMAT(CODE("From afar, #MN# smiles at you.",me,target)));
  write("[Press Enter to continue]");
  input_to("return_to_edit");  
}

void return_to_edit() {
  edit_social_menu();
}

void display_codes() {
  write("   ---- Codes for Emotion Creation ----\n\n");
  write("  User   Target    Effect         Example result\n");
  write("  #MN#    #TN#      Name           Harper\n");
  write("  #MP#    #TP#      Possessive     his\n");
  write("  #MS#    #TS#      Subjective     he\n");
  write("  #MO#    #TO#      Objective      him\n");
  write(" #INST#   none      Instrument     Guitar (colorized)\n");
  write(" Put a C at the beginning of a code to capitalize it, ie, #CMP#\n");
  write(" #RET# to force a newline.  Your social will be auto-formatted\n");
  write(" so a #RET# at the end is not needed.\n");
  write(" You can use $ instead of # if you choose.\n");
  write("You can also use the Bard color codes:\n");
  write("`red`,`green`,`yellow`,`blue`,`purple`,`cyan`,`black`,`white`\n");
  write("`RED`,`GREEN`,`YELLOW`,`BLUE`,`PURPLE`,`CYAN`,`BLACK`,`WHITE`\n");
  write("`bold`,`off`\n");
}

void edit_social_choice(string arg) {
  switch(arg) {
    case "q": 
      start_create();
      return;
    case "1": case "2": case "3": case "4": case "5": case "6": case "7":
      sscanf(arg,"%d",editing_message);
      call_other(this_object(),"prompt_message");
      return;
    case "s":
      save_social();
      return;
    case "h":
      edit_social_help();
      return;
    case "c":
      display_codes();
      write("[Press Enter to continue]");
      input_to("return_to_edit");
      return;
    default:
      edit_social_menu();
      return;
  }
}

void prompt_message() {
  write("Enter the message (h to list available codes):\n");
  input_to("enter_message");
}

void enter_message(string arg) {
  string before,after;
  if(!arg || arg=="") {
    social_info[editing_message-1]="none";
    edit_social_menu();
    return;
  } else if(arg=="h") {
    display_codes();
    prompt_message();
    return;
  }
  if(!editing_message) {
    write("Incorrect initialization.  Aborting.");
    end_create();
    return;
  }
  social_info[editing_message-1]=COLOR(arg);
  edit_social_menu();
}

void edit_social_name(string arg) {
  string chkcreator;
  string *stuff;
  if(!arg || arg=="") {
    write("You must enter the emote you wish to edit (q to quit).\n");
    edit_social_prompt();
    return;
  } else if(arg=="q") {
    start_create();
    return;
  }
  stuff=(approved?(string*)APPROVED_OB->get_social(arg):(string*)UNAPPROVED_OB->get_social(arg));
  if(!stuff) {
    write("Social not found.  Re-enter the name or (q to quit).\n");
    edit_social_prompt();
    return;
  }
  chkcreator=(approved?(string)APPROVED_OB->get_creator(arg):(string)UNAPPROVED_OB->get_creator(arg));
  if(chkcreator!=(string)me->query_real_name() && (int)me->query_level()<19) {
    write("You may only edit your own socials.\n");
    edit_social_prompt();
    return;
  }
  creator=chkcreator;
  social_info=stuff;
  social_name=arg;
  edit_social_menu();
}

void remove_social_name(string arg) {
  string chkcreator;
  string *stuff;
  if(!arg || arg=="") {
    write("You must enter the emote you wish to remove (q to quit).\n");
    remove_social_prompt();
    return;
  } else if(arg=="q") {
    start_create();
    return;
  }
  stuff=(approved?(string*)APPROVED_OB->get_social(arg):(string*)UNAPPROVED_OB->get_social(arg));
  if(!stuff) {
    write("Social not found.  Re-enter the name or (q to quit).\n");
    remove_social_prompt();
    return;
  }
  chkcreator=(approved?(string)APPROVED_OB->get_creator(arg):(string)UNAPPROVED_OB->get_creator(arg));
  if(chkcreator!=(string)me->query_real_name() && (int)me->query_level()<19) {
    write("You may only remove your own socials.\n");
    remove_social_prompt();
    return;
  }
  social_name=arg;
  write("Are you sure you want to remove the social "+arg+"[y/n]? ");
  input_to("remove_social_confirm");
} 
void remove_social_confirm(string arg) {
  if(arg=="y") {
    if(approved)
      APPROVED_OB->remove_social(social_name);
    else
      UNAPPROVED_OB->remove_social(social_name);
    write("Social "+social_name+" removed from "+(approved?"approved":"unapproved")+" socials.\n\n");
    start_create();
    return;
  }
  write("Remove aborted.\n");
  social_name=0;
  remove_social_prompt();
}

void choose_approve(string arg) {
  string *stuff;
  if(!arg || arg=="") {
    write("You must enter an emote you want to approve(q to quit).\n");
    approve_social_prompt();
    return;
  } else if(arg=="q") {
    start_create();
    return;
  }
  stuff=(string*)UNAPPROVED_OB->get_social(arg);
  if(!stuff) {
    write("That's not one of the pending socials.\n");
    approve_social_prompt();
    return;
  }
  social_info=stuff;
  social_name=arg;
  write("Unapproved Social: "+arg+"\n");
  write("Untargeted Room Messages:\n");
  write("  User:     "+FORMAT(CODE(social_info[0],me,target)));
  write("  Room:     "+FORMAT(CODE(social_info[1],me,target)));
  write("Targeted Room Messages:\n");
  write("  User:     "+FORMAT(CODE(social_info[2],me,target)));
  write("  Room:     "+FORMAT(CODE(social_info[3],me,target)));
  write("  Target:   "+FORMAT(CODE(social_info[4],me,target)));
  write("Afar Messages:\n");
  write("  User:     "+FORMAT(CODE(social_info[5],me,target)));
  write("  Target:   "+FORMAT(CODE(social_info[6],me,target)));
  write("Approve this social[y/n]? ");
  input_to("confirm_approve");
}

void confirm_approve(string arg) {
  if(arg=="y") {
    creator=(string)UNAPPROVED_OB->get_creator(social_name);
    approved=1;
    UNAPPROVED_OB->remove_social(social_name);
    write("The social "+social_name+" has been removed from the unapproved socials.\n");
    save_social();
    return;
  }
  social_name=0;
  social_info=0;
  approve_social_prompt();
}
