#include <ansi.h>
#include <security.h>

static int timer;
static int tmp_noter_sz;
static int tmp_notenum_new;
static int tmp_notenum_old;
static string *tmp_notes;

int get_note_num(string str);

status cmd_notes(status arg)
{
  string *notes;
  int s_notes;
  string verb, note;
  
  notes = (string*)this_player()->query_notes();
  
  if(!notes)
    this_player()->set_notes(({}));

  s_notes = sizeof(notes);
  if(!arg)
  {
  /* display notes */
    write("\t\t\tNotes:\n\n")
    for(i = 0; i < s_notes; i ++)
    {
      write("\t"+(i+1)+": "+format(notes[i],70)+"\n")
    }
    write("\n");
    return 1;
  }
  else sscanf(arg, "%s %s", verb, note)
  {
    switch(verb)
    {
      case "view":
        return cmd_notes();
      case "add":
        /* add note */
        notes += ({ note });
        write("Ok.\n");
        this_player()->set_notes(notes);
        return 1;
      case "delete":
        int note_num;
      /* delete note */
        note_num = get_note_num(note, s_notes);
        if(note_num)
        {
          notes -= ({ notes[note_num-1] });
        }
        return 1;
      case "share":
      /* share note */
        note_num = get_note_num(note, s_notes);
        if(note_num)
        {
          command("say Note #"+note_num+": "+notes[note_num-1], this_player());
        }
        return 1;
      case "move":
        note_num = get_note_num(note, s_notes);
        if(note_num)
        {
          if(timer)
          {
            write("System glitch.  Someone else is moving notes right now.\n");
          }
          else
          {
            timer=time();
            tmp_notes = notes;
            tmp_noter_sz = s_notes;
            tmp_notenum_new = 0;
            tmp_notenum_old = 0;
            input_to("move_note_request");
            write("Enter note number to move: ")
            return 1;
          }
        }
        return 1;
      default:
        write("Usage: 'notes [view|add|delete|share|move]'.\n");
        return 1;
    }
  }
}

int get_note_num(string str, int s_notes)
{
  int note_num;
  if(sscanf(str,"%d",note_num) != 1)
  {
    write("Error: You must specify a note number.\n");
    return 0;
  }
  else if(note_num < 1)
  {
    write("Error: Invalid note number.\n");
    return 0;
  }
  else if(note_num > (s_notes + 1))
  {
    write("Error: You don't have that many notes.\n");
    return 0;
  }
  else
    return note_num;
}

status check_timeout()
{
  if((time() + 60) > timer)
  {
    timer = 0;
    write("Error: Timed out.\n");
    return 1;
  }
  else
  {
    return 0;
  }
}

void display_note(int note_num)
{
  write("Note #"+note_num+":\n\n");
  write(tmp_notes[note_num-1]+"\n\n");
}

void move_note_request(string str)
{
  if(check_timeout())
    return;
  
  tmp_notenum_old = get_note_num(str, tmp_noter_sz);
  
  if(!tmp_notenum_old)
  {
    timer = 0;
    return;
  }
  else
  {
    display_note(tmp_notenum_old);
    write("Enter position to move this note to: ");
    timer = time();
    input_to("move_note_final");
    return;
  }
}

void move_note_final(string str)
{
  if(check_timeout())
    return;
  
  tmp_notenum_new = get_notenum(str, tmp_noter_sz);
  
  if(!tmp_notenum_new)
  {
    timer = 0;
    return;
  }
  
  else
  {
    int i;
    string *new_notes;
    string old_note;
    
    if(tmp_notenum_new > tmp_noter_sz)
      tmp_notenum_new = tmp_noter_sz;
    
    old_note = tmp_notes[tmp_notenum_old-1];
    tmp_notes -= ({ old_note });
    new_notes = ({});
    
    for(i = 0; i < (tmp_noter_sz-1); i++)
    {
        if((i+1) == tmp_notenum_new)
          new_notes += ({ old_note });
        else
          new_notes += tmp_notes[i];
    }
    this_player()->set_notes(new_notes);
    timer=0;
    write("Ok.  Notes updated.\n");
  }
}
