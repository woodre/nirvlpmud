#define REPORT_SAVE "obj/user/reports/reports"

string *typo_files;
mixed  *typo_names;
mixed  *typo_reports;
mixed  *typo_dates;

string *bug_files;
mixed  *bug_names;
mixed  *bug_reports;
mixed  *bug_dates;

string *idea_files;
mixed  *idea_names;
mixed  *idea_reports;
mixed  *idea_dates;

/*
#define STAMP ctime()[4..15]
*/
#define STAMP ctime(time())[4..15]+" "+ctime(time())[20..23]

void reset(int x) {
  if(x) return;
  
  if(!restore_object(REPORT_SAVE)) {
    typo_files = bug_files = idea_files = ({ });
    typo_names = typo_reports = typo_dates =
    idea_names = idea_reports = idea_dates =
    bug_names = bug_reports = bug_dates = ({ });    
  }
}

void save_me()
{
  save_object(REPORT_SAVE);
}
  
void add_bug(string file, string nm, string rep)
{
  int i;
  if((i = member_array(file, bug_files)) == -1)
  {
    bug_files   += ({ file });
    bug_names   += ({ ({ nm }) });
    bug_reports += ({ ({ rep }) });
    bug_dates   += ({ ({ STAMP }) });
  }
  else {
    bug_names[i] += ({ nm }); 
    bug_reports[i] += ({ rep });
    bug_dates[i] += ({ STAMP });
  }
  save_me();
}

mixed * query_bug()
{
  return ({ bug_files, bug_names, bug_reports, bug_dates });
}

void add_idea(string file, string nm, string rep)
{
  int i;
  if((i = member_array(file, idea_files)) == -1)
  {
    idea_files   += ({ file });
    idea_names   += ({ ({ nm }) });
    idea_reports += ({ ({ rep }) });
    idea_dates   += ({ ({ STAMP }) });
  }
  else {
    idea_names[i] += ({ nm }); 
    idea_reports[i] += ({ rep });
    idea_dates[i] += ({ STAMP });
  }
  save_me();
}

mixed * query_idea()
{
  return ({ idea_files, idea_names, idea_reports, idea_dates });
}

void add_typo(string file, string nm, string rep)
{
  int i;
  if((i = member_array(file, typo_files)) == -1)
  {
    typo_files   += ({ file });
    typo_names   += ({ ({ nm }) });
    typo_reports += ({ ({ rep }) });
    typo_dates   += ({ ({ STAMP }) });
  }
  else {
    typo_names[i] += ({ nm }); 
    typo_reports[i] += ({ rep });
    typo_dates[i] += ({ STAMP });
  }
  save_me();
}

mixed * query_typo()
{
  return ({ typo_files, typo_names, typo_reports, typo_dates });
}

#include "/obj/simul_efun/a_delete.c"

void delete_idea(int x)
{
    idea_files   = a_delete(x, idea_files);
    idea_names   = a_delete(x, idea_names);
    idea_reports = a_delete(x, idea_reports);
    idea_dates   = a_delete(x, idea_dates);
  save_me();
}

void delete_bug(int x)
{
    bug_files   = a_delete(x, bug_files);
    bug_names   = a_delete(x, bug_names);
    bug_reports = a_delete(x, bug_reports);
    bug_dates   = a_delete(x, bug_dates);
    save_me();
}

void delete_typo(int x)
{
    typo_files   = a_delete(x, typo_files);
    typo_names   = a_delete(x, typo_names);
    typo_reports = a_delete(x, typo_reports);
    typo_dates   = a_delete(x, typo_dates);
    save_me();
}
