#include <grp.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define LOGNAME		"Login name:"
#define UID			"UID:"
#define HOMEDIR		"Home Directory:"
#define DEFSHELL	"Default Shell:"
#define DEFGRP		"Default Group:"
    
int main (void)
{
    uid_t me;
    struct passwd *my_passwd;
    struct group *my_group;
    char **members;
   
    /* Get information about the user ID. */
    me = getuid ();
    my_passwd = getpwuid (me);
    if (!my_passwd)
    {
        printf ("Couldn't find out about user %d.\n", (int) me);
        exit (EXIT_FAILURE);
     }
     
     /* Print the information. */
//     printf ("I am %s.\n", my_passwd->pw_gecos);
     printf ("%16s %s\n", LOGNAME, my_passwd->pw_name);
     printf ("%16s %d\n", UID, (int) (my_passwd->pw_uid));
     printf ("%16s %s\n", HOMEDIR, my_passwd->pw_dir);
     printf ("%16s %s\n", DEFSHELL, my_passwd->pw_shell);
     
     /* Get information about the default group ID. */
     my_group = getgrgid (my_passwd->pw_gid);
     if (!my_group)
     {
         printf ("Couldn't find out about group %d.\n",
         (int) my_passwd->pw_gid);
         exit (EXIT_FAILURE);
     }
     
     /* Print the information. */
     printf ("%16s %s (%d)\n", DEFGRP, 
	 my_group->gr_name, (int) (my_passwd->pw_gid));
     /*printf ("The members of this group are:\n");
     members = my_group->gr_mem;
     while (*members)
     {
         printf ("  %s\n", *(members));
         members++;
     }
     */ 
     return EXIT_SUCCESS;
}

