/*******************************************************************************	/basic/job.c by Ugh in March 1994 for Tubmud - an inheritable
	job-interface, which makes adding jobs to the server easy
*******************************************************************************/

#include <jobs.h>

/*
 * add_job can get up to four arguments:
 * 1.) the function string of the function, which should be called
 *     initally (when beginning the job) in the function-handler
 *     or: a closure to be called with the job as argument 
 *	(the handler will be ignored in this case, but can still be
 *	  used by the job)
 * 2.) a mapping containing the data which should be passed to the 
 *     job and the function, which will be called with this mapping,
 *     being able to change the data in the course
 * 3.) either a string or the number 1 (0 is converted to 1) which discerns,
 *     if the output of the job (which your handling function would have to
 *     put into the field J_RESULT, if there is some) is a file (the
 *     string being the file-name) or the screen of the player
 *     who gave the command which started the job 
 * 4.) the handler (given as string or object-pointer) where the function
 *     to be called resides in (per default this_object() is taken)
 *
 * When called, this function builds a job and adds it to the job-queue
 * of the calling user in the job-server, where it will be evaluated,
 * when the time to do so has come. :)
 *
 * It also returns the job-number of the inserted job, or 0 on error.
 */

varargs static int
add_job (string func, mapping job, mixed output, mixed handler, 
	  mixed privilege)
{
    int result;
    if (!func || (!stringp (func) && 
			!closurep (func))) return 0;
    if (!job) job = m_allocate (5, 1);
    job += ([J_HANDLER: (handler || this_object()),
    	     J_FUNCTION: func, 
	     J_OUTPUT: (output || 1) ]);
    return JOB_SERVER->add_job (job, privilege || 
				     get_privilege (this_object ()));
}
