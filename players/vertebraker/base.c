mapping vars;

void reset(status arg)
{
  if(arg) return;
  vars = ([]);
}

void set(mixed name, mixed what)
{
  vars[name]=what;
}

void add(mixed name, mixed what)
{
  vars[name]+=what;
}

void delete(mixed name, mixed what)
{
  vars[name]-=what;
}

mixed query(mixed name)
{
  return vars[name];
} 