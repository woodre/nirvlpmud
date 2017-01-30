/* *************************************************************************
 * 
 * Patch
 *
 * - Earwax 09/15/03
 *
 * Patch command for my wiztool.
 *
 * According to Boltar and the updated rules for wiztools, it's legal if
 * it's coded by the user, so don't go demoting me or bitching at me about
 * this if you're reading this and don't like it.  It's a very useful, if
 * not necessary, tool for the coding and testing of code I do.
 *
 * ************************************************************************* 
 *
 * Support for up to 2 args.
 * 'near' means environment of
 * 'in' means inside
 * Also checks my nicknames for matches
 * Should also have very limited array tracing as well.
 *
 * Syntax:
 * p armor in player,armor_class
 * p weapon near monster,weapon_class
 * p player,query_weapon
 * p player,set_title,The fungus among us
 * p player,set_attribs,str,5
 *
 * NOTE: Add checks for the functions existing, or a catch() to make sure
 *       that it's a valid function call.
 * 
 *       Also, it probably needs better array tracing than it has right now.
 *       Worry about that shit later.
 *
 * *************************************************************************
*/

#include "../defs.h"

#pragma weak_types

/* heh, haven't coded nicknames for my tool yet, it's a later project
inherit NICKNAMES;
*/
inherit WAXFUNS;

/* *************************************************************************
 * not_found
 *
 * Yes, I'm THAT lazy :)
*/

object
not_found(string arg)
{
  write("Object not found: "+arg+"\n");
  return 0;
}

/* *************************************************************************
 * return object
 *
 * Find the object to patch.
*/

object
return_object(string what, object where)
{
  string str;
  object ob;

/*
  what = query_nickname(what);
*/

  if (!where)
  {
    ob = present(what,this_player());
    if (!ob) ob = present(what,environment(this_player()));
    if (!ob) ob = find_player(what);
/* This is supposedly buggy
    if (!ob) ob = find_living(what);
*/
    if (!ob) ob = find_object(what);
    if (!ob) return 0;
    return ob;
  }

  ob = present(what,where);
  if (ob) return ob;
  else return 0;
}

/* *************************************************************************
 * parse_what
 *
 * I imagine this will get huge over time as I add more syntax and
 * capabilities to this thing.  For now, I'm trying to just leave as much
 * room for improvement as possible.
*/

object
parse_what(string arg)
{
  string what, where;
  object ob;

  what = arg;

/*
  what = query_nickname(what);
*/

  if (what == "me") return this_player();
  if (what == "here") return environment(this_player());

  /* I can do this a lot more efficiently, but I like very explicit error
   * messages. */

  /* Near means environment of */
  if (sscanf(arg, "near %s", where) == 1)
  {
    ob = return_object(where,0);
    if (!ob) return not_found(where);
    if (environment(ob)) ob = environment(ob);
    if (!ob) return not_found("Environment of "+where);
    return ob;
  }

  if (sscanf(arg, "%s near %s", what, where) == 2)
  {
    ob = return_object(where,0);
    if (!ob) return not_found(where);
    ob = environment(ob);
    if (!ob) return not_found("Environment of "+where);
    ob = return_object(what,ob);
    if (!ob) return not_found(arg);
    return ob;
  }

  /* In means inside */
  if (sscanf(arg, "%s in %s", what, where) == 2)
  {
    ob = return_object(where,0);
    if (!ob) return not_found(where);
    ob = return_object(what,ob);
    if (!ob) return not_found(arg);
    return ob;
  }

  ob = return_object(arg,0);
  if (!ob) return not_found(arg);
  return ob;
}  

/* *************************************************************************
 * Output Functions
 *
 * Main determines what kind of output is returned.
 * These functions do the outputting.
*/

/* 
 * Mainly here for testing the array tracing with users().  May expand this
 * later, however, if it will be worth it.
 * Possible ways to expand:
 * Check for monster (living), weapon, armor, treasure, other, and show
 * short for them.
*/

status
ob_info(object ob)
{

  if ((string)ob->is_player())
  {
    write("(PlayerOb): "+capitalize((string)ob->query_real_name())+"\n");
    return 1;    
  }
  return 0;
}

void
display_subarray(mixed *stuffs)
{
  int i, siz;

  siz = sizeof(stuffs);
  for (i = 0; i < siz; i++)
    write(stuffs[i]+"\t");   /* keep it real simple for now */
  write("\n");
}

void
display_array(mixed *stuffs)
{
  int i, siz;

  siz = sizeof(stuffs);
  write("Result: ARRAY of size "+siz+"\n");
  if (!siz) return;
  if (pointerp(stuffs[i]))
    write("Subarray: \n");

  for (i = 0; i < siz; i++)
  {
    if (pointerp(stuffs[i]))             /* if it works, it'll be ugly */
      display_subarray(stuffs[i]);       /* not sure if this is wise */
    else if (objectp(stuffs[i]))         /* For testing it with users() */
    {
      if (!ob_info(stuffs[i]))
        write("OBJECT: "+pad(file_name(stuffs[i]), 50)+"\t"+((string)stuffs[i]->short() ? (string)stuffs[i]->short() : "INVIS OBJECT")+"\n");
    }
    else
      write(stuffs[i]+"\n");             /* what should usually happen */
  }
}

void
display_results(mixed result)
{
write("Let's see how typeof works: "+typeof(result)+"\n");
  write("Result ");

  if (intp(result))                    /* It's an int */
    write("(int): "+result+"\n");
  else if (stringp(result))            /* It's a string */
    write("(string): "+result+"\n");
  else if (objectp(result))            /* It's an object */
  {
    if (!ob_info(result))
      write("(object): "+file_name(result)+"\n"); /* may expand this part later */
  }
  else if (pointerp(result))
    write("(pointer):" + "\n");        /* shouldn't happen */
  else
    write("(unknown): "+result+"\n");  /* nor should this */
}

/* *************************************************************************
 * main
 *
 * Break the argument apart
 * Parse it to find out what to patch
 * Find the object to patch
 * Ensure int arguements are passed to funs as int
 * Patch it
 * Output the results
*/

status
main(string arg)
{
  mixed *results, *st;
  mixed result;
  object target;
  string callee, fun, str1, str2;
  int i, j, int1, int2;
  status flag_array;

  if (query_verb() == "pt")
    flag_array = 1;

  i = sizeof(st = explode(arg,","));

  if (!i)
  {
    write("Must supply a function to call.\n");
    return 1;
  }

  if (i < 2)
  {
    write("What function do you wish to call?\n");
    return 1;
  }

  callee = st[0]; fun = st[1];
  i -= 2;

  if (i)
  {
    for (j = 0; j < i; j++)
      if (!st[j+2] || st[j+2] == 0)
        st[j+2] = "0";

    arg = implode(st[2..i+2], ",");
  }

  target = parse_what(callee);
  if (!target) return 1;

  if (!function_exists(fun, target))
  {
    write("Function does not exist.\n");
    return 1;
  }

  if (i < 1)
  {
    if (flag_array)
    {
      results = (mixed*)call_other(target,fun);
      display_array(results);
      return 1;
    }
    result = (mixed)call_other(target,fun);
    display_results(result);
    return 1;
  }

  if (i == 1)
  {
    if (flag_array)
    {
      if (sscanf(arg+"","%d"+"",int1) == 1)
        results = (mixed*)call_other(target,fun, int1);
      else
        results = (mixed*)call_other(target,fun, arg);

      display_array(results);
      return 1;
    }
    if (sscanf(arg+"","%d"+"",int1) == 1)
      result = (mixed)call_other(target,fun, int1);
    else
      result = (mixed)call_other(target,fun, arg);

    display_results(result);
    return 1;
  }
    
  /* Make sure that if the arg is an int, it's passed as one */

  if (flag_array)
  {
    if (sscanf(arg,"%d,%d",int1,int2) == 2)
      results = (mixed*)call_other(target,fun, int1, int2);
    else if (sscanf(arg,"%d,%s",int1,str1) == 2)
      results = (mixed*)call_other(target,fun, int1, str1);
    else if (sscanf(arg,"%s,%d",str1,int1) == 2)
      results = (mixed*)call_other(target,fun, str1, int1);
    else if (sscanf(arg,"%s,%s",str1,str2) == 2)
      results = (mixed*)call_other(target,fun, str1, str2);
    else
    {
      write("Arguement did not parse: "+arg+"\n");
      return 1;
    }
    display_array(results);
    return 1;
  }
  if (sscanf(arg,"%d,%d",int1,int2) == 2)
    result = (mixed)call_other(target,fun, int1, int2);
  else if (sscanf(arg,"%d,%s",int1,str1) == 2)
    result = (mixed)call_other(target,fun, int1, str1);
  else if (sscanf(arg,"%s,%d",str1,int1) == 2)
    result = (mixed)call_other(target,fun, str1, int1);
  else if (sscanf(arg,"%s,%s",str1,str2) == 2)
    result = (mixed)call_other(target,fun, str1, str2);
  else
  {
    write("Arguement did not parse: "+arg+"\n");
    return 1;
  }

  display_results(result);
  return 1;

}

/* Removing this for now, ints should pass properly.
 * For making sure the mixed* works properly 
for (j = 2; j < i; j++) {
  write(j+")\t"+st[j]+" ");
  if (stringp(st[j])) write(st[j]+": (STRING)");
  if (intp(st[j]))     write(st[j]+": (INT)");
  write("\n");
}
*/


    

