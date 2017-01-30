/******************************************************************************
 *
 *  File:         id_obj.c
 *
 *  Function:     provide id functions for other objects
 *
 *  Author(s):    Vital
 *
 *  Copyright:    Copyright (c) 2007 Vital-Dev
 *                All Rights Reserved.
 *
 *  Source:       Started anew.
 *
 *  Notes:      
 *
 *  Change History:
 *      30/05/2007    Added Header
 *  
 *****************************************************************************/

#pragma strict_types

static string *ids;                /*  Array of id strings   */
static string name, alias;         /*  Possible ids          */
static string alt, alt_name, id;

void set_id(string str);
void set_name(string str);
void set_alias(string str);
void set_alt(string str);
void set_alt_name(string str);
void set_ids(string *str);

int
id(string str)
{
 if(!ids) ids = ({ });
 return ( str == name ||
          str == alias ||
          str == alt_name ||
          str == alt ||
          (member_array(str,ids) > -1));
}

void
set_id(string str)
{
  id = str;
}

void
set_name(string str)
{
  set_id(str);
  name = str;
  if (!alias) set_alias(str);
  if (!alt) set_alt(str);
  if (!alt_name) set_alt_name(str);
}

void
set_alias(string str)
{
  alias = str;
  if (!alt) set_alt(str);
  if (!alt_name) set_alt_name(str);
}

void
set_alt(string str)
{
  alt = str;
  if (!alias) set_alias(str);
  if (!alt_name) set_alt_name(str);
}

void
set_alt_name(string str)
{
  alt_name = str;
  if (!alias) set_alias(str);
  if (!alt) set_alt(str);
}

void
set_ids(string *str)
{
 ids = str;
}

array
query_ids()
{
 return ids;
}

