/****************************************************************************
      body.c -- written by Alfe, Chameloid and Ugh for Tubmud
****************************************************************************/

// ATTENTION: This file is still in work and will probably still change a lot
// in the nearer future. Please don't use it in your code, yet

private mapping body_data;

status
query_bodypart(mixed part)
{
  return body_data && part && member(body_data,part);
}

void
set_body_data(mixed part, string data_type, mixed data)
{
  if (!(body_data && part && data_type))
    body_data = ([]);
  if (!member(body_data,part))
    body_data[part] = ([]);
  body_data[part][data_type] = data;
}

varargs void
remove_body_data(mixed part, string data_type)
{
  if (!query_bodypart(part))
    return;
  if (data_type)
    m_delete(body_data[part],data_type);
  else
    m_delete(body_data,part);
}

mixed
get_body_data(mixed part, string data_type)
{
  if (!query_bodypart(part))
    return 0;
  if (!data_type)
    return body_data[part];
  else
    return body_data[part][data_type];
}

status
has_body_data(mixed part, string data_type)
{
  return
    query_bodypart(part) &&
    member(body_data[part],data_type);
}
