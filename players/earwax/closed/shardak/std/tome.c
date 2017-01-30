#include "../include/ansi.h"
#include "../def.h"
#include "security.h"

int curr_page, torn_pages, max_pages, *tpgs;
mapping Pages;
string title, ppath, colour;
status open;

void
reset(status arg)
{
    if(arg) return;

    curr_page = 1;
    ppath = "/players/earwax/";
    title = "Nothing";

    switch(random(5))
    {
      case 0: colour = HIM; break;
      case 1: colour = HIR; break;
      case 2: colour = HIB; break;
      case 3: colour = HIC; break;
      case 4: colour = HIY; break;
    }

    if(!root())
    {
      max_pages = sizeof(get_dir(ppath));
      tpgs = ({ });
    }
}

void
load_pages(string heh) 
{
    max_pages = sizeof(get_dir(ppath = heh));
}

string
short()
{
    return "The Tome of " + title + " " + colour + "[enchanted]" + NORM
           + " (" + (open ? "open" : "closed") + ")";
}

void
long()
{
    int diff;

    write("\
The long forgotten Tome of " + title + ".\n\
It contains magical scribblings handed down from the former\n\
Worshippers of Shardak, written in blood.  The pages are\n\
bound in human flesh, and strange scrawlings decorate the\n\
face of this book.\n");

    if(open)
    {
      if(curr_page)
        write("It is open to page " + curr_page + ".\n");
      else
        write("It is open.\n");
    }
    else if(!open)
      write("It is closed.\n");

    switch(torn_pages)
    {
      case 0: break;
      case 1: write("A page is missing.\n"); break;
      case 2..4: write("Several pages are missing.\n"); break;
      default: write("Many pages are missing.\n"); break;
    }
}

status
get()
{
    object x;

    if((x = this_player()) && 
     (((string)x->query_guild_name() == GUILDNAME)
      || (int)x->query_level() >= APPRENTICE))
      return 1;
}

int
query_weight()
{
    return 1;
}

void
init()
{
    add_action("cmdOpen", "open");
    add_action("cmdClose", "close");
    add_action("cmdRead", "read");
    add_action("cmdTurn", "turn");
    add_action("cmdTear", "tear");
    add_action("cmdTear", "rip");
}

status
id(string str)
{
    return (str == "tome" || str == "tome of " + lower_case(title) ||
       str == "the tome" || str == "the tome of " + lower_case(title));
}

status
all_pages_torn()
{
    return (sizeof(tpgs) == max_pages);
}

int
recalc_page(int pg)
{

    if(pg > max_pages) return 0;

    while(pg < (max_pages + 1))
    {
      if(member_array(pg, tpgs) == -1)
        return pg;
      pg ++;
    }

    return 0;
}

int
pick_back(int pg)
{
   while(pg > 0)
   {
     if(member_array(pg, tpgs) == -1 && pg <= max_pages)
       return pg;
     pg --;
   }

   return 0;
}


int
invalid_page(int page)
{
    if(page <= 0)
      return 1;
    if(page > max_pages)
      return 3;
    if(!torn_pages)
      return 0;
    if(member_array(page, tpgs) != -1) return 2;
}
    

status
cmdRead(string arg)
{
    int pg, heh;

    if(!arg)
    {
      notify_fail("Read what?\n");
      return 0;
    }
    if((string)this_player()->query_guild_name() != GUILDNAME)
    {
      write("You cannot understand this magikal text.\n");
      return 1;
    }
 
    if(id(arg) || arg == "page")
    {
      if(!open)
      {
        notify_fail("The book is not open.\n");
        return 0;
      }

      if(all_pages_torn())
      {
        curr_page = 0;
        write("There aren't any pages left.\n");
        return 1;
      }

      if(invalid_page(curr_page) == 3)
      {
         /* this better not happen */
        if(!(curr_page = pick_back(curr_page)))
        {
          write("There aren't any pages left.\n");
          return 1;
        }
      }

      say((string)this_player()->query_name() + " \
reads from The Tome of " + title + ".\n");
      write(BOLD + "\tYou read page " + curr_page + ".\n\n" + NORM);
      cat(ppath + "" + curr_page);
      return 1;
    }

    if(sscanf(arg, "page %d", pg))
    {
      if(!open)
       {
        notify_fail("The book is not open.\n");
        return 0;
      }
      if(heh = invalid_page(pg))
      {
        switch(heh)
        {
          case 1:
            write("You can't turn to page 0!\n");
            break;
          case 2:
            write("That page is missing.\n");
            break;
          case 3:
            write("There aren't that many pages.\n");
            break;
        }
        return 1;
      }
      write(BOLD + "\tYou turn to page " + pg + " and read.\n\n" + NORM);

      say((string)this_player()->query_name() + " \
flips through The Tome of " + title + ".\n" +
capitalize(subjective(this_player())) + " begins reading.\n");

      cat(ppath + "" + (curr_page = pg));
      return 1;
    }

    notify_fail("You may read the tome if you wish.\n");
    return 0;
}

status
cmdOpen(string arg)
{
    if(!arg)
    {
      notify_fail("Open what?\n");
      return 0;
    }
    if(!id(arg))
    {
      notify_fail("You may open the tome if you wish.\n");
      return 0;
    }
    if(open)
    {
      write("The Tome of " + title + " is already open.\n");
      return 1;
    }
    if((string)this_player()->query_guild_name() != GUILDNAME)
    {
      write("You cannot pry open the Tome of " + title + ".\n");
      return 1;
    }
    write("\
You slowly open up the magical Tome of " + title + ".\n");
    say((string)this_player()->query_name() + " slowly opens up \
the magical Tome of " + title + ".\n");
    open ++;
    return 1;
}


status
cmdClose(string arg)
{
    if(!arg)
    {
      notify_fail("Close what?\n");
      return 0;
    }
    if(!id(arg))
    {
      notify_fail("You may close the tome if you wish.\n");
      return 0;
    }
    if(!open)
    {
      notify_fail("The Tome of " + title + " is already closed.\n");
      return 0;
    }
    write("You close the Tome of " + title + ".\n");
    say((string)this_player()->query_name() + " slowly closes the \
Tome of " + title + ".\n");
    open --;
    return 1;
}

status
cmdTear(string arg)
{
    int pg, r, h;
    string me;
    object x;

    if(!arg)
    {
      notify_fail("Tear out what?\n");
      return 0;
    }

    if(arg == "page" || arg == "out page" ||
       arg == "the page" || arg == "out the page" ||
       sscanf(arg, "page %d out from %s", pg, me) ||
       sscanf(arg, "the page out from %s", me) ||
       sscanf(arg, "the page from %s", me) ||
       sscanf(arg, "out page %d", pg))
    {
      if(!pg) pg = curr_page;

      if(me && !id(me))
      {
        notify_fail("What would you like to tear the page from?\n");
        return 0;
      }

      if(!open)
      {
        notify_fail("The book is not open.\n");
        return 0;
      }
      r = invalid_page(pg);
      if(r == 1)
      {
        write("You can't tear that out.. that would be impossible.\n");
        return 1;
      }
      if(r == 2)
      {
        write("That page has already been torn out.\n");
        return 1;
      }
      if(r == 3)
      {
        write("There aren't that many pages.\n");
        return 1;
      }
      write(BOLD + "\tYou tear out page " + pg + ".\n" + NORM);
      say((string)this_player()->query_name() + " tears out a page \
from The Tome of " + title + ".\n");
      x=clone_object("/obj/treasure");
      x->set_short("A torn paper [" + RED + "bloody" + NORM + "]");
      x->set_id("paper");
      x->set_alias("torn paper");
      x->set_weight(0); /* for a reason */
      x->set_value(0);
#define meth (ppath + "" + pg)
      x->set_read(read_bytes(meth, 0, file_size(meth)));
#undef meth
      x->set_long("\
A bloody, nasty looking piece of paper, with some\n\
words on it that you may be able to read.\n");
      move_object(x, this_player());
      torn_pages ++;
      tpgs += ({ pg });

      if(all_pages_torn())
      {
        curr_page = 0;
        write("There aren't any more pages remaining in the book.\n");
        return 1;
      }
      if(!(h = recalc_page(curr_page)))
        if(!(h = pick_back(curr_page))) /* this shouldn't happen */
        {
          curr_page = 0;
          write("There aren't any more pages remaining in the book.\n");
          return 1;
        }

      write(BOLD + "\tYou flip to page " + h + ".\n\n" + NORM);
      curr_page = h;

      return 1;
    }

    notify_fail("Tear out what from what?\n");
    return 0;
}
      
status
query_save_flag()
{
    write("The tome glows " + CYN + "softly" + NORM + ".\n");
    return 1;
}

string
query_name()
{
    return "The Tome of " + title;
}

status
cmdTurn(string arg)
{
    int num, bog;

    if(!open) return 0;

    if(!arg)
    {
      notify_fail("You may turn the page.\n");
      return 0;
    }
    if(arg == "back")
    {
      if(all_pages_torn())
      {
        write("All the pages have been torn out.\n");
        return 1;
      }
      if(!pick_back(curr_page - 1))
      {
        write("You can't go back any further.\n");
        return 1;
      }
      else
      {
      write(BOLD + "\tYou turn back to page " + (curr_page = pick_back(curr_page - 1)) + ".\n\n" + NORM);
        return 1;
      }
    }
    if(!id(arg) && arg != "page" && arg != "the page")
    {
      if(sscanf(arg, "to page %d", num) ||
         sscanf(arg, "page %d", num))
      {
        switch(bog = invalid_page(num)) 
        {
          case 1: write("You can't turn to that page...\n"); return 1;
          case 2: write("That page has been torn out!\n"); return 1;
          case 3: write("There aren't that many pages.\n"); return 1;
        }          
        write(BOLD + "\tYou turn to page " + num + "...\n\n" + NORM);
        curr_page = num;
        cmdRead("page");
        return 1;
      }
      notify_fail("Turn what?\n");
      return 0;
    }
    if(all_pages_torn())
    {
      write("\
All the pages have been torn out of the Tome of " + title + ".\n");
      return 1;
    }

    if(!recalc_page(curr_page + 1))
    {
      write("You are on the last page.\n");
      return 1;
    }

    else curr_page = recalc_page(curr_page + 1);
      write(BOLD + "\tYou turn to page " + curr_page + "...\n\n" + NORM);

      cmdRead("page");
    return 1;
}
