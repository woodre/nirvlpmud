
/*
 * Simulate compat efuns needed for Nirvana
 */
 

//---------------------------------------------------------------------------
varargs string cat(string file, int start, int block) {
  string str;

  if(!file) return 0;
  if(!block) block = 45;
  if(!(str = read_file(file,start,block))) {
    str = read_file(file,start);
  }
  if(str) write(str);
  return str;
}
//---------------------------------------------------------------------------
string function_exists (string str, object ob)
{
    string rc;

    rc = efun::function_exists(str, ob);
    return stringp(rc) ? rc[1..] : 0;
}

//---------------------------------------------------------------------------
string file_name(object ob)
{
    string rc;

    rc = efun::object_name(ob);
    return stringp(rc) ? rc[1..] : 0;
}

//---------------------------------------------------------------------------
string object_name(object ob)
{
    string rc;

    rc = efun::object_name(ob);
    return stringp(rc) ? rc[1..] : 0;
}

//---------------------------------------------------------------------------
varargs string program_name(object ob)
{
    string rc;

	if(ob)
    	rc = efun::program_name(ob);
    else rc = efun::program_name();
    return stringp(rc) ? rc[1..] : 0;
}

//---------------------------------------------------------------------------
string* inherit_list(object ob)
{
    string *rc;
    int i;

    rc = efun::inherit_list(ob);
    for (i = sizeof(rc); i-- > 0; )
        rc[i] = rc[i][1..];
    return rc;
}

//---------------------------------------------------------------------------
string to_string(mixed arg)
{
    string rc;

    rc = efun::to_string(arg);
    return objectp(arg) ? rc[1..] : rc;
}

//---------------------------------------------------------------------------
string creator(object ob)
{
    return getuid(ob);
}

#if 0
//---------------------------------------------------------------------------
varargs void add_action(string fun, string cmd, int flag)
{
    if (fun == "exit")
        raise_error("Illegal to define a command to the exit() function.\n");

    efun::set_this_object(previous_object());
    if (cmd)
        efun::add_action(fun, cmd, flag);
    else /* historic usage */
        efun::add_action(fun);
}
#endif

//---------------------------------------------------------------------------
object present_clone (mixed obj, object env)
{
  if (stringp(obj) && '/' != obj[0])
      obj = "/"+obj;
  return efun::present_clone(obj, env);
}

//---------------------------------------------------------------------------

#if !__EFUN_DEFINED__(present)
//---------------------------------------------------------------------------
varargs object present(mixed ob, object env)
{
    int specific, num, i;
    object found;
    string str;

    if (!env)
    {
        env = previous_object();
        specific = 0;
    }
    else
        specific = 1;

    if (objectp(ob))
    {
        /* Quick check: is ob there or not? */

        if (specific)
            return environment(ob) == env ? ob : 0;
        if (environment(ob) == env
         || (environment(env) && environment(ob) == environment(env))
           )
            return ob;
        return 0;
    }

    /* Search by name. Prepare the search parameters */
    if (2 != sscanf(ob, "%s %d", str, num))
    {
        num = 1;
        str = ob;
    }

    /* First, search in env by name */
    for (found = first_inventory(env), i = 0
        ; found
        ; found = next_inventory(env))
    {
        if (found->id(str) && ++i == num)
            break;
        if (!found)  /* may happen */
            break;
    }

    if (found || specific)
        return found;

    /* If not found, search in environment(env) by name */
    env = environment(env);
    if (!env)
        return 0;
    if (env->id(ob))
        return env;
    if (!env) /* the id() may have destructed env */
        return 0;

    for (found = first_inventory(env), i = 0
        ; found
        ; found = next_inventory(env))
    {
        if (found->id(str) && ++i == num)
            break;
        if (!found)  /* may happen */
            break;
    }

    return found;
}

#endif /* !efun_defined(present) */

#if !__EFUN_DEFINED__(transfer)
//---------------------------------------------------------------------------
/*
 * Transfer an object from an object to an object.
 * Call add_weight(), drop(), get(), prevent_insert(), add_weight(),
 * and can_put_and_get() where needed.
 * Return 0 on success, and special code on failure:
 *
 * 1: To heavy for destination.
 * 2: Can't be dropped.
 * 3: Can't take it out of it's container.
 * 4: The object can't be inserted into bags etc.
 * 5: The destination doesn't allow insertions of objects.
 * 6: The object can't be picked up.
 */
int transfer(object item, object dest)
{
    int weight;
    object from;

    efun::set_this_object(previous_object());

    weight = item->query_weight();
    if (!item)
        return 3;

    from = environment(item);
    if (from)
    {
        /*
         * If the original place of the object is a living object,
         * then we must call drop() to check that the object can be dropped.
         */
        if (living(from))
        {
            if (item->drop() || !item)
                return 2;
        }
        /*
         * If 'from' is not a room and not a player, check that we may
         * remove things out of it.
         */
        else if (environment(from))
        {
            if (!from->can_put_and_get() || !from)
                return 3;
        }
    }

    /*
     * If the destination is not a room, and not a player,
     * Then we must test 'prevent_insert', and 'can_put_and_get'.
     */
    if (environment(dest) && !living(dest))
    {
        if (item->prevent_insert())
            return 4;
        if (!dest->can_put_and_get() || !dest)
            return 5;
    }

    if (living(dest))
    {
        if (!item->get() || !item)
            return 6;
    }

    /*
     * If it is not a room, correct the total weight in the destination.
     */
    if (environment(dest) && weight)
    {
        if (!dest->add_weight(weight) || !dest)
            return 1;
    }

    /*
     * If it is not a room, correct the weight in the 'from' object.
     */
    if (from && environment(from) && weight)
    {
        from->add_weight(-weight);
    }

    move_object(item, dest);

    return 0;
}

#endif /* !efun_define(transfer) */

#if !__EFUN_DEFINED__(extract)
//---------------------------------------------------------------------------
mixed extract (mixed data, varargs mixed*from_to)

{
    int from, to;

    if (!stringp(data) && !pointerp(data))
    {
        raise_error("Illegal type for extract(): must be string or array.\n");
        return 0;
    }

    switch(sizeof(from_to))
    {
    case 0: return data;
    case 1:
        if (!intp(from_to[0]))
        {
            raise_error("Illegal 'from' index for extract(): must be a number.\n");
            return 0;
        }
        from = from_to[0];
        if (from >= 0)
            return data[from..];
        return data[<-from..];
    case 2:
        if (!intp(from_to[0]) || !intp(from_to[1]))
        {
            raise_error("Illegal index for extract(): must be a number.\n");
            return 0;
        }
        from = from_to[0];
        to = from_to[1];
        if (from >= 0)
        {
            if (to >= 0)
                return data[from..to];
            return data[<from..<-to];
        }
        if (to >= 0)
            return data[<-from..to];
        return data[<from..<-to];
    }

    raise_error("Illegal number of arguments for extract().\n");
    return 0;
}

#endif /* !efun_defined(extract) */

/*************************************************************************/

