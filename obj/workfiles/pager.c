/* obj/pager.c
 *  -- Rumplemintz
 * page through a string, nothing fancy
 */

#define PAGE_LENGTH 15

object caller;
string caller_fn;

string *txt;
int position;

status id(string str) { return str == "page"; }
string query_name()   { return "pager"; }

static void
quit()
{
  if (caller)
  {
    call_other(caller,"pager_quit", caller_fn);
  }
  destruct(this_object());
}

status
drop()
{
  quit();
  return 1;
}

void
do_page(string answer)
{
  int next;

  if (answer == "q")
  {
    write("Ok.\n");
    quit();
    return;
  }
  if (answer == "b")
  {
    position = position - (2 * PAGE_LENGTH);
    if (position < 0) position = 0;
  }
  next = position + PAGE_LENGTH;
  if (next > sizeof(txt)-1)
    next = sizeof(txt)-1;
  write(implode(txt[position..next],"\n") + "\n");
  if (next != sizeof(txt) -1)
  {
    position = next + 1;
    write("\nContinue (y/q/b) [y]: ");
    input_to("do_page");
  }
  else
  {
    write("Ok.\n");
    quit();
  }
}

void
page(string str, string return_fn)
{
  caller = previous_object();
  caller_fn = return_fn;
  if (!str)
  {
    quit();
    return;
  }
#ifdef OLD_EXPLODE
  txt = explode(str +"\n","\n");
#else
  txt = explode(str,"\n");
#endif
  if (txt[sizeof(txt)-1] == "")
    txt = txt[0..(sizeof(txt)-2)];
  position = 0;
  do_page("y");
}
